#include "outputParser.h"
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
    updateDisplay();

}

void calcDisplay::updateDisplay() {
    if (currentCycle == FIRST_OPERAND) {
        calcBuffer->set_text(trailingZeroesToSpaces(std::to_string(operandOne)));
    } else {
        calcBuffer->set_text(trailingZeroesToSpaces(std::to_string(operandTwo)));
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
        default:
            return;
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
    if (oper == ROOT) {
        if (currentCycle == FIRST_OPERAND) {
            operandOne = std::sqrt(operandOne);
        } else {
            operandTwo = std::sqrt(operandTwo);
        }
        updateDisplay();
        return;
    } else if (oper == PERCENT) {
        if (currentCycle == FIRST_OPERAND) {
            return;
        } else {
            operandTwo = (operandOne * (operandTwo / 100));
            updateDisplay();
            return;
        }
        return;
    } else if (currentCycle == SECOND_OPERAND) {
        evaluate();
    } else {
        currentCycle = SECOND_OPERAND;
        inputtingDecimal = false;
        significantDigit = 1;
    }
    currentOperation = oper;
}

void calcDisplay::recallMemory() {
    if (currentCycle == FIRST_OPERAND) {
        operandOne = operandMemory;
    } else {
        operandTwo = operandMemory;
    }
    updateDisplay();
}

void calcDisplay::addToMemory(bool negative) {
    if (negative) {
        if (currentCycle == FIRST_OPERAND) {
            operandMemory -= operandOne;
        } else {
            operandMemory -= operandTwo;
        }
    } else {
        if (currentCycle == FIRST_OPERAND) {
            operandMemory += operandOne;
        } else {
            operandMemory -= operandTwo;
        }
    }
}

calcDisplay::~calcDisplay() {

}