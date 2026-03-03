class Solution {
public:
    char findKthBit(int n, int k) {
        if(n == 1) 
            return '0';
        
        int total_bits = (1 << n) - 1;
        int mid = total_bits / 2 + 1;

        if(mid == k)
            return '1';
        
        else if(k < mid)
            return findKthBit(n-1, k);
        
        else {
            char res = findKthBit(n-1, total_bits - k + 1);
            if(res == '1')
                return '0';
            return '1';
        }
    }
};