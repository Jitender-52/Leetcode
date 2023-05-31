class UndergroundSystem {
public:
    
    
      unordered_map<string, pair<long long, int>> stationTimes;
    //customerId -> startStation
    unordered_map<int, pair<string,int>> inTransit;
    UndergroundSystem() {
        stationTimes.clear();
        inTransit.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        if(inTransit.find(id) != inTransit.end()) return;
        inTransit[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto& info = inTransit[id];
        string startStation = info.first;
        int startTime = info.second;
        string key = startStation + ":" + stationName;
        int time = t - startTime;
        
        if(stationTimes.find(key) != stationTimes.end()) {
            auto& oldTimes = stationTimes[key];
            oldTimes.first += time;
            oldTimes.second++;
        } else {
            stationTimes[key] = {time, 1};
        }
        inTransit.erase(id);
        
    }
    
    double getAverageTime(string startStation, string endStation) {
        string key = startStation + ":" + endStation;
        auto& info = stationTimes[key];
        double avg = (double)info.first / (double)info.second;
        return avg;
    }
};
    
    // why my solution is giving wrong answer
    
    // map<string, int> mp, mp2;
    // map<pair<int,string>, int> mp1, mp2;
    // map<string, pair<int,int>> mp1, mp2;
//     map<string, set<pair<int,int>>> mp1, mp2;

    
    
//     // map<string, vector<pair<int,int>>> mp1, mp2;
//     map<int,int> v;
    
//     UndergroundSystem() {
        
//     }
    
//     void checkIn(int id, string stationName, int t) {
//         if(v[id] == 1)
//             return;
//         mp1[stationName].insert({id, t});
//         v[id] = 1;
//         // mp1[stationName].push_back({id, t});
//     }
    
//     void checkOut(int id, string stationName, int t) {
//         if(v[id] == 0)
//             return;
//         mp2[stationName].insert({id, t});
//         v[id] = 0;
//         // mp2[stationName].push_back({id, t});
//     }
    
//     double getAverageTime(string startStation, string endStation) {
//         long long sum = 0;
//         int count = 0;
        
//         auto st = mp1[startStation];
//         auto st2 = mp2[endStation];
//         for(auto i : st)
//         {
//             for(auto j : st2)
//             {
//                 if(i.first == j.first && j.second >= i.second)
//                 {
//                     sum += abs(j.second - i.second);
//                     count++;
//                     break;
//                 }
//             }
//         }
//         return (double)(sum / (double)count);
//     }
// };

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */