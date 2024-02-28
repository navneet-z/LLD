#include <iostream>
#include "instruction.cpp"
#include "register.cpp"

using namespace std;

class AddInstruction : public Instruction {
    private:
        Register* reg1;
        Register* reg2;

    public:
        AddInstruction(Register* reg1, Register* reg2) {
            this->reg1 = reg1;
            this->reg2 = reg2;
        }

        void executeInstruction() {
            this->reg1->setValue(this->reg1->getValue() + this->reg2->getValue());
        }
};
