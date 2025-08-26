#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        
        int n = dimensions.size();

        double max_Length_Diagonal = -1;
        int maxArea = 0;

        for(int i = 0 ; i < n ; i++){

            int length = dimensions[i][0];
            int width = dimensions[i][1];

            double x = sqrt(length * length + width * width);

            if(x > max_Length_Diagonal){
                max_Length_Diagonal = sqrt(length * length + width * width);
                maxArea = length * width;
            }
            else if(x == max_Length_Diagonal){
                maxArea = max(maxArea , length * width);
            }


        }

        return maxArea;


    }
};

int main() {
    
    return 0;
}