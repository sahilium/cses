#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int n;
    cin >> n;

    int prev = 0;
    long long ops = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (x < prev) {
            ops += prev - x;
            x = prev;
        } else {
            prev = x;
        }
    }
    cout << ops << endl;
    return 0;
}
