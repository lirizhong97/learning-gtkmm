#include "examplewindow.h"
#include <gtkmm/main.h>
#include <iostream>
#include <cstdlib>

using std::atoi;

/*
g++ -g examplewindow.cc packbox.cc main.cc `pkg-config --cflags --libs gtkmm-3.0` -o example
*/
int main(int argc, char *argv[])
{
  Gtk::Main main_instance(argc, argv);

  if(argc != 2)
  {
    std::cerr << "usage: packbox num, where num is 1, 2, or 3." << std::endl;
    return 1;
  }

  ExampleWindow window( atoi(argv[1]) );
  Gtk::Main::run(window); //Shows the window and returns when it is closed.

  return 0;
}