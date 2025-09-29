#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:

    int dp[51][51];

    int f(vector<int>& values , int i , int j){

        if(j - i < 2) return 0;
        int n = values.size();

        if(dp[i][j] != -1) return dp[i][j];

        int result = INT_MAX;
        
        for(int k = i + 1 ; k < j ; k++){
            int wt = values[i] * values[j] * values[k] + f(values , i , k) + f(values , k , j);
            result = min(result , wt);
        }

        return dp[i][j] = result;

    }


    int minScoreTriangulation(vector<int>& values) {

        int n = values.size();

        memset(dp , -1 , sizeof dp);

        return f(values , 0 , n - 1);

    }
};

int main() {
    
    return 0;
}