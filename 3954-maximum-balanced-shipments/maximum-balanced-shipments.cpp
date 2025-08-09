class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int res = 0;
        int maxi = 0;
        for(int i = 0; i < weight.size(); i++) {
            if(weight[i] < maxi) {
                res++;
                maxi = 0;
            }
            else maxi = max(weight[i], maxi);
        }

        return res;
    }
};