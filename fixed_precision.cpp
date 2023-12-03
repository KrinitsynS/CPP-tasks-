#include <iostream>
#include <fstream>
#include <iomanip>

int main() {
    std::ifstream inputFile("input.txt");

    if(inputFile.is_open()) {
        std::cout << std::setprecision(3) << std::fixed;

        double number;
        while(inputFile >> number) {
            std::cout << number << std::endl;
        }

        inputFile.close();
    } else {
        std::cerr << "Unable to open the file." << std::endl;
    }

    return 0;
}
