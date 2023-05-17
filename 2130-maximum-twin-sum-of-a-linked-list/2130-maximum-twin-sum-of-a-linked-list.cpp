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
    
    int twin(ListNode *head1, ListNode *&head2)
    {
        if(!head1)
            return 0;
        int ans = twin(head1->next, head2);
        ans = max(ans, head1->val + head2->val);
        head2 = head2->next;
        return ans;
    }
    
    int pairSum(ListNode* head) {
        return twin(head, head);
    }
};