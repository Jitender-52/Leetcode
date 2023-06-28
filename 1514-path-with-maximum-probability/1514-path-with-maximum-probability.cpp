class Solution {
public:
    
    // Try again Just copy paste
    
//     Runtime: 204 ms, faster than 82.18% of C++ online submissions for Path with Maximum Probability.
// Memory Usage: 64.9 MB, less than 86.47% of C++ online submissions for Path with Maximum Probability.
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<double> prob(n, 0);
        vector<pair<int, double>> adj[n];
        int m = edges.size();
        for(int i = 0; i < m; i++) {
            adj[edges[i][0]].push_back({ edges[i][1], succProb[i] });
            adj[edges[i][1]].push_back({ edges[i][0], succProb[i] });
        }
        
        priority_queue<pair<double, int>> q;
        q.push({ 1.0, start });
        prob[start] = 1;
        while(!q.empty()) {
            int node = q.top().second;
            double suc = q.top().first;
            
            q.pop();
            for(auto &it:adj[node]) {
                if((suc * it.second) > prob[it.first]) {
                    prob[it.first] = suc * it.second;
                    q.push({ prob[it.first], it.first });
                }
            }
        }
        return prob[end];
    }
};