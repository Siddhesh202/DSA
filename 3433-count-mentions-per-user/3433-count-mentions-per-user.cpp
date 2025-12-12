class Solution {
public:
    vector<int> getId(string str)
    {
        string s;
        stringstream ss(str);
        vector<int> v;

        while(getline(ss, s, ' ')) {
            v.push_back(stoi(s.substr(2)));
        }

        return v;
    }

    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> offTime(numberOfUsers, 0);
        vector<int> mentions(numberOfUsers, 0);
        // sort acc to timestamp
        auto comp=[&](auto& a, auto& b){
            if(a[1] == b[1])
                return a[0] == "OFFLINE";
            return stoi(a[1]) < stoi(b[1]);
        };
        sort(events.begin(), events.end(), comp);

        // process each event
        for(int i = 0; i < events.size(); i++) {
            auto event = events[i];
            int timestamp = stoi(event[1]);
            if(event[0] == "MESSAGE") {
                if(event[2] == "ALL") {
                    for(int i = 0; i < numberOfUsers; i++) mentions[i]++;
                }
                else if(event[2] == "HERE") {
                    for(int i = 0; i < numberOfUsers; i++) {
                        if(offTime[i] == 0 || (offTime[i] + 60 <= timestamp)) {
                            cout << i << ",";
                            mentions[i]++;
                        }
                    }
                }
                else {
                    vector<int> userIds = getId(event[2]);
                    for(auto &userid: userIds) {
                        mentions[userid]++;
                    }
                }
            } 
            else {
                offTime[stoi(event[2])] = timestamp;
            }
        }

        return mentions;
    }
};