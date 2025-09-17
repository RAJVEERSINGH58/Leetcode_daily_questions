#include<bits/stdc++.h>
#include<vector>

using namespace std;

class FoodRatings {
    unordered_map<string , set<pair<int, string>> > cuisines_rating;
    unordered_map<string , int > food_rating;
    unordered_map<string , string > food_cuisines;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i = 0 ; i < n ; i++){
            food_rating[foods[i]] = ratings[i];
            cuisines_rating[cuisines[i]].insert({-ratings[i], foods[i]});
            food_cuisines[foods[i]] = cuisines[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        int rat = food_rating[food];
        
        string cuis = food_cuisines[food];

        cuisines_rating[cuis].erase({-rat, food});

        food_rating[food] = newRating;
        cuisines_rating[cuis].insert({-newRating, food});

    }
    
    string highestRated(string cuisine) {
        return cuisines_rating[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */

int main() {
    
    return 0;
}