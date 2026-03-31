#define P pair<int,int>
class EventManager {
public:
    priority_queue<P> pq;
    unordered_map<int, int> mp; // eventId -> current priority

    EventManager(vector<vector<int>>& events) {
        for(auto &event : events) {
            int eventId = event[0], priority = event[1];
            pq.push({priority, -1 * eventId}); // priority, eventId
            mp[eventId] = priority;
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        pq.push({newPriority, -1 * eventId});
        mp[eventId] = newPriority;
    }
    
    int pollHighest() {
        while(!pq.empty()) {
            auto [pr, negId] = pq.top();
            int id = -negId;

            if(mp.count(id) && mp[id] == pr) {
                pq.pop();
                mp.erase(id);
                return id;
            }

            pq.pop(); // discard wrong entry
        }

        return -1;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */