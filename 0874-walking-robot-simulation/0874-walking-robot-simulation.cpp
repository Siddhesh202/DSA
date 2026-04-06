class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // north 0, east 1, south 2, west 3
        int moveX[4] = {0, 1, 0, -1};
        int moveY[4] = {1, 0, -1, 0};
        int dir = 0;
        int x_start = 0, y_start = 0;
        int maxi = 0;
        set<pair<int,int>> obs;
        for(auto p : obstacles) {
            obs.insert({p[0], p[1]});
        }

        for(auto command : commands) {
            if(command == -2) {
                // turn to left
                dir = (dir + 3) % 4;
            }else if(command == -1) {
                // turn to right
                dir = (dir + 1) % 4;
            }else {
                int moves = command;
                while(moves > 0) {
                    int new_x = x_start + moveX[dir];
                    int new_y = y_start + moveY[dir];

                    if(obs.find({new_x, new_y}) == obs.end()) {
                        x_start = new_x;
                        y_start = new_y;
                        moves--;
                        maxi = max(maxi, ((x_start*x_start)+(y_start*y_start)));
                    }else {
                        break;
                    }
                }
            }
        }

        return maxi;
        
    }
};