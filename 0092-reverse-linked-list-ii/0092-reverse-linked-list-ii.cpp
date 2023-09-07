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
    
//     Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reverse Linked List II.
// Memory Usage: 7.5 MB, less than 46.43% of C++ online submissions for Reverse Linked List II.
    
    void reverse(ListNode *head, ListNode *&l, ListNode *r, int left, int &right)
    {
        if(!head)
            return;
        if(left > 0)
        {
            left--;
            l = head;
        }
        right--;
        r = head;
        reverse(head->next, l, r, left, right);
        // cout << left << " " << right << endl;
        if(l && r)
        {
            // cout << left << " " << right << endl;
            // cout << l->val << " " << r->val << endl;
        }
        if(l != r && l && r && right >= 0)
        {
            // cout << l->val << " " << r->val << endl;
            swap(l->val, r->val);
            l = l->next;
        }
        if(l == r)
        {
            l = NULL;
            r = NULL;
        }
        right++;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *l, *r;
        reverse(head, l, r, left, right);
        return head;
    }
};