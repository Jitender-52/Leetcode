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
    void reorderList(ListNode* head) {
        vector<int> v;
        ListNode *temp = head;
        while(temp)
        {
            v.push_back(temp->val);
            temp = temp->next;
        }
        int l = 0, r = v.size() - 1;
        temp = head;
        while(l <= r)
        {
            temp->val = v[l];
            temp = temp->next;
            l++;
            if(l > r)
                break;
            temp->val = v[r];
            temp = temp->next;
            r--;
        }
    }
};