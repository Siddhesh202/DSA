class Solution {
public:
    vector<vector<double>> dp;

    double f(int a, int b) {
        if(a <= 0 && b <= 0) return 0.5;

        if(a <= 0) return 1.0;

        if(b <= 0) return 0.0;

        if(dp[a][b] != -1) return dp[a][b];
        double opt1 = f(a-100, b);
        double opt2 = f(a-75, b-25);
        double opt3 = f(a-50, b-50);
        double opt4 = f(a-25, b-75);

        return dp[a][b] = 0.25 * (opt1 + opt2 + opt3 + opt4);
    }

    double soupServings(int n) {   
        if(n >= 4800) return 1;
        dp.assign(n+1, vector<double>(n+1, -1)); 
        return f(n, n);
    }
};