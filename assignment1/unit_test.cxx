#include <cmath>
#include "utest.h"
#include "functions.cxx"


// int test(int argc, const char *const argv[]) {
//     auto f = [](double x) -> double {
//         return x;
//     };
//     ASSERT_EQ(asiAlgo(f, 0, 1, pow(10,-2)), 0.5);
//     return utest_main(argc, argv);
// }

UTEST_MAIN();


UTEST(SimpsonTest, SimpleIntegration) {
    auto f = [](double x) -> double {
        return x;
    };
    ASSERT_EQ(asiAlgo(f, 0, 1, pow(10,-2)), 0.5);
}

UTEST(SimpsonTest, InvalidTau){
    auto f = [](double x) -> double {
        return x;
    };
    ASSERT_EXCEPTION(asiAlgo(f, 0, 1, 0), std::exception);
}