#include <string>
#include <sstream>
#include <exception>

// Класс исключения bad_from_string
class bad_from_string : public std::exception {
private:
    std::string message;
public:
    bad_from_string(const std::string& message) : message(message) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

template<class T>
T from_string(const std::string& s) {
    std::istringstream iss(s);
    iss >> std::noskipws;

    T result;
    if (!(iss >> result) || !iss.eof()) {
        throw bad_from_string("Error: impossible to convert the string to the desired type!");
    }
    return result;
}
