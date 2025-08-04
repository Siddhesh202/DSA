class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i = 0, j = 0, n = fruits.size(), maxi = INT_MIN;
        unordered_map<int,int> mp;

        while(j < n) {
            int fruit = fruits[j];
            mp[fruit]++;

            while(mp.size() > 2) {
                int prevFruit = fruits[i];
                mp[prevFruit]--;

                if(mp[prevFruit] == 0) mp.erase(prevFruit);
                i++;
            }

            maxi = max(maxi, j-i+1);
            j++;
        }

        return maxi;
    }
};