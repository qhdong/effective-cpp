class Rational {
    friend const Rational operator*(const Rational &lhs, const Rational &rhs);
public:
    Rational() = default;
    Rational(int x): x(x) {}
private:
    int x = 0;
};

const Rational operator*(const Rational &lhs, const Rational &rhs) {
    return Rational(lhs.x * rhs.x);
}

int main() {
    Rational a(1), b(2), c;
    // (a*b) = c;
}
