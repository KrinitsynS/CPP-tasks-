#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream inputFile("input.txt");
    std::string line;

    if (inputFile.is_open()) {
        while (std::getline(inputFile, line)) {
            std::cout << line << std::endl;  // Печать содержимого файла на экран
        }
        inputFile.close();
    } else {
        std::cerr << "Не удалось открыть файл input.txt" << std::endl;
    }

    return 0;
}
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");
    std::string line;

    if (inputFile.is_open() && outputFile.is_open()) {
        while (std::getline(inputFile, line)) {
            outputFile << line << std::endl;  // Запись содержимого файла в файл output.txt
        }
        inputFile.close();
        outputFile.close();
        std::cout << "Содержимое файла input.txt успешно записано в файл output.txt" << std::endl;
    } else {
        std::cerr << "Не удалось открыть файл input.txt или создать файл output.txt" << std::endl;
    }

    return 0;
}
