# EECE 7205: Dynamic Programming Practice Set

Solutions to the three open questions in the dynamic programming practice set (Questions 3, 6 and 9).

Northeastern University, Electrical and Computer Engineering, Fall 2026.

## Contents

`Dynamic_Programming.pdf` covers each question in five parts:
state and recurrence, pseudocode, table simulation, frequency count, and C++ with vectors.

| Q | Problem | Answer | Time |
|---|---------|--------|------|
| 3 | Gold mine | 12 (and 16 for the 4 x 4 mine) | Θ(mn) |
| 6 | Longest palindromic subsequence | 7 for BBABCBCAB, 5 for AGBDBA | Θ(n²) |
| 9 | Maximum sum rectangle | 29, rows 1-3 and columns 1-3 | Θ(n²m) |

## C++ programs

- `gold_mine.cpp`
- `lps.cpp`
- `max_rectangle.cpp`

Build and run any of them with:

```
g++ -std=c++17 -o gold_mine gold_mine.cpp && ./gold_mine
```
