class Uncopyable {
protected:
    Uncopyable() = default;
    ~Uncopyable() = default;
private:
    Uncopyable(const Uncopyable&);
    Uncopyable& operator=(const Uncopyable&);
};
