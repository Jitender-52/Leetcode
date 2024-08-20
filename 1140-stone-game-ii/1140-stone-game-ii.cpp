class Solution {
public:
    
//     Runtime: 186 ms, faster than 5.38% of C++ online submissions for Stone Game II.
// Memory Usage: 88.7 MB, less than 5.29% of C++ online submissions for Stone Game II.
    
    int rec(vector<int> &piles, int idx, int M, int noOfPiles, int turn, vector<vector<vector<int> > > &dp){
        if(idx >= noOfPiles) return 0;
        if(dp[idx][M][turn] != -1){
            return dp[idx][M][turn];
        }
        int alexGotStones;
        if(turn){
            alexGotStones = INT_MAX;
            for(int i = 0; i < 2 * M; i++){
                if(!(idx + i < noOfPiles)) break;
                alexGotStones = min(alexGotStones, rec(piles, idx + i + 1, max(i + 1, M), noOfPiles, 0, dp));          
            } 
        }else{
            alexGotStones = 0;
            int tempSum = 0;
            for(int i = 0; i < 2 * M; i++){
                if(!(idx + i < noOfPiles)) break;
                tempSum += piles[idx + i];
                alexGotStones = max(alexGotStones, tempSum + rec(piles, idx + i + 1, max(i + 1, M), noOfPiles, 1, dp));          
            }
        }
        dp[idx][M][turn] = alexGotStones;
        return alexGotStones;
    }
    
    int stoneGameII(vector<int>& piles) {
        vector<vector<vector<int> > > dp(105, vector<vector<int> > (105, vector<int> (2, -1)));
        int noOfPiles = piles.size();
        return rec(piles, 0, 1, noOfPiles, 0, dp);
    }
};
    
    
    
//     int rec(int idx, int M, vector<int> &piles, int turn){
//         if(idx >= piles.size()) return 0;
        
//         if(turn){
//             int alexStones = INT_MAX;
//             for(int i = 0; i < 2 * M && idx + i < piles.size(); i++){
//                 alexStones = min(alexStones, rec(idx + i + 1, max(M, i + 1), piles, !turn));
//             }
//             return alexStones;
//         }else{
//             int alexStones = 0, temp = 0;
//             for(int i = 0; i < 2 * M && idx + i < piles.size(); i++){
//                 temp += piles[idx + i];
//                 alexStones = max(alexStones, temp + rec(idx + i + 1, max(M, i + 1), piles, !turn));
//             }
//             return alexStones;
//         }
//     }
    
//     int stoneGameII(vector<int>& piles) {
//         return rec(0, 1, piles, 0);        
//     }
// };