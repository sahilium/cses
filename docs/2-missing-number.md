# 2. Missing Number

**Source:** CSES `1083` · **File:** `missing.cpp`

## Problem
You are given all integers from `1..n` except **one**, in some shuffled order. Find the
missing one.

## Implementation Details
- **Read `n`**, then compute `expected_sum = n * (n + 1) / 2` — the formula for the sum
  of the first `n` natural numbers.
- **Read the `n - 1` given numbers**, adding each to `sum`.
- **Answer = `expected_sum - sum`.** The gap between what the full set should sum to and
  what you actually got is exactly the missing value.
- Store `n` and `sum` as `long long`: `n * (n + 1)` can exceed 32-bit range, and
  `n` can be up to `2·10^5` (the sum is ~`2·10^10`).

## DSA Concepts / Techniques
- **Formula / arithmetic insight** — the "trick" is to avoid sorting or hashing by
  exploiting a closed-form sum.
- **Inclusion–exclusion thinking** — the missing element is the difference between the
  expected total and the observed total.

## Novice Notes
- The naive approach (search for each of `1..n` in the array) is `O(n²)`. The sum trick
  solves it in **one pass, `O(n)` time and `O(1)` extra space**.
- If the numbers weren't `1..n` you couldn't use this — it works only because the values
  form a known contiguous range whose total has a formula.
- Alternative correct approach: `XOR` all of `1..n` with all given numbers; the missing
  value is the result. Both are valid; the sum version is easier to explain.