#ifndef PERSON_H_
#define PERSON_H_

#include <string>
#include <memory>

class Person {
public:
    virtual ~Person() = 0;
    virtual std::string name() const = 0;
    virtual std::string birthDate() const = 0;
    virtual std::string address() const = 0;

    static std::shared_ptr<Person> create(
            const std::string& name,
            const std::string& birthday,
            const std::string& addr);
};


#endif
