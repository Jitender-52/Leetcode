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

    
//     Runtime: 0 ms, faster than 100.00% of C++ online submissions for Swap Nodes in Pairs.
// Memory Usage: 7.6 MB, less than 50.79% of C++ online submissions for Swap Nodes in Pairs.
    
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode *newHead = head->next;
        ListNode *nextptr = head->next->next;
        newHead->next = head;
        head->next = swapPairs(nextptr); 
        return newHead;
    }
};