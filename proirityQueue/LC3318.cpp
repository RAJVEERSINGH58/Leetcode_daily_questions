#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:

    int sum(vector<int>& nums , vector<int>& freq , int x , int i , int j){

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        unordered_set<int> st;

        int s = 0;

        for(int k = i ; k <= j ; k++){
            int num = nums[k];
            s += num;

            if(st.count(num) == 0){
                pq.push({freq[num], num});
                if(pq.size() > x) pq.pop();
                st.insert(num);
            }
        }

        if(pq.size() < x) return s;

        int ans = 0;
        while(!pq.empty()){
            ans += pq.top().first * pq.top().second;
            pq.pop();
        }

        return ans;
    }

    vector<int> findXSum(vector<int>& nums, int k, int x) {
        
        int n = nums.size();
        vector<int> freq(51, 0);   
        vector<int> ans;

        int i = 0, j = 0;

        while(j < n){

            freq[nums[j]]++;

            if(j - i + 1 < k){
                j++;
            }
            else if(j - i + 1 == k){
                
                ans.push_back(sum(nums, freq, x, i, j));

                freq[nums[i]]--;
                i++;
                j++; 
            }
        }

        return ans;
    }
};


int main() {
    
    return 0;
}