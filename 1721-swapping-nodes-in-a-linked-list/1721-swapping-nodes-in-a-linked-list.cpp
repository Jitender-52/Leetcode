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
    
//     Runtime: 705 ms, faster than 28.82% of C++ online submissions for Swapping Nodes in a Linked List.
// Memory Usage: 180.1 MB, less than 87.37% of C++ online submissions for Swapping Nodes in a Linked List.

    
    ListNode* swapNodes(ListNode* head, int k) {
        
        
         ListNode *first = head;
    ListNode *second = head;

    ListNode *temp = head;
    int start = 0;
    int end = 0;
    int count = 0;
    while (temp != NULL)
    {
        if (count <= k - 2)
        {
            first = first->next;
        }
        else if (count >= k)
        {
            second = second->next;
        }
        count++;
        temp = temp->next;
    }

    int a = first->val;
    first->val = second->val;
    second->val = a;
        return head;
    }
};