#include<bits/stdc++.h>
#include<vector>
using namespace std;
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> st;

        int maxval = *max_element(arr.begin() , arr.end());
        int bits = maxval == 0 ? 0 : 1 + log2(maxval);

        int all_bit_set = (1<<bits) - 1;

        for(int i = 0 ; i < n ; i++){
            int x = 0;
            for(int j = i ; j < n ; j++){
                x = x | arr[j];
                st.insert(x);
                if(x == all_bit_set) break;
            }
        }

        return st.size();

    }
};

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> result , prev , curr;

        for(int i = 0 ; i < n ; i++){
            curr = {arr[i]};
            for(int y : prev){
                curr.insert(y | arr[i]);
            }
            prev = curr;
            result.insert(curr.begin() , curr.end());
        }

        return result.size();

    }
};