class Solution {
public:
    void DFS(int n, int currNum, vector<int>& ans)
    {
        if(currNum > n)
            return;
        
        ans.push_back(currNum);
        for(int i = 0; i <= 9; i++)
        {
            int newNum = currNum*10 + i;
            if(newNum > n)
                return;

            DFS(n, newNum, ans);
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int> ans;

        for(int startNum = 1; startNum <= 9; startNum++)
        {
            DFS(n, startNum, ans);
        }

        return ans;
    }
};