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
            if(!right.empty() && *left.rbegin() > *right.begin()) {
                int temp1 = *left.rbegin();
                int temp2 = *right.begin();

                left.erase(left.find(temp1));
                right.erase(right.find(temp2));
                
                left.insert(temp2);
                right.insert(temp1);
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