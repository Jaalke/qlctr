#ifndef CALC_WINDOW_H
#define CALC_WINDOW_H
#include <gtkmm.h>
#include "calcDisplay.h"

class calcWindow : public Gtk::Window {
    Glib::RefPtr<Gtk::Builder> builder;
    calcDisplay* mainDisplay;
    Gtk::Button* offButton{nullptr};
    Gtk::Button* zeroButton{nullptr};
    Gtk::Button* oneButton{nullptr};
    Gtk::Button* twoButton{nullptr};
    Gtk::Button* threeButton{nullptr};
    Gtk::Button* fourButton{nullptr};
    Gtk::Button* fiveButton{nullptr};
    Gtk::Button* sixButton{nullptr};
    Gtk::Button* sevenButton{nullptr};
    Gtk::Button* eightButton{nullptr};
    Gtk::Button* nineButton{nullptr};
    Gtk::Button* decimalButton{nullptr};
    Gtk::Button* clearAllButton{nullptr};
    Gtk::Button* divideButton{nullptr};
    Gtk::Button* multiplyButton{nullptr};
    Gtk::Button* subtractButton{nullptr};
    Gtk::Button* addButton{nullptr};
    Gtk::Button* equalsButton{nullptr};
protected:
    void onClickOffButton();
    void onClickDigitButton(float number);
    void onClickDecimalButton();
    void onClickClearAllButton();
    void onClickOperationButton(operation oper);
    void onClickEqualsButton();

public:
    calcWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder> refBuilder);
    virtual ~calcWindow();
    
};

#endif