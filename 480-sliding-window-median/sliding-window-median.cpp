class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> left;
        multiset<int> right;
        vector<double> ans;
        int i = 0, j = 0, n = nums.size();

        while(j < n) {
            // First insert nums[j] in multiset
            if(left.empty() || left.size() <= right.size())
                left.insert(nums[j]);
            else 
                right.insert(nums[j]);
            
            // Swap elements if leftMax > rightMin
            if(left.size() > 0 && right.size() > 0 && *left.rbegin() > *right.begin()) {
                int temp = *left.rbegin();
                left.erase(prev(left.end()));
                left.insert(*right.begin());
                right.erase(right.begin());
                right.insert(temp);
            }

            // If window size == k then store median
            if(j-i+1 == k) {
                if(k&1) // odd window
                    ans.push_back((double) *left.rbegin());
                else
                    ans.push_back(((double) *left.rbegin() + (double) *right.begin()) / 2.0);
                
                // Now remove nums[i] present wherever
                if(left.find(nums[i]) != left.end())
                    left.erase(left.find(nums[i]));
                else
                    right.erase(right.find(nums[i]));
                
                i++;
            }

            j++;
        }

        return ans;
    }
};