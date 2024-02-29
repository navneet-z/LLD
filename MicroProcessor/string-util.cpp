#include <iostream>
#include "my-bits.h"

using namespace std;

class StringUtil {
    public:
        vector<string> explode(string text, char del) {
            vector<string> explodedText;
            string currentWord = "";
            for (auto ch : text) {
                if (ch == del && currentWord != "") {
                    explodedText.push_back(currentWord);
                    currentWord = "";
                    continue;
                }
                currentWord += ch;
            }

            if (currentWord != "") {
                explodedText.push_back(currentWord);
            }

            return explodedText;
        }
};
