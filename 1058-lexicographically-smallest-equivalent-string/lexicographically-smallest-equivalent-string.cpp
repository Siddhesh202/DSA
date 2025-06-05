class Solution {
public:
    char dfs(unordered_map<char, vector<char>> &adj, vector<int> &visited, char node) {
        visited[node-'a'] = true;
        char ans = node;

        for(auto &adjNode: adj[node]) {
            if(!visited[adjNode-'a']) {
                ans = min(dfs(adj, visited, adjNode), ans);
            }
        }

        return ans;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        unordered_map<char, vector<char>> adj;
        int n = s1.length();
        string ans = "";

        for(int i = 0; i < n; i++) {
            char u = s1[i];
            char v = s2[i];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i = 0; i < baseStr.length(); i++) {
            vector<int> visited(26, 0);
            ans += dfs(adj, visited, baseStr[i]);
        }

        return ans;
    }


};