#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>
using namespace std;

class Bank {
private:
    unordered_map<int, long long> accounts;

public:

    // CREATE X Y
    bool create(int userId, long long amount) {
        if (accounts.find(userId) == accounts.end()) {
            accounts[userId] = amount;
            return true;
        }

        // User already exists, add money
        accounts[userId] += amount;
        return false;
    }

    // DEBIT X Y
    bool debit(int userId, long long amount) {
        if (accounts.find(userId) == accounts.end()) {
            return false;
        }

        if (accounts[userId] < amount) {
            return false;
        }

        accounts[userId] -= amount;
        return true;
    }

    // CREDIT X Y
    bool credit(int userId, long long amount) {
        if (accounts.find(userId) == accounts.end()) {
            return false;
        }

        accounts[userId] += amount;
        return true;
    }

    // BALANCE X
    long long balance(int userId) {
        if (accounts.find(userId) == accounts.end()) {
            return -1;
        }

        return accounts[userId];
    }
};

int main() {
    int Q;
    cin >> Q;
    cin.ignore();

    Bank bank;

    while (Q--) {
        string query;
        getline(cin, query);

        stringstream ss(query);
        string operation;
        ss >> operation;

        if (operation == "CREATE") {
            int x;
            long long y;
            ss >> x >> y;

            cout << (bank.create(x, y) ? "true" : "false") << endl;
        }

        else if (operation == "DEBIT") {
            int x;
            long long y;
            ss >> x >> y;

            cout << (bank.debit(x, y) ? "true" : "false") << endl;
        }

        else if (operation == "CREDIT") {
            int x;
            long long y;
            ss >> x >> y;

            cout << (bank.credit(x, y) ? "true" : "false") << endl;
        }

        else if (operation == "BALANCE") {
            int x;
            ss >> x;

            cout << bank.balance(x) << endl;
        }
    }

    return 0;
}
