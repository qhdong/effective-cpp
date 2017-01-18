#ifndef _HOME_FOR_SALE_H_
#define _HOME_FOR_SALE_H_

#include "uncopyable.h"

class HomeForSale: private Uncopyable {
public:
    HomeForSale() = default;

    HomeForSale copy();
private:
    HomeForSale(const HomeForSale&);
    HomeForSale& operator=(const HomeForSale&);
};

HomeForSale HomeForSale::copy() {
    HomeForSale temp = *this;
    return temp;
};

#endif
