class Solution {
public:
    
//     Runtime: 293 ms, faster than 55.86% of C++ online submissions for Divide Intervals Into Minimum Number of Groups.
// Memory Usage: 92.7 MB, less than 81.98% of C++ online submissions for Divide Intervals Into Minimum Number of Groups.
    
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        if(a[0] == b[0])
        {
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }
    
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), cmp);
        priority_queue<int, vector<int>, greater<int>> pq;
        
        // for(int i = 0; i < n; i++)
        // {
        //     for(int j = 0; j < 2; j++)
        //     {
        //         cout << intervals[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        
        int mini = intervals[0][1];
        pq.push(mini);
        // pq.push(-1);
        int count = 1;
        
        for(int i = 1; i < n; i++)
        {
            // if(i == 1)
            // {
            //     cout << pq.top() << " ";
            // }
            if(intervals[i][0] > pq.top())
            {
                pq.pop();
                pq.push(intervals[i][1]);
            }
            else
            {
                pq.push(intervals[i][1]);
                count++;
            }
        }
        return count;
    }
};