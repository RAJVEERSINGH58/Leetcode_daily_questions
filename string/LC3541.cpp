#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:
    int maxFreqSum(string s) {

        vector<int> freq(26, 0);

        for (auto ch : s) {
            freq[ch - 'a']++;
        }

        int maxVowelCount = 0;
        int maxConsCount = 0;

        for (int i = 0; i < 26; i++) {
            if (i == 0 || i == 4 || i == 8 || i == 14 || i == 20)
                maxVowelCount = max(maxVowelCount, freq[i]);
            else
                maxConsCount = max(maxConsCount, freq[i]);
        }

        return maxConsCount + maxVowelCount;
    }
};

int main() {
    
    return 0;
}