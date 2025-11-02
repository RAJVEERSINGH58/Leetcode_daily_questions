#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:

    void dfs(int i , int j , vector<vector<int>>& mat , int m , int n){

            // go right

            int i_ = i;
            int j_ = j + 1;

            while(j_ < n && mat[i_][j_] != 2 && mat[i_][j_] != 1){
                mat[i_][j_] = -1;
                j_++;
            }


            // go left

            i_ = i;
            j_ = j - 1;

            while(j_ >= 0 && mat[i_][j_] != 2 && mat[i_][j_] != 1){
                mat[i_][j_] = -1;
                j_--;
            }

            // go down

            i_ = i + 1;
            j_ = j;

            while(i_ < m && mat[i_][j_] != 2 && mat[i_][j_] != 1){
                mat[i_][j_] = -1;
                i_++;
            }

            // go up

            i_ = i - 1;
            j_ = j;

            while(i_ >= 0 && mat[i_][j_] != 2 && mat[i_][j_] != 1){
                mat[i_][j_] = -1;
                i_--;
            }

            return;

    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        
        vector<vector<int>> mat(m , vector<int>(n , 0));

        for(auto x : guards){ 
            mat[x[0]][x[1]] = 1;
        }

        for(auto x : walls){
            mat[x[0]][x[1]] = 2;
        }

        for(auto x : guards){
            dfs(x[0] , x[1] , mat , m , n);
        }

        int ans = 0;

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(mat[i][j] == 0) ans++;
            }
        }

        return ans;



    }
};

int main() {
    
    return 0;
}