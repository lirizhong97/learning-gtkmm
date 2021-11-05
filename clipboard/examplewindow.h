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
  void on_button_copy();
  void on_button_paste();
  void on_clipboard_text_received(const Glib::ustring& text);

  //Child widgets:
  Gtk::VBox m_VBox;

  Gtk::Label m_Label;
  
  Gtk::Table m_Table;
  Gtk::ToggleButton m_ButtonA1, m_ButtonA2, m_ButtonB1, m_ButtonB2;

  Gtk::HButtonBox m_ButtonBox;
  Gtk::Button m_Button_Copy, m_Button_Paste;
};

#endif //GTKMM_EXAMPLEWINDOW_H