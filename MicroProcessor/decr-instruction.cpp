#include <iostream>
#include "instruction.cpp"
#include "register.cpp"

using namespace std;

class DecrInstruction : public Instruction {
    private:
        Registr* reg;

    public:
        DecrInstruction(Registr* reg) {
            this->reg = reg;
        }

        void executeInstruction() {
            this->reg->setValue(this->reg->getValue() - 1);
        }
};
