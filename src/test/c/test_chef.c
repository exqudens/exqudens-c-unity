#include "chef.h"

#include <unity_fixture.h>

unsigned int testChefMakeOrder() {
    uint16_t sum = chefMakeOrder("hotdog");

    if (sum != 5) {
        printf("ERROR sum: %d", sum);
        return 1;
    }

    return 0;
}

TEST_GROUP(test_chef);

TEST_SETUP(test_chef) {
}

TEST_TEAR_DOWN(test_chef) {
}

TEST(test_chef, test1) {
    unsigned int sum = chefMakeOrder("hotdog");
    TEST_ASSERT_EQUAL(5, sum);
}

TEST_GROUP_RUNNER(test_chef) {
    RUN_TEST_CASE(test_chef, test1);
}
