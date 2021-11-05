#include "examplewindow.h"
#include <iostream>


ExampleWindow::ExampleWindow()
: m_Button("sans")
{
  set_title("Gtk::FontSelectionDialog example");

  add(m_Button);
  m_Button.signal_font_set().connect(sigc::mem_fun(*this,
              &ExampleWindow::on_button_font_set) );

  show_all_children();
}

ExampleWindow::~ExampleWindow()
{
}

void ExampleWindow::on_button_font_set()
{
  Glib::ustring font_name = m_Button.get_font_name();
  std::cout << "Font chosen: " << font_name << std::endl;
}