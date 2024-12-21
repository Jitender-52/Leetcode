class Solution
{
public:
    int ans;
    // vector<vector<int>> graph;
    vector<int> values;
    int k;
    int n;
    
    int components(vector<vector<int>> &graph, int src, int last)
    {
        long long a = values[src];
        for (auto &i : graph[src])
        {
            if (i != last)
            {
                int x = components(graph, i, src);

                ans += (!x);
                a += x;
            }
        }

        return a % k;
    }

    int maxKDivisibleComponents(int N, vector<vector<int>> &edges, vector<int> &v, int K)
    {
        //         int n = nums.size();

        //         long long count = 0;
        //         for(int i =0 ; i < n-1; i++)
        //         {
        //             count += values[i];
        //         }

        //         if(count % k != 0)
        //             return 0;
        
        values = v;
        k = K;
        n = N;
        
        // vector<vector<int>> arr(N);
        // graph = arr;

        vector<vector<int>> graph(N);
        for (auto &i : edges)
        {
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }

        // graph = arr;
        
        components(graph, 0, -1);
        return ans + 1;
    }
};