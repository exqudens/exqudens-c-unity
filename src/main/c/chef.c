#include "chef.h"

#include <string.h>

unsigned int chefMakeOrder(const char* name) {
    if (strcmp("hotdog", name) == 0) {
        return 5;
    } else {
        return 0;
    }
}
