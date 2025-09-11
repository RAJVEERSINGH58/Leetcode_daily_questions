#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:

    void insert(unordered_set<char>& st){

        st.insert('A');
        st.insert('E');
        st.insert('I');
        st.insert('O');
        st.insert('U');
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');

    }

    string sortVowels(string s) {

        int n = s.length();

        unordered_set<char> st;

        vector<int> vowel;

        insert(st);

        for(char ch : s){
            if(st.count(ch) > 0) vowel.push_back(ch);
        }

        sort(vowel.begin() , vowel.end());

        string ans(n , ' ');

        int k = 0;

        for(int i = 0 ; i < n ; i++){

            if(st.count(s[i]) > 0) ans[i] = vowel[k++];
            else ans[i] = s[i];

        }

        return ans;

    }
};

int main() {
    
    return 0;
}