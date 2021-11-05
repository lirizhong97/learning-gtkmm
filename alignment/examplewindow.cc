#include "examplewindow.h"

ExampleWindow::ExampleWindow()
: m_Alignment(Gtk::ALIGN_END, Gtk::ALIGN_CENTER, 0.0, 0.0),
  m_Button("Close")
{
  set_title("Gtk::Alignement");
  set_border_width(10);
  set_default_size(200, 50);

  add(m_Alignment);

  m_Alignment.add(m_Button);

  m_Button.signal_clicked().connect( sigc::mem_fun(*this,
              &ExampleWindow::on_button_clicked) );

  show_all_children();
}

ExampleWindow::~ExampleWindow()
{
}

void ExampleWindow::on_button_clicked()
{
  hide();
}
