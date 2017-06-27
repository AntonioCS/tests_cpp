#include <iostream>
#include <cstdint>
#include <string>

#ifndef NUMTOWORDS_H
#define NUMTOWORDS_H
namespace acs {

    class numToWords {
    private:
        const char *numsSmallerThan14[14] = {
            "zero", "one", "two",
            "three", "four", "five",
            "six", "seven", "eight", "nine",
            "ten", "eleven", "twelve", "thirteen"
        };

        const char *tens[8] = {
            "twenty", "thirty", "forty", "fifty",
            "sixty", "seventy", "eighty", "ninety"
        };
    public:
        numToWords();
        numToWords(const numToWords &orig);
        virtual ~numToWords();
        std::string words(uint64_t n);

    };
}
#endif /* NUMTOWORDS_H */

