#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        
        int n = text.length();
        int m = brokenLetters.length();

        unordered_set<char> st;

        for(char ch : brokenLetters){
            st.insert(ch);
        }

        int ans = 0;

        bool flag = true;

        for(int i = 0 ; i < n ; i++){
            if(text[i] == ' '){
                ans++;
                continue;
            }
            flag = true;

            if(st.count(text[i]) > 0){
                while(i < n && text[i] != ' ') i++;
                flag = false;
            }

        }

        if(flag == true) ans++;


        return ans;

    }
};

int main() {
    
    return 0;
}