#define ll long long
class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.length()-1;

        while(i <= j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }

        return true;
    }

    string baseKVersion(ll num, ll base) {
        if(num == 0) return "0";

        string result = "";

        while(num > 0) {
            result += to_string(num % base);
            num /= base;
        }

        reverse(result.begin(), result.end());
        return result;
    }

    long long kMirror(int k, int n) {
        ll sum = 0;
        int L = 1;

        while(n > 0) {
            int half_length = (L+1) / 2;
            ll mini_num = pow(10, half_length-1);
            ll maxi_num = pow(10, half_length) - 1;

            for(ll num = mini_num; num <= maxi_num; num++) {
                string first_half = to_string(num);
                string second_half = first_half;
                reverse(second_half.begin(), second_half.end());
                
                if(L % 2 == 1) first_half += second_half.substr(1);
                else first_half += second_half;

                // now check if baseK is also a palindrome or not
                if(isPalindrome(baseKVersion(stoll(first_half), k)) && n > 0) { 
                    // cout << first_half << endl;
                    sum += stoll(first_half);
                    n--;
                    if(n == 0) break;
                } 
            }

            L++;
        }

        return sum;
    }
};