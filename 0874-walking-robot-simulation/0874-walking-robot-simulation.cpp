class Solution {
public:
    
//     Runtime: 61 ms, faster than 86.74% of C++ online submissions for Walking Robot Simulation.
// Memory Usage: 37.5 MB, less than 76.80% of C++ online submissions for Walking Robot Simulation.
    
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int i=0,j=0,res = 0,direction=1;
        set<pair<int,int>> st;
        for(const auto &it : obstacles){
            st.insert({it[0],it[1]});
        }

        for(const auto & command : commands){
            if(command == -1){
                direction = (direction+1) % 5;
                if(direction == 0) direction = 1;
            }else if(command == -2){
                direction = (direction-1);
                if(direction == 0) direction = 4;
            }else{
                int dist = command;
                while(dist > 0){
                    if(direction == 1){
                        if(st.find({i,j+1}) != st.end()) break;
                        j++;
                    }else if(direction == 2){
                        if(st.find({i+1,j}) != st.end()) break;
                        i++;
                    }else if(direction == 3){
                        if(st.find({i,j-1}) != st.end()) break;
                        j--;
                    }else{
                        if(st.find({i-1,j}) != st.end()) break;
                        i--;
                    }
                    res = max(res,i*i + j*j);
                    dist--;
                }
            }
        }
        return res;
    }
};