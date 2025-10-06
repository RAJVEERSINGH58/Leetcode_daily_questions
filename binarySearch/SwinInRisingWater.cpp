#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:

    vector<int> dx = {1 , 0 , -1 , 0};
    vector<int> dy = {0 , 1 , 0 , -1};

    bool canPossibleToReach(vector<vector<int>>& grid , int i , int j , int t , vector<vector<bool>>& vis){

        int n = grid.size();

        if(i < 0 || i >= n || j < 0 || j >= n || vis[i][j] || grid[i][j] > t) return false;

        vis[i][j] = true;

        if(i == n - 1 && j == n - 1) return true;
 
        for(int k = 0 ; k < 4 ; k++){
            int i_ = i + dx[k];
            int j_ = j + dy[k];

            if(canPossibleToReach(grid , i_ , j_ , t , vis)) return true;
        }

        return false;

    }

    int swimInWater(vector<vector<int>>& grid) {
        
        int n = grid.size();

        int l = 0;
        int r = n * n - 1;
        int ans = 0;

        while(l <= r){

            vector<vector<bool>> vis(n , vector<bool>(n , false));
            int mid = l + (r - l) / 2;
            if(canPossibleToReach(grid , 0 , 0 , mid , vis)){
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;

        }

        return ans;

    }
};

int main() {
    
    return 0;
}