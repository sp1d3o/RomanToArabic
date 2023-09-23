#include <iostream>
#include <map>
#include <set>
#include <string>

int romanToArabic(std::string roman) {
    std::map<char, int> romanToArabicMap;
    romanToArabicMap['I'] = 1;
    romanToArabicMap['V'] = 5;
    romanToArabicMap['X'] = 10;
    romanToArabicMap['L'] = 50;
    romanToArabicMap['C'] = 100;
    romanToArabicMap['D'] = 500;
    romanToArabicMap['M'] = 1000;

    int result = 0;
    int prevValue = 0;

    for (int i = roman.length() - 1; i >= 0; i--) {
        int currentValue = romanToArabicMap[roman[i]];

        if (currentValue < prevValue) {
            result -= currentValue;
        } else {
            result += currentValue;
        }

        prevValue = currentValue;
    }

    return result;
}

bool check_validity(std::string arg) {
    std::set<char> elements = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

    for (auto &it: arg) {
        if (elements.find(arg[it]) != elements.end()) {
            return true;
        }
    }

    return false;
}

int main(int argc, char *argv[])
{

   if(argc != 2) {
       std::cerr << "Wrong argument count, type [-h] or [--help] for more info" << std::endl;
   }

   if(argv[1] == "-h" || argv[1] == "--help" ) {
       std::cout << "Program to convert roman number to arabic." << std::endl;
       std::cout << "Usage: " << std::endl;
       std::cout << "./convert [roman number]" << std::endl;
   }

   if(argv[1] == "-p" || argv[1] == "--pos") {
       std::cout << "Input valid roman number in capital letters (xiv) is invalid input" << std::endl;
   }

   int res {0};

   if(check_validity(argv[1])) {
       res = romanToArabic(argv[1]);
   }

   else {
       std::cerr << "Invalid argument. Please see [-p] or [--pos] to see possible inputs" << std::endl;
   }

   std::cout << res << std::endl;

    return 0;
}