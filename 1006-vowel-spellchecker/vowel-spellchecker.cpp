class Solution {
public:
    string convertToLowerCase(string word) {
        string lowerCase = "";
        for(auto &ch : word) {
            lowerCase += tolower(ch);
        }
        return lowerCase;
    }

    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    string devowel(string word) {
        for (auto &ch : word) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                ch = '*';
        }
        return word;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        vector<string> ans(queries.size(), "");
        unordered_set<string> st(wordlist.begin(), wordlist.end());
        unordered_map<string, string> caseMap, devowelMap;  // kite -> KiTe

        // create the case map
        for(auto &word : wordlist) {
            string lowerCase = convertToLowerCase(word);
            if(caseMap.find(lowerCase) == caseMap.end()) caseMap[lowerCase] = word;

            string dev = devowel(lowerCase);
            if (devowelMap.find(dev) == devowelMap.end()) devowelMap[dev] = word;
        }


        for(int i = 0; i < queries.size(); i++) {
            string query = queries[i];
            string lowerCaseQuery = convertToLowerCase(query);

            // 1. Find for exact match
            if(st.find(query) != st.end()) {
                ans[i] = query;
                continue;
            }

            // 2. For Case Insensitive match
            if(caseMap.find(lowerCaseQuery) != caseMap.end()) {
                ans[i] = caseMap[lowerCaseQuery];
                continue;
            }

            // 3. Look for Vowel Errors
            string dev = devowel(lowerCaseQuery);
            if (devowelMap.find(dev) != devowelMap.end()) {
                ans[i] = devowelMap[dev];
                continue;
            }

        }

        return ans;
    }
};