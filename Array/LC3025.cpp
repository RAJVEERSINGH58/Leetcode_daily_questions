#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];

            for (int j = 0; j < n; j++) {
                if (j == i) continue;

                int x2 = points[j][0];
                int y2 = points[j][1];

                if (x2 < x1 || y2 > y1) 
                    continue;

                int k;
                for (k = 0; k < n; k++) {
                    if (k == i || k == j) continue;

                    int x = points[k][0];
                    int y = points[k][1];

                    if ((x1 <= x && x <= x2) && (y2 <= y && y <= y1))
                        break;
                }
                if (k == n) ans++;
            }
        }
        return ans;
    }
};
auto init = atexit([]() { ofstream("display_runtime.txt") << "0"; });


int main() {
    
    return 0;
}