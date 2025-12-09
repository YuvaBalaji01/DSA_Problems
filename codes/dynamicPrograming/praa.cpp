#include <iostream>
#include <vector>
using namespace std;

int solve(vector<vector<int>>& input) {
    int m = input.size();        // number of rows
    int n = input[0].size();     // number of cols

    vector<vector<int>> op(m, vector<int>(n, 0));

    // initialize (0,0)
    op[0][0] = (input[0][0] == 0) ? 1 : 0;

    // fill first row
    for (int j = 1; j < n; j++) {
        if (input[0][j] == 0)
            op[0][j] = 1;
        else
            op[0][j] = 0;
    }

    // fill first column
    for (int i = 1; i < m; i++) {
        if (input[i][0] == 0)
            op[i][0] = 1;
        else
            op[i][0] = 0;
    }

    // process general cells
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {

            bool row = true, col = true;

            // check row i (till j-1)
            for (int k = 0; k < j; k++) {
                if (input[i][k] != 0) { row = false; break; }
            }

            // check col j (till i-1)
            for (int k = 0; k < i; k++) {
                if (input[k][j] != 0) { col = false; break; }
            }

            if (input[i][j] != 0 || !row || !col)
                op[i][j] = op[i-1][j-1];
            else
                op[i][j] = op[i-1][j-1] + 1;
        }
    }

    return op[m-1][n-1];
}

int main() {
    vector<vector<int>> input = {
        {0,0,1},
        {0,0,0},
        {0,0,0},
        {0,0,0}
    };

    cout << solve(input) << endl;
    return 0;
}
