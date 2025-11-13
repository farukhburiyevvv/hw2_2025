#include <bits/stdc++.h>
using namespace std;

void heapDown(vector<long long>& A, int n, int i) {
    int p = i;
    while (true) {
        int l = 2 * p + 1, r = 2 * p + 2, smallest = p;
        if (l < n && A[l] < A[smallest]) smallest = l;
        if (r < n && A[r] < A[smallest]) smallest = r;
        if (smallest != p) { swap(A[p], A[smallest]); p = smallest; }
        else break;
    }
}

int main() {
    int n, idx;
    cin >> n;
    vector<long long> A(n);
    for (int i = 0; i < n; ++i) cin >> A[i];
    cin >> idx;
    heapDown(A, n, idx);
    for (int i = 0; i < n; ++i) cout << (i ? " " : "") << A[i];
    cout << "\n";
}
