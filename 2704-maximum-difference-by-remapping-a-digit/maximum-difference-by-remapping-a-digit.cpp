class Solution {
public:
    void replace(string& str, char oldChar, char newChar) {
        for (char& c : str) {
            if (c == oldChar) {
                c = newChar;
            }
        }
    }

    int minMaxDifference(int num) {
        string mini = to_string(num);
        string maxi = to_string(num);
        int n = mini.length();

        // get minimum
        replace(mini, mini[0], '0');

        // get maximum
        for(int i = 0; i < n; i++) {
            if(maxi[i] != '9') {
                replace(maxi, maxi[i], '9');
                break;
            }
        }

        cout << maxi << " : " << maxi << endl;
        cout << mini << " : " << mini << endl;

        return stoi(maxi) - stoi(mini);
    }
};