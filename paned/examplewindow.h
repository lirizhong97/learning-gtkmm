#ifndef GTKMM_EXAMPLEWINDOW_H
#define GTKMM_EXAMPLEWINDOW_H

#include "messageslist.h"
#include "messagetext.h"
#include <gtkmm.h>

using namespace std;

class ExampleWindow : public Gtk::Window
{
public:
  ExampleWindow();
  virtual ~ExampleWindow();

protected:

  //Child widgets:
  Gtk::VPaned m_VPaned;
  MessagesList m_MessagesList;
  MessageText m_MessageText;
};

#endif //GTKMM_EXAMPLEWINDOW_H