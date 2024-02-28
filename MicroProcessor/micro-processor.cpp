#include <iostream>
#include <map>
#include "Register.cpp"
#include "Instruction.cpp"

using namespace std;

class MicroProcessor {
    private: 
        map<string, Register*> registers;

    public:
        void addRegister(string name) {
            registers[name] = new Register();
        }

        void removeRegister(string name) {
            registers.erase(name);
        }

        Register* getRegister(string name) {
            return registers[name];
        }

        void executeInstruction(Instruction* instruction) {
            instruction->executeInstruction();
        }
};
