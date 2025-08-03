class Solution {
public:
    int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws, vector<int>& wd) {
        int min1 = INT_MAX;
        int min2 = INT_MAX;
        int landWater = INT_MAX, waterLand = INT_MAX;

        for(int i = 0; i < ls.size(); i++) 
            min1 = min(min1, ls[i]+ld[i]);

        for(int i = 0; i < ws.size(); i++) 
            landWater = min(landWater, (max(ws[i], min1) + wd[i]));
        
        for(int i = 0; i < ws.size(); i++)
            min2 = min(min2, ws[i]+wd[i]);
        
        for(int i = 0; i < ls.size(); i++) 
            waterLand = min(waterLand, (max(min2, ls[i]) + ld[i]));
        
        return min(landWater, waterLand);
    }
};