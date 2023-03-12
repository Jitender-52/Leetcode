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
        
    // Also solve using merge sort
    
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            int n = lists.size();
            priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
            
            for(int i = 0; i < n; i++)
            {
                if(lists[i])
                    pq.push({lists[i]->val, lists[i]});
            }
            
            ListNode *head = new ListNode(-1);
            ListNode *temp = head;
            while(!pq.empty())
            {
                pair<int, ListNode*> p = pq.top();
                pq.pop();
                temp->next = p.second;
                temp = temp->next;
                if(p.second->next)
                    pq.push({p.second->next->val, p.second->next});
            }
            return head->next;
        }
};
            
    
    
    
    
//     Runtime: 24 ms, faster than 74.33% of C++ online submissions for Merge k Sorted Lists.
// Memory Usage: 13.3 MB, less than 74.06% of C++ online submissions for Merge k Sorted Lists.

    
// class comp{
// public:
//     bool operator()(ListNode *a, ListNode *b)
//     {
//         return a->val > b->val;
//     }
// };
    
// //     bool comp(ListNode *a, ListNode *b)
// //     {
// //         return a->val < b->val;
// //     }
    
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         int n = lists.size();
//         priority_queue<ListNode *, vector<ListNode *>, comp> pq; 
//         // priority_queue<ListNode *, vector<ListNode *>, greater<ListNode *>> pq; 
//         for(int i = 0; i < n; i++)
//         {
//             if(lists[i])
//                 pq.push(lists[i]);
//         }
        
//         ListNode *head = new ListNode(-1);
//         ListNode *t = head;
      
// //         Why this while loop is giving error while down one is working
        
//         while(!pq.empty())
//         {
//             ListNode *temp = pq.top();
//             pq.pop();
            
//             t->next = temp;
//             t = temp;
            
//             // if(temp->next); // Semi-colon mistake in if statement
//             if(temp->next)
//                 pq.push(temp->next);
//             // temp = temp->next;
//         }

        
// //          while(!pq.empty())
// //             {
// //                 ListNode *temp = pq.top();
// //                 pq.pop();
                
// //                 t->next = temp;
// //                 t = temp;
                
// //                 if(temp->next)
// //                     pq.push(temp->next);
// //             }
        
//         return head->next;
//     }
// };