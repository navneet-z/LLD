#include <iostream>
#include "instruction.cpp"
#include "register.cpp"

using namespace std;

class SetInstruction : public Instruction {
    private:
        Registr* reg;
        int val;

    public:
        SetInstruction(Registr* reg, int val) {
            this->reg = reg;
            this->val = val;
        }

        void executeInstruction() {
            this->reg->setValue(this->val);
        }
};
