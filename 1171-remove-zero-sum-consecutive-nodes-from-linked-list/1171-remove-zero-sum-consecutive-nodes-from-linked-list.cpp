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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode *ans = new ListNode(0, head);
        ListNode *temp = ans;
        
        while(temp)
        {
            int sum = 0;
            ListNode *temp2 = temp->next;
            while(temp2)
            {
                sum += temp2->val;
                if(sum == 0)
                    temp->next = temp2->next;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        return ans->next;
    }
};