class Solution {
public:
    int maxDistance(string str, int k) {
        int west=0, east=0, north=0, south=0, maxMD = 0;

        for(int i = 0; i < str.length(); i++) {
            char ch = str[i];
            if(ch == 'W') west++;
            else if(ch == 'E') east++;
            else if(ch == 'N') north++;
            else south++;

            int md = abs(east - west) + abs(north - south);
            int wasted = (i+1) - md; // steps - manhattan distance
            int extra = 0;
            if(wasted != 0) {
                extra = min(2*k, wasted);
            }
            
            maxMD = max(maxMD, (md + extra));
        }

        return maxMD;
    }
};