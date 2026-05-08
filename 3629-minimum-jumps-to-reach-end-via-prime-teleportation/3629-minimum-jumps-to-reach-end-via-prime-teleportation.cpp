class Solution {
public:

    vector<bool> sieve(int maxEl) {
        vector<bool> isPrime(maxEl+1, true);
        isPrime[0] = false;
        isPrime[1] = false;

        for(int i = 2; i <= sqrt(maxEl); i++) {
            if(isPrime[i] == true) {
                for(int j = 2; i*j <= maxEl; j++) isPrime[i*j] = false;  
            }
        }

        return isPrime;
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();
        int maxEl = *max_element(nums.begin(), nums.end());
        vector<bool> isPrime = sieve(maxEl);

        // store num -> arr of idx in map
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++) mp[nums[i]].push_back(i);

        // Do a simple BFS
        unordered_set<int> seen;
        vector<bool> visited(n, false);
        queue<int> q;
        visited[0] = true;
        q.push(0);
        int steps = 0;

        while(!q.empty()) {
            int size = q.size();

            while(size--) {
                int idx = q.front();
                q.pop();

                if(idx == n-1) return steps;

                if(idx-1 >= 0 && !visited[idx-1]) {
                    visited[idx-1] = true;
                    q.push(idx-1);
                }

                if(idx+1 < n && !visited[idx+1]) {
                    visited[idx+1] = true;
                    q.push(idx+1);
                }

                if(!isPrime[nums[idx]] || seen.count(nums[idx])) {
                    continue;
                }

                // special case for prime
                int val = nums[idx];
                seen.insert(val);
                for(int j = 1; j * val <= maxEl; j++) {
                    if(mp.count(val*j)) {
                        vector<int> idxs = mp[val*j];
                        for(auto &index : idxs) if(!visited[index]) {
                            visited[index] = true;
                            q.push(index);
                        }
                    }
                }
            }

            steps++;
        }

        return steps;
    }
};