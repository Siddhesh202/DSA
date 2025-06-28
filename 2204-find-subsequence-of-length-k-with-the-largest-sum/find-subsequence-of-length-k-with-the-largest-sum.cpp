#define P pair<int,int>
class Solution {
public:
    bool static customComp(P &a, P &b) {
        return a.second < b.second;
    }

    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<P, vector<P>, greater<P>> minh;
        vector<P> ans;
        vector<int> res;

        for(int i = 0; i < nums.size(); i++) {
            if(minh.size() == k) {
                if(minh.top().first < nums[i]) {
                    minh.pop();
                    minh.push({nums[i], i});
                }
            } else {
                minh.push({ nums[i], i});
            }
        }

        while(!minh.empty()) {
            ans.push_back(minh.top());
            minh.pop();
        }

        sort(ans.begin(), ans.end(), customComp);

        for(auto &p : ans) res.push_back(p.first);

        return res;
    }
};