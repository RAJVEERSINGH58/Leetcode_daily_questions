#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> getDiagonal(int row, int col, vector<vector<int>>& grid, int n) {
        vector<int> diagonal;
        while (row < n && col < n) {
            diagonal.push_back(grid[row][col]);
            row++; col++;
        }
        return diagonal;
    }
    
    void putDiagonal(int row, int col, const vector<int>& diagonal, vector<vector<int>>& grid, int n) {
        int index = 0;
        while (row < n && col < n) {
            grid[row][col] = diagonal[index++];
            row++; col++;
        }
    }
    
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) { 
        int n = grid.size();

        for (int row = 0; row < n; row++) {
            int col = 0;
            vector<int> diagonal = getDiagonal(row, col, grid, n);
            sort(diagonal.begin(), diagonal.end(), greater<int>());
            putDiagonal(row, col, diagonal, grid, n);
        }
        
        for (int col = 1; col < n; col++) {
            int row = 0;
            vector<int> diagonal = getDiagonal(row, col, grid, n);
            sort(diagonal.begin(), diagonal.end());
            putDiagonal(row, col, diagonal, grid, n);
        }
        
        return grid;
    }
};

int main() {
    
    return 0;
}