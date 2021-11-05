#include "examplewindow.h"
#include <iostream>


ExampleWindow::ExampleWindow()
{
  set_title("Gtk::ColorButton example");
  set_default_size(200, 200);

  add(m_VBox);

  m_VBox.pack_start(m_Button, Gtk::PACK_SHRINK);
  m_Button.signal_color_set().connect(sigc::mem_fun(*this,
              &ExampleWindow::on_button_color_set) );

  //Set start color:
  m_Color.set_red(0);
  m_Color.set_blue(1);
  m_Color.set_green(0);
  m_Button.set_rgba(m_Color);

  m_DrawingArea.override_background_color(m_Color);

  m_VBox.pack_start(m_DrawingArea);

  show_all_children();
}

ExampleWindow::~ExampleWindow()
{
}

void ExampleWindow::on_button_color_set()
{
  //Store the chosen color, and show it:
  m_Color = m_Button.get_rgba();
  m_DrawingArea.override_background_color(m_Color);
}