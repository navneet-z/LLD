#include <iostream>
#include "micro-processor.cpp"
#include "instruction-registry.cpp"
#include "register-state.cpp"

using namespace std;

MicroProcessor* initMicroProcessor() {
    MicroProcessor* microProcessor = new MicroProcessor();
    microProcessor->addRegister("A");
    microProcessor->addRegister("B");
    microProcessor->addRegister("C");
    microProcessor->addRegister("D");

    return microProcessor;
}

int main() {
    MicroProcessor* microProcessor = initMicroProcessor();

    vector<string> commands = {"SET A 10","ADR C D","ADD A 12","MOV A B","INR C","DCR A","RST"};

    for (string command : commands) {
        Instruction* instruction = (new InstructionRegistry(microProcessor->getRegisters(), command))->getInstruction();
        instruction->executeInstruction();

        cout << (new RegisterState(microProcessor->getRegisters()))->show() << endl;
    }
}
