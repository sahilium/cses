# 4. Increasing Array

**Source:** CSES `1094` · **File:** `increase.cpp`

## Problem
Given an array of `n` integers, you may repeatedly increase any element by 1. Find the
minimum total number of increases so the array becomes **non-decreasing** (each element
`>=` the previous one).

## Implementation Details
- **Keep `prev` = the value of the previous element.**
- **Read each `x`.** If `x < prev`, the array would decrease, so we must raise `x` up to
  `prev`:
  - `ops += prev - x` — each unit of increase costs 1 operation.
  - set `x = prev` (the raised value becomes the new "previous" for the next element).
- Otherwise `x >= prev`, so just set `prev = x` and continue.
- Print total `ops`.

## DSA Concepts / Techniques
- **Greedy algorithm** — at each step we do the minimum necessary (raise `x` only to
  `prev`, never higher) and accumulate the cost. Greedy is optimal here because raising an
  element more than needed can only hurt later elements.
- **Single pass / linear scan** — one `O(n)` loop with `O(1)` extra space.

## Novice Notes
- Why not raise `x` to more than `prev`? Any extra increases only make future elements
  more expensive to keep up with, so the minimum at every step is also the global minimum
  (a greedy exchange argument).
- Use `long long` for `ops` — with up to `2·10^5` elements, the answer can reach ~10¹⁰,
  far beyond 32-bit `int`.
- This is the classic **"make array non-decreasing with minimal cost"** template: track
  the running max (`prev`) and sum up the shortfalls.