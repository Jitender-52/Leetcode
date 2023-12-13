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
        ListNode *ans = new ListNode(-5001);
        ans->next = head;
        ListNode *temp = head->next;
        ListNode *prev = head;
        while(temp != NULL)
        {
            ListNode *curr = ans;
            ListNode *nxtptr;
            while(curr && curr->next != temp)
            {
                nxtptr = curr->next;
                if(nxtptr && temp->val >= curr->val && temp->val <= nxtptr->val)
                {
                    prev->next = temp->next;
                    curr->next = temp;
                    temp->next = nxtptr;
                    temp = prev;
                    break;
                }
                curr = curr->next;
            }
            ListNode *check = ans;
            // while(check)
            // {
            //     cout << check->val << " ";
            //     check = check->next;
            // }
            // cout << endl;
            prev = temp;
            temp = temp->next;
        }
        return ans->next;
    }
};