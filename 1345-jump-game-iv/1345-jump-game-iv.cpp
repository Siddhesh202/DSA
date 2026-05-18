class Solution {
public:
    int minJumps(vector<int>& arr) {
        int steps = 0, n = arr.size();
        queue<int> q;
        vector<bool> visited(n, 0);
        q.push(0);
        visited[0] = true;

        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++) mp[arr[i]].push_back(i);

        while(!q.empty()) {

            int size = q.size();

            while(size--) {
                int curridx = q.front();
                q.pop();

                if(curridx == n-1) return steps;

                // go right
                if(curridx+1 < n && !visited[curridx+1]) {
                    q.push(curridx+1);
                    visited[curridx+1] = true;
                } 

                // go left
                if(curridx-1 >= 0 && !visited[curridx-1]) {
                    q.push(curridx-1);
                    visited[curridx-1] = true;
                }

                // iterated through map
                for(auto &idx : mp[arr[curridx]]) {
                    if(idx != curridx && !visited[idx]) {
                        q.push(idx);
                        visited[idx] = true;
                    }
                }

                mp[arr[curridx]].clear();
                
            }

            steps++;
        }

        return steps;
    }
};