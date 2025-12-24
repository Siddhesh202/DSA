class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = apple.size(), m = capacity.size(), sum = 0;
        int totalAppls = accumulate(apple.begin(), apple.end(), 0);
        sort(capacity.begin(), capacity.end(),greater<int>());

        for(int i = 0; i < m; i++) {
            sum += capacity[i];

            if(sum >= totalAppls) return i+1;
        }

        return 0;
    }
};