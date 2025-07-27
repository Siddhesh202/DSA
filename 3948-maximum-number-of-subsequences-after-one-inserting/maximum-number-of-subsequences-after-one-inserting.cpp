#define ll long long        
class Solution {
public:
    long long numOfSubsequences(string s) {
        int n = s.length();
        ll ans = 0, ans1 = 0, ans2 = 0, ans3 = 0, maxi = LLONG_MIN;
        vector<ll> prefL(n, 0), suffT(n, 0);

        prefL[0] = (s[0] == 'L') ? 1 : 0;
        suffT[n-1] = (s[n-1] == 'T') ? 1 : 0;

        for(int i = 1; i < n; i++) {
            char ch = s[i];
            prefL[i] = prefL[i-1];
            if(ch == 'L') prefL[i] += 1;
        }

        for(int i = n-2; i >= 0; i--) {
            char ch = s[i];
            suffT[i] = suffT[i+1];
            if(ch == 'T') suffT[i] += 1;
        }

        // calc basic ans without any addition
        for(int i = 0; i < n; i++) {
            char ch = s[i];
            if(s[i] == 'C') 
                ans += prefL[i] * suffT[i];
        }

        // Now calc what if we add L, C or T 
        
        // 1. If we add L
        for(int i = 0; i < n; i++) {
            char ch = s[i];
            if(s[i] == 'C') 
                ans1 += (prefL[i] + 1) * suffT[i];
        }

        // 2. If we add T
        for(int i = 0; i < n; i++) {
            char ch = s[i];
            if(s[i] == 'C') 
                ans2 += prefL[i] * (suffT[i] + 1);
        }

        // 3. if we add C
        for(int i = 0; i < n; i++) {
            maxi = max(prefL[i] * suffT[i], maxi);
        }

        ans3 = ans + maxi;

        return max({ans, ans1, ans2, ans3});
    }
};