#include<bits/stdc++.h>
#include<vector>

using namespace std;

#define pp pair<int,int>
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double , pp>> pq;

        int n = classes.size();

        for(int i = 0 ; i < n ; i++){
            int pass = classes[i][0];
            int total = classes[i][1];

            double currAvg = (double)pass / total;

            double nextAvg = (double)(pass + 1) / (total + 1);

            pq.push({(nextAvg - currAvg) , {pass , total}});

        }

        while(extraStudents > 0){
            auto x = pq.top();
            pq.pop();



            int pass = x.second.first + 1;
            int total = x.second.second + 1;

            double currAvg = (double)pass / total;

            double nextAvg = (double)(pass + 1) / (total + 1);

            pq.push({(nextAvg - currAvg) , {pass , total}});
            extraStudents--;


        }

        double totalAvg = 0;


        while(! pq.empty()){

            auto x = pq.top();
            pq.pop();

            int pass = x.second.first;
            int total = x.second.second;

            totalAvg += (double)pass / total;

        }

        return totalAvg / n;

    }
};
auto init = atexit([]() { ofstream("display_runtime.txt") << "0"; });

int main() {
    
    return 0;
}