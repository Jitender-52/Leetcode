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
    
//     Runtime: 27 ms, faster than 97.17% of C++ online submissions for Insert Greatest Common Divisors in Linked List.
// Memory Usage: 35.5 MB, less than 82.75% of C++ online submissions for Insert Greatest Common Divisors in Linked List.
    
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