class Solution {
public:
    
//     Runtime: 63 ms, faster than 87.26% of C++ online submissions for Find Building Where Alice and Bob Can Meet.
// Memory Usage: 262.5 MB, less than 67.52% of C++ online submissions for Find Building Where Alice and Bob Can Meet.

    int search(int height, vector<pair<int, int>>& monoStack)
    {
        int left = 0;
        int right = monoStack.size() - 1;
        int ans = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (monoStack[mid].first > height) {
                ans = max(ans, mid);
                left = mid + 1;
            } else
                right = mid - 1;
        }
        return ans;
    }
        
    vector<int> leftmostBuildingQueries(vector<int>& heights,
                                        vector<vector<int>>& queries) {
        vector<pair<int, int>> monoStack;
        vector<int> result(queries.size(), -1);
        vector<vector<pair<int, int>>> newQueries(heights.size());
        for (int i = 0; i < queries.size(); i++) {
            int a = queries[i][0];
            int b = queries[i][1];
            if (a > b) swap(a, b);
            if (heights[b] > heights[a] || a == b)
                result[i] = b;
            else
                newQueries[b].push_back({heights[a], i});
        }

        for (int i = heights.size() - 1; i >= 0; i--) {
            int monoStackSize = monoStack.size();
            for (auto& [a, b] : newQueries[i]) {
                int position = search(a, monoStack);
                if (position < monoStackSize && position >= 0)
                    result[b] = monoStack[position].second;
            }
            while (!monoStack.empty() && monoStack.back().first <= heights[i])
                monoStack.pop_back();
            monoStack.push_back({heights[i], i});
        }
        return result;
    }
};
    
    
// struct SegmentTreeNode {
//     int max_height;
//     int index;

//     SegmentTreeNode() : max_height(0), index(-1) {}
// };

// class SegmentTree {
// private:
//     vector<SegmentTreeNode> tree;
//     int n;

//     void build(const vector<int>& heights, int node, int start, int end) {
//         if (start == end) {
//             tree[node].max_height = heights[start];
//             tree[node].index = start;
//         } else {
//             int mid = (start + end) / 2;
//             build(heights, 2 * node + 1, start, mid);
//             build(heights, 2 * node + 2, mid + 1, end);

//             if (tree[2 * node + 1].max_height > tree[2 * node + 2].max_height) {
//                 tree[node] = tree[2 * node + 1];
//             } else {
//                 tree[node] = tree[2 * node + 2];
//             }
//         }
//     }

//     SegmentTreeNode query(int node, int start, int end, int left, int right) {
//         if (right < start || left > end) {
//             return SegmentTreeNode(); // Out of range
//         }
//         if (left <= start && right >= end) {
//             return tree[node];
//         }

//         int mid = (start + end) / 2;
//         SegmentTreeNode leftChild = query(2 * node + 1, start, mid, left, right);
//         SegmentTreeNode rightChild = query(2 * node + 2, mid + 1, end, left, right);

//         if (leftChild.max_height > rightChild.max_height) {
//             return leftChild;
//         } else {
//             return rightChild;
//         }
//     }

// public:
//     SegmentTree(const vector<int>& heights) {
//         n = heights.size();
//         int tree_size = 2 * n - 1;
//         tree.resize(tree_size);
//         build(heights, 0, 0, n - 1);
//     }

//     int queryMaxIndex(int left, int right) {
//         SegmentTreeNode result = query(0, 0, n - 1, left, right);
//         return result.index;
//     }
// };
    
    
// // vector<int> solveQueries(const vector<int>& heights, const vector<vector<int>>& queries) {
// //     int n = heights.size();
// //     vector<int> result;

// //     SegmentTree segmentTree(heights);

// //     for (const auto& query : queries) {
// //         int aliceBuilding = query[0];
// //         int bobBuilding = query[1];

// //         int maxRightIndex = segmentTree.queryMaxIndex(aliceBuilding, n - 1);

// //         if (maxRightIndex > bobBuilding) {
// //             result.push_back(maxRightIndex + 1);
// //         } else {
// //             result.push_back(0);
// //         }
// //     }

// //     return result;
// // }
    
// //     vector<int> solveQueries(const vector<int>& heights, const vector<vector<int>>& queries) {
// //     int n = heights.size();
// //     vector<int> result;

// //     // Create a vector to store the leftmost index to the left of each building
// //     vector<int> leftmostIndex(n, -1);

// //     // Initialize the leftmost index for the first building
// //     leftmostIndex[0] = 0;

// //     // Populate the leftmost index for each building
// //     for (int i = 1; i < n; ++i) {
// //         if (heights[i - 1] < heights[i]) {
// //             leftmostIndex[i] = i - 1;
// //         } else {
// //             leftmostIndex[i] = leftmostIndex[i - 1];
// //         }
// //     }

