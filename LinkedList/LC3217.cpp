#include<bits/stdc++.h>
#include<vector>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        
        unordered_set<int> st(nums.begin() , nums.end());

        while(st.count(head->val) > 0) head = head->next;

        ListNode* temp = head;

        while(temp->next != NULL){

            int val = temp->next->val;

            if(st.count(val) ==  0){
                temp = temp->next;
            }
            else{

                temp->next = temp->next->next;

            }


        }

        return head;

    }
};

int main() {
    
    return 0;
}