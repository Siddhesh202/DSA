#define P pair<string,string>
class Solution {
public:
    bool isValidCode(string s) {
        if (s.empty()) return false;

        for (char c : s) {
            if (!(std::isalnum(c) || c == '_')) {
                return false;
            }
        }
        return true;
    }

    bool isValidBusinessLine(string bl) {
        if(bl == "electronics" || bl == "grocery" || bl == "pharmacy" || bl == "restaurant") return true;
        return false;
    }

    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        map<string, vector<string>> mp;
        vector<string> ans;

        for(int i = 0; i < n; i++) {
            string c = code[i];
            string b = businessLine[i];
            bool isAct = isActive[i];

            if(isAct && isValidBusinessLine(b) && isValidCode(c)) 
                mp[b].push_back(c);
        }

        for(auto &p : mp) {
            vector<string> arr = p.second;
            sort(arr.begin(), arr.end());

            for(auto &elem : arr) ans.push_back(elem);
        }

        return ans;
    }
};