#include <gtkmm.h>
#include <iostream>
#include "calcWindow.h"

namespace {

calcWindow* mainWindow{nullptr};
Gtk::Button* offButton{nullptr};
Glib::RefPtr<Gtk::Application> app;

void onAppActivate() {
    // Attempting to load the glade file and css file
    auto refBuilder = Gtk::Builder::create();
    auto cssProvider = Gtk::CssProvider::create();
    try {
        refBuilder->add_from_file("Desktop/Documents/Coding/qlctr/qlctr.glade");
        cssProvider->load_from_path("Desktop/Documents/Coding/qlctr/style.css");
    }
    catch(const Glib::FileError& ex) {
        std::cerr << "FileError: " << ex.what() << "\n";
        return;
    }
    catch(const Glib::MarkupError& ex) {
        std::cerr << "MarkupError: " << ex.what() << "\n";
        return;
    }
    catch(const Gtk::BuilderError& ex) {
        std::cerr << "BuilderError: " << ex.what() << "\n";
        return;
    }

    mainWindow = Gtk::Builder::get_widget_derived<calcWindow>(refBuilder, "mainWindow");
    offButton = refBuilder->get_widget<Gtk::Button>("offButton");

    // auto mainStyleContext = mainWindow->get_style_context();
    // auto offButtonStyleContext = offButton->get_style_context();
    // APPLYING STYLES
    // mainStyleContext->add_provider(cssProvider, GTK_STYLE_PROVIDER_PRIORITY_USER);

    app->add_window(*mainWindow);
    mainWindow->show();
}

}

int main(int argc, char* argv[]) {
    app = Gtk::Application::create("org.gtkmm.example");
    app->signal_activate().connect([] () { onAppActivate(); });

    return app->run(argc, argv);
}