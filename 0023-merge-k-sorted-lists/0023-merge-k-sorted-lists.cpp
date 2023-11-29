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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode *>, vector<pair<int,ListNode *>>, greater<pair<int, ListNode *>>> pq;
        for(auto i : lists)
        {
            if(i)
                pq.push({i->val, i});
        }
        ListNode *ans = new ListNode(-1);
        ListNode *temp = ans;
        while(!pq.empty())
        {
            auto it = pq.top().second;
            pq.pop();
            temp->next = new ListNode(it->val);
            temp = temp->next;
            it = it->next;
            if(it)
                pq.push({it->val, it});
        }
        return ans->next;
    }
};