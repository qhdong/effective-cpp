class UnCopyable {
protected:
    UnCopyable() = default;
    ~UnCopyable() = default;
private:
    UnCopyable(const UnCopyable&);
    UnCopyable& operator=(const UnCopyable&);
};

class HomeForSale: private UnCopyable {
public:
    HomeForSale() = default;
    ~HomeForSale() = default;
};

int main() {
    HomeForSale a;
    HomeForSale b;
    b = a;

    return 0;

}
