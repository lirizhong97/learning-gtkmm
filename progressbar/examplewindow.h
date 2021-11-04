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
  void on_checkbutton_text();
  void on_checkbutton_activity();
  void on_checkbutton_orientation();
  virtual bool on_timeout();
  void on_button_close();

  //Child widgets:
  Gtk::VBox m_VBox;
  Gtk::Alignment m_Alignment;
  Gtk::Table m_Table;
  Gtk::ProgressBar m_ProgressBar;
  Gtk::HSeparator m_Separator;
  Gtk::CheckButton m_CheckButton_Text, m_CheckButton_Activity, m_CheckButton_Inverted;
  Gtk::Button m_Button_Close;

  sigc::connection m_connection_id_timeout;
  bool m_bActivityMode;
};

#endif //GTKMM_EXAMPLEWINDOW_H
