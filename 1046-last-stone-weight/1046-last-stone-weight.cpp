class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int,vector<int>> pq;
        for(auto i : stones)
        {
            pq.push(i);
        }
        while(pq.size() > 1)
        {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            int x = abs(a - b);
            if(a)
                pq.push(x);
        }
        return pq.top();
    }
};