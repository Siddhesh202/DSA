#define P pair<char,int>

struct comp {
    bool operator()(const P &a, const P &b) const {
        if(a.first != b.first) return a.first > b.first;
        return a.second < b.second; 
    }
};


class Solution {
public:
    string clearStars(string s) {
        int n = s.length();
        vector<bool> toRemove(n, 0);
        string ans = "";

        priority_queue<P, vector<P>, comp> pq;

        for(int i = 0; i < n; i++) {
            if(s[i] != '*') pq.push({s[i], i});
            else {
                toRemove[pq.top().second] = true;
                toRemove[i] = true;
                pq.pop();
            }
        }

        for(int i = 0; i < n; i++) {
            if(!toRemove[i]) ans += s[i];
        }


        return ans;
    }
};