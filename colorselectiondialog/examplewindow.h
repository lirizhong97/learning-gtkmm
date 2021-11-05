#ifndef GTKMM_EXAMPLEWINDOW_H
#define GTKMM_EXAMPLEWINDOW_H

#include <gtkmm.h>

class ExampleWindow : public Gtk::Window
{
public:
  ExampleWindow();
  virtual ~ExampleWindow();

protected:
  //Signal handlers:
  void on_button_color_set();

  //Child widgets:
  Gtk::VBox m_VBox;
  Gtk::ColorButton m_Button;
  Gtk::DrawingArea m_DrawingArea; //To show the color.

  Gdk::RGBA m_Color;
};

#endif //GTKMM_EXAMPLEWINDOW_H
