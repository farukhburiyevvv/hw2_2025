#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    vector<long long> A;
    while (q--) {
        string cmd;
        cin >> cmd;
        if (cmd == "insert") {
            long long x; cin >> x;
            A.push_back(x);
        } else if (cmd == "get") {
            string tmp; cin >> tmp;
            if (A.empty()) cout << "EMPTY\n";
            else {
                long long mx = A[0];
                for (auto x : A) if (x > mx) mx = x;
                cout << mx << "\n";
            }
        } else if (cmd == "extract") {
            string tmp; cin >> tmp;
            if (A.empty()) cout << "EMPTY\n";
            else {
                long long mx = A[0];
                int idx = 0;
                for (int i = 0; i < A.size(); ++i)
                    if (A[i] > mx) { mx = A[i]; idx = i; }
                cout << mx << "\n";
                A.erase(A.begin() + idx);
            }
        } else if (cmd == "size") {
            cout << A.size() << "\n";
        }
    }
}
