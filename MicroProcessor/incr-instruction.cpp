#include <iostream>
#include "instruction.cpp"
#include "register.cpp"

using namespace std;

class IncrInstruction : public Instruction {
    private:
        Registr* reg;

    public:
        IncrInstruction(Registr* reg) {
            this->reg = reg;
        }

        void executeInstruction() {
            this->reg->setValue(this->reg->getValue() + 1);
        }
};
