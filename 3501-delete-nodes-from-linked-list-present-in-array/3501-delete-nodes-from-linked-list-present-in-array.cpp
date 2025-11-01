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
         ListNode* dummy= new  ListNode(-1);
          ListNode*ans=dummy;
         unordered_set<int>s;
         for(auto it:nums) s.insert(it);
          ListNode*temp=head;
         while(temp){
            if(s.find(temp->val)==s.end()){
                dummy->next=temp;
                dummy=dummy->next;
            }
            temp=temp->next;
         }
         dummy->next=nullptr;
         return ans->next;

    }
};