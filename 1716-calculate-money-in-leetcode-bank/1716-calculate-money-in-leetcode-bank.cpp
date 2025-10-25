class Solution {
public:
    int totalMoney(int n) {
        int noEntireWeeks = n / 7;
        int noRemDays = n % 7;
        int i = 1, ans = 0;

        while(i <= noEntireWeeks) {
            int t1 = i;
            int Sn = 7 * (t1 + 3);
            ans += Sn;
            i++;
        }

        ans += noRemDays * ((2 * i) + noRemDays - 1) / 2;

        return ans;
    }
};

// int n
// n/10 = no of entire week
// n%10 will give remaining days
// Sn = (t1+tn)*n/2
// Sn = (t1 + t1 + 6) * n / 2
// Sn = (t1 + 3) * n = 7 * (t1 + 3)

// Calc for rem Days - I will have t1
// Sn = noRemDays / 2 (2 * t1 + noRemDays - 1)