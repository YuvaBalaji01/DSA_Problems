#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

int closestCost(int n, int m, vector<int>& base, vector<int>& toppings, int target) {
    int ans = INT_MAX;

    for (int i = 0; i < n; i++) {
        int baseCost = base[i];

        // Brute force all topping combinations (each topping 0/1/2 times)
        // Total combinations = 3^m
        int totalComb = pow(3, m);

        for (int mask = 0; mask < totalComb; mask++) {
            int cost = baseCost;
            int temp = mask;

            for (int j = 0; j < m; j++) {
                int times = temp % 3;  // use topping 0, 1, or 2 times
                temp /= 3;
                cost += times * toppings[j];
            }

            int diff1 = abs(ans - target);
            int diff2 = abs(cost - target);

            if (diff2 < diff1 || (diff2 == diff1 && cost < ans)) {
                ans = cost;
            }
        }
    }

    return ans;
}

int main() {
    int n = 4, m = 3;
    vector<int> base = {1, 8, 3, 4};
    vector<int> toppings = {2, 3, 4};

    int target = 20;
    int ans = closestCost(n, m, base, toppings, target);

    cout << ans << endl;
    return 0;
}
