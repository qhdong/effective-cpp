#include <utility>

using namespace std;

class Widget {
public:
    Widget() = default;
    Widget(const Widget&);
    Widget& operator=(Widget);
    void swap(Widget &rhs) {std::swap(p, rhs.p);}

private:
    int *p = nullptr;
};

Widget::Widget(const Widget &rhs) {
    p = rhs.p;
}

Widget& Widget::operator=(Widget rhs) {
    swap(rhs);
    return *this;
}

int main() {
    Widget w;
    Widget w2;
    w2 = w;
}
