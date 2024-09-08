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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode *> ans;
        ListNode *temp = head;
        int count = 0;
        while(temp)
        {
            count++;
            temp = temp->next;
        }
        // cout << "HII" << endl;

        int a = count / k;
        int b = count % k;
        temp = head;
        for(int i = 0; i < k; i++)
        {
            ListNode *p = new ListNode(-1);
            ListNode *t = p;
            for(int i = 0; i < a; i++)
            {
                if(!temp)
                    break;
                cout << temp->val << " ";
                t->next = new ListNode(temp->val);
                t = t->next;
                temp = temp->next;
            }
            if(b > 0)
            {
                // cout << "HII" << endl;
                t->next = new ListNode(temp->val);
                t = t->next;
                temp = temp->next;
                b--;
            }
            if(t)
                t->next = NULL;
            // cout << endl;
            // while(head)
            // {
            //     cout << head->val << " ";
            //     head = head->next;
            // }
            ans.push_back(p->next);
        }
        return ans;
    }
};
    
//     vector<ListNode*> splitListToParts(ListNode* head, int k) {
//         int count = 0;
//         ListNode *temp = head;
//         while(temp)
//         {
//             count++;
//             temp = temp->next;
//         }
//         int a = count / k;
//         int b = count % k;
        
//         vector<ListNode *> ans;
//         temp = head;
//         while(k--)
//         {
//             ListNode *p = temp;
//             ListNode *t = p;
//             if(temp)
//                 temp = temp->next;
//             for(int i = 0; i < a && temp; i++)
//             {
//                 t->next = temp;
//                 temp = temp->next;
//                 t = t->next;
//             }
//             t->next = NULL;
//             ans.push_back(p);
//             // if(b > 0)
//             // {
//             //     t->next = temp;
//             //     temp = temp->next;
//             // b--
//             // }
//             // t->next = NULL;
//             // int x = a + b;
//             // if(b > 0)
//             //     b--;
//             // ListNode *t = temp;
//             // temp = temp->next;
//             // ans.push_back(t);
//             // while(x > 0 && temp)
//             // {
//             //     t->next = temp;
//             //     temp = temp->next; 
//             //     t = t->next;
//             //     x--;
//             // }
//             // t->next = NULL;
//         }
//         return ans;
//     }
// };