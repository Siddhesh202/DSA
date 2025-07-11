#define ll long long
#define P pair<ll, int>
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> ans(n,0);
        priority_queue<P, vector<P>, greater<P>> busyRooms;
        priority_queue<int, vector<int>, greater<int>> freeRooms;

        sort(meetings.begin(), meetings.end());

        for (int i = 0; i < n; i++) freeRooms.push(i);

        for(int i = 0; i < meetings.size(); i++) {
            ll dur = meetings[i][1] - meetings[i][0];
            int start = meetings[i][0];
            int end = meetings[i][1];

            // free up rooms if any
            while(!busyRooms.empty() && busyRooms.top().first <= start)
            {
                freeRooms.push(busyRooms.top().second);
                busyRooms.pop();
            }

            // if any freeRoom then place meeting in that room
            if(!freeRooms.empty()) {
                int room = freeRooms.top();
                freeRooms.pop();
                ans[room]++;
                busyRooms.push({end, room});
            }
            else { // free room is not available, wait until the meeting with lowest endTime finishes   
                ll newStartTime = busyRooms.top().first;
                int room = busyRooms.top().second;
                busyRooms.pop();
                ans[room]++;
                ll endTime = newStartTime + dur;
                busyRooms.push({endTime, room});
            }
            
        }

        // find maximum
        int maxi = 0, maxIdx = 0;
        for(int i = 0; i < n; i++) {
            if(ans[i] > maxi) {
                maxi = ans[i];
                maxIdx = i;
            }
        }

        return maxIdx;
    }
};