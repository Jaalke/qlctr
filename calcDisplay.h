#ifndef CALC_ENTRY_H
#define CALC_ENTRY_H
#include <gtkmm.h> 

// These two enums track the internal state of the calculator: what operation has been selected
// and if the first operand has already been inserted. In effect, they determine what happens 
// when the '=' button is pressed. Cycle currently has only two options, but it's kept as an enum 
// for future need.

enum cycle {
    FIRST_OPERAND,
    SECOND_OPERAND
};

enum operation {
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE,
    ROOT,
    PERCENT
};

class calcDisplay : public Gtk::Entry {
    Glib::RefPtr<Gtk::Builder> mBuilder;
    Glib::RefPtr<Gtk::EntryBuffer> calcBuffer;
    long double operandOne{0};
    long double operandTwo{0};
    long double operandMemory{0};
    bool inputtingDecimal{false};
    int significantDigit{1};
    cycle currentCycle;
    operation currentOperation;
    void updateDisplay();

public:
    calcDisplay(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder> refBuilder);
    virtual ~calcDisplay();
    void evaluate();
    void insertDigit(float digit);
    void inputDecimal();
    void clearAll();
    void selectOperation(operation oper);
    void recallMemory();
    void addToMemory(bool negative = false);
};

#endif