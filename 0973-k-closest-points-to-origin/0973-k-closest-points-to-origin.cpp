class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), [&](vector<int> &a, vector<int> &b){
            // cout << sqrtf(float(a[0] * a[0]) + float(a[1] * a[1])) << " " << sqrtf(float(b[0] * b[0]) + float(b[1] * b[1])) << endl;
                return sqrtf(float(a[0] * a[0]) + float(a[1] * a[1])) < sqrtf(float(b[0] * b[0]) + float(b[1] * b[1]));
        });
        
        vector<vector<int>> ans;
        for(int i = 0; i < k; i++)
        {
            ans.push_back(points[i]);
        }
        return ans;
    }
};