#include "unity_fixture.h"

static void runAllTests() {
    RUN_TEST_GROUP(test_chef);
}

int main() {
    int argc = 1;
    const char* argv = "main -v";
    return UnityMain(argc, &argv, &runAllTests);
}
