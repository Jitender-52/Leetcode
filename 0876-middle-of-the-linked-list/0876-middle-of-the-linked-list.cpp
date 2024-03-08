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
    
//     Runtime: 0 ms, faster than 100.00% of C++ online submissions for Middle of the Linked List.
// Memory Usage: 8.6 MB, less than 38.53% of C++ online submissions for Middle of the Linked List.
    
//     Runtime: 3 ms, faster than 41.27% of C++ online submissions for Middle of the Linked List.
// Memory Usage: 8.6 MB, less than 66.29% of C++ online submissions for Middle of the Linked List.
    
    ListNode* middleNode(ListNode* head) {
            ListNode *slow = head;
            ListNode *fast = head;
            while(fast != NULL && fast->next != NULL)
            {
                slow = slow->next;
                fast = fast->next->next;
            }
            return slow;
        }
};