#include <iostream>
#include "instruction.cpp"
#include "register.cpp"

using namespace std;

class AdrInstruction : public Instruction {
    private:
        Registr* reg1;
        Registr* reg2;

    public:
        AdrInstruction(Registr* reg1, Registr* reg2) {
            this->reg1 = reg1;
            this->reg2 = reg2;
        }

        void executeInstruction() {
            this->reg1->setValue(this->reg1->getValue() + this->reg2->getValue());
        }
};
