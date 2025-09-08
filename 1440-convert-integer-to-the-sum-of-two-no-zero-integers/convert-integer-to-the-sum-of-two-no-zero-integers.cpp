class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> ans(2);

        for(int a = 1; a <= (n/2 + 1); a++) {
            int b = n - a;

            string x = to_string(a);
            string y = to_string(b);

            if(!x.contains('0') && !y.contains('0')) {
                ans[0] = a,
                ans[1] = b;
                break;
            }
        }

        return ans;
    }
};