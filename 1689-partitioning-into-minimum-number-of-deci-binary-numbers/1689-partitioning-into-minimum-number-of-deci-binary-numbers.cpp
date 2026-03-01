class Solution {
public:
    int minPartitions(string n) {
        char maxCh = *max_element(begin(n), end(n));

        return maxCh - '0';
    }
};

// 1, 10, 11, 100, 101, 111, 1000, 1001, 1011, 1100, 1101