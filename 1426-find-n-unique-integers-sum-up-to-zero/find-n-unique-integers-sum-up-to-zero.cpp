class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> v1, v2;

        for(int i = 1; i <= n/2; i++) {
            v1.push_back(i);
        }

        for(int i = 0; i < v1.size(); i++) 
            v2.push_back(-1 * v1[i]);
        
        if(n % 2 != 0) v1.push_back(0);

        v1.insert(v1.end(), v2.begin(), v2.end());

        return v1;
    }
};