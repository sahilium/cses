# 3. Maximum Length Substring (Repetitions)

**Source:** CSES `1069` · **File:** `max.cpp`

## Problem
Given a string, find the length of the longest **contiguous run** of the same character
(e.g. `ATTCGGGA` → the longest run is `GGG`, length `3`).

## Implementation Details
- **Single pass, left to right.** Keep two counters:
  - `len` — length of the current run of identical characters.
  - `max_len` — the best (largest) `len` seen so far.
- For each character `c`:
  - if `c == prev` → the run continues, so `len++`.
  - else → a new run starts, reset `len = 1` and set `prev = c`.
  - update `max_len = max(max_len, len)`.
- Print `max_len`.
- A sentinel `prev = 0` (a char value that cannot appear) makes the first character
  always count as the start of a new run, so no special-casing is needed.

## DSA Concepts / Techniques
- **Two-pointer / sliding window idea (single-run tracking)** — one index `i` for the
  start of the current run, `j` sweeping forward. Here it collapses into two counters.
- **Greedy scanning** — making the locally best choice (extend or reset) at each step.

## Novice Notes
- The original nested-loop version was **`O(n²)`** — for every `i` it scanned ahead to
  find that character's run. On a long string (say 1,000,000 chars) that is ~10¹²
  operations → **timeout**.
- The one-pass version is **`O(n)` time and `O(1)` extra space** — each character is
  examined exactly once, so even very long strings finish instantly.
- Watch that you still track `max_len` even after a run ends; a run that is reset must not
  erase the best answer found earlier.