class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> leftClosestR(n), rightClosestL(n);
        string ans = "";

        leftClosestR[0] = dominoes[0] == 'R' ? 0 : -1;
        rightClosestL[n-1] = dominoes[n-1] == 'L' ? n-1 : -1;

        // traverse from left to right
        for(int i = 1; i < n; i++) {
            char ch = dominoes[i];

            if(ch == 'L') leftClosestR[i] = -1;
            else if(ch == 'R') leftClosestR[i] = i;
            else leftClosestR[i] = leftClosestR[i-1];
        }

        // traverse from right to left
        for(int i = n-2; i >= 0; i--) {
            char ch = dominoes[i];

            if(ch == 'R') rightClosestL[i] = -1;
            else if(ch == 'L') rightClosestL[i] = i;
            else rightClosestL[i] = rightClosestL[i+1];
        }

        for(int i = 0; i < n; i++) {
            // cout << leftClosestR[i] << " , " << rightClosestL[i] << endl;
            if((leftClosestR[i] == -1) && (rightClosestL[i] == -1)) ans += '.';
            else if(leftClosestR[i] == -1) ans += 'L';
            else if(rightClosestL[i] == -1) ans += 'R';
            else {
                int distLeftR = abs(i - leftClosestR[i]);
                int distRightL = abs(i - rightClosestL[i]);
                if(distLeftR < distRightL) ans += 'R';
                else if(distLeftR > distRightL) ans += 'L';
                else ans += '.';
            }

        }

        return ans;
    }
};