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
    
class comp{
public:
    bool operator()(ListNode *a, ListNode *b)
    {
        return a->val > b->val;
    }
};
    
//     bool comp(ListNode *a, ListNode *b)
//     {
//         return a->val < b->val;
//     }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        priority_queue<ListNode *, vector<ListNode *>, comp> pq; 
        // priority_queue<ListNode *, vector<ListNode *>, greater<ListNode *>> pq; 
        for(int i = 0; i < n; i++)
        {
            if(lists[i])
                pq.push(lists[i]);
        }
        
        ListNode *head = new ListNode(-1);
        ListNode *t = head;
      
//         Why this while loop is giving error while down one is working
        
//         while(!pq.empty())
//         {
//             ListNode *temp = pq.top();
//             pq.pop();
            
//             t->next = temp;
//             t = temp;
            
//             if(temp->next);
//                 pq.push(temp->next);
//             // temp = temp->next;
//         }

        
         while(!pq.empty())
            {
                ListNode *temp = pq.top();
                pq.pop();
                
                t->next = temp;
                t = temp;
                
                if(temp->next)
                    pq.push(temp->next);
            }
        
        return head->next;
    }
};