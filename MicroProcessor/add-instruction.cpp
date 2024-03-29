#include <iostream>
#include "instruction.cpp"
#include "register.cpp"

using namespace std;

class AddInstruction : public Instruction {
    private:
        Registr* reg;
        int val;

    public:
        AddInstruction(Registr* reg, int val) {
            this->reg = reg;
            this->val = val;
        }

        void executeInstruction() {
            this->reg->setValue(this->reg->getValue() + this->val);
        }
};
