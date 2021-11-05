#include "helloworld.h"
#include <gtkmm.h>
#include <iostream>

using namespace std;

/*
g++ -g main.cc helloworld.cc `pkg-config --cflags --libs gtkmm-3.0` -o example
*/
int main (int argc, char *argv[])
{
  Gtk::Main kit(argc, argv);

  HelloWorld helloworld;
  //Shows the window and returns when it is closed.
  Gtk::Main::run(helloworld);

  return 0;
}
