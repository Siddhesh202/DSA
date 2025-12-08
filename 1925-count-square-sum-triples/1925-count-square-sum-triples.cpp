class Solution {
public:
    int countTriples(int n) {
        int cnt = 0;

        for(int a = 1; a < n-1; a++) {
            for(int b = a+1; b < n; b++) {

                double root = sqrt((a*a) + (b*b));
                if(ceil(root) == floor(root) && root <= n) cnt+=2;
            }
        }

        return cnt;
    }
};