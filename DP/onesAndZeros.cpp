#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:

    int dp[605][101][101];

    int dfs(vector<vector<int>>& v , int i , int m , int n){

        if(i >= v.size()) return 0;

        if(dp[i][m][n] != -1) return dp[i][m][n];

        int take = 0;
        if (m >= v[i][0] && n >= v[i][1])
            take = 1 + dfs(v, i + 1, m - v[i][0], n - v[i][1]);

        int notTake = dfs(v , i + 1 , m , n); 

        return dp[i][m][n] = max(take , notTake);

    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        
        int x = strs.size();

        vector<vector<int>> v(x , vector<int>(2));

        for(int i = 0 ; i < x ; i++){

            int m_ = 0 , n_ = 0;

            for(char ch : strs[i]){
                if(ch == '0') m_++;
                else n_++;
            }

            v[i][0] = m_;
            v[i][1] = n_;

        }

        memset(dp , -1 , sizeof dp);

        return dfs(v , 0 , m , n);
    }
};

int main() {
    
    return 0;
}