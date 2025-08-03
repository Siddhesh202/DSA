class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int m = landStartTime.size();
        int n = waterStartTime.size();
        int ans = INT_MAX;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                  
                // case 1 land then water
                int time = landStartTime[i] + landDuration[i];
                time = max(time, waterStartTime[j]) + waterDuration[j];

                ans = min(time, ans);

                // case 2 water then land
                time = waterStartTime[j] + waterDuration[j];
                time = max(time, landStartTime[i]) + landDuration[i]; 

                ans = min(time, ans);
            }
        }

        return ans;
    }
};