#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:

    double epsilon = 0.1;

    bool solve(vector<double>& card){
        if(card.size() == 1){
            if(abs(card[0] - 24) < epsilon) return true;
        }

        for(int i = 0 ; i < card.size() ; i++){
            for(int j = 0 ; j < card.size() ; j++){
                if(i == j) continue;

                vector<double> temp;

                for(int k = 0 ; k < card.size() ; k++){
                    if(k != i && k != j){
                        temp.push_back(card[k]);
                    }
                }

                double a = card[i];
                double b = card[j];

                vector<double> val = {a - b , b - a , a + b , a * b};

                if(a > 0.0) val.push_back(b/a);
                if(b > 0.0) val.push_back(a/b);

                for(double x : val){
                    temp.push_back(x); //do
                    if(solve(temp) == true) return true; //explore
                    temp.pop_back(); //undo
                }


            }
        }

        return false;

    }

    bool judgePoint24(vector<int>& cards) {
        vector<double> temp;

        for(int x : cards){
            temp.push_back(1.0 * x);
        }

        return solve(temp);

    }
};

int main() {
    
    return 0;
}