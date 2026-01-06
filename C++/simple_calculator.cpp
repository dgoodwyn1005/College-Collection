#include <iostream>

int main() {
    int num1, num2;

    std::cout << "Enter the first number: ";
    std::cin >> num1;

    std::cout << "Enter the second number: ";
    std::cin >> num2;

    // Output the results
    std::cout << "The sum is: " << (num1 + num2) << std::endl;
    std::cout << "The difference is: " << (num1 - num2) << std::endl;
    std::cout << "The product is: " << (num1 * num2) << std::endl;
    std::cout << "The quotien is: " << (num1 / num2) << std::endl;

    return 0;
}