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
    
//     Runtime: 164 ms, faster than 59.93% of C++ online submissions for Spiral Matrix IV.
// Memory Usage: 130.5 MB, less than 65.45% of C++ online submissions for Spiral Matrix IV.

    
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> v(m, vector<int> (n, -1));
        int i = 0;
        int j = 0;
        ListNode *temp = head;
        int first = true;
        int second = false;
        int third = false;
        int fourth = false;
        int a = 0;
        int b = 0;
        while(temp != NULL)
        {
            // cout << temp->val << " ";
            v[i][j] = temp->val;
            temp = temp->next;
            
            if(first)
            {
                if(j == n-b-1)
                {
                    second = true;
                    first = false;
                }
                else
                {
                    j++;
                }
            }
            if(second)
            {
                if(i == m-a-1)
                {
                    third = true;
                    second = false;
                }
                else
                {
                   i++; 
                }
            }
            if(third)
            {
                if(j == b)
                {
                    fourth = true;
                    third = false;
                }
                else
                {
                    j--;
                }
            }
            if(fourth)
            {
                if(i == a + 1)
                {
                    a++;
                    b++;
                    i = a;
                    j = b;
                    first = true;
                    fourth = false;
                }
                else
                {
                    i--;
                }
            }
        }
        return v;
    }
};