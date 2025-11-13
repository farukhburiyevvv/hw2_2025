#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    vector<long long> A;
    string cmd;
    for (int i = 0; i < q; ++i) {
        cin >> cmd;
        if (cmd == "insert") { long long x; cin >> x; A.push_back(x); }
        else if (cmd == "get") { string tmp; cin >> tmp; 
            if (A.empty()) cout << "EMPTY\n"; 
            else cout << *max_element(A.begin(), A.end()) << "\n"; 
        }
        else if (cmd == "extract") { string tmp; cin >> tmp; 
            if (A.empty()) cout << "EMPTY\n"; 
            else { 
                auto it = max_element(A.begin(), A.end()); 
                cout << *it << "\n"; 
                A.erase(it); 
            } 
        }
        else if (cmd == "size") cout << A.size() << "\n";
    }
}
