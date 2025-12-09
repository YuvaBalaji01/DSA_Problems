#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int X, N;
    cin >> X >> N;

    vector<int> requests(N);
    for (int i = 0; i < N; ++i)
        cin >> requests[i];

    list<int> cache; // most recently used at front
    unordered_map<int, list<int>::iterator> cacheMap; // page -> iterator
    int hits = 0;

    for (int i = 0; i < N; ++i) {
        int page = requests[i];

        // Cache hit
        if (cacheMap.find(page) != cacheMap.end()) {
            hits++;
            cache.erase(cacheMap[page]);  // remove old position
        }
        // Cache miss
        else if ((int)cache.size() == X && X != 0) {
            int last = cache.back();
            cacheMap.erase(last);
            cache.pop_back(); // remove LRU
        }

        // Insert page at front if cache size is not 0
        if (X != 0) {
            cache.push_front(page);
            cacheMap[page] = cache.begin();
        }

        // Print current cache state (X elements)
        int printed = 0;
        for (int val : cache) {
            cout << val << " ";
            printed++;
            if (printed == X) break;
        }
        for (int j = printed; j < X; ++j)
            cout << "0 ";
        cout << endl;
    }

    int percentage = (hits * 100) / N;
    cout << percentage << endl;

    return 0;
}
