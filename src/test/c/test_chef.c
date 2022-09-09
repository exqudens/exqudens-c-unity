#include <string.h>
#include <stdio.h>

#include <unity_fixture.h>

#include "chef.h"

extern unsigned int __real_chefMakeOrder(const char* name);

unsigned int __wrap_chefMakeOrder(const char* name) {
    printf("call: %s\n", __FUNCTION__);
    if (strcmp("burger", name) == 0) {
        return 7;
    } else {
        return __real_chefMakeOrder(name);
    }
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

TEST(test_chef, test2) {
    unsigned int sum = chefMakeOrder("burger");
    TEST_ASSERT_EQUAL(7, sum);
}

TEST_GROUP_RUNNER(test_chef) {
    RUN_TEST_CASE(test_chef, test1);
    RUN_TEST_CASE(test_chef, test2);
}
