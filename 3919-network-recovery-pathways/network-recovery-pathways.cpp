#define P pair<int,int>
#define ll long long
class Solution {
public:
    int n;
    bool isPossible(unordered_map<int, vector<P>> &adj, vector<bool>& online, ll k, ll tar) {
        vector<ll> ans(n, LLONG_MAX);
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll,int>>> pq;
        ans[0] = 0;
        pq.push({0, 0});

        while(!pq.empty()) {
            ll currCost = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(currCost > ans[node]) continue;
            if(online[node] == false) continue;

            for(auto &neig : adj[node]) {
                int adjNode = neig.first;
                ll cost     = neig.second;
                ll newcost = cost + currCost;
                if(cost >= tar && newcost < ans[adjNode] && online[adjNode]) {
                    ans[adjNode] = newcost;
                    pq.push({newcost, adjNode});
                }
            }
        }

        return ans[n-1] <= k;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        n = online.size();
        int l = 0, r = 0, ans=-1;
        unordered_map<int, vector<P>> adj;

        // 1. build an adj matrix
        for(auto &edge: edges) {
            int u = edge[0];
            int v = edge[1];
            int cost = edge[2];
            r = max(cost, r);
            adj[u].push_back({v, cost});
        }

        //2. do a binary search on the ans
        while(l <= r) {
            int mid = l + (r - l) / 2;
            cout << mid << endl;
            if(isPossible(adj, online, k, mid)) {
                ans = mid;
                l = mid+1;
            }
            else
                r = mid-1;
        }

        return ans;
    }
};