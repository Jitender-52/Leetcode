class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        
        set<pair<int,int>> vis;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        
        pq.push({nums1[0] + nums2[0], {0, 0}});
        
        vector<vector<int>> ans;
        while(k-- && !pq.empty())
        {
            auto temp = pq.top();
            pq.pop();
            int i = temp.second.first;
            int j = temp.second.second;
            
            ans.push_back({nums1[i], nums2[j]});
            
            if(i + 1 < n && vis.find({i+1, j}) == vis.end())
            {
                pq.push({nums1[i+1] + nums2[j], {i+1, j}});
                vis.insert({i+1, j});
            }
            
            if(j + 1 < m && vis.find({i, j+1}) == vis.end())
            {
                pq.push({nums1[i] + nums2[j+1], {i, j+1}});
                vis.insert({i, j+1});
            }
        }   
        return ans;
    }
};