#include <iostream>
#include <vector>
#include <string>
using namespace std;

class LinearMaxPQ {
    vector<int> arr;

public:
    void insertValue(int x) {
        arr.push_back(x);
    }

    int findMaxIdx() const {
        int pos = 0;
        for (int i = 1; i < arr.size(); i++)
            if (arr[i] > arr[pos])
                pos = i;
        return pos;
    }

    void printTop() const {
        if (arr.empty()) {
            cout << "EMPTY\n";
            return;
        }
        cout << arr[findMaxIdx()] << "\n";
    }

    void popTop() {
        if (arr.empty()) {
            cout << "EMPTY\n";
            return;
        }
        int idx = findMaxIdx();
        cout << arr[idx] << "\n";
        arr[idx] = arr.back();
        arr.pop_back();
    }

    void printCount() const {
        cout << arr.size() << "\n";
    }
};

int main() {
    int q;
    cin >> q;

    LinearMaxPQ pq;

    while (q--) {
        string c;
        cin >> c;

        if (c == "insert") {
            int v;
            cin >> v;
            pq.insertValue(v);
        } else if (c == "get_max") {
            pq.printTop();
        } else if (c == "extract_max") {
            pq.popTop();
        } else if (c == "size") {
            pq.printCount();
        }
    }
    return 0;
}
