#define ll long long
#define P pair<int,int>
class Solution {
const int MOD = 1e9 + 7;
public:
    ll findPow(ll a, ll b) {
        if(b == 0) 
            return 1;
        
        ll val = findPow(a, b / 2);
        ll res = (val * val) % MOD;

        if(b & 1)
            res = (res * a) % MOD;
        
        return res;
    }

    vector<int> getPrimes(int limit) {
        vector<bool> isPrime(limit + 1, true);
        vector<int> primes;

        for (int i = 2; i * i <= limit; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= limit; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        for (int i = 2; i <= limit; i++) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
        }

        return primes;
    }

    vector<int> findPrimeScores(vector<int>& nums) {
        int n = nums.size();
        vector<int> primeScores(n, 0);

        int maxElement = *max_element(begin(nums), end(nums));
        vector<int> primes = getPrimes(maxElement); //O(mloglogm)

        for(int i = 0; i < n; i++) { //O(n * log(m))
            int num = nums[i];

            for(int prime : primes) {
                if(prime*prime > num) {
                    break;
                }

                if(num % prime != 0) {
                    continue;
                }

                primeScores[i]++;
                while(num%prime == 0) {
                    num /= prime;
                }
            }
            if(num > 1) { //example : 15 : 3, 5
                primeScores[i]++;
            }
        }

        return primeScores;
    }

    // [1,2,2,3,2,4]
    // [6,3,3,5,5,6]
    vector<int> nextGreaterElement(vector<int> &nums) {
        int n = nums.size();
        vector<int> nextGreaterElem(n, n);
        stack<int> st;

        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }

            if(!st.empty()) {
                nextGreaterElem[i] = st.top();
            }

            st.push(i);
        }

        return nextGreaterElem;
    }

    vector<int> prevGreaterElement(vector<int> &nums) {
        int n = nums.size();
        vector<int> prevGreaterElem(n, -1);
        stack<int> st;

        for(int i = 0; i < n; i++) {

            while(!st.empty() && nums[st.top()] < nums[i])
                st.pop();
            
            if(!st.empty()) 
                prevGreaterElem[i] = st.top();
            
            st.push(i);
        }

        return prevGreaterElem;
    }


    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size(), idx = 0;
        ll score = 1;
        vector<int> primeScores = findPrimeScores(nums);
        vector<int> nextGreaterElem = nextGreaterElement(primeScores);
        vector<int> prevGreaterElem = prevGreaterElement(primeScores);
        vector<ll> subarrays(n, 0);
        vector<P> sortedNums(n);

        // calc no of subarrays that can be made with each number
        for(int i = 0; i < n; i++) 
            subarrays[i] = (ll)(nextGreaterElem[i] - i) * (i - prevGreaterElem[i]);
        
        for(int i = 0; i < n; i++) sortedNums[i] = {nums[i], i};

        sort(sortedNums.begin(), sortedNums.end(), greater<>());

        while(k>0) {
            auto &[num, i] = sortedNums[idx];

            ll operations = min(k * 1LL, subarrays[i]);

            score = (score * findPow(num, operations)) % MOD;

            k = k - operations;

            idx++;
        }

        return score;
    }                   
};