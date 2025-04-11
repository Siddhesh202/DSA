class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;

        for(int num = low; num <= high; num++) {
            if(num >= 10 && num <= 99) {
                if(num % 11 == 0) ans++;
            }

            else if(num >= 1000 && num <= 9999) {
                int digit1 = num / 1000;
                int digit2 = (num / 100) % 10;
                int digit3 = (num / 10) % 10;
                int digit4 = num % 10;

                if(digit1 + digit2 == digit3 + digit4) ans++;
            }
        }

        return ans;
    }
};