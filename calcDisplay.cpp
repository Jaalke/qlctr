#include "calcDisplay.h"
#include <iostream>
#include <string>
#include <math.h>

calcDisplay::calcDisplay(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder> refBuilder) : 
Gtk::Entry{cobject},
mBuilder{refBuilder} {
    calcBuffer = get_buffer();
    currentCycle = FIRST_OPERAND;
    
    //Setting the display to 0 at start
    //to_string gives a lot of ugly zeroes with float values, to be fixed
    updateDisplay();

}

void calcDisplay::updateDisplay() {
    if (currentCycle == FIRST_OPERAND) {
        calcBuffer->set_text(std::to_string(operandOne));
    } else {
        calcBuffer->set_text(std::to_string(operandTwo));
    }
}

void calcDisplay::evaluate() {
    switch (currentOperation) {
        case DIVIDE:
            operandOne /= operandTwo;
            break;
        case MULTIPLY:
            operandOne *= operandTwo;
            break;
        case SUBTRACT:
            operandOne -= operandTwo; 
            break;
        case ADD:
            operandOne += operandTwo; 
            break;
    }
    currentCycle = FIRST_OPERAND;
    operandTwo = 0;
    inputtingDecimal = false;
    significantDigit = 1;
    updateDisplay();
}

void calcDisplay::insertDigit(float digit) {
    long double* currentOperand{nullptr};
    currentOperand = (currentCycle == FIRST_OPERAND) ? &operandOne : &operandTwo; 
    if (inputtingDecimal) {
        *currentOperand += (digit / pow(10, significantDigit));   
        significantDigit += 1;
    } else {
        *currentOperand *= 10;
        *currentOperand += digit;
    }

    updateDisplay();
}

void calcDisplay::inputDecimal() {
    inputtingDecimal = true;
}

void calcDisplay::clearAll() {
    operandOne = 0;
    operandTwo = 0;
    currentCycle = FIRST_OPERAND;
    inputtingDecimal = false;
    significantDigit = 1;
    updateDisplay();
}

void calcDisplay::selectOperation(operation oper) {
    if (currentCycle == SECOND_OPERAND) {
        evaluate();
    } else {
        currentCycle = SECOND_OPERAND;
        inputtingDecimal = false;
        significantDigit = 1;
    }
    currentOperation = oper;
}

calcDisplay::~calcDisplay() {

}