class Solution {
public: 
    vector<bool> sieve(int n) {
        // creation of boolean array
        vector<bool> prime(n + 1, true);
        prime[0] = prime[1] = false;
        for (int p = 2; p * p <= n; p++) {
            if (prime[p] == true) {
                
                // marking as false
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }
        
        return prime;
    }

    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        vector<bool> primes = sieve(33);

        for(int i = left; i <= right; i++) {
            cout << i << " : " << __builtin_popcount(i) << endl;
            if(primes[__builtin_popcount(i)]) ans++;
        }

        return ans;
    }
};