class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int count = 0;
        int i = 0;
        int n = events.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        sort(events.begin(), events.end());
        int day = events[0][0];

        while(!pq.empty() || i < n) {
            
            if(pq.empty())
                day = events[i][0];

            // get all events starting at this day
            while(i < n && events[i][0] == day) {
                pq.push(events[i][1]);
                i++;
            }

            // pop the event with minimum end day
            if(!pq.empty()) {
                pq.pop();
                count++;
            }

            day++;

            // skip those events whose end day < day
            while(!pq.empty() && pq.top() < day) {
                pq.pop();
            }
        }

        return count;
    }
};