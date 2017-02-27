#include <string>
#include <cstring>

class TextBlock {
public:
    TextBlock() = default;
    TextBlock(const std::string &s) : text(s) {}
    char& operator[](size_t n);
    const char& operator[](size_t n) const { return text[n]; }
private:
    std::string text;
};

inline
char& TextBlock::operator[](size_t n) {
    return const_cast<char&>(static_cast<const TextBlock&>(*this)[n]);
}


class CTextBlock {
public:
    CTextBlock() = default;
    CTextBlock(const char *p);
    ~CTextBlock() { if(pText) delete[] pText; }
    char& operator[](size_t pos) const {return *(pText + pos); }
    std::size_t length() const;
private:
    char *pText = nullptr;
    mutable std::size_t textLength = 0;
    mutable bool lengthIsValid = false;
};

inline
CTextBlock::CTextBlock(const char *p) {
    pText = new char[std::strlen(p)];
    std::strcpy(pText, p);
}

inline
std::size_t CTextBlock::length() const {
    if (!lengthIsValid) {
        textLength = std::strlen(pText);
        lengthIsValid = true;
    }
    return textLength;
}

int main() {
    TextBlock tb("hello");
    const TextBlock ctb("hello");
    tb[0] = 'b';
    // ctb[0] = 'c';

    const CTextBlock cb("helo");
    // cb[0] = 'o';
    cb.length();
}
