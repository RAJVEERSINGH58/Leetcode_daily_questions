#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Bank {
public:

    bool isValid(int account) {
        return account >= 1 && account <= (int)balance.size();
    }

    vector<long long> balance;

    Bank(vector<long long>& balance) {
        this->balance = balance;
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(isValid(account1) && isValid(account2) && balance[account1-1] >= money){
            balance[account1-1] -= money;
            balance[account2-1] += money;
            return true;
        }
        else return false;
    }
    
    bool deposit(int account, long long money) {
        if(money < 0 || !isValid(account)) return false;
        balance[account-1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(isValid(account) && balance[account-1] >= money){
            balance[account-1] -= money;
            return true;
        }
        else return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */

int main() {
    
    return 0;
}