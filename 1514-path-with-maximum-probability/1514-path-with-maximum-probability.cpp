class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<vector<double>>> adj(n);
        int count = 0;
        for(auto i : edges)
        {
            adj[i[0]].push_back({double(i[1]), succProb[count]});
            adj[i[1]].push_back({double(i[0]), succProb[count]});
            count++;
        }
        vector<double> prob(n, 0);
        priority_queue<pair<int, double>> pq;
        pq.push({start_node, 1.0});
        prob[start_node] = 1.0;
        
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int node = it.first;
            int p = it.second;
            for(auto i : adj[node])
            {
                int nnode = i[0];
                double pro = i[1];
                if(prob[node] * pro > prob[nnode])
                {
                    prob[nnode] = prob[node] * pro;
                    pq.push({nnode, prob[nnode]});
                }
            }
        }
        return prob[end_node];
    }
};