#define ll long long
class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        ll curr = 0;
        ll minVal = 0, maxVal = 0;

        for(int i = 0; i < differences.size(); i++) {
            curr = differences[i] + curr;
            minVal = min(minVal, curr);
            maxVal = max(maxVal, curr);
        }
        
        // b - a + 1
        ll total = (upper - maxVal) - (lower -  minVal) + 1;

        return total < 0 ? 0 : total;
    }
};