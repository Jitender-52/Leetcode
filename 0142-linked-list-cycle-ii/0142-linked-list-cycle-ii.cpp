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
    ListNode *detectCycle(ListNode *head) {
        
        if(!head)
            return NULL;
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast != NULL && fast->next != NULL)
        {
            // cout << fast->val << " " << slow->val << endl;
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
            {
                break;
            }
        }
        
        if(fast == NULL || fast->next == NULL || fast->next->next == NULL)
            return NULL;
        
        // cout << fast->val << " " << slow->val << endl;
        
        fast = head;
        while(fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};