class TimeKeeper {
public:
    TimeKeeper() = default;
    virtual ~TimeKeeper() = 0;
};

TimeKeeper::~TimeKeeper() {}

class AtomicKeeper: public TimeKeeper {
};

int main() {
    TimeKeeper *t = new AtomicKeeper();
    delete t;
}
