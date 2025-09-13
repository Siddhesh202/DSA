class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        unordered_map<int,int> mp;
        double sum = 0.0, avg = 0.0;
        int sn = 0;

        for(auto &num : nums) { 
            sum += num;
            mp[num]++;
        }

        avg = sum / nums.size();
        sn = floor(avg);

        // cout << sn << endl;

        for(int i = max(sn+1, 1); i <= 101; i++) {
            if(!mp.count(i)) return i;
        }

        return 0;
    }
};