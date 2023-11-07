class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<double> v;
        for(int i = 0; i < n; i++)
        {
            v.push_back(double(dist[i]) / speed[i]);
        }
        sort(v.begin(), v.end());
        
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(v[i] <= i)
                break;
            ans++;
        }
        return ans;
    }
};