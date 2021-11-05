#ifndef GTKMM_EXAMPLEWINDOW_H
#define GTKMM_EXAMPLEWINDOW_H

#include <gtkmm.h>
#include "treeview_withpopup.h"

class ExampleWindow : public Gtk::Window
{
public:
  ExampleWindow();
  virtual ~ExampleWindow();

protected:
  //Signal handlers:
  void on_button_quit();

 

  //Child widgets:
  Gtk::VBox m_VBox;

  Gtk::ScrolledWindow m_ScrolledWindow;
  TreeView_WithPopup m_TreeView;

  Gtk::HButtonBox m_ButtonBox;
  Gtk::Button m_Button_Quit;
};

#endif //GTKMM_EXAMPLEWINDOW_H