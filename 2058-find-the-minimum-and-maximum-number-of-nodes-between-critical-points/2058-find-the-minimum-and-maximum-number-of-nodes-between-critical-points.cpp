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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode *temp = head;
        int last = -1e9;
        int mini = 1e9, maxi = -1;
        if(!head->next->next)
            return {-1, -1};
        head = head->next;
        int ans1 = 1e9, count = 0;
        while(head && head->next)
        {
            if(head->val > temp->val && head->val > head->next->val)
            {
                mini = min(mini, count);
                maxi = max(maxi, count);
                ans1 = min(ans1, count - last);
                last = count;
            }
            if(head->val < temp->val && head->val < head->next->val)
            {
                mini = min(mini, count);
                maxi = max(maxi, count);
                ans1 = min(ans1, count - last);
                last = count;
            }
            head = head->next;
            temp = temp->next;
            count++;
        }
        if(ans1 >= 1e8)
            return {-1, -1};
        return {ans1, maxi - mini};
    }
};