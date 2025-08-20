#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:
    int dp[305][305];

    int f(int i, int j, vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        if (i < 0 || j < 0 || i >= m || j >= n || mat[i][j] == 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int right = f(i, j + 1, mat);
        int dia = f(i + 1, j + 1, mat);
        int below = f(i + 1, j, mat);

        return dp[i][j] = 1 + min({right, below, dia});
    }

    int fbu(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                if (mat[i][j] == 1) {
                    mat[i][j] +=
                        min({mat[i + 1][j + 1], mat[i + 1][j], mat[i][j + 1]});
                }
            }
        }

        int totalSquares = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                totalSquares += mat[i][j];
            }
        }

        return totalSquares;
    }

    int countSquares(vector<vector<int>>& mat) {

        // int m = mat.size();
        // int n = mat[0].size();

        // memset(dp , -1 , sizeof dp);

        // long long ans = 0;

        // for(int i = 0 ; i < m ; i++){
        //     for(int j = 0 ; j < n ; j++){
        //         if(mat[i][j] == 1) ans += f(i , j , mat);
        //     }
        // }

        return fbu(mat);

        //return ans;
    }
};

int main() {
    
    return 0;
}