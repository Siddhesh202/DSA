#define ll long long
class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        ll score = 0;
        int i = 0, n = values.size();
        vector<bool> visited(n, false);

        while(i >= 0 && i < n && !visited[i]) {

            string action = instructions[i];
            visited[i] = true;

            if(action == "add") 
            {
                score += values[i];
                i++;
            }

            else {
                i += values[i];
            }
        }

        return score;
    }
};