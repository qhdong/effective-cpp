#include <vector>

using std::vector;

int main() {
    vector<int> vec{1, 2, 3, 4};

    const vector<int>::iterator it = vec.begin();
    *it = 2;
    // ++it;

    vector<int>::const_iterator cit = vec.begin();
    ++cit;
    // *cit = 2;

    return 0;
}
