#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:

    unordered_set<string> exactset;
    unordered_map<string , string> casemp;
    unordered_map<string , string> vowelmp;

    string toLower(string & s){

        string result = s;

        for(char & ch : result){
            ch = tolower(ch);
        }

        return result;

    }

    string toVowel(string & s){

        string result = s;

        for(char & ch : result){
            if(ch == 'a' || ch == 'i' || ch == 'e' || ch == 'o' || ch == 'u'){
                ch = '*';
            }
        }

        return result;

    }

    string checkForMatch(string &query){

        if(exactset.find(query) != exactset.end()){
            return query;
        }

        string lower = toLower(query);
        if(casemp.count(lower) > 0){
            return casemp[lower];
        }

        string vowel = toVowel(lower);

        if(vowelmp.count(vowel) > 0){
            return vowelmp[vowel];
        }

        return "";

    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {

        exactset.clear();
        casemp.clear();
        vowelmp.clear();

        for(string word : wordlist){

            exactset.insert(word);

            string lowerCase = toLower(word);

            if(casemp.find(lowerCase) == casemp.end()){
                casemp[lowerCase] = word;
            }

            string vowelCase = toVowel(lowerCase);

            if(vowelmp.find(vowelCase) == vowelmp.end()){
                vowelmp[vowelCase] = word;
            }

        }

        vector<string> result;

        for(string &query : queries){
            result.push_back(checkForMatch(query));
        }

        return result;

    }
};

int main() {
    
    return 0;
}