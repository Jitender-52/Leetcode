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
    
    vector<vector<int>> levelOrder(TreeNode* root) {
         vector<vector<int>> ans;
    vector<int> v;
    queue<TreeNode *> q;

    if (root)
    {
        q.push(root);
    }

    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            TreeNode *temp = q.front();
            q.pop();
            v.push_back(temp->val);
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
        ans.push_back(v);
        v.clear();
    }
    return ans;
    }
    
    int insertionSort(vector<int> arr)
{
        int ans = 0;
        int n = arr.size();
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
            ans++;
        }
        arr[j + 1] = key;
    }
        return ans;
}
    
    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = a;
    }
    
    int selectionSort(vector<int> arr)
{
        int n = arr.size();
    int i, j, min_idx;
 
   int ans = 0;
    for (i = 0; i < n-1; i++)
    {
       
        
        min_idx = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[min_idx])
            min_idx = j;
 
     
        if(min_idx!=i)
        {
            ans++;
            swap(arr[min_idx], arr[i]);
        }
    }
        return ans;
}
    
    
    
    
    int minSwaps(vector<int> arr)
{
        int n = arr.size();
 
    pair<int, int> arrPos[n];
    for (int i = 0; i < n; i++)
    {
        arrPos[i].first = arr[i];
        arrPos[i].second = i;
    }
 
   
    sort(arrPos, arrPos + n);
 
    // Initialize
    vector<bool> vis(n, false);
 
    int ans = 0;
 
    for (int i = 0; i < n; i++)
    {
 
        if (vis[i] || arrPos[i].second == i)
            continue;
 
      
        int cycle_size = 0;
        int j = i;
        while (!vis[j])
        {
            vis[j] = 1;
 
            j = arrPos[j].second;
            cycle_size++;
        }
 
        if (cycle_size > 0)
        {
            ans += (cycle_size - 1);
        }
    }
 
    return ans;
}
    
    
    int minimumOperations(TreeNode* root) {
        
        vector<vector<int>> v = levelOrder(root);
        
        
        int ans = 0;
        
        for(int i = 0; i < v.size(); i++)
        {
//             for(int j = 0; j < v[i].size(); j++)
//             {
                
//             }
//             cout << endl;
            
            // ans += insertionSort(v[i]);
            // ans += selectionSort(v[i]);
            ans += minSwaps(v[i]);
        }
        
        return ans;
        
//         for(int i = 0; i < v.size(); i++)
//         {
//             for(int j = 0; j < v[i].size(); j++)
//             {
              
//             }
//             cout << endl;
//         }
        
        return 0;
        
        
//         queue<TreeNode *> q;
//         if(root)
//             q.push(root);
        
//         while(!q.empty())
//         {
//             // TreeNode *temp = root;
//             // q.pop();
//             int n = q.size();
            
//             for(int i = 0; i < n; i++)
//             {
//                 TreeNode *root;
//             }
//         }
        
        
    }
};