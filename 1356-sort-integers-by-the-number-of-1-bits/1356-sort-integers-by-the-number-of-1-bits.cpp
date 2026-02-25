#define P pair<int,int>
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int &a, int &b) {
            int cA = __builtin_popcount(a);
            int cB = __builtin_popcount(b);

            if(cA == cB) return a < b;
            return cA < cB;
        });

        return arr;
    }
};