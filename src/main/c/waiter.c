#include "waiter.h"
#include "chef.h"

unsigned int waiterMakeOrder(const char* name) {
    unsigned int sum = chefMakeOrder(name);
    return sum;
}
