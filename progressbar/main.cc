#include "examplewindow.h"
#include <gtkmm/main.h>

/* 
g++ -g main.cc examplewindow.cc `pkg-config --cflags --libs gtkmm-3.0` -o example 
*/
int main(int argc, char *argv[])
{
  Gtk::Main kit(argc, argv);

  ExampleWindow window;
  //Shows the window and returns when it is closed.
  Gtk::Main::run(window);

  return 0;
}
