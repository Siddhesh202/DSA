class Solution {
public:
    int getNoCameras(string str) {
        int ans = 0;
        for(auto &ch : str) {
            if(ch == '1') ans++;
        }

        return ans;
    }

    int numberOfBeams(vector<string>& bank) {
        int prev = 0, ans = 0;

        for(auto &str : bank) {
            int noCameras = getNoCameras(str);
            if(noCameras > 0) {
               ans += noCameras * prev;
               prev = noCameras;
            }
        }

        return ans;
    }
};