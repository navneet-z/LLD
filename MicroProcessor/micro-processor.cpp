#pragma once
#include <iostream>
#include <map>
#include "register.cpp"

using namespace std;

class MicroProcessor {
    private: 
        map<string, Registr*> registers;

    public:
        void addRegister(string name) {
            registers[name] = new Registr();
        }

        void removeRegister(string name) {
            registers.erase(name);
        }

        Registr* getRegister(string name) {
            return registers[name];
        }

        // void executeInstruction(Instruction* instruction) {
        //     instruction->executeInstruction();
        // }

        map<string, Registr*> getRegisters() {
            return registers;
        }
};
