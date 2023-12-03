#include <iostream>
#include <sstream>
#include <string>

class numfilterbuf : public std::streambuf {
private:
    std::istream *in;
    std::ostream *out;
    char buffer[1];

protected:
    virtual int overflow(int c) override {
        if (c == traits_type::eof())
            return !traits_type::eof();
        char ch = traits_type::to_char_type(c);
        if (isdigit(ch) || isspace(ch)) {
            *buffer = ch;
            out->rdbuf()->sputn(buffer, 1);
        }
        return !traits_type::eof();
    }

    virtual int uflow() override {
        if (in->rdbuf()->sbumpc() == traits_type::eof())
            return traits_type::eof();
        return *buffer;
    }

    virtual int underflow() override {
        if ((cur = in->rdbuf()->sbumpc()) == traits_type::eof())
            return traits_type::eof();
        setg(buffer, buffer, buffer + 1);
        return cur;
    }
public:
    numfilterbuf(std::istream& _in, std::ostream &_out)
        : in(&_in), out(&_out), cur(traits_type::eof()) {
        setp(buffer, buffer + 1);
    }
};

int main(int argc, char **argv) {
    const char str1[] = "In 4 bytes contains 32 bits";
    const char str2[] = "Unix time starts from Jan 1, 1970";
    std::istringstream str(str1);
  
    numfilterbuf buf(str, std::cout);
    std::iostream numfilter(&buf);
  
    std::string val;
    std::getline(numfilter, val);
    numfilter.clear();

    std::cout << "Original: '" << str1 << "'" << std::endl;
    std::cout << "Read from numfilter: '" << val << "'" << std::endl;
  
    std::cout << "Original: '" << str2 << "'" << std::endl;
    std::cout << "Written to numfilter: '";
    numfilter << str2;
    std::cout << "'" << std::endl;
  
    return 0;
}
