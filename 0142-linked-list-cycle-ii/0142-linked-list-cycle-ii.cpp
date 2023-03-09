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
            set<ListNode *> st;
            while(head != NULL)
            {
                if(st.find(head) != st.end())
                    return head;
                st.insert(head);
                head = head->next;
            }
           return NULL;
       }
};
    
    
    
//     Runtime: 5 ms, faster than 90.93% of C++ online submissions for Linked List Cycle II.
// Memory Usage: 7.5 MB, less than 84.91% of C++ online submissions for Linked List Cycle II.
    
//        ListNode *detectCycle(ListNode *head) {
//         if(!head)
//             return NULL;
//         ListNode *slow = head;
//         ListNode *fast = head;
        
//         while(fast != NULL && fast->next != NULL)
//         {
//             fast = fast->next->next;
//             slow = slow->next;
//             if(fast == slow)
//             {
//                 fast = head;
//                 while(fast != slow)
//                 {
//                     slow = slow->next;
//                     fast = fast->next;
//                 }
//                 return slow;
//             }
//         }
//         return NULL;
//     }
// };
    
    
    
    
//     Runtime: 8 ms, faster than 76.50% of C++ online submissions for Linked List Cycle II.
// Memory Usage: 7.7 MB, less than 68.59% of C++ online submissions for Linked List Cycle II.
    
//     ListNode *detectCycle(ListNode *head) {
        
//         if(!head)
//             return NULL;
        
//         ListNode *slow = head;
//         ListNode *fast = head;
        
//         while(fast != NULL && fast->next != NULL)
//         {
//             // cout << fast->val << " " << slow->val << endl;
//             fast = fast->next->next;
//             slow = slow->next;
//             if(fast == slow)
//             {
//                 break;
//             }
//         }
        
//         if(fast == NULL || fast->next == NULL || fast->next->next == NULL)
//             return NULL;
        
//         // cout << fast->val << " " << slow->val << endl;
        
//         fast = head;
//         while(fast != slow)
//         {
//             fast = fast->next;
//             slow = slow->next;
//         }
//         return slow;
//     }
// };