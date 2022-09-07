#include "customer.h"
#include "waiter.h"

unsigned int customerMakeOrder(unsigned char* name) {
    unsigned int sum = waiterMakeOrder("hotdog");
    return sum + ((unsigned int) ((float) sum * 0.25F));
}
