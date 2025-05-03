class Solution {
public:
    int check(int target, vector<int>& A, vector<int>& B) {
        int rotationsA = 0, rotationsB = 0;
        int n = A.size();
        for(int i = 0; i < n; ++i) {
            if(A[i] != target && B[i] != target) return -1;
            else if(A[i] != target) rotationsA++;
            else if(B[i] != target) rotationsB++;
        }
        return min(rotationsA, rotationsB);
    }

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int res = check(tops[0], tops, bottoms);
        if(res != -1) return res;
        return check(bottoms[0], tops, bottoms);
    }
};