#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:

    int m , n;
    vector<vector<int>> right;

    int rightcount(vector<vector<int>>& mat , int i , int j){
        if(i < 0 || j < 0 || i >= m || j >= n || mat[i][j] == 0) return 0;

        if(right[i][j] != -1) return right[i][j];

        return right[i][j] = 1 + rightcount(mat , i , j + 1);

    }

    int countFromPosition(vector<vector<int>>& mat , int i , int j){

        int minWidth = rightcount(mat , i , j);
        int count = 0;

        for(int k = i ; k < m ; k++){
            minWidth = min(minWidth , rightcount(mat , k , j));
            count += minWidth;
        }

        return count;

    }

    int numSubmat(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();

        right.assign(m , vector<int>(n , -1));

        int total = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    total += countFromPosition(mat, i, j);
                }
            }
        }

        return total;
    }
};


int main() {
    
    return 0;
}