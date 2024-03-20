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
    
//     Runtime: 176 ms, faster than 68.26% of C++ online submissions for Merge In Between Linked Lists.
// Memory Usage: 98.1 MB, less than 44.80% of C++ online submissions for Merge In Between Linked Lists.
    
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *temp = list1, *first, *second;
        int count = 0;
        while(temp)
        {
            if(count == a-1)
                first = temp;
            if(count == b+1)
                second = temp;
            temp = temp->next;
            count++;
        }
        first->next = list2;
        while(list2->next)
            list2 = list2->next;
        list2->next = second;
        return list1;
    }
};