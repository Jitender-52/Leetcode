class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& v, vector<int>& arr) {    
    int n = v.size();
    int prev;
    int start = -1;
    int end = -1;

    vector<vector<int>> ans;

    int i = 0;
    for (i; i < n; i++)
    {
        if (arr[0] > v[i][0] && arr[0] <= v[i][1])
        {
            start = v[i][0];
            break;
        }
        else if (v[i][0] >= arr[0])
        {
            start = arr[0];
            break;
        }
        vector<int> v1;
        v1.push_back(v[i][0]);
        v1.push_back(v[i][1]);

        ans.push_back(v1);
    }

    vector<int> v1;
    for (i; i < n; i++)
    {
        if (v[i][0] > arr[1])
        {
            end = arr[1];
            // cout << "HII" << endl;
            break;
        }
        else if (v[i][0] <= arr[1] && v[i][1] >= arr[1])
        {
            end = v[i][1];
            i++;
            break;
        }
        else if (v[i][0] == arr[1])
        {
            end = v[i][1];
            i++;
            break;
        }
    }
    // cout << "end = " << end << endl;
    if (start != -1)
    {
        v1.push_back(start);
    }
    if (end != -1)
    {
        v1.push_back(end);
        ans.push_back(v1);
    }

    // cout << "Start = " << start << endl;
    // return ans;

    for (i; i < n; i++)
    {
        vector<int> v2;
        v2.push_back(v[i][0]);
        v2.push_back(v[i][1]);

        ans.push_back(v2);
    }

    if (start == -1 && end == -1)
    {
        vector<int> v2;
        v2.push_back(arr[0]);
        v2.push_back(arr[1]);
        ans.push_back(v2);
    }
    else if (end == -1)
    {
        vector<int> v2;
        v2.push_back(start);
        v2.push_back(arr[1]);
        ans.push_back(v2);
    }
    return ans;
        
    }
};