#include "calcWindow.h"
#include <iostream>

calcWindow::calcWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder> refBuilder) : 
Gtk::Window{cobject},
builder{refBuilder},
mainDisplay{Gtk::Builder::get_widget_derived<calcDisplay>(refBuilder, "mainDisplay")} {

    // Attaching widgets to pointers using the builder:
    offButton = builder->get_widget<Gtk::Button>("offButton");
    // Digit buttons:
    zeroButton = builder->get_widget<Gtk::Button>("zeroButton");
    oneButton = builder->get_widget<Gtk::Button>("oneButton");
    twoButton = builder->get_widget<Gtk::Button>("twoButton");
    threeButton = builder->get_widget<Gtk::Button>("threeButton");
    fourButton = builder->get_widget<Gtk::Button>("fourButton");
    fiveButton = builder->get_widget<Gtk::Button>("fiveButton");
    sixButton = builder->get_widget<Gtk::Button>("sixButton");
    sevenButton = builder->get_widget<Gtk::Button>("sevenButton");
    eightButton = builder->get_widget<Gtk::Button>("eightButton");
    nineButton = builder->get_widget<Gtk::Button>("nineButton");
    decimalButton = builder->get_widget<Gtk::Button>("decimalButton");
    // Operation buttons:
    clearAllButton = builder->get_widget<Gtk::Button>("clearAllButton");
    divideButton = builder->get_widget<Gtk::Button>("divideButton");
    multiplyButton = builder->get_widget<Gtk::Button>("multiplyButton");
    subtractButton = builder->get_widget<Gtk::Button>("subtractButton");
    addButton = builder->get_widget<Gtk::Button>("addButton");
    rootButton = builder->get_widget<Gtk::Button>("rootButton");
    percentButton = builder->get_widget<Gtk::Button>("percentButton");
    memoryRecallButton = builder->get_widget<Gtk::Button>("memoryRecallButton");
    memorySubtractButton = builder->get_widget<Gtk::Button>("memorySubtractButton");
    memoryAddButton = builder->get_widget<Gtk::Button>("memoryAddButton");
    equalsButton = builder->get_widget<Gtk::Button>("equalsButton");

    // Attaching listeners to buttons:
    offButton->signal_clicked().connect(sigc::mem_fun(*this, &calcWindow::onClickOffButton));
    // Digit buttons:
    zeroButton->signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &calcWindow::onClickDigitButton), 0));
    oneButton->signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &calcWindow::onClickDigitButton), 1));
    twoButton->signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &calcWindow::onClickDigitButton), 2));
    threeButton->signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &calcWindow::onClickDigitButton), 3));
    fourButton->signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &calcWindow::onClickDigitButton), 4));
    fiveButton->signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &calcWindow::onClickDigitButton), 5));
    sixButton->signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &calcWindow::onClickDigitButton), 6));
    sevenButton->signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &calcWindow::onClickDigitButton), 7));
    eightButton->signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &calcWindow::onClickDigitButton), 8));
    nineButton->signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &calcWindow::onClickDigitButton), 9));
    decimalButton->signal_clicked().connect(sigc::mem_fun(*this, &calcWindow::onClickDecimalButton));
    // Operation buttons:
    clearAllButton->signal_clicked().connect(sigc::mem_fun(*this, &calcWindow::onClickClearAllButton));
    divideButton->signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &calcWindow::onClickOperationButton), DIVIDE));
    multiplyButton->signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &calcWindow::onClickOperationButton), MULTIPLY));
    subtractButton->signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &calcWindow::onClickOperationButton), SUBTRACT));
    addButton->signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &calcWindow::onClickOperationButton), ADD));
    rootButton->signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &calcWindow::onClickOperationButton), ROOT));
    percentButton->signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &calcWindow::onClickOperationButton), PERCENT));
    memoryRecallButton->signal_clicked().connect(sigc::mem_fun(*this, &calcWindow::onClickMemoryRecallButton));
    memorySubtractButton->signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &calcWindow::onClickMemoryAddButton), true));
    memoryAddButton->signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &calcWindow::onClickMemoryAddButton), false));
    equalsButton->signal_clicked().connect(sigc::mem_fun(*this, &calcWindow::onClickEqualsButton));
}

void calcWindow::onClickOffButton() {
    hide();
}

void calcWindow::onClickDigitButton(float number) {
    mainDisplay->insertDigit(number);
}

void calcWindow::onClickDecimalButton() {
    mainDisplay->inputDecimal();
};

void calcWindow::onClickClearAllButton() {
    mainDisplay->clearAll();
}

void calcWindow::onClickOperationButton(operation oper) {
    mainDisplay->selectOperation(oper);
}

void calcWindow::onClickMemoryRecallButton() {
    mainDisplay->recallMemory();
}

void calcWindow::onClickMemoryAddButton(bool negative) {
    mainDisplay->addToMemory(negative);
}

void calcWindow::onClickEqualsButton() {
    mainDisplay->evaluate();
}

calcWindow::~calcWindow() {

}