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
    
//     Runtime: 254 ms, faster than 86.97% of C++ online submissions for Remove Nodes From Linked List.
// Memory Usage: 185.1 MB, less than 5.47% of C++ online submissions for Remove Nodes From Linked List.
     
    void insert(ListNode** root, int item)
    {
        ListNode *ptr, *temp;
        temp = new ListNode;
        temp->val = item;
        temp->next = NULL;

        if (*root == NULL)
            *root = temp;
        else {
            ptr = *root;
            while (ptr->next != NULL)
                ptr = ptr->next;

            ptr->next = temp;
        }
    }
    
    ListNode* removeNodes(ListNode* head) {
        vector<int> v;
        
        ListNode *temp = head;
        while(temp)
        {
            v.push_back(temp->val);
            temp= temp->next;
        }
        
        int maxi = 0;
        vector<int> v1;
        for(int i = v.size()-1; i >= 0; i--)
        {
            if(v[i] >= maxi)
            {
                v1.push_back(v[i]);
                maxi = v[i];
            }
        }
        
        reverse(v1.begin(), v1.end());
        
        ListNode *t = new ListNode(-1);
        ListNode *t1 = t;
        
        for(int i = 0; i < v1.size(); i++)
        {
                ListNode *help = new ListNode(v1[i]);
                t->next = help;
                t = t->next;
        }
        return t1->next;
    }
};