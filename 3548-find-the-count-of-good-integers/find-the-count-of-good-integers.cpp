#define ll long long
class Solution {
public:
    void calcFact(vector<ll> &fact) {
        for(int i = 1; i < 11; i++) 
            fact[i] = fact[i-1] * i;
    }

    long long countGoodIntegers(int n, int k) {
        unordered_set<string> st;
        vector<ll> fact(11, 1);
        int d = (n+1) / 2;
        int start = pow(10, d-1);
        int end = pow(10, d) - 1;
        ll ans = 0;

        calcFact(fact);

        for(int num = start; num <= end; num++) {
            string leftHalf = to_string(num);
            string full = "";

            if(n%2 == 0) { // agar even hai toh
                string rightHalf = leftHalf;
                reverse(rightHalf.begin(), rightHalf.end());
                full = leftHalf + rightHalf;
            }
            else { // agar odd hai toh
                string rightHalf = leftHalf.substr(0, d-1);
                reverse(rightHalf.begin(), rightHalf.end());
                full = leftHalf + rightHalf;
            }

            ll number = stoll(full);

            if(number % k != 0) // number is not a k palindrome
                continue;

            sort(full.begin(), full.end());
            st.insert(full);
        }


        // process the set now 
        for(auto &s : st) {
            vector<int> count(10, 0);
            for(auto &ch : s)
                count[ch - '0']++;
            
            int nonZeroDigits = n - count[0];
            ll perm = nonZeroDigits * fact[n-1];

            for(int i = 0; i < 10; i++) 
                perm /= fact[count[i]];
            
            ans += perm;
        }

        return ans;
    }
};