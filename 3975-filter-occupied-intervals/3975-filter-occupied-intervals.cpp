class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        sort(occupiedIntervals.begin(), occupiedIntervals.end());
        stack<vector<int>> st;
        vector<vector<int>> ans;

        for(auto &interval: occupiedIntervals) {
            if(!st.empty()) {
                // check for overlapping or touching condition
                auto a = st.top();
                auto b = interval;

                if(a[1] >= b[0] || b[0] == a[1]+1) {
                    st.pop();
                    st.push({a[0], max(a[1], b[1])});
                }
                else st.push(b);
            }
            else st.push(interval);
        }

        while(!st.empty()) {
            auto interval = st.top();
            st.pop();

            // No overlap
            if (interval[1] < freeStart || interval[0] > freeEnd) {
                ans.push_back(interval);
                continue;
            }
            
            // completely removed
            if (freeStart <= interval[0] && freeEnd >= interval[1]) continue;
            
            // left part
            if (interval[0] < freeStart) ans.push_back({interval[0], min(interval[1], freeStart - 1)});

            // right part
            if (interval[1] > freeEnd) ans.push_back({max(interval[0], freeEnd + 1), interval[1]});
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};

// overlapping a,b
// a.second >= b.first
// compress it to (a.first,max(a.second, b.second))

// 2-----8
//     7-----11


//     4-----8
//   1-----7

//   4---6
// 1--------8