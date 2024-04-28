# **Maze Solver using Recursive Backtracking and BFS**

# **Introduction:**
   The Maze Solver project aims to generate a maze using recursive backtracking algorithm and solve it using breadth-first search (BFS). The project focuses on understanding these two fundamental algorithms and implementing them in the context of maze generation and solving.

# **Maze Generation (Recursive Backtracking):**
   - The maze generation phase utilizes the recursive backtracking algorithm.
   - Recursive backtracking is a depth-first search algorithm that creates a maze by exploring as far as possible along each branch before backtracking.
   - It starts with an empty grid and randomly selects a starting cell.
   - The algorithm recursively chooses a random neighboring cell that has not been visited yet, carving a path to it.
   - If all neighboring cells are visited, it backtracks to the previous cell until it finds unvisited neighbors.

# **Maze Representation:**
   - The maze is represented as a grid of cells.
   - Each cell has walls that can either be present or absent, forming passages.
   - Walls between cells are represented using boolean values or bitwise operations.

# **Maze Solving (BFS):**
   - Once the maze is generated, the project employs BFS to find the shortest path from the start to the end of the maze.
   - BFS explores the maze level by level, starting from the entrance, until it finds the exit.
   - It maintains a queue of cells to explore, marking each cell as visited to avoid revisiting them.
   - When BFS encounters the exit cell, it traces back the path from the exit to the entrance, forming the shortest path.
# **Why not DFS?**
   In general, BFS is a better algorithm for solving mazes than DFS. This is because BFS is guaranteed to find the shortest path to the goal, while DFS is not. Additionally, BFS is less likely to get stuck in a dead end than DFS.
   However, there are some cases where DFS may be a better choice than BFS. For example, if the maze is very large, DFS may be able to find a solution faster than BFS. Additionally, if the maze is very complex, DFS may be able to find a        solution that BFS cannot.

**This project is implemented in C++**
