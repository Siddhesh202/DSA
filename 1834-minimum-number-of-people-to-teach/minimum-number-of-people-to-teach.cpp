class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> sadUsers;

        for(auto &friends : friendships) {
            int u = friends[0] - 1; // for 0 based indexing
            int v = friends[1] - 1;
            bool areGood = false;

            unordered_set<int> langSet;

            for(auto &val : languages[u]) langSet.insert(val);

            for(int &val : languages[v]) {
                if(langSet.find(val) != langSet.end()) {
                    areGood = true;
                    break;
                }
            }

            if(!areGood) {
                sadUsers.insert(u);
                sadUsers.insert(v);
            }
        }

        // Find max among sad users
        map<int,int> mp; // lang -> freq
        int maxi = 0;

        for(auto &sadUser : sadUsers) {
            
            for(auto &val : languages[sadUser]) {
                mp[val]++;
                maxi = max(maxi, mp[val]);
            }
        }

        return sadUsers.size() - maxi < 0 ? 0 : sadUsers.size() - maxi;
    }
};