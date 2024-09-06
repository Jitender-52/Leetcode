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
    
//     Runtime: 556 ms, faster than 25.00% of C++ online submissions for Delete Nodes From Linked List Present in Array.
// Memory Usage: 261.1 MB, less than 75.00% of C++ online submissions for Delete Nodes From Linked List Present in Array.
    
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> st;
        for(auto i : nums)
            st.insert(i);
        ListNode *ans = new ListNode(-1);
        ListNode *temp = ans;
        while(head)
        {
            if(st.find(head->val) == st.end())
            {
                temp->next = head;
                temp = head;
            }
            head = head->next;
        }
        temp->next = head;
        return ans->next;
    }
};