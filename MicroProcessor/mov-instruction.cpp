#include <iostream>
#include "instruction.cpp"
#include "register.cpp"

using namespace std;

class MovInstruction : public Instruction {
    private:
        Registr* reg1;
        Registr* reg2;

    public:
        MovInstruction(Registr* reg1, Registr* reg2) {
            this->reg1 = reg1;
            this->reg2 = reg2;
        }

        void executeInstruction() {
            this->reg1->setValue(this->reg2->getValue());
        }
};
