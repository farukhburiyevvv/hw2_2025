#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    vector<long long> A;
    string cmd;
    for (int i = 0; i < q; ++i) {
        cin >> cmd;
        if (cmd == "insert") {
            long long x; cin >> x;
            A.push_back(x);
        }
        else if (cmd == "get") {
            string tmp; cin >> tmp; // max
            if (A.empty()) cout << "EMPTY\n";
            else {
                long long mx = A[0];
                for (auto v : A) if (v > mx) mx = v;
                cout << mx << "\n";
            }
        }
        else if (cmd == "extract") {
            string tmp; cin >> tmp; // max
            if (A.empty()) cout << "EMPTY\n";
            else {
                long long mx = A[0];
                int idx = 0;
                for (int j = 0; j < (int)A.size(); ++j)
                    if (A[j] > mx) { mx = A[j]; idx = j; }
                cout << mx << "\n";
                A.erase(A.begin() + idx); // remove first occurrence
            }
        }
        else if (cmd == "size") cout << A.size() << "\n";
    }
}
