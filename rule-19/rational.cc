#include <iostream>

class Rational {
    friend const Rational operator*(const Rational& lhs, const Rational& rhs);
    friend std::ostream& operator<<(std::ostream& os, const Rational& rhs);
public:
    Rational(int n = 0, int d = 1) : n(n), d(d) {}
private:
    int n;
    int d;
};

const Rational operator*(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.n * rhs.n, lhs.d * rhs.d);
}

std::ostream& operator<<(std::ostream& os, const Rational& rhs) {
    os << rhs.n << " / " << rhs.d;
    return os;
}

int main() {
    Rational a(1, 3), b(2, 4);
    Rational c = a * b;
    // a * b = c;
    std::cout << c << "\n";
}
