#include <iostream>
#include <cmath>
#include "functions.cxx"

int main(){
    int counter = 0;
    auto f = [](double x) -> double {
        return x + std::cos(pow(x, 5));
    };

    double result = asiAlgo(f, 0, M_PI, pow(10,-4), &counter);
    std::cout << result << std::endl;
    std::cout << counter << std::endl;
    counter = 0;
    result = asiAlgo(f, 0, M_PI, pow(10,-3), &counter);
    std::cout << result << std::endl;
    std::cout << counter << std::endl;
    counter = 0;
    result = asiAlgo(f, 0, M_PI, pow(10,-2), &counter);
    std::cout << result << std::endl;
    std::cout << counter << std::endl;
}
