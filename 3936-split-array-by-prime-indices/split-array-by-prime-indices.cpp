#define ll long long

class Solution {
public:
    void sieve(int n, vector<bool>& isprime) {
        isprime[0] = false;
        isprime[1] = false;
        for(int i = 2; i <= sqrt(n); i++) {
            if(isprime[i])
                for(int j = 2; i*j <= n; j++) isprime[i*j] = false;
        }
    }

    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        ll sumA = 0, sumB = 0;
        vector<bool> isprime(n+1, true);

        // calculate primes uptil n
        sieve(n, isprime);

        for(int i = 0; i < n; i++) {
            
            if(isprime[i])
                sumA += nums[i];
            else
                sumB += nums[i];
        }

        return abs(sumA - sumB);
    }
};