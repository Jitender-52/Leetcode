class LRUCache {
public:
    
    list<pair<int,int>> l;
        unordered_map<int,list<pair<int, int>>::iterator> m;
        int size;
        LRUCache(int capacity)
        {
            size=capacity;
        }
        int get(int key)
        {
            if(m.find(key)==m.end())
                return -1;
            l.splice(l.begin(),l,m[key]);
            return m[key]->second;
        }
        void put(int key, int value)
        {
            if(m.find(key)!=m.end())
            {
                l.splice(l.begin(),l,m[key]);
                m[key]->second=value;
                return;
            }
            if(l.size()==size)
            {
                auto d_key=l.back().first;
                l.pop_back();
                m.erase(d_key);
            }
            l.push_front({key,value});
            m[key]=l.begin();
        }
}; 
    
    
    
//     queue<pair<int,int>> q;
//     int size;
    
//     LRUCache(int capacity) {
//         size = capacity;
//     }
    
//     int get(int key) {
//         int sz = q.size();
//         int ans = -1;
//         for(int i = 0; i < sz; i++)
//         {
//             auto it = q.front();
//             q.pop();
//             if(it.first == key)
//                 ans = q.front().second;
//             q.push(it);
//         }
//         return ans;
//     }
    
//     void put(int key, int value) {
//         int sz = q.size();
//         for(int i = 0; i < sz; i++)
//         {
//             if(q.front().first != key)
//             {
//                 q.push(q.front());
//             }
//             q.pop();
//         }
//         if(q.size() == size)
//         {
//             q.pop();
//         }
//         q.push({key, value});
//     }
// };

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */