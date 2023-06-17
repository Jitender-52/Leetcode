class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        int m = beginWord.length();
        
        map<string, vector<string>> adj;
        for(int i = 0; i < n; i++)
        {
            int a = 0;
            for(int k = 0; k < m; k++)
            {
                if(wordList[i][k] != beginWord[k])
                    a++;
            }
            if(a == 1)
                adj[beginWord].push_back(wordList[i]);
            
            for(int j = i+1; j < n; j++)
            {
                int count = 0;
                for(int k = 0; k < m; k++)
                {
                    if(wordList[i][k] != wordList[j][k])
                        count++;
                }
                if(count == 1)
                {
                    adj[wordList[i]].push_back(wordList[j]);
                    adj[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        
        map<string, int> dist;
        
        for(int i = 0; i < n; i++)
        {
            dist[wordList[i]] = 1e9;
        }
        
        queue<string> q;
        q.push(beginWord);
        dist[beginWord] = 1;
        
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            for(auto i : adj[node])
            {
                if(dist[i] > dist[node] + 1)
                {
                    dist[i] = dist[node] + 1;
                    q.push(i);
                }
            }
        }
        return dist[endWord] == 1e9 ? 0 : dist[endWord];
    }
};