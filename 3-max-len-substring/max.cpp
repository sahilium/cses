#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    string s;
    cin >> s;
    int max_len = 0;
    int len = 0; // length of the current run of identical characters
    char prev = 0; // sentinel (not real data) so the first character always starts a new run
    for (char c : s) {
        if (c == prev) { // extend the current run
            len++;
        } else { // start a new run
            len = 1;
            prev = c; // reset the sentinel
        }
        max_len = max(max_len, len); // track the longest run seen so far
    }
    cout << max_len << endl;
}
