class Solution {
public:
    
    int poorPigs(int buckets, int poisonTime, int totalTime) {
        return ceil(log10(buckets) / log10(totalTime / poisonTime + 1));
    }
};

    
//         int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
//         return ceil((log(buckets)) / log(minutesToTest/minutesToDie + 1));
//     }
// };