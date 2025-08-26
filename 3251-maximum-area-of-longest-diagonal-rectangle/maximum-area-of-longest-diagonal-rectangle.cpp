class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int longDiag = INT_MIN, largArea = INT_MIN;

        for(auto &dimension : dimensions) {
            int len = dimension[0];
            int wid = dimension[1];
            int diag = pow(len,2) + pow(wid,2);

            if(diag > longDiag) {
                longDiag = diag;
                largArea = len * wid;
            }
            else if(diag == longDiag) {
                longDiag = diag;
                largArea = max(largArea, len * wid);
            }
        }

        return largArea;
    }
};