class Solution {
public:
    int countOdds(int low, int high) {
        int cnt = high - low + 1;

        if(cnt % 2 == 0) return cnt / 2;
        
        if(low % 2 == 0) return cnt / 2;

        return (cnt+1) / 2;
    }
};

// 3 4 5 6 7 --> 3 --> tn = a + (n-1)*2 --> high = low + (2*n) - 2 ---> (high - low + 2) / 2
// 8 9 10 11 12 13 14 ---> total Num - aboveCalc
// 3 4 5 6 7 8 9 10 11 12 13 14 ---> 