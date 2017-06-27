#include "numToWords.h"

namespace acs {

    numToWords::numToWords() {
    }

    numToWords::numToWords(const numToWords& orig) {
    }

    numToWords::~numToWords() {
    }

    std::string numToWords::words(uint64_t n) {
        std::string res;

        if (n <= 13) {
            res = std::string(this->numsSmallerThan14[n]);
        } else if (n < 20) {
            n -= 10;
            res = std::string(this->numsSmallerThan14[n]).append("teen");
        } else if (n < 100) {
            int tens = (n / 10);
            int unit = n - (tens * 10);

            //to get the correct key in the array I need to take 2
            res = std::string(this->tens[tens - 2]);

            if (unit > 0) {
                res.append("-").append(this->numsSmallerThan14[unit]);
            }
        } else if (n < 1000) {
            int hundreds = (n / 100);
            int tens = n - (hundreds * 100);
            res.append(this->numsSmallerThan14[hundreds]).append(" hundred");

            if (tens > 0) {
                res.append(" ").append(this->words(tens));
            }
        }

        return res;
    }
}