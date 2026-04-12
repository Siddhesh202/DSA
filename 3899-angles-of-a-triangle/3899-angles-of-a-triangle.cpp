class Solution {
public:
    bool isValid(vector<int>& sides) {
        int a = sides[0], b = sides[1], c = sides[2];

        return (a+b > c) && (b+c > a) && (a+c > b);  
    }

    double findAngle(int a, int b, int c) {
        double cosA = (b*b + c*c - a*a) / (2 * b * c * 1.0);
        double angle_deg = acos(cosA) * 180.0 / M_PI;
        return angle_deg;
    }

    vector<double> internalAngles(vector<int>& sides) {
        vector<double> ans;
        
        if(!isValid(sides)) return ans;

        // Find internal angles
        int a = sides[0], b = sides[1], c = sides[2];
        ans.push_back(findAngle(a, b, c));
        ans.push_back(findAngle(b, a, c));
        ans.push_back(findAngle(c, a, b));

        sort(ans.begin(), ans.end());
        return ans;

    }
};