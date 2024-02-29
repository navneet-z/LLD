#include <iostream>
#include "my-bits.h"
// #include "instruction.cpp"
#include "string-util.cpp"
#include <stdexcept>
#include "micro-processor.cpp"
#include "add-instruction.cpp"
#include "adr-instruction.cpp"
#include "set-instruction.cpp"
#include "mov-instruction.cpp"
#include "incr-instruction.cpp"
#include "decr-instruction.cpp"
#include "rst-instruction.cpp"

using namespace std;

class InstructionRegistry {
    private:
        map<string, Registr*> registers;
        Instruction* instruction;

    public:
        InstructionRegistry(map<string, Registr*> registers, string command) {
            this->registers = registers;
            vector<string> parsedCommand = parseCommand(command);
            if (parsedCommand.size() == 0) {
                throw invalid_argument("Invalid command");
            }

            this->setInstruction(parsedCommand);
        }

        vector<string> parseCommand(string command) {
            return (new StringUtil())->explode(command, ' ');
        }

        void setInstruction(vector<string> parsedCommand) {
            string method = parsedCommand[0];
            if (method == "ADD") {
                if (parsedCommand.size() != 3) {
                    throw invalid_argument("invalid ADD command");
                }

                Registr* registr = this->registers[parsedCommand[1]];
                int val = stoi(parsedCommand[2]);

                this->instruction = new AddInstruction(registr, val);
            } else if (method == "SET") {
                if (parsedCommand.size() != 3) {
                    throw invalid_argument("invalid SET command");
                }

                Registr* registr = this->registers[parsedCommand[1]];
                int val = stoi(parsedCommand[2]);

                this->instruction = new SetInstruction(registr, val);
            } else if (method == "ADR") {
                if (parsedCommand.size() != 3) {
                    throw invalid_argument("invalid ADR command");
                }

                Registr* registr1 = this->registers[parsedCommand[1]];
                Registr* registr2 = this->registers[parsedCommand[2]];

                this->instruction = new AdrInstruction(registr1, registr2);
            } else if (method == "MOV") {
                if (parsedCommand.size() != 3) {
                    throw invalid_argument("invalid MOV command");
                }

                Registr* registr1 = this->registers[parsedCommand[1]];
                Registr* registr2 = this->registers[parsedCommand[2]];

                this->instruction = new MovInstruction(registr1, registr2);
            } else if (method == "INR") {
                if (parsedCommand.size() != 2) {
                    throw invalid_argument("invalid INR command");
                }

                Registr* registr = this->registers[parsedCommand[1]];

                this->instruction = new IncrInstruction(registr);
            } else if (method == "DCR") {
                if (parsedCommand.size() != 2) {
                    throw invalid_argument("invalid DCR command");
                }

                Registr* registr = this->registers[parsedCommand[1]];

                this->instruction = new DecrInstruction(registr);
            } else if (method == "RST") {
                if (parsedCommand.size() != 1) {
                    throw invalid_argument("invalid RST command");
                }

                vector<Registr*> registers;
                for (auto it = this->registers.begin(); it != this->registers.end(); it++) {
                    registers.push_back(it->second);
                }

                this->instruction = new RstInstruction(registers);
            } else {
                throw invalid_argument("invalid method");
            }
        }

        Instruction* getInstruction() {
            return this->instruction;
        }
};