// //     // Process each query
// //     for (const auto& query : queries) {
// //         int aliceBuilding = query[0] - 1;  // Adjust indices to 0-based
// //         int bobBuilding = query[1] - 1;

// //         if (leftmostIndex[bobBuilding] <= aliceBuilding) {
// //             result.push_back(leftmostIndex[bobBuilding] + 1);  // Convert back to 1-based index
// //         } else {
// //             result.push_back(0);
// //         }
// //     }

// //     return result;
// // }
    
// //     vector<int> solveQueries(const vector<int>& heights, const vector<vector<int>>& queries) {
// //     int n = heights.size();
// //     vector<int> result;

// //     // Create a vector to store the rightmost index to the left of each building
// //     vector<int> rightmostIndex(n, -1);

// //     // Initialize the rightmost index for the first building
// //     rightmostIndex[0] = 0;

// //     // Populate the rightmost index for each building
// //     for (int i = 1; i < n; ++i) {
// //         if (heights[i - 1] < heights[i]) {
// //             rightmostIndex[i] = i - 1;
// //         } else {
// //             rightmostIndex[i] = rightmostIndex[i - 1];
// //         }
// //     }

// //     // Process each query
// //     for (const auto& query : queries) {
// //         int aliceBuilding = min(query[0], query[1]) - 1;  // Adjust indices to 0-based
// //         int bobBuilding = max(query[0], query[1]) - 1;

// //         if (rightmostIndex[bobBuilding] <= aliceBuilding) {
// //             result.push_back(rightmostIndex[bobBuilding] + 1);  // Convert back to 1-based index
// //         } else {
// //             result.push_back(0);
// //         }
// //     }

// //     return result;
// // }
    
// //     vector<int> solveQueries(const vector<int>& heights, const vector<vector<int>>& queries) {
// //     int n = heights.size();
// //     vector<int> result;

// //     // Create a vector to store the leftmost index to the right of each building
// //     vector<int> leftmostIndex(n, n);

// //     // Initialize the leftmost index for the last building
// //     leftmostIndex[n - 1] = n - 1;

// //     // Populate the leftmost index for each building
// //     for (int i = n - 2; i >= 0; --i) {
// //         if (heights[i] < heights[i + 1]) {
// //             leftmostIndex[i] = i + 1;
// //         } else {
// //             leftmostIndex[i] = leftmostIndex[i + 1];
// //         }
// //     }

// //     // Process each query
// //     for (const auto& query : queries) {
// //         int aliceBuilding = query[0] - 1;  // Adjust indices to 0-based
// //         int bobBuilding = query[1] - 1;

// //         if (leftmostIndex[bobBuilding] > aliceBuilding) {
// //             result.push_back(leftmostIndex[bobBuilding]);  // Convert back to 1-based index
// //         } else {
// //             result.push_back(-1);
// //         }
// //     }

// //     return result;
// // }
    
    
// // vector<int> solveQueries(vector<int> heights, vector<vector<int>> queries) {
// //     int n = heights.size();
// //     vector<int> result;

// //     // Create a vector to store the leftmost index to the right of each building
// //     vector<int> leftmostIndex(n, n);

// //     // Initialize the leftmost index for the last building
// //     leftmostIndex[n - 1] = n - 1;

// //     // Populate the leftmost index for each building
// //     for (int i = n - 2; i >= 0; --i) {
// //         if (heights[i] < heights[i + 1]) {
// //             leftmostIndex[i] = i + 1;
// //         } else {
// //             leftmostIndex[i] = leftmostIndex[i + 1];
// //         }
// //     }

// //     // Process each query
// //     for (const auto& query : queries) {
// //         int aliceBuilding = query[0] - 1;  // Adjust indices to 0-based
// //         int bobBuilding = query[1] - 1;

// //         if (bobBuilding < n && leftmostIndex[bobBuilding] < n &&
// //             leftmostIndex[bobBuilding] > aliceBuilding) {
// //             result.push_back(leftmostIndex[bobBuilding] + 1);  // Convert back to 1-based index
// //         } else {
// //             result.push_back(0);
// //         }
// //     }

// //     return result;
// // }
    
//     vector<int> solveQueries(const vector<int>& heights, const vector<vector<int>>& queries) {
//     int n = heights.size();
//     vector<int> result;

//     // Create a vector to store the leftmost index to the right of each building
//     vector<int> leftmostIndex(n, n);

//     // Initialize the leftmost index for the last building
//     leftmostIndex[n - 1] = n - 1;

//     // Populate the leftmost index for each building
//     for (int i = n - 2; i >= 0; --i) {
//         if (heights[i] < heights[i + 1]) {
//             leftmostIndex[i] = i + 1;
//         } else {
//             leftmostIndex[i] = leftmostIndex[i + 1];
//         }
//     }

