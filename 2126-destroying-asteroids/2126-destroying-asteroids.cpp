#define ll long long
class Solution {
public:
    bool asteroidsDestroyed(ll mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());

        for(auto &asteroid : asteroids) {
            if(mass < asteroid) return false;
            mass += asteroid;
        }

        return true;
    }
};