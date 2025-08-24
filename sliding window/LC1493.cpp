class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        int i = 0 , j = 0 , flip = 0;
        int maxLen = INT_MIN , len;

        while(j < n){
            
            if(nums[j] == 1) j++;
            else{
                if(flip < 1){
                    flip++;
                    j++;
                }
                else{
                    len = j - i - 1;
                    maxLen = max(maxLen , len);

                    while(nums[i] == 1) i++;
                    i++;
                    j++;

                }
            }

        }

        len = j - i - 1;
        maxLen = max(maxLen , len);

        return maxLen;
    }
};
