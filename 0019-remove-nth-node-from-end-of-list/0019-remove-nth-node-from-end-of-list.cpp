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
    
    void solve(ListNode *head, int &n)
    {
        if(!head)
            return;
        solve(head->next, n);
        if(n == 0)
            head->next = head->next->next;
        n--;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        solve(head, n);
        if(n >= 0)
            return head->next;
        return head;
    }
};