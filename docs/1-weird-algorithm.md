# 1. Weird Algorithm

**Source:** CSES `1069` · **File:** `weird.cpp` / `weird_optimised.cpp`

## Problem
Starting from an integer `n`, repeatedly apply:
- if `n` is even → `n = n / 2`
- if `n` is odd → `n = 3 * n + 1`

Print every value until you reach `1`. This sequence is called the **Collatz sequence**.

## Implementation Details
- **Read `n` into a `long long`, not `int`.** The `3n + 1` step can grow the value several times
  beyond the original input before it comes back down, so 32-bit `int` risks overflow.
  `long long` is the safe, standard choice for CP.
- **Loop while `n != 1`.** Print the current value, then branch:
  - even → `n /= 2`
  - odd → `n = 3 * n + 1`
- After the loop prints the final `1`.

### Optimised version (bit tricks)
Two micro-optimisations in `weird_optimised.cpp` (same logic, faster constant factor):
1. `(n & 1)` instead of `n % 2` — a bitwise AND tests the lowest bit. Cheaper than
   computing a signed remainder.
2. `n >>= 1` instead of `n /= 2` — a right shift equals dividing by 2 but is faster.
3. Because `3n + 1` for odd `n` is **always even**, we fold two steps into one
   iteration: compute `3n + 1`, then immediately shift right. This roughly halves the
   loop iterations.

## DSA Concepts / Techniques
- **Simulation** — directly following the steps the problem describes.
- **Bit manipulation** — using `& 1` and `>>` as fast alternatives to modulo and division.
- **`long long` overflow safety** — choosing a wider type when intermediate values can grow.

## Novice Notes
- The Collatz conjecture (that every sequence reaches 1) is **still unproven in
  mathematics**, but it holds for every input CSES will test.
- `ios::sync_with_stdio(false); cin.tie(nullptr);` at the top makes `cin`/`cout` fast.
  Without it, mixing C++ streams with C stdio can slow down I/O and cause TLE.
- `>>=` and `&` are just faster spellings of `/= 2` and `% 2 == 0` — they are *not* a
  different algorithm.