class Solution {
public:
    int getSumOfDivisors(int num) {
        int cnt = 0;
        int sum = 0;

        for (int i = 1; i * i <= num; i++) {
            if (num % i == 0) {
                int d1 = i;
                int d2 = num / i;

                cnt++;
                sum += d1;

                if (d1 != d2) {
                    cnt++;
                    sum += d2;
                }

                if (cnt > 4) return 0;
            }
        }

        return (cnt == 4) ? sum : 0;
    }

    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for (int num : nums) {
            ans += getSumOfDivisors(num);
        }
        return ans;
    }
};

// n = 21, 4, 7