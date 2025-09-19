#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Spreadsheet {
public:
    vector<vector<int>> v;

    Spreadsheet(int rows) {
        v.clear();
        v.resize(rows , vector<int>(26 , 0));
    }
    
    void setCell(string cell, int value) {
        char ch = cell[0];
        int col = ch - 'A';
        int row = stoi(cell.substr(1)) - 1;
        v[row][col] = value;

    }
    
    void resetCell(string cell) {
        char ch = cell[0];
        int col = ch - 'A';
        int row = stoi(cell.substr(1)) - 1;
        v[row][col] = 0;
    }
    
    int getValue(string formula) {
        string s1 , s2;
        int i = 1;
        bool a1 = false , a2 = false;
        while(formula[i] != '+'){
            if(!isdigit(formula[i])) a1 = true;
            s1 += formula[i];
            i++;
        }
        i++;
        while(i < formula.length()){
            if(!isdigit(formula[i])) a2 = true;
            s2 += formula[i];
            i++;
        }
        int x1 , x2;
        if(a1){
            char ch = s1[0];
            int col = ch - 'A';
            int row = stoi(s1.substr(1)) - 1;
            x1 = v[row][col];
        }
        else x1 = stoi(s1);

        if(a2){
            char ch = s2[0];
            int col = ch - 'A';
            int row = stoi(s2.substr(1)) - 1;
            x2 = v[row][col];
        }
        else x2 = stoi(s2);

        return x1 + x2;

    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */

int main() {
    
    return 0;
}