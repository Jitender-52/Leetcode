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
    
        ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {
            stack<int> st1, st2;
            while(head1)
            {
                st1.push(head1->val);
                head1 = head1->next;
            }
            while(head2)
            {
                st2.push(head2->val);
                head2 = head2->next;
            }
            
            int carry = 0;
            ListNode *head = new ListNode();
            while(!st1.empty() || !st2.empty())
            {
                int sum = carry;
                if(!st1.empty())
                {
                    sum += st1.top();
                    st1.pop();
                }
                if(!st2.empty())
                {
                    sum += st2.top();
                    st2.pop();
                }
                
                head->val = sum % 10;
                carry = sum / 10;
                ListNode *temp = new ListNode(carry);
                temp->next = head;
                head = temp;
            }
            
            if(carry == 0)
                head = head->next;
            return head;
        }
};
    
    
//     ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {
//         int n1 = 0, n2 = 0;
//         ListNode *temp = head1;
//         while(temp != NULL)
//         {
//             n1++;
//             temp = temp->next;
//         }
//         temp = head2;
//         while(temp)
//         {
//             n2++;
//             temp = temp->next;
//         }
        
//         int carry = 0;
//         if(n1 > n2)
//         {
//             add(head1, head2, carry);
//         }
//         else if(n1 < n2)
//         {
//             add(head2, head1, carry)l
//         }
//     }
// };
    
    
//     ListNode *null = NULL;
    
//     void add(ListNode *&head1, ListNode *&head2, int &carry, int n1, int n2)
//     {
//         if(!head1 && !head2)
//             return;
//         if(n1 == n2)
//         {
//             n1--, n2--;
//             add(head1->next, head2->next, carry, n1, n2);
//         }
//         else if(n1 > n2)
//         {
//             if(abs(n1 - n2) == 1)
//                 add(head1->next, head2, carry, n1-1, n2-1);
//             else
//                 add(head1->next, null, carry, n1-1, n2);
//         }
//         else
//         {
//             if(abs(n1 - n2) == 1)
//                 add(head1, head2->next, carry, n1-1, n2-1);
//             else
//                 add(null, head2->next, carry, n1, n2-1);
//         }
//         if(head1 && head2)
//         {
//             int sum = head1->val + head2->val + carry;
//             head1->val = sum % 10;
//             carry = sum / 10;
//         }
//         else if(head1)
//         {
//             int sum = head1->val + carry;
//             head1->val = sum % 10;
//             carry = sum / 10;
//         }
//         else
//         {
//             int sum = head2->val + carry;
//             head1->val = sum % 10;
//             carry = sum / 10;
//         }
//     }
    
//     ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {
//         ListNode *temp = head1;
//         int n1 = 0, n2 = 0, carry = 0;
//         while(temp)
//             temp = temp->next, n1++;
//         temp = head2;
//         while(temp)
//             temp = temp->next, n2++;
//         add(head1, head2, carry, n1, n2);
//         return head1;
//     }
// };