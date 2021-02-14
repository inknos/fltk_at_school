// hello.cxx (example1)
//
#include "barcode_program.cpp"

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>


#define GLOBAL_W 600

#define P_TOP 10
#define P_LEF 100

#define BOX_W GLOBAL_W
#define BOX_H 100

#define BTN_W GLOBAL_W
#define BTN_H 40

#define IOS_W GLOBAL_W
#define IOS_H 40

// https://www.fltk.org/doc-1.3/common.html

Fl_Box *box = new Fl_Box(
        P_LEF,
        P_TOP,
        BOX_W, BOX_H, "Is the barcode right?");

Fl_Input *input =  new Fl_Input(
        P_LEF,
        P_TOP*2 + BOX_H,
        IOS_W, IOS_H,
        "Enter Code:"
        );

Fl_Button *button = new Fl_Button(
        P_LEF,
        P_TOP*3 + BOX_H + IOS_H,
        BTN_W, BTN_H, "submit input");

Fl_Output *output =  new Fl_Output(
        P_LEF,
        P_TOP*4 + BOX_H + BTN_H + IOS_H,
        IOS_W, IOS_H, "Output"
        );


void click_enter_cb(
        Fl_Widget* w,
        void* pars) {
    Fl_Input * in = reinterpret_cast<Fl_Input*>(pars);
    bool valid = codiceValido(in->value());
    output->value(valid ? "valid" : "not valid");
    printf("%s is %s",
            in->value(),
            codiceValido(in->value()) ? "valid" : "not valid"
            );
}



int main(int argc, char **argv) {
    Fl_Window *window = new Fl_Window(
            GLOBAL_W + P_LEF * 3/2,
            P_TOP*6 + IOS_H*2 + BTN_H + BOX_H);

    box->box(FL_UP_BOX);
    box->labelsize(36);
    box->labelfont(FL_BOLD+FL_ITALIC);
    box->labeltype(FL_SHADOW_LABEL);

    button->type(FL_NORMAL_BUTTON);
    button->shortcut(FL_Enter);
    button->callback(click_enter_cb, input);

    window->add(box);
    window->add(input);
    window->add(output);
    window->add(button);

    window->end();
    window->show(argc, argv);
    return Fl::run();
}
