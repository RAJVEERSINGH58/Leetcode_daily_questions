#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:

    int m , n;
    vector<int> dx = {1 , 0 , -1 , 0};
    vector<int> dy = {0 , 1 , 0 , -1};

    bool isSafe(int i , int j){
        return i >= 0 && j >= 0 && i < m && j < n;
    }

    vector<vector<bool>> bfs(queue<pair<int , int>>& qu , vector<vector<int>>& heights){

        vector<vector<bool>> vis(m , vector<bool>(n , false));

        while(! qu.empty()){

            auto [i , j] = qu.front();
            qu.pop();
            vis[i][j] = true;

            for(int k = 0 ; k < 4 ; k++){
                int i_ = i + dx[k];
                int j_ = j + dy[k];

                if(isSafe(i_ , j_) && ! vis[i_][j_] && heights[i_][j_] >= heights[i][j]){
                    qu.push({i_ , j_});
                }

            }

        }

        return vis;


    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        m = heights.size();
        n = heights[0].size();

        queue<pair<int , int>> paci;
        queue<pair<int , int>> atl;

        for (int i = 0; i < m; i++) {
            paci.push({i, 0});
            atl.push({i, n - 1});
        }

        for (int i = 1; i < n; i++) {
            paci.push({0, i});
        }

        for (int i = 0; i < n - 1; i++) {
            atl.push({m - 1, i});
        }

        vector<vector<bool>> pacific = bfs(paci , heights);
        vector<vector<bool>> atlantic = bfs(atl , heights);

        vector<vector<int>> ans;

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(pacific[i][j] && atlantic[i][j]) ans.push_back({i , j});
            }
        }

        return ans;

    }
};

int main() {
    
    return 0;
}