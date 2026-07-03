#define ll long long
class Solution {
public:
    int n;
    vector<ll> minTime(vector<vector<pair<int, int>>>& adj, int power, vector<int>& cost, int source, int target) {
        vector<vector<ll>> dist(n, vector<ll>(power + 1, LLONG_MAX));

        using State = tuple<ll, int, int>; // {time, remainingPower, node}
        priority_queue<State, vector<State>, greater<State>> pq;

        dist[source][power] = 0;
        pq.push({0, power, source});

        ll bestTime = -1;
        ll bestPower = -1;

        while (!pq.empty()) {
            auto [currTime, currPower, node] = pq.top();
            pq.pop();

            // Ignore stale states
            if (currTime != dist[node][currPower])
                continue;

            // Early stopping
            if (bestTime != -1 && currTime > bestTime)
                break;

            // Reached target
            if (node == target) {
                if (bestTime == -1)
                    bestTime = currTime;

                bestPower = max(bestPower, (ll)currPower);
                continue;
            }

            if (currPower < cost[node])
                continue;

            int nextPower = currPower - cost[node];

            for (auto& [nextNode, wt] : adj[node]) {
                ll nextTime = currTime + wt;

                if (nextTime < dist[nextNode][nextPower]) {
                    dist[nextNode][nextPower] = nextTime;
                    pq.push({nextTime, nextPower, nextNode});
                }
            }
        }

        if (bestTime == -1)
            return {-1, -1};

        return {bestTime, bestPower};
    }

    vector<long long> minTimeMaxPower(int nodes, vector<vector<int>>& edges, int power, vector<int>& cost, int source, int target) {
        n = nodes;
        vector<vector<pair<int, int>>> adj(n);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
        }

        return minTime(adj, power, cost, source, target);
    }
};