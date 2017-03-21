#include <iostream>

using namespace std;

class Airport{
};

class Airplane {
public:
    virtual void fly(const Airport& destination) const = 0;
    int objectID() const;
};

void Airplane::fly(const Airport& destination) const {
    cout << "default fly method" << endl;
}

class ModelA: public Airplane {
public:
    void fly(const Airport& destination) const override {
        Airplane::fly(destination);
    }
};

class ModelB: public Airplane {
public:
    void fly(const Airport& destination) const override {
        cout << "Model B new method" << endl;
    }
};

int main() {
    Airport NK;
    ModelA a;
    ModelB b;
    a.fly(NK);
    b.fly(NK);

    return 0;
    
}
