You are given 4 registers A, B, C, D. All 4 registers have a `value`  associated to them. We are given some functionalities that are need to be implemented for these registers.
1. Set(register(string), value(int)) ->  set the value of input register to the new input value.
2. Inc(register(string)) - increment the register value by 1.
3. Move(register1(string), register2(string)) -> copy value of register2 to register1.
4. Dec(register(string)) -> decrement value of register by 1.
5. AddR(register1(string), register2(string), value) -> Add value of register1 and register2 and update register1 value equal to the new value.

Input command:
SET A 25
MOVE A B

Basically the question is to implement a dummy microprocessor with above functionalies.
