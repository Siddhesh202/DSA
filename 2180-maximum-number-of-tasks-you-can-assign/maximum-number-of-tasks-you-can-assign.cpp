class Solution {
public:
    int n, m;
    bool isPossible(vector<int>& tasks, vector<int>& workers, int pills, int strength, int mid) {
        int pillsUsed = 0;
        multiset<int> st(workers.begin(), workers.begin() + mid); // first best mid workers

        for(int i = mid-1; i >= 0; i--) {
            int reqd = tasks[i];
            auto it  = prev(st.end());
            if(*it >= reqd) {
                st.erase(it);
            } 
            else if(pills == pillsUsed) {
                return false;
            } 
            else {
                auto weakestWorkerIt = st.lower_bound(reqd - strength);
                if(weakestWorkerIt == st.end()) return false;
                pillsUsed++;
                st.erase(weakestWorkerIt);
            }
        }

        return true;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        n = tasks.size(), m = workers.size();
        int l = 0, r = min(n, m), ans = 0;
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end(), greater<int>());

        while(l <= r) {
            int mid = l + (r - l) / 2;

            if(isPossible(tasks, workers, pills, strength, mid)) {
                ans = mid;
                l = mid + 1;
            } else 
                r = mid - 1;
        }

        return ans;
    }
};