class Solution {
public:
    void replace(string& str, char oldChar, char newChar) {
        for (char& c : str) {
            if (c == oldChar) {
                c = newChar;
            }
        }
    }

    int maxDiff(int num) {
        string a = to_string(num);
        string b = to_string(num);

        // if 1st char is not 1 replace it with 1
        if(a[0] != '1') {
            replace(a, a[0], '1');
        } 
        else {  
            for(int i = 1; i < a.length(); i++) {
                if(a[i] != a[0] && a[i] != '0') {
                    replace(a, a[i], '0');
                    break;
                }
            }
        }

        for(int i = 0; i < b.length(); i++) {
            if(b[i] != '9') {
                replace(b, b[i], '9');
                break;
            }
        }

        cout << "a : " << a << endl;
        cout << "b : " << b << endl;

        return stoi(b) - stoi(a);
    }
};