class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size(), ans = 0;
        queue<int> q;
        unordered_set<int> visited, foundBoxes;
        
        for(auto &box: initialBoxes) {
            if(status[box] == 1) {
                q.push(box);
                visited.insert(box);
                ans += candies[box];
            }
            foundBoxes.insert(box);
        }

        while(!q.empty()) {
            int currBox = q.front();
            q.pop();

            for(auto& adjBox: containedBoxes[currBox]) {
                foundBoxes.insert(adjBox);
                if(status[adjBox] == 1 && !visited.count(adjBox)) { // Box is open
                    visited.insert(adjBox);
                    q.push(adjBox);
                    ans += candies[adjBox];
                }
            }

            for(auto& key: keys[currBox]) {
                status[key] = 1; // can be opened in future or if it has been reached in the past
                if(foundBoxes.count(key) && !visited.count(key)) {
                    q.push(key);
                    visited.insert(key);
                    ans += candies[key];
                }
            }
        }

        return ans;
    }
};