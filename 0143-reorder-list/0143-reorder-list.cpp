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
    
//     Runtime: 22 ms, faster than 86.75% of C++ online submissions for Reorder List.
// Memory Usage: 18.7 MB, less than 29.66% of C++ online submissions for Reorder List.
    
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