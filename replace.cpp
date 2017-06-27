#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

//http://stackoverflow.com/a/3418285/8715
size_t replace(std::string &str, const std::string &from, const std::string &to, std::size_t start_pos = 0) {
    std::size_t pos = str.find(from, start_pos);

    if (pos == std::string::npos) {
        return std::string::npos;
    }

    str.replace(pos, from.length(), to);
    return pos;
}

void replaceAll(std::string &str, const std::string &from, const std::string &to, std::size_t start_pos = 0) {
    std::size_t res;

    while ((res = replace(str, from, to, start_pos)) != std::string::npos) {
        start_pos += to.length();
    }
}

int main(int argc, char** argv) {
    string test = "addassdaasdasd aaas {{PROGRAM}} 111111 {{PROGRAM}} asdasdasdasdasasd asdasd {{PROGRAM}} {{PROGRAM}}";
    string test2 = "addassdaasdasd aaas {{PROGRAM}} 111111 {{PROGRAM}} asdasdasdasdasasd asdasd {{PROGRAM}} {{PROGRAM}}";
    string replace_word = "{{PROGRAM}}";
    string replace_value = "hello";

    printf("Original: %s\n", test.c_str());

    //replace(test, replace_word, replace_value);
    //printf("Value: %s\n", test.c_str());       

    replaceAll(test2, replace_word, replace_value);
    printf("Value: %s\n", test2.c_str());

    return 0;
}

