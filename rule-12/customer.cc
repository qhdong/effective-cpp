#include <string>

using namespace std;

class Customer {
public:
    Customer() = default;
    Customer(const Customer&);
    Customer& operator=(const Customer&);
private:
    string address;
    string phone;
    int *p = nullptr;
};

Customer::Customer(const Customer &rhs) {
    address = rhs.address;
    phone = rhs.phone;
    p = rhs.p;
}

Customer& Customer::operator=(const Customer &rhs) {
    address = rhs.address;
    phone = rhs.phone;
    int *tmp = p;
    p = rhs.p;
    delete tmp;
    return *this;
}

class PriorityCustomer: public Customer {
public:
    PriorityCustomer(): Customer(), priority(0) {}
    PriorityCustomer(const PriorityCustomer &rhs):
        Customer(rhs), priority(rhs.priority) {}
    PriorityCustomer& operator=(const PriorityCustomer &rhs) {
        Customer::operator=(rhs);
        priority = rhs.priority;
        return *this;
    }
private:
    int priority;
};

int main() {
    PriorityCustomer pc;
    PriorityCustomer pc2(pc);
    pc2 = pc;
}
