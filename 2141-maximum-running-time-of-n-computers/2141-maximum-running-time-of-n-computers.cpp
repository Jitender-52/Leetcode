class Solution {
public:
    
    bool isFeasible(long long mid, int n, vector<int> v)
    {
        int m = v.size();
        vector<long long> batteries(m);
        
        for(int i = 0; i < m; i++)
        {
            batteries[i] = v[i];
            // cout << batteries[i] << " ";
        }
        
        sort(batteries.begin(), batteries.end());
        for(int j = n; j < m; j++)
        {
            batteries[j] = min(batteries[j], mid);
            // cout << batteries[j] << " ";
        }
        // cout << "HII" << endl;
        // for(int i = 0; i < m; i++)
        // {
        //     cout << batteries[i] << " ";
        // }
        // cout << endl;
        
        long long i = 0, j = m-1;
        while(i < n && j >= n)
        {
            // if(batteries[i] >= mid)
            //     break;
            bool check = true;
            while(i < n && j >= n && batteries[i] < mid)
            {
                check = false;
                // cout << i << " " << j << endl;
                long long a = mid - batteries[i];
                if(a <= batteries[j])
                {
                    batteries[i] = mid;
                    batteries[j] -= a;
                    i++;
                }
                else
                {
                    batteries[i] += batteries[j];
                    j--;
                }
            }
            if(check)
                i++;
        }
        // cout << "BYE" << endl;
        // cout << batteries[n-1] << " " << mid << endl;
        // for(int i = 0; i < m; i++)
        // {
        //     cout << batteries[i] << " ";
        // }
        // cout << endl;
        bool check = true;
        for(int i = 0; i < n; i++)
        {
            if(batteries[i] < mid)
                check = false;
        }
        return check;
    }
    
    long long maxRunTime(int n, vector<int>& batteries) {
        long long l = 0, r = 1e15;
        
        while(l <= r)
        {
            long long mid = (l + r) / 2;
            // cout << mid << endl;
            if(isFeasible(mid, n, batteries))
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return l - 1;
    }
};