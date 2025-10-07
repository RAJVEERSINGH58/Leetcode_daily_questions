#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        
        int n = rains.size();

        set<int> st;
        unordered_map<int, int> last;

        vector<int> ans(n , 1);

        for(int i = 0 ; i < n ; i++){

            int lake = rains[i];

            if(lake > 0){

                ans[i] = -1;

                if(last.count(lake)){
                    auto it = st.upper_bound(last[lake]);
                    if(it == st.end()) return {};
                    ans[*it] = lake;
                    st.erase(it);
                }
                

                last[lake] = i;
            }

            else{
                st.insert(i);
            }

        }

        return ans;


    }
};

int main() {
    
    return 0;
}