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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    TreeNode *bst(ListNode *left, ListNode *right)
    {
        if(left == right)
            return NULL;
        
        ListNode *slow = left;
        ListNode *fast = left;
        while(fast != right && fast->next != right)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        TreeNode *root = new TreeNode(slow->val);
        root->left = bst(left, slow);
        root->right = bst(slow->next, right);
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        return bst(head, NULL);
    }
};
    
    
    
//     Runtime: 23 ms, faster than 89.37% of C++ online submissions for Convert Sorted List to Binary Search Tree.
// Memory Usage: 28.6 MB, less than 41.04% of C++ online submissions for Convert Sorted List to Binary Search Tree.
    
    
//     TreeNode *bst(vector<int> &v, int left, int right)
//     {
//         if(left > right)
//             return NULL;
//         int mid = (left + right) / 2;
//         TreeNode *root = new TreeNode(v[mid]);
//         root->left = bst(v, left, mid-1);
//         root->right = bst(v, mid+1, right);
//         return root;
//     }
    
//     TreeNode* sortedListToBST(ListNode* head) {
//         vector<int> v;
//         ListNode *temp = head;
//         while(temp)
//         {
//             v.push_back(temp->val);
//             temp = temp->next;
//         }
        
//         return bst(v, 0, v.size() - 1);
//     }
// };