#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        unordered_set<char> s;

        for(int i = 0 ; i < 9 ; i++){
            for(int j = 0 ; j < 9 ; j++){
                if(board[i][j] == '.') continue;
                if(s.count(board[i][j]) != 0) return false;
                else s.insert(board[i][j]);
            }
            s.clear();
        }

        s.clear();

        for(int i = 0 ; i < 9 ; i++){
            for(int j = 0 ; j < 9 ; j++){
                if(board[j][i] == '.') continue;
                if(s.count(board[j][i]) != 0) return false;
                else s.insert(board[j][i]);
            }
            s.clear();
        }

        s.clear();

        for(int i = 0 ; i < 9 ; i = i + 3){
            for(int j = 0 ; j < 9 ; j = j + 3){

                int row = i;
                int col = j;

                for(int k = row ; k < row + 3 ; k++){
                    for(int l = col ; l < col + 3 ; l++){
                        if(board[k][l] == '.') continue;
                        if(s.count(board[k][l]) != 0) return false;
                        else s.insert(board[k][l]);
                    }
                }

                s.clear();

            }
        }

        return true;
        
    }
};

int main() {
    
    return 0;
}