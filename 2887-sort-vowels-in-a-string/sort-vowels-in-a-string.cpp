class Solution {
public:
    string sortVowels(string s) {
        priority_queue<char, vector<char>, greater<char>> pq;

        for(auto ch : s) {
            if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'
            || ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            {
                pq.push(ch);
            }
        }

        for(int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'
            || ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            {
                s[i] = pq.top();
                pq.pop();
            }
        }

        return s;
    }
};