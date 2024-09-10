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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head->next)
            return head;
        ListNode *currPtr = head;
        ListNode *nextPtr = head->next;
        while(nextPtr)
        {
            int a = __gcd(currPtr->val, nextPtr->val);
            currPtr->next = new ListNode(a);
            currPtr->next->next = nextPtr;
            currPtr = nextPtr;
            nextPtr = nextPtr->next;
        }
        return head;
    }
};