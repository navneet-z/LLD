#pragma once
#include <iostream>
#include "my-bits.h"
// #include "micro-processor.cpp"
#include "register.cpp"

using namespace std;

class RegisterState {
    private:
        string regState;

    public:
        RegisterState(map<string, Registr*> registers) {
            string output = "";
            for (auto it = registers.begin(); it != registers.end(); it++) {
                output += "Registr name: ";
                output += it->first;
                output += " and value: ";
                output += to_string(it->second->getValue());
                output += ". ";
            }

            this->regState = output.substr(0, output.size() - 1);
        }

        string show() {
            return this->regState;
        }
};