//     // Process each query
//     for (const auto& query : queries) {
//         int aliceBuilding = query[0] - 1;  // Adjust indices to 0-based
//         int bobBuilding = query[1] - 1;

//         if (aliceBuilding >= 0 && bobBuilding >= 0 &&
//             bobBuilding < n && leftmostIndex[bobBuilding] < n &&
//             leftmostIndex[bobBuilding] > aliceBuilding) {
//             result.push_back(leftmostIndex[bobBuilding] + 1);  // Convert back to 1-based index
//         } else {
//             result.push_back(0);
//         }
//     }

//     return result;
// }
    
    
//     vector<int> findMeetings(const vector<int>& heights, const vector<vector<int>>& queries) {
//     int n = heights.size();
//     vector<int> ans;

//     // Create a set to store the buildings with their heights
//     set<pair<int, int>> buildingSet;

//     // Process each building and insert it into the set
//     for (int i = 0; i < n; ++i) {
//         buildingSet.insert({heights[i], i});
//     }

//     // Process each query
//     for (const auto& query : queries) {
//         int aliceBuilding = query[0] - 1;  // Adjust indices to 0-based
//         int bobBuilding = query[1] - 1;

//         // Find the first building taller than Alice's building
//         auto it = buildingSet.lower_bound({heights[aliceBuilding], aliceBuilding});

//         // Check if there is such a building and if it is to the left of Bob's building
//         if (it != buildingSet.end() && it->second < bobBuilding) {
//             ans.push_back(it->second + 1);  // Convert back to 1-based index
//         } else {
//             ans.push_back(-1);
//         }
//     }

//     return ans;
// }
    
//     struct SegmentTreeNode {
//     int index;
//     int height;

//     SegmentTreeNode() : index(-1), height(0) {}
// };

// class SegmentTree {
// public:
//     vector<SegmentTreeNode> tree;
//     int n;

//     void build(const vector<int>& heights, int node, int start, int end) {
//         if (start == end) {
//             tree[node].index = start;
//             tree[node].height = heights[start];
//         } else {
//             int mid = (start + end) / 2;
//             build(heights, 2 * node + 1, start, mid);
//             build(heights, 2 * node + 2, mid + 1, end);

//             if (tree[2 * node + 1].height < tree[2 * node + 2].height) {
//                 tree[node] = tree[2 * node + 1];
//             } else {
//                 tree[node] = tree[2 * node + 2];
//             }
//         }
//     }

//     SegmentTreeNode query(int node, int start, int end, int left, int right) {
//         if (right < start || left > end) {
//             return SegmentTreeNode(); // Out of range
//         }
//         if (left <= start && right >= end) {
//             return tree[node];
//         }

//         int mid = (start + end) / 2;
//         SegmentTreeNode leftChild = query(2 * node + 1, start, mid, left, right);
//         SegmentTreeNode rightChild = query(2 * node + 2, mid + 1, end, left, right);

//         if (leftChild.height < rightChild.height) {
//             return leftChild;
//         } else {
//             return rightChild;
//         }
//     }

// // public:
//     SegmentTree(const vector<int>& heights) {
//         n = heights.size();
//         int tree_size = 2 * n - 1;
//         tree.resize(tree_size);
//         build(heights, 0, 0, n - 1);
//     }

//     int queryLeftmostIndex(int left, int right) {
//         SegmentTreeNode result = query(0, 0, n - 1, left, right);
//         return result.index;
//     }
// };

// vector<int> findMeetings(const vector<int>& heights, const vector<vector<int>>& queries) {
//     int n = heights.size();
//     vector<int> ans;

//     SegmentTree segmentTree(heights);

//     // Process each query
//     for (const auto& query : queries) {
//         int aliceBuilding = query[0] - 1;  // Adjust indices to 0-based
//         int bobBuilding = query[1] - 1;

//         // Find the leftmost building that satisfies the condition
//         int meetBuilding = segmentTree.queryLeftmostIndex(aliceBuilding + 1, bobBuilding);

//         // Check if there is such a building
//         if (meetBuilding <= bobBuilding) {
//             ans.push_back(meetBuilding + 1);  // Convert back to 1-based index
//         } else {
//             ans.push_back(-1);
//         }
//     }

//     return ans;
// }

    
//     vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
//         // heights.push_back(1e9+2);
//         // reverse(heights.begin(), heights.end());
//         // vector<int> result = solveQueries(heights, queries);
//         int n = heights.size();
//         int tree_size = 2 * n - 1;
//         tree.resize(tree_size);
//         vector<int> result = findMeetings(heights, queries);
//         vector<int> ans(heights.size(), 0);
//         for(auto i : result)
//                 cout << i << " ";
//         cout << endl;
//         return ans;
//     }
// };