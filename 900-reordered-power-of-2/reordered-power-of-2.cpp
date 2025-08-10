class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string num = to_string(n);
        vector<int> vec;

        // put it in vec
        for(int i = 0; i < num.length(); i++) {
            int dig = num[i] - '0';
            vec.push_back(dig);
        }

        // sort the vec
        sort(vec.begin(), vec.end());

        // Check for powers of 2
        for(int i = 0; i <= 30; i++) {
            int power = pow(2, i);
            string str = to_string(power);
            vector<int> temp;

            for(int i = 0; i < str.length(); i++) {
                temp.push_back(str[i] - '0');
            }

            sort(temp.begin(), temp.end());

            if(temp.size() == vec.size() && vec == temp)
                return true;
        }

        return false;

    }
};