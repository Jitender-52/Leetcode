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
    
    bool solve(ListNode *head1, ListNode *&head2)
    {
        if(!head1)
            return true;
        if(!solve(head1->next, head2))
            return false;
        if(head1->val != head2->val)
            return false;
        head2 = head2->next;
        return true;
    }
    
    bool isPalindrome(ListNode* head) {
        return solve(head, head);
    }
};