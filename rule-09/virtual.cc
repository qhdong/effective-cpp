#include <iostream>
#include <string>

using namespace std;

class Transaction {
public:
    explicit Transaction(const string &msg);
    void logTransaction(const string &msg) const;
    virtual ~Transaction() = 0;
};

Transaction::~Transaction() {}

Transaction::Transaction(const string &msg) {
    logTransaction(msg);
}

void Transaction::logTransaction(const string &msg) const {
    cout << msg;
}

class BuyTransaction: public Transaction {
public:
    BuyTransaction(): Transaction(createLogMessage()) {}
private:
    static string createLogMessage();
};

string BuyTransaction::createLogMessage() {
    return "Buy Transaction.\n";
}

int main() {
    BuyTransaction buy;
}
