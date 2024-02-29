#include <iostream>
#include "instruction.cpp"
#include "register.cpp"

using namespace std;

class RstInstruction : public Instruction {
    private:
        vector<Registr*> registers;

    public:
        RstInstruction(vector<Registr*> registers) {
            this->registers = registers;
        }

        void executeInstruction() {
            for (Registr* reg : this->registers) {
                reg->setValue(0);
            }
        }
};
