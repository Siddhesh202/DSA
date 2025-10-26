#define ll long long
class Bank {
public:
    vector<ll> balance;
    int n;
    Bank(vector<long long>& balance) {
        this->balance = balance;
        n = balance.size();
    }
    
    bool transfer(int account1, int account2, long long money) {
        int acc1 = account1-1, acc2 = account2-1;

        if(acc1 >= 0 && acc1 < n && acc2 >= 0 && acc2 < n) {
            if(balance[acc1] >= money) {
                balance[acc1] -= money;
                balance[acc2] += money;
                return true;
            }
        }

        return false;
    }
    
    bool deposit(int account, long long money) {
        if(account < 1 || account > n) return false;
        balance[account-1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(account < 1 || account > n) return false;
        if(balance[account-1] >= money) {
            balance[account-1] -= money;
            return true;
        }

        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */