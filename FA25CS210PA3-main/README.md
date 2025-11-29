

# PA3: Maze Escape Using DFS  

Starter Code README

This project provides you with a randomly generated maze stored in a 2D matrix. Your job is to implement a recursive Depth-First Search (DFS) that determines whether there is a path from the entrance to the exit.

The starter code already includes:
1. Maze generation  
2. Entrance and exit selection  
3. Maze printing  
4. Data structures for visited tracking  
5. Data structures for tracking parent cells  
6. A function to print the final reconstructed path  

You must implement the DFS logic yourself.

---

## 1. Maze Representation

The maze is stored in:

```
vector<vector<int>> maze;
```

Each cell contains:
- `0` meaning the cell is open  
- `1` meaning the cell is a wall  

Movement is allowed only in four directions: up, right, down, left.

---

## 2. Direction Arrays

```
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
```

These arrays represent the change in row and column for each direction.

Index | Direction | dr | dc  
---|---|---|---  
0 | Up | -1 | 0  
1 | Right | 0 | +1  
2 | Down | +1 | 0  
3 | Left | 0 | -1  

---

## 3. Entrance and Exit

Two open boundary cells are randomly chosen:

```
pair<int,int> entrance;
pair<int,int> exitcell;
```

They are extracted for convenience into:

```
int ent_r, ent_c;
int exit_r, exit_c;
```

---

## 4. Visited Array

```
vector<vector<bool>> visited(N, vector<bool>(M, false));
```

This tracks whether DFS has visited a cell.

You must mark each visited cell in your DFS implementation.

---

## 5. Parent Tracking Arrays

To reconstruct the path, the program provides:

```
vector<vector<int>> parent_r;   // row of parent cell
vector<vector<int>> parent_c;   // column of parent cell
```

When DFS moves from `(r, c)` to `(nr, nc)` you must set:

```
parent_r[nr][nc] = r;
parent_c[nr][nc] = c;
```

This allows the starter code to rebuild the path from exit to entrance.

---

## 6. Provided Functions (Do Not Modify)

### **generateMaze(...)**  
Creates the random maze.

### **chooseBoundaryCell(...)**  
Selects an open boundary cell for the entrance or exit.

### **printMaze(...)**  
Prints the maze with `S` marking the entrance and `E` marking the exit.

### **printPath(...)**  
Uses the parent arrays to reconstruct and print the full path from the entrance to the exit.

---

## 7. Your Task: Implement DFS

You must implement:

```
bool dfs(int r, int c,
         const vector<vector<int>>& maze,
         vector<vector<bool>>& visited,
         vector<vector<int>>& parent_r,
         vector<vector<int>>& parent_c,
         int exit_r, int exit_c);
```

Your DFS must handle the following:

1. Out-of-bounds checks  
2. Wall checks (`maze[r][c] == 1`)  
3. Visited checks  
4. Marking the current cell as visited  
5. Checking if `(r, c)` is the exit  
6. Exploring neighbors using `dr` and `dc`  
7. Assigning the parent before recursing  
8. Returning true when the exit is found  

---

## 8. Running DFS

In `main()`, you will add:

```cpp
bool found = dfs(ent_r, ent_c, maze, visited, parent_r, parent_c, exit_r, exit_c);
```

---

## 9. Final Output

If DFS succeeds:

```cpp
printPath(exitcell, parent_r, parent_c, ent_r, ent_c);
```

Otherwise:

```cpp
cout << "\nNo path exists.\n";
```

---

## 10. Summary of Variables

Variable | Meaning
---|---
`maze` | The maze grid of 0s and 1s
`visited` | Tracks which cells DFS has visited
`parent_r`, `parent_c` | Store parent coordinates for path reconstruction
`dr`, `dc` | Direction arrays for movement
`entrance`, `exitcell` | Boundary start and end cells
`ent_r`, `ent_c` | Entrance coordinates
`exit_r`, `exit_c` | Exit coordinates
`N`, `M` | Maze dimensions

---

## 11. What You Need to Submit

Your submission must include:
1. Your completed DFS implementation  
2. Correct use of visited and parent arrays  
3. A successful path printout when a path exists  

Do not modify the maze generator or the provided print functions.