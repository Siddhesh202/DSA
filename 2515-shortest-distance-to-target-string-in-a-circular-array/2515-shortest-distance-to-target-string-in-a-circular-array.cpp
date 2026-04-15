class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        if(target == words[startIndex]) return 0;
        int n = words.size();
        int ans = INT_MAX;

        // go right
        int idx = (startIndex+1)%n;
        int steps = 1;
        while(idx != startIndex) {
            if(words[idx] == target) {
                ans = min(ans, steps);
                break;
            }
            steps++;
            idx = (idx + 1) % n;
        }   

        // go left
        idx = (startIndex-1+n) % n;
        steps = 1;
        while(idx != startIndex) {
            if(words[idx] == target) {
                ans = min(ans, steps);
                break;
            }
            steps++;
            idx = (idx - 1 + n) % n;
        }   

        if(ans == INT_MAX) return -1;
        return ans;

    }
};