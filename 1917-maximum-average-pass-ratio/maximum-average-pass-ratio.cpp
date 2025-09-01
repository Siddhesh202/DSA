#define P pair<double, int>
class Solution {
public:
    double calculateGain(int pass, int total)
    {
        return (double) (pass+1) / (total+1) - (double) pass / total;
    }

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<P> maxh;
        double sum = 0.0, n = classes.size();

        for(int i = 0; i < n; i++) {
            int pass = classes[i][0];
            int total = classes[i][1];
            maxh.push({calculateGain(pass, total), i});
        }    

        while(extraStudents--) {
            double delta = maxh.top().first;
            int idx = maxh.top().second;

            classes[idx][0]++;
            classes[idx][1]++;

            maxh.pop();
            maxh.push({calculateGain(classes[idx][0], classes[idx][1]), idx});
        }

        while(!maxh.empty()) {
            int idx = maxh.top().second;
            sum += (classes[idx][0] * 1.0 / classes[idx][1]);
            maxh.pop();
        }

        return sum / n;
    }
};