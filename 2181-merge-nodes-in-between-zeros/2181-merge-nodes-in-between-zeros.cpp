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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *ans = new ListNode(0);
        ListNode *temp = ans;
        head = head->next;
        while(head)
        {
            int count = 0;
            while(head && head->val != 0)
            {
                count += head->val;
                head = head->next;
            }
            temp->next = new ListNode(count);
            temp = temp->next;
            head = head->next;
        }
        return ans->next;
    }
};