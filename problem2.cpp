#include <bits/stdc++.h>
using namespace std;

void heapDown(vector<long long>& H, int n, int i) {
    int p = i;
    while (true) {
        int l = 2 * p + 1, r = 2 * p + 2, smallest = p;
        if (l < n && H[l] < H[smallest]) smallest = l;
        if (r < n && H[r] < H[smallest]) smallest = r;
        if (smallest != p) { swap(H[p], H[smallest]); p = smallest; }
        else break;
    }
}

void buildMinHeap(vector<long long>& H) {
    for (int i = H.size() / 2 - 1; i >= 0; --i) heapDown(H, H.size(), i);
}

long long extractMin(vector<long long>& H) {
    long long res = H[0];
    H[0] = H.back();
    H.pop_back();
    if (!H.empty()) heapDown(H, H.size(), 0);
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<long long> H(n);
    for (int i = 0; i < n; ++i) cin >> H[i];
    buildMinHeap(H);
    for (int i = 0; i < n; ++i) cout << (i ? " " : "") << extractMin(H);
    cout << "\n";
}
