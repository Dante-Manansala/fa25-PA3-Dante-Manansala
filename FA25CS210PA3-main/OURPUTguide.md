

# Output Guide for PA3: Maze Escape Using DFS

This guide explains what the program will generate, how you should interact with it, and how to understand the maze grid that appears on your screen. You should read this before running and testing your DFS implementation.

---

## 1. What the Program Will Generate

When you run the program, it will:

1. Ask you for maze dimensions `N M`.
2. Generate a random N×M matrix filled with **0s** and **1s**.
3. Randomly choose:
   - **S** (the entrance)  
   - **E** (the exit)
4. Print the entire maze to the screen.
5. After you implement DFS, the program will either:
   - Print the full path from S to E, if one exists  
   - Or print “No path exists.”

---

## 2. What You Should Type as Input

When the program starts, you will see:

```
Enter maze dimensions N M:
```

You must enter two integers, for example:

```
5 5
```

This creates a 5×5 maze.

You may choose any size you want, but smaller grids (5×5, 6×6, 8×8) are easier for debugging.

---

## 3. Understanding the Maze Matrix

After you enter dimensions, the program prints something like:

```
Maze:
0 0 0 0 0
0 0 1 0 1
1 1 0 0 0
0 0 0 0 E
0 1 S 0 0
```

### What each symbol means:

Symbol | Meaning
---|---
`0` | Open path, DFS can move here
`1` | Wall, DFS cannot move here
`S` | Entrance (Start position for DFS)
`E` | Exit (Goal position)

### Important:
- Walls **block** DFS.
- DFS may move only up, right, down, or left.
- There is **exactly one S and one E**, always on the boundary.

---

## 4. Example Where a Path *Is Possible*

Here is a small example where DFS *can* reach the exit:

```
Maze:
S 0 1
0 0 1
1 0 E
```

One valid path is:

```
(0,0) → (0,1) → (1,1) → (2,1) → (2,2)
```

Your DFS, if implemented correctly, will print something like:

```
Path from entrance to exit:
(0,0)
(0,1)
(1,1)
(2,1)
(2,2)
```

---

## 5. Example Where a Path Is *Not Possible*

Here is a maze that cannot reach the exit:

```
Maze:
S 1 1
1 0 1
1 0 E
```

In this case:

- The entrance is blocked in by walls.
- DFS will explore open cells but **never reach E**.

Your output should be:

```
No path exists.
```

---

## 6. What the Output Should Look Like After You Implement DFS

Once you complete your DFS and run the program, you will see:

1. The maze printed.
2. Debug messages (if you choose to add them).
3. A final result:

### If path exists:
```
Path from entrance to exit:
(r1, c1)
(r2, c2)
...
(exit_r, exit_c)
```

### If no path exists:
```
No path exists.
```

---

## 7. Summary

You now know:

- What to type as input  
- What the maze symbols mean  
- How to interpret the printed matrix  
- What valid DFS output looks like  
- What failure output looks like  

Use this guide while writing and testing your DFS.