/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
//     Runtime: 8 ms, faster than 59.69% of C++ online submissions for Linked List Cycle.
// Memory Usage: 10.6 MB, less than 53.92% of C++ online submissions for Linked List Cycle.
    
    bool hasCycle(ListNode *head) {
        if(!head)
            return false;
        ListNode *slow = head, *fast = head->next;
        while(fast && fast->next)
        {
            if(fast == slow)
                return true;
            fast = fast->next->next;
            slow = slow->next;
        }
        return false;
    }
};