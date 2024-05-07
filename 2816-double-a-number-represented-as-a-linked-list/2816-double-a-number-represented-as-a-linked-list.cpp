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
    
    void solve(ListNode *head, int &carry)
    {
        if(!head)
            return;
        solve(head->next, carry);
        int x = head->val * 2 + carry;
        head->val = x % 10;
        carry = x / 10;
    }
    
    ListNode* doubleIt(ListNode* head) {
        int carry = 0;
        solve(head, carry);
        if(carry)
        {
            ListNode *ans = new ListNode(1);
            ans->next = head;
            return ans;
        }
        return head;
    }
};