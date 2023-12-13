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
    
    ListNode* insertionSortList(ListNode* head) {
        ListNode *temp = head;
        while(temp)
        {
            ListNode *temp2 = head;
            while(temp2 != temp)
            {
                if(temp2->val >= temp->val)
                {
                    swap(temp2->val, temp->val);
                }
                temp2 = temp2->next;
            }
            
            temp = temp->next;
        }
        return head;
    }
};
    
    
//     Runtime: 33 ms, faster than 44.59% of C++ online submissions for Insertion Sort List.
// Memory Usage: 10 MB, less than 51.38% of C++ online submissions for Insertion Sort List.
    
//     ListNode* insertionSortList(ListNode* head) {
//         ListNode *ans = new ListNode(-5001);
//         ans->next = head;
//         ListNode *temp = head->next;
//         ListNode *prev = head;
//         while(temp != NULL)
//         {
//             ListNode *curr = ans;
//             ListNode *nxtptr;
//             while(curr && curr->next != temp)
//             {
//                 nxtptr = curr->next;
//                 if(nxtptr && temp->val >= curr->val && temp->val <= nxtptr->val)
//                 {
//                     prev->next = temp->next;
//                     curr->next = temp;
//                     temp->next = nxtptr;
//                     temp = prev;
//                     break;
//                 }
//                 curr = curr->next;
//             }
//             ListNode *check = ans;
//             // while(check)
//             // {
//             //     cout << check->val << " ";
//             //     check = check->next;
//             // }
//             // cout << endl;
//             prev = temp;
//             temp = temp->next;
//         }
//         return ans->next;
//     }
// };