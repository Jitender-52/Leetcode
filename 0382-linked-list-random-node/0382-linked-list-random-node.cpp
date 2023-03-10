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
    
    
    vector<int> v;
    Solution(ListNode* head) {
        while(head)
        {
            v.push_back(head->val);
            head = head->next;
        }
    }
    
    int getRandom() {
        return   v[rand() % v.size()];
    }
};
    
    
    
    
//     ListNode *temp = NULL;
//     ListNode *head1;
//     Solution(ListNode* head) {
//         if(!temp)
//             temp = head;
//         head1 = head;
//     }
    
//     int getRandom() {
//         int ans = temp->val;
//         temp = temp->next;
//         if(!temp)
//             temp = head1;
//         return ans;
//     }
// };

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */