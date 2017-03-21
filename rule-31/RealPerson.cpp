#include "person.h"
#include <string>
#include <memory>

class RealPerson : public Person {
public:
    RealPerson(const std::string& name, const std::string& birthday,
            const std::string& addr)
        : theName(name), theBirthDate(birthday), theAddress(addr) {
        }
    ~RealPerson() {}
    std::string name() const { return theName; }
    std::string birthDate() const { return theBirthDate; }
    std::string address() const { return theAddress; }
    
private:
    std::string theName;
    std::string theBirthDate;
    std::string theAddress;
};

std::shared_ptr<Person> Person::create(const std::string& name,
                                        const std::string& birthday,
                                        const std::string& addr) {
    return std::make_shared<RealPerson>(name, birthday, addr);
}

int main() {
    auto p = Person::create("jason", "1993/2/3", "Nanjing");

    return 0;
}
