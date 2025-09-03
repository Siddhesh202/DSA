#define ll long long
class Solution {
public:
    int bestDiff = INT_MAX;
    vector<int> bestArr;

    vector<int> getDivisors(int n) {
        vector<int> ans;

        for(int i = 1; i <= n; i++) {
            if(n % i == 0) ans.push_back(i);
        }

        return ans;
    }

    void backtrack(int n, int k, int currIdx, vector<int> &divisors, vector<int> &arr) {
        if(arr.size() == k) {
            if(n == 1) {
                int diff = arr.back() - arr.front();
                if(diff < bestDiff) {
                    bestDiff = diff;
                    bestArr = arr;
                }
            }
            return;
        }

        for(int i = currIdx; i < divisors.size(); i++) {
            if(divisors[i] > n) break; // Apply Pruning

            if(n%divisors[i] == 0) {
                arr.push_back(divisors[i]);
                backtrack(n/divisors[i], k, i, divisors, arr);
                arr.pop_back();
            }
        }
    }

    vector<int> minDifference(int n, int k) {
        vector<int> arr;
        vector<int> divisors = getDivisors(n);
        backtrack(n, k, 0, divisors, arr);
        return bestArr;
    }
};