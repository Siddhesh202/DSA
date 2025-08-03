class Solution {
public:
    int earliestFinishTime(vector<int>& LS, vector<int>& LD, vector<int>& WS, vector<int>& WD) {
        int m = LS.size();
        int n = WS.size();
        int ans = INT_MAX;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                  
                // case 1 land then water
                int finishLandWater = max(LS[i]+LD[i], WS[j]) + WD[j];

                // case 2 water then land
                int finishWaterLand = max(WS[j]+WD[j], LS[i]) + LD[i];

                ans = min({ans, finishLandWater, finishWaterLand});
            }
        }

        return ans;
    }
};