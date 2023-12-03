#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class CSVReader {
private:
    std::vector<std::vector<int>> data;
    size_t rows;
    size_t cols;

public:
    CSVReader(const std::string& filename) {
        // Чтение файла
        std::ifstream file(filename);
        std::string line;

        // Разбиение строк на столбцы и преобразование в целые числа
        while (std::getline(file, line)) {
            std::vector<int> row;
            size_t pos = 0;
            while ((pos = line.find(',')) != std::string::npos) {
                row.push_back(std::stoi(line.substr(0, pos)));
                line.erase(0, pos + 1);
            }
            row.push_back(std::stoi(line));
            data.push_back(row);
        }

        rows = data.size();
        cols = (rows > 0) ? data[0].size() : 0;
    }

    // Метод для вывода данных в виде таблицы
    void printTable() {
        for (const auto& row : data) {
            for (const auto& value : row) {
                std::cout << std::to_string(value) + std::string(10 - std::to_string(value).size(), ' ') << " ";
            }
            std::cout << std::endl;
        }
    }
};
int main() {
    CSVReader reader("input.txt");
    reader.printTable();
    return 0;
}
