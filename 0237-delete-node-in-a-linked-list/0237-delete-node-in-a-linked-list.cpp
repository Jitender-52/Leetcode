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

     void deleteNode(ListNode* node) 
     {
        node->val = node->next->val;
        node->next = node->next->next;
     }
};
        
         
         
// Runtime: 32 ms, faster than 28.46% of C++ online submissions for Delete Node in a Linked List.
// Memory Usage: 7.6 MB, less than 37.95% of C++ online submissions for Delete Node in a Linked List.
    
    
    
    // void deleteNode(ListNode* node) {
        // ListNode *temp = node->next;
        // while(temp)
        // {
        //     node->val = temp->val;
        //     if(!temp->next)
        //         node->next = NULL;
        //     else
        //         node = temp;
        //     temp = temp->next;
        // }
        // node->next = NULL;
//     }
// };