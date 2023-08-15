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
    
    
    ListNode* partition(ListNode* ghead, int x) {
        
        ListNode *head = new ListNode(-300);
        head->next = ghead;
        
        ListNode *curr = head, *nextPtr = head->next;
        if(!head && !head->next)
            return head;
        while(curr->next && curr->next->val < x)
        {
            curr = curr->next;
            nextPtr = curr->next;
            // nextPtr = curr->next->next; my bad curr has already moved one step so need to move only one step ahead. This small mistake made to debug complete code taking whole day.;
        }
        // cout << curr << " " << nextPtr << endl;
        
        ListNode *p = curr;
        ListNode *c = curr->next;
        ListNode *n;

        while(c)
        {
            n = c->next;
            if(c->val < x)
            {
                curr->next = c;
                c->next = nextPtr;
                curr = c;
                // nextPtr = curr->next;
                p->next = n;
                c = n;
            }
            else
            {
                p = c;
                c = n;
            }
            ListNode *temp = head;
            // cout << nextPtr->val << endl;
            while(temp)
            {
                // cout << temp->val << " ";
                temp = temp->next;
            }
            // cout << endl;
        }
        // cout << endl;
        return head->next;   
    }
};
    
    
//     ListNode* partition(ListNode* head, int x) {
//         ListNode *head1 = head;
//         ListNode *ans = new ListNode(-1);
//         ListNode *head2 = ans;
//         head2->next = head;
        
//         while(head1)
//         {
            
//             if(head2->next && head2->next->val < x)
//             {
//                 head2 = head2->next;
//             }
//             if(head1->next && head1->next->val < x)
//             {
//                 ListNode *temp = head2->next;
//                 ListNode *temp2 = head1->next->next;
//                 head2->next = head1->next;
//                 head2 = head2->next;
//                 // head1->next = head1->next->next;
//                 head1->next = temp2;
//                 head2->next = temp;
//             }
//             head1 = head1->next;
//         }
//         return ans->next;
//     }
// };
// [1,4,3,0,2,5,2]
// 3
