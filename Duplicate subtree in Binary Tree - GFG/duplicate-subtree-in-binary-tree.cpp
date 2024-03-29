//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	char data;
	struct Node *left;
	struct Node *right;

	Node(char x) {
		data = x;
		left = NULL;
		right = NULL;
	}
};

struct Node* buildTree(string str)
{
	// Corner Case
	if (str.length() == 0 || str[0] == 'N')
		return NULL;

	// Creating vector of strings from input
	// string after spliting by space
	vector<string> ip;

	istringstream iss(str);
	for (string str; iss >> str; )
		ip.push_back(str);

	// Create the root of the tree
	Node *root = new Node(stoi(ip[0]));

	// Push the root to the queue
	queue<Node*> queue;
	queue.push(root);

	// Starting from the second element
	int i = 1;
	while (!queue.empty() && i < ip.size()) {

		// Get and remove the front of the queue
		Node* currNode = queue.front();
		queue.pop();

		// Get the current node's value from the string
		string currVal = ip[i];

		// If the left child is not null
		if (currVal != "N") {

			// Create the left child for the current Node
			currNode->left = new Node(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->left);
		}

		// For the right child
		i++;
		if (i >= ip.size())
			break;
		currVal = ip[i];

		// If the right child is not null
		if (currVal != "N") {

			// Create the right child for the current node
			currNode->right = new Node(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->right);
		}
		i++;
	}

	return root;
}


// } Driver Code Ends
/*The structure of the Binary Tree Node  is
struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};*/

class Solution {
  public:
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/
    
    map<vector<int>, int> mp;
    
    void subtree(Node *root, vector<int> &v)
    {
        // if(root && !root->left && !root->right)
        // {
        //     v.push_back(root->data);
        //     if(v.size() > 1)
        //         mp[v]++;
        //     return;
        // }
        if(!root)
            return;
        v.push_back(root->data);
        subtree(root->left, v);
        subtree(root->right, v);
    }
    
    void dfs(Node *root)
    {
        if(!root)
            return;
        vector<int> v;
        subtree(root, v);
        if(v.size() > 1)
            mp[v]++;
        dfs(root->left);
        dfs(root->right);
    }
    
    int dupSub(Node *root) {
         // code here
         
        dfs(root);
        int ans = 0;
        for(auto i : mp)
        {
            if(i.second > 1)
                return 1;
            // for(auto j : i.first)
            // {
            //     cout << j << " ";
            // }
            // cout << "-> " << i.second;
            // cout << endl;
        }
        return 0;
    }
};
    
//     map<string, int> mp;
    
//     string solve(Node *root)
//     {
//         if(!root)
//             return "N";
//         if(!root->left && !root->right)
//             return to_string(root->data);
//         string s = to_string(root->data) + ',' + solve(root->left) + ',' + solve(root->right);
//         mp[s]++;
//         return s;
//     }
    
//     int dupSub(Node *root) {
//         solve(root);
//         int ans = 0;
//         for(auto i : mp)
//         {
//             if(i.second > 1)
//                 return 1;
//         }
//         return 0;
//     }
// };
    
    
//     map<vector<int>, int> mp;
    
//     void subtree(Node *root, vector<int> &v)
//     {
//         // if(root && !root->left && !root->right)
//         // {
//         //     v.push_back(root->data);
//         //     if(v.size() > 1)
//         //         mp[v]++;
//         //     return;
//         // }
//         if(!root)
//             return;
//         v.push_back(root->data);
//         subtree(root->left, v);
//         subtree(root->right, v);
//     }
    
//     void dfs(Node *root)
//     {
//         if(!root)
//             return;
//         vector<int> v;
//         subtree(root, v);
//         if(v.size() > 1)
//             mp[v]++;
//         dfs(root->left);
//         dfs(root->right);
//     }
    
//     int dupSub(Node *root) {
//          // code here
         
//         dfs(root);
//         int ans = 0;
//         for(auto i : mp)
//         {
//             if(i.second > 1)
//                 return 1;
//             // for(auto j : i.first)
//             // {
//             //     cout << j << " ";
//             // }
//             // cout << "-> " << i.second;
//             // cout << endl;
//         }
//         return 0;
//     }
// };

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin >> t;
	//cout << t << "\n";
	while (t--)
	{
		string treeString;
		getline(cin >> ws, treeString);
		struct Node* root = buildTree(treeString);
		Solution ob;
		cout << ob.dupSub(root) << "\n";
	}
	return 0;
}
// } Driver Code Ends