class KthLargest {
public:
    
    map<int,int> mp;
    int a;
    
    KthLargest(int k, vector<int>& nums) {
        for(auto &i : nums)
            mp[i]++;
        a = k;
    }
    
    int add(int val) {
        int count = 0;
        mp[val]++;
        // for(auto it = mp.rbegin(); it != mp.rend(); it++)
        // {
        //     for(int j = 0; j < it->second; j++)
        //         cout << it->first << " ";
        // }
        // cout << endl;
        
        for(auto it = mp.rbegin(); it != mp.rend(); it++)
        {
            count += it->second;
            if(count >= a)
                return it->first;
        }
        return 0;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */