#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;
    long long expected_sum = n * (n + 1) / 2; // sum of first n natural numbers

    long long sum = 0;
    for (long long i = 1; i < n; ++i) {
        long long x;
        cin >> x;
        sum += x;
    }

    cout << expected_sum - sum << '\n'; // TRICK: subtract sum from expected total

    return 0;
}
