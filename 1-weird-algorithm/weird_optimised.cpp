#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n; // long long to handle large values
    cin >> n;

    while (n != 1) {
        cout << n << ' '; // cout the value before right shift
        if ((n & 1) == 0) // check if n is even
            n >>= 1; // bitwise right shift means divide by 2
        else {
            n = (3 * n + 1);
            cout << n << ' '; // cout the value before right shift
            n >>= 1; // we know n is even after this so we can safely right shift to optimise
        }
    }
    cout << n << '\n'; // cout the final value

    return 0;
