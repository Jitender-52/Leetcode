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
    
    int pairSum(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *nextNode, *prev = NULL;
        while(slow)
        {
            nextNode = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextNode;
        }
        
        int ans = 0;
        ListNode *start = head;
        while(prev)
        {
            ans = max(ans, start->val + prev->val);
            start = start->next;
            prev = prev->next;
        }
        return ans;
    }
};
    
//     Runtime: 279 ms, faster than 34.99% of C++ online submissions for Maximum Twin Sum of a Linked List.
// Memory Usage: 121.3 MB, less than 52.01% of C++ online submissions for Maximum Twin Sum of a Linked List.
    
//     int twin(ListNode *head1, ListNode *&head2)
//     {
//         if(!head1)
//             return 0;
//         int ans = twin(head1->next, head2);
//         ans = max(ans, head1->val + head2->val);
//         head2 = head2->next;
//         return ans;
//     }
    
//     int pairSum(ListNode* head) {
//         return twin(head, head);
//     }
// };