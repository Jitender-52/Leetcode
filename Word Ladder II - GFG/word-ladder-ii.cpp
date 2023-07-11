//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:

    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList){
        set<string> st(wordList.begin(), wordList.end());
        
        vector<vector<string>> ans;
        set<string> used;
        queue<vector<string>> q;
        q.push({beginWord});
        int level = 0;
        used.insert(beginWord);
        int sz = beginWord.size();
        
        while(!q.empty())
        {
            auto v = q.front();
            q.pop();
            
            if(v.size() > level)
            {
                level++;
                for(auto it : used)
                {
                    st.erase(it);
                }
            }
            auto word = v.back();
            
            // Storing the answer if we have reached the endWord
            if(word == endWord)
            {
                if(ans.size() == 0)
                    ans.push_back(v);
                else if(ans[0].size() == v.size()) // For checking the shortest path
                    ans.push_back(v);
                continue;
            }
            
            for(int i = 0; i < sz; i++)
            {
                char original = word[i];
                for(char c = 'a'; c <= 'z'; c++)
                {
                    word[i] = c;
                    if(st.count(word))
                    {
                        v.push_back(word);
                        q.push(v);
                        v.pop_back();
                        used.insert(word);
                    }
                }
                word[i] = original;
            }
        }
        // while(!q.empty()) // This will not work because the queue will be already empty
        // {
        //     ans.push_back(q.front());
        //     q.pop();
        // }
        return ans;
    }
};


//     map<string, int> mp;
//     vector<vector<string>> ans;
//     string b;
    
//     void dfs(string word, vector<string> &v)
//     {
//         // cout << word << endl;
//         if(mp[word] == 1)
//         // if(word == b)
//         {
//             reverse(v.begin(), v.end());
//             ans.push_back(v);
//             reverse(v.begin(), v.end());
//             return;
//         }
        
//         int sz = word.size();
//         int steps = mp[word];
//         for(int i = 0; i < sz; i++)
//         {
//             char original = word[i];
//             for(char c = 'a'; c <= 'z'; c++)
//             {
//                 word[i] = c;
//                 // cout << word << " " << mp[word] << endl;
//                 if(mp.find(word) != mp.end() && mp[word] + 1 == steps)
//                 {
//                     v.push_back(word);
//                     dfs(word, v);
//                     v.pop_back();
//                 }
//             }
//             word[i] = original;
//         }
//     }

//     vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
//         // code here
        
//         b = beginWord;
            
//         set<string> st;
//         for(auto i : wordList)
//             st.insert(i);
        
//         // for(auto i : st)
//         //     cout << i << " ";
        
//         queue<string> q;
//         q.push(beginWord);
//         mp[beginWord] = 1;
//         st.erase(beginWord);
//         int sz = beginWord.size();
//         while(!q.empty())
//         { 
//             string word = q.front();
//             q.pop();
//             int steps = mp[word];
//             if(word == endWord)
//                 break;
//             for(int i = 0; i < sz; i++)
//             {
//                 char original = word[i]; 
//                 for(char c = 'a'; c <= 'z'; c++)
//                 {
//                     word[i] = c;
//                     if(st.count(word))
//                     {
//                         // cout << word << endl;
//                         q.push(word);
//                         st.erase(word);
//                         mp[word] = steps + 1;
//                     }
//                 }
//                 word[i] = original;
//             }
//         }
        
//         if(mp.find(endWord) != mp.end())
//         {
//             vector<string> v;
//             v.push_back(endWord);
//             dfs(endWord, v);
//         }
//         return ans;
//     }
// };

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends