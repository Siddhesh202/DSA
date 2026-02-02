#define ll long long
#define P pair<int,int>
class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size(), i = 1;
        set<P> minEls, rem;
        ll sum = 0, mini = LLONG_MAX;
    
        while(i - dist < 1) {
            sum += nums[i];

            minEls.insert({nums[i], i});

            if(minEls.size() > k-1) {
                P temp = *minEls.rbegin();
                sum -= temp.first;
                rem.insert(temp);
                minEls.erase(temp);
            }

            i++;
        }

        // Now go ahead with the window
        while(i < n) {
            sum += nums[i];

            minEls.insert({nums[i], i});

            if(minEls.size() > k-1) {
                P temp = *minEls.rbegin();
                sum -= temp.first;
                rem.insert(temp);
                minEls.erase(temp);
            }

            mini = min(sum, mini);

            // Now need to remove first elem from the window
            // i-dist elem will be removed
            P remove = {nums[i-dist], i-dist};

            if(minEls.count(remove)) { // sum par impact hoga
                sum -= remove.first;
                minEls.erase(remove);

                if(!rem.empty()) {
                    P temp = *rem.begin();
                    sum += temp.first;
                    minEls.insert(temp);
                    rem.erase(temp);
                }
            }
            else {
                rem.erase(remove);
            }

            i++;
        }

        return mini + nums[0];
    }
};