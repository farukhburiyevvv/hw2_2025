#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    vector<long long> pq;
    for (int i = 0; i < q; ++i) {
        string cmd;
        cin >> cmd;
        if (cmd == "insert") {
            long long x;
            cin >> x;
            pq.push_back(x);
        } else if (cmd == "get") {
            string tmp; cin >> tmp; // max
            if (pq.empty()) cout << "EMPTY\n";
            else {
                long long mx = pq[0];
                for (auto x : pq) if (x > mx) mx = x;
                cout << mx << "\n";
            }
        } else if (cmd == "extract") {
            string tmp; cin >> tmp; // max
            if (pq.empty()) cout << "EMPTY\n";
            else {
                long long mx = pq[0];
                int idx = 0;
                for (int j = 1; j < (int)pq.size(); ++j)
                    if (pq[j] > mx) { mx = pq[j]; idx = j; }
                cout << mx << "\n";
                pq.erase(pq.begin() + idx);
            }
        } else if (cmd == "size") {
            cout << pq.size() << "\n";
        }
    }
}
