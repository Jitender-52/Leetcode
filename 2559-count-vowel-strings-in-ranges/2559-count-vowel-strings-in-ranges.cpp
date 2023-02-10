class Solution {
public:
    
//     bool isVowel(char a)
//     {
//         if(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
//             return true;
//         return false;
//     }
    
//     vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& q) {
//         int n = words.size();
        
//         vector<int> v;
//         int count = 0;
//         for(int i = 0; i < n; i++)
//         {
//             int m = words[i].length();
//             if(isVowel(words[i][0]) && isVowel(words[i][m-1]))
//            {
//                count++;
//            }
//            v.push_back(count);
//         }
               
//         vector<int> ans;
//         for(int i = 0; i < q.size(); i++)
//                {
//                    int a = q[i][0];
//                    int b = q[i][1];
                   
//                    int x = v[b] - v[a];
                   
//                     int m = words[a].length();
//                    if(isVowel(words[a][0]) && isVowel(words[a][m-1]))
//                    {
//                        x++;
//                    }
//                    ans.push_back(x);
//                }
//         return ans;
//     }
// };
    
    
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
       set<char>s;
        s.insert('a');
        s.insert('e');
        s.insert('i');
        s.insert('o');
        s.insert('u');
        vector<int>prefix(words.size());
        // for(auto it:queries){
        //     int x=it[0];
        //     int y=it[1];
            for(int i=0;i< words.size();i++){
                int n=words[i].size()-1;
                if(s.count(words[i][0])>0 && s.count(words[i][n])>0){
                    prefix[i]=1;
                }
                else{
                    prefix[i]=0;
                }
            }
        // }
        vector<int>answer;
        for(int i=1;i<prefix.size();i++){
            prefix[i]=prefix[i]+prefix[i-1];
        }
        
        for(auto it:queries){
            int p=it[0];
            int q=it[1];
            if(p==0){
               answer.push_back(prefix[q]); 
            }
            else{
                answer.push_back(prefix[q]-prefix[p-1]);
            }
        }
        return answer;
    }
};