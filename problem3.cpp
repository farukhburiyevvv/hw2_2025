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
        } else if (cmd == "get") {
            string tmp; cin >> tmp;
            if (A.empty()) cout << "EMPTY\n";
            else {
                long long mx = LLONG_MIN;
                for (auto v : A) mx = max(mx, v);
                cout << mx << "\n";
            }
        } else if (cmd == "extract") {
            string tmp; cin >> tmp;
            if (A.empty()) cout << "EMPTY\n";
            else {
                long long mx = LLONG_MIN;
                int idx = -1;
                for (int j = 0; j < (int)A.size(); ++j) {
                    if (A[j] > mx) { mx = A[j]; idx = j; }
                }
                cout << mx << "\n";
                A.erase(A.begin() + idx);
            }
        } else if (cmd == "size") cout << A.size() << "\n";
    }
}
