class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int total = accumulate(neededTime.begin(), neededTime.end(), 0);
        int sum = 0, n = colors.size();
        char currBalloon = colors[0];
        int maxiBalloon = neededTime[0];

        for(int i = 1; i < n; i++) {
            char ch = colors[i];
            int time = neededTime[i];

            if(ch == currBalloon) {
                maxiBalloon = max(maxiBalloon, time);
            }
            else {
                sum += maxiBalloon;
                currBalloon = ch;
                maxiBalloon = time;
            }
        } 

        sum += maxiBalloon;
        return total - sum;
    }
};