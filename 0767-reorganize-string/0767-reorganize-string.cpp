class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        map<char,int> mp;
        for(int i = 0; i < n; i++)
        {
            mp[s[i]]++;
        }
        
        priority_queue<pair<int,char>, vector<pair<int,char>>> pq;

        for(auto i : mp)
        {
            pq.push({i.second, i.first});
        }
        
        string ans = "";
        pair<int,char> last {-1, '.'};
        while(!pq.empty())
        {
            auto p = pq.top();
            pq.pop();
            int a = p.first;
            if(a > (n+1) / 2)
                return "";
            a--;
            ans += p.second;
            
            if(last.first != -1)
                pq.push(last);
            if(a > 0)
                last = {a, p.second};
            else
                last = {-1, p.second};
        }
        return ans;
    }
};