class Solution {
public:
    
    bool check(vector<int> &v, int j, int k)
    {
        int count = 0;
        for(int i = 0; i < 26; i++)
        {
            if(v[i] == 0)
                continue;
            if(v[i] != k)
                return false;
            if(v[i] == k)
                count++;
        }
        return count == j;
    }
    
    int solve(string &s, int k)
    {
        int n = s.length();        
        int count = 0;
        for(int j = 1; j <= 26; j++)
        {
            int len = j * k;
            vector<int> v(26, 0);
            if(len > n)
                break;
            for(int i = 0; i < len; i++)
            {
                v[s[i] - 'a']++;
            }
            
            for(int i = len; i < n; i++)
            {
                if(check(v, j, k))
                    count++;
                v[s[i] - 'a']++;
                v[s[i-len] - 'a']--;
            }
            if(check(v, j, k))
                count++;
        }
        return count;
    }
    
    int countCompleteSubstrings(string word, int k) {
        int n = word.length();
        string s = "";
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            s += word[i];
            if(i < n-1 && abs(word[i] - word[i+1]) > 2)
            {
                ans += solve(s, k);
                s = "";
            }
        }
        ans += solve(s, k);
        return ans;
    }
};
    
    
//     int countCompleteSubstrings(string word, int k) {
//         int n = word.size();
//         int i = 1, j = 0, ans = 0;
//         map<char, int> mp;
//         mp[word[0]]++;
//         bool check = true;
//         vector<pair<int,int>> v;
        
//         if(k == 1)
//         {
//             for(int i = 0; i < n; i++)
//             {
//                 mp.clear();
//                 for(int j = i; j < n; j++)
//                 {
//                     mp[word[j]]++;
//                     check = true;
//                     for(auto i : mp)
//                     {
//                         if(i.second > 1)
//                         {
//                             check = false;
//                             break;
//                         }
//                     }
//                     if(check)
//                         ans++;
//                     else
//                         break;
//                 }
//             }
//             return ans;
//         }
        
        
// //         if(k == 1)
// //         {
// //             int count = 1;
// //             for(int i = 1; i < n; i++)
// //             {
// //                 if(abs(word[i] - word[i-1]) <= 2)
// //                 {
// //                     count++;
// //                 }
// //                 else
// //                 {
// //                     ans += (count * (count + 1)) / 2;
// //                     count = 1;
// //                 }
// //             }
// //             // cout << count << endl;
// //             ans += (count * (count + 1)) / 2;
// //             return ans;
// //         }
        
// //         if(n == 1)
// //         {
// //             if(k == 1)
// //                 return 1;
// //             return 0;
// //         }
        
//         while(j < n)
//         {
//             while(j < n && j <= i)
//             { 
//                 bool check1 = true, check2 = true;
//                 for(auto i : mp)
//                 {
//                     if(i.second > 0)
//                     {
//                         if(i.second > k)
//                             check2 = false;
//                         if(i.second < k)
//                             check1 = false;
//                     }
//                 }
//                 if(!check2)
//                 {
//                     mp[word[j]]--;
//                     j++;
//                 }
//                 else if(!check1)
//                 {
//                     if(i < n)
//                     {
//                         if(abs(word[i] - word[i-1]) > 2)
//                         {
//                             j = i;
//                             mp.clear();
//                         }
//                         mp[word[i]]++;
//                         i++;
//                     }
//                     else
//                     {
//                         mp[word[j]]--;
//                         j++;
//                         // check = false;
//                         // break;
//                     }
//                 }
//                 else
//                 {
//                     v.push_back({j, i});
//                     // cout << j << " " << i << endl;
//                     // ans++;
//                     break;
//                 }
//             }
//             if(!check)
//                 break;
//             if(j == n)
//                 break;
//             if(i == n)
//             {
//                 mp[word[j]]--;
//                 j++;
//                 continue;
//             }
//             if(abs(word[i] - word[i-1]) > 2)
//             {
//                 j = i;
//                 mp.clear();
//             }
//             mp[word[i]]++;
//             i++;
//         }
        
// //         bool check1 = true, check2 = true;
// //         for(auto i : mp)
// //         {
// //             if(i.second > 0)
// //             {
// //                 if(i.second > k)
// //                     check2 = false;
// //                 if(i.second < k)
// //                     check1 = false;
// //             }
// //         }
        
        
//         i = 0;
//         while(i < v.size())
//         {
//             int a = v[i].first;
//             int count = 0;
//             while(i < v.size() && v[i].first == a)
//             {
//                 count++;
//                 i++;
//             }
//             // cout << a << "  -> " << count << endl;
//             ans += (count * (count + 1)) / 2;
//         }
        
//         // if(k == 1)
//         //     ans += n;
        
//         // cout << i << " " << j << endl;
//         // cout << endl;
//         return ans;
//     }
// };