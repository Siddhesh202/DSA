class Solution {
public:
    pair<int,int> getCord(int num, int n) {
        int rt = (num-1) / n;
        int rb = n - 1 - rt;
        int lr = ((n%2 == 0 && rb%2 ==0) || (n%2 != 0 && rb%2 != 0))? false : true;
        int col;
        if(lr) col = (num-1)%n;
        else col = (n-1) - ((num-1) % n);

        return {rb, col};
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size(), steps = 0;
        queue<int> q;
        vector<vector<bool>> vis(n, vector<bool>(n, 0));
        vis[n-1][0] = true;
        q.push(1);

        while(!q.empty()) {
            int N = q.size();
            
            while(N--) {
                int x = q.front();
                q.pop();

                if(x == n*n) return steps;

                for(int k = 1; k <= 6; k++) {
                    int val = x+k;

                    if(val > n*n) break;

                    auto coord = getCord(val, n);
                    int r = coord.first;
                    int c = coord.second;

                    if(vis[r][c]) continue;
                    vis[r][c] = true;
                    if(board[r][c] == -1) q.push(val);
                    else q.push(board[r][c]);
                }
            }

            steps++;
        }

        return -1;
    }
};