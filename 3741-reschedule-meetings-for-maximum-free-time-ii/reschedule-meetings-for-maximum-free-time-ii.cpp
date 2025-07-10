class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        vector<int> freeArr;
        int n;
        freeArr.push_back(startTime[0]);
        for(int i = 1; i < startTime.size(); i++) freeArr.push_back(startTime[i] - endTime[i-1]);
        freeArr.push_back(eventTime - endTime[endTime.size()-1]);
        n = freeArr.size();

        // precompute maxToRight and maxToLeft
        vector<int> maxToRight(n), maxToLeft(n);
        maxToRight[n-1] = 0; maxToRight[0] = 0;

        for(int i = n-2; i >= 0; i--) maxToRight[i] = max(maxToRight[i+1], freeArr[i+1]);
        for(int i = 1; i < n; i++) maxToLeft[i] = max(maxToLeft[i-1], freeArr[i-1]);

        int maxi = *max_element(freeArr.begin(), freeArr.end());

        // iterate over freeArr
        for(int i = 1; i < n; i++) {
            int dur = endTime[i-1] - startTime[i-1];
            int currMaxDur = 0;

            // Case1 - Place that event somewhere else ----> f[i-1] + f[i] + dur;
            if(maxToLeft[i-1] >= dur || maxToRight[i] >= dur) 
                currMaxDur = max(currMaxDur, freeArr[i-1] + freeArr[i] + dur);
            

            // Case 2 - Place it adjacently ---> f[i-1] + f[i]
            currMaxDur = max(currMaxDur, freeArr[i-1] + freeArr[i]);

            maxi = max(maxi, currMaxDur);
        }

        return maxi;
    }
};