#include <iostream>
#include "examplewindow.h"

ExampleWindow::ExampleWindow()
: m_Label1("Contents of tab 1"),
  m_Label2("Contents of tab 2"),
  m_Button_Quit("Quit")
{
  set_title("Gtk::Notebook example");
  set_border_width(10);
  set_default_size(400, 200);


  add(m_VBox);

  //Add the Notebook, with the button underneath:
  m_Notebook.set_border_width(10);
  m_VBox.pack_start(m_Notebook);
  m_VBox.pack_start(m_ButtonBox, Gtk::PACK_SHRINK);

  m_ButtonBox.pack_start(m_Button_Quit, Gtk::PACK_SHRINK);
  m_Button_Quit.signal_clicked().connect(sigc::mem_fun(*this,
              &ExampleWindow::on_button_quit) );

  //Add the Notebook pages:
  m_Notebook.append_page(m_Label1, "First");
  m_Notebook.append_page(m_Label2, "Second");

  m_Notebook.signal_switch_page().connect(sigc::mem_fun(*this,
              &ExampleWindow::on_notebook_switch_page) );

  show_all_children();
}

ExampleWindow::~ExampleWindow()
{
}

void ExampleWindow::on_button_quit()
{
  hide();
}

void ExampleWindow::on_notebook_switch_page(Gtk::Widget* /* page */, guint page_num)
{
  std::cout << "Switched to tab with index " << page_num << std::endl;

  //You can also use m_Notebook.get_current_page() to get this index.
}