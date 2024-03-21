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
    
    void solve(ListNode *head1, ListNode *&head2, int &count)
    {
        if(!head1)
            return;
        count++;
        solve(head1->next, head2, count);
        if(count > 0)
        {
            swap(head1->val, head2->val);
            count -= 2;
        }
        head2 = head2->next;
    }
    
    ListNode* reverseList(ListNode* head) {
        int count = 0;
        ListNode *temp = head;
        solve(temp, temp, count);
        return head;
    }
};