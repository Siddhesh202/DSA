class Solution {
public:
    bool f(vector<double>& cards) {
        int n = cards.size();

        // base case
        if (n == 1) {
            return fabs(cards[0] - 24.0) < 1e-6;
        }

        // perform operation on any 2 no's and then rely on recursion
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) continue;

                vector<double> temp;
                for(int k = 0; k < n; k++) {
                    if(k != i && k != j) temp.push_back(cards[k]); 
                }

                double a = cards[i], b = cards[j];

                // now apply backtracking
                temp.push_back(a+b);
                bool opt1 = f(temp);
                temp.pop_back();

                temp.push_back(a-b);
                bool opt2 = f(temp);
                temp.pop_back();

                temp.push_back(b-a);
                bool opt3 = f(temp);
                temp.pop_back();

                temp.push_back(a*b);
                bool opt4 = f(temp);
                temp.pop_back();

                temp.push_back(a/b);
                bool opt5 = f(temp);
                temp.pop_back();

                temp.push_back(b/a);
                bool opt6 = f(temp);
                temp.pop_back();

                if(opt1 || opt2 || opt3 || opt4 || opt5 || opt6) return true;
            }
        }

        return false;
    }

    bool judgePoint24(vector<int>& cards) {
        vector<double> c(4);
        for(int i = 0; i < 4; i++) c[i] = cards[i];

        return f(c);
    }
};