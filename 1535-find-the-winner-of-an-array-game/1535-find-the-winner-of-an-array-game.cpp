class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        if(k == 1)
            return max(arr[0], arr[1]);
        if(k >= n)
            return *max_element(arr.begin(), arr.end());
        queue<int> q;
        for(int i = 0; i < n; i++)
        {
            q.push(arr[i]);
        }
        
        int maxi = arr[0], count = 0;
        q.pop();
        while(1)
        {
            int a = q.front();
            q.pop();
            if(a > maxi)
            {
                q.push(maxi);
                maxi = a;
                count = 1;
            }
            else
            {
                q.push(a);
                count++;
            }
            if(count >= k)
                return maxi;
        }
        return arr[n-1];
    }
};