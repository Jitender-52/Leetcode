class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        
        vector<int> factoryPositions;
        for (auto& f : factory)
        {
            for (int i = 0; i < f[1]; i++) 
                factoryPositions.push_back(f[0]);
        }
        
        int robotCount = robot.size(), factoryCount = factoryPositions.size();
        vector<vector<long long>> memo(robotCount, vector<long long>(factoryCount, -1));
        return calculateMinDistance(0, 0, robot, factoryPositions, memo);
    }

    long long calculateMinDistance(int robotIdx, int factoryIdx, vector<int>& robot, vector<int>& factoryPositions, vector<vector<long long>>& memo) {

        if (robotIdx == robot.size()) 
            return 0;
        if (factoryIdx == factoryPositions.size()) 
            return 1e12;
        if (memo[robotIdx][factoryIdx] != -1) 
            return memo[robotIdx][factoryIdx];

        long long assign = abs(robot[robotIdx] - factoryPositions[factoryIdx]) + calculateMinDistance(robotIdx + 1, factoryIdx + 1, robot, factoryPositions, memo);
        long long skip = calculateMinDistance(robotIdx, factoryIdx + 1, robot, factoryPositions, memo);
        
        return memo[robotIdx][factoryIdx] = min(assign, skip);
    }
};


// long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
//         int n = robot.size();
//         int m = factory.size();
        
//         map<int,int> mp;
    
//         mp[INT_MIN] = 10;
//         mp[INT_MAX] = 10;
        
//         for(int i = 0; i < m; i++)
//         {
//             // factory[i] = abs([factory[i][1]);
//             mp[abs(factory[i][0])] += factory[i][1];      
//         }
        
//         long long ans = 0;
//         for(int i = 0; i < n; i++)
//         {
//             robot[i] = abs(robot[i]);
//             auto lb = mp.lower_bound(abs(robot[i]));
//             auto ub = mp.upper_bound(abs(robot[i]));
            
//             if(lb->first == INT_MIN || abs(ub->first - robot[i]) <= abs(robot[i] - lb->first))
//             {
//                 ans += abs(robot[i] - ub->first);
//                 mp[ub->first]--;
//                 if(mp[ub->first] == 0)
//                 {
//                     mp.erase(ub->first);
//                 }
//             }
//             else
//             {
//                ans += abs(robot[i] - lb->first);
//                 mp[lb->first]--;
//                 if(mp[lb->first] == 0)
//                 {
//                     mp.erase(lb->first);
//                 } 
//             }
            
//         }
        
//         return ans;
//     }
// };