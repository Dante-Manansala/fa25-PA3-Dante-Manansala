//
// Created by Manju Muralidharan on 11/22/25.
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Directions for DFS (students must use these)
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

// ----------------------------------------------------------
// DO NOT MODIFY: Maze generation
// ----------------------------------------------------------
void generateMaze(vector<vector<int>>& maze, int N, int M) {
    srand(time(0));

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            int roll = rand() % 100;
            maze[r][c] = (roll < 70) ? 0 : 1;   // 0 = open, 1 = wall
        }
    }
}

// ----------------------------------------------------------
// DO NOT MODIFY: Choose a random boundary cell that is open
// ----------------------------------------------------------
pair<int,int> chooseBoundaryCell(const vector<vector<int>>& maze) {
    int N = maze.size();
    int M = maze[0].size();

    while (true) {
        int side = rand() % 4;
        int r, c;

        if (side == 0) {          // top row
            r = 0;
            c = rand() % M;
        } else if (side == 1) {   // bottom row
            r = N - 1;
            c = rand() % M;
        } else if (side == 2) {   // left column
            r = rand() % N;
            c = 0;
        } else {                  // right column
            r = rand() % N;
            c = M - 1;
        }

        if (maze[r][c] == 0) {
            return {r, c};
        }
    }
}

// ----------------------------------------------------------
// DO NOT MODIFY: Print the maze with S and E markers
// ----------------------------------------------------------
void printMaze(const vector<vector<int>>& maze,
               int ent_r, int ent_c,
               int exit_r, int exit_c)
{
    int N = maze.size();
    int M = maze[0].size();

    cout << "\nMaze:\n";
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            if (r == ent_r && c == ent_c) {
                cout << "S ";
            } else if (r == exit_r && c == exit_c) {
                cout << "E ";
            } else {
                cout << maze[r][c] << " ";
            }
        }
        cout << "\n";
    }
}

// ----------------------------------------------------------
// DO NOT MODIFY: Print the reconstructed path
// Students must fill parent[][] correctly during DFS
// ----------------------------------------------------------
void printPath(pair<int,int> exitcell,
               const vector<vector<int>>& parent_r,
               const vector<vector<int>>& parent_c,
               int ent_r, int ent_c)
{
    int r = exitcell.first;
    int c = exitcell.second;

    vector<pair<int,int>> path;

    // Walk backward from exit to entrance
    while (!(r == ent_r && c == ent_c)) {
        path.push_back({r, c});
        int pr = parent_r[r][c];
        int pc = parent_c[r][c];
        r = pr;
        c = pc;
    }
    path.push_back({ent_r, ent_c});

    cout << "\nPath from entrance to exit:\n";
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << "(" << path[i].first << ", " << path[i].second << ")\n";
    }
}

// ----------------------------------------------------------
// STUDENTS IMPLEMENT DFS HERE
// TODO:Add arguments, return type, and logic
// TODO:Recursive method
// ----------------------------------------------------------
/// NOTE: make Depth-First Search(DFS)
/// has 8 inputs based off main : dfs(ent_r, ent_c, maze, visited, parent_r, parent_c, exit_r, exit_c)
bool dfs(int ent_r, int ent_c,
         const vector<vector<int>>& maze,
         vector<vector<bool>>& visited,
         vector<vector<int>>& parent_r, vector<vector<int>>& parent_c,
         int exit_r, int exit_c) {

    ///NOTE: current is current cell
    // check if current cell is viable
    // if not in bounds, false (helps avoid bound errors)
    if (ent_r < 0 || ent_r >= maze.size() || ent_c < 0 || ent_c >= maze[0].size()) return false;
    // if current == wall, false
    if (maze[ent_r][ent_c] == 1) return false;
    // if visited == true, false
    if (visited[ent_r][ent_c]) return false;

    //mark current as visited
    visited[ent_r][ent_c] = true;

    ///EXIT CONDITION: recursion
    // if current == exit, true
    if (ent_r == exit_r && ent_c == exit_c) return true;

    // prep for each adjacent cell for recursion
    for (int x = 0; x < 4; x++) {

        // created for easier reading
        int ar = ent_r + dr[x]; //adjacent row
        int ac = ent_c + dc[x]; //adjacent column

        ///NOTE: maybe add wall and visit check here? help fix more runtime errors, unsure why
        // realized was running to problem of bounds here with loading parent.
        // if not in bounds, skip (helps avoid bound errors)
        if (ar < 0 || ar >= maze.size() || ac < 0 || ac >= maze[0].size()) continue;
        // if current == wall, skip
        if (maze[ar][ac] == 1) continue;
        // if visited == true, skip
        if (visited[ar][ac]) continue;

        // mark parents for adjacent/new cell in recursion
        // Used to backtrack when printing printPath
        parent_r[ar][ac] = ent_r;
        parent_c[ar][ac] = ent_c;

        /// RECURSION
        // Recursion adjacent cell of current
        if (dfs(ar, ac, maze, visited, parent_r, parent_c, exit_r, exit_c)) return true;
    }

    ///EXIT CONDITION: recursion
    return false; // if exit not reachable, false
}


// ----------------------------------------------------------
// MAIN PROGRAM (students add DFS calls and logic)
// ----------------------------------------------------------
int main() {
    int N, M; // N = columns, M = rows

    cout << "Enter maze dimensions N M: ";
    cin >> N >> M;

    vector<vector<int>> maze(N, vector<int>(M)); // vector within vector
    generateMaze(maze, N, M);

    // Pick entrance and exit
    pair<int,int> entrance = chooseBoundaryCell(maze);
    pair<int,int> exitcell = chooseBoundaryCell(maze);

    while (exitcell == entrance) {
        exitcell = chooseBoundaryCell(maze);
    }

    int ent_r = entrance.first;
    int ent_c = entrance.second;
    int exit_r = exitcell.first;
    int exit_c = exitcell.second;

    // Display the maze
    printMaze(maze, ent_r, ent_c, exit_r, exit_c);

    // Students must use these
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    vector<vector<int>> parent_r(N, vector<int>(M, -1));
    vector<vector<int>> parent_c(N, vector<int>(M, -1));

    // ------------------------------------------------------
    // STUDENT WORK:
    // TODO: Call your DFS, track visited, and fill parent_r and parent_c
    // ------------------------------------------------------
     bool found = dfs(ent_r, ent_c, maze, visited, parent_r, parent_c, exit_r, exit_c);

    // ------------------------------------------------------
    // STUDENT WORK:
    // TODO: If found, print the path
    // ------------------------------------------------------
     if (found) {printPath(exitcell, parent_r, parent_c, ent_r, ent_c);
     } else {cout << "\nNo path exists.\n";}

    return 0;
}