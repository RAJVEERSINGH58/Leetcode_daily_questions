#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {

        int n = fruits.size();
        int m = baskets.size();

        unordered_set<int> st; // or vector<bool> used(n , false);
        int count = 0;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(baskets[j] >= fruits[i] && !st.count(j)){
                    count++;
                    st.insert(j);
                    break;
                }
            }
        }

        return n - count;

    }
};

int main() {
    
    return 0;
}