class Solution {
public:
    int WIDTH = 6;
    int n;
    int dp[301][27][27];

    int findDist(int ch1, int ch2) {
        if(ch1 == 26 || ch2 == 26) return 0; // Basically one hand is free

        int x1 = ch1 / WIDTH, y1 = ch1 % WIDTH;
        int x2 = ch2 / WIDTH, y2 = ch2 % WIDTH;

        return abs(x1-x2) + abs(y1-y2);
    }

    int solve(string &word, int idx, int f1, int f2) {
        if(idx >= n) return 0;

        if(dp[idx][f1][f2] != -1) return dp[idx][f1][f2];
        
        int ch = word[idx] - 'A';

        // option 1 -> go with f1
        int opt1 = solve(word, idx+1, ch, f2) + findDist(f1, ch);

        // option 2 -> go with f2
        int opt2 = solve(word, idx+1, f1, ch) + findDist(f2, ch);

        return dp[idx][f1][f2] = min(opt1, opt2);
    }

    int minimumDistance(string word) {
        n = word.size();
        memset(dp, -1, sizeof(dp));
        return solve(word, 0, 26, 26);
    }
};

// I --> 8
// width is 6
// x = (char - 'A) / width --> 8/6 = 1
// y = (char - 'A') % width --> 8%6 = 2