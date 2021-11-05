#include "examplewindow.h"
#include <gtkmm/stock.h>
#include <iostream>

ExampleWindow::ExampleWindow()
: m_Label("Right-click to see the popup menu."),
  m_pMenuPopup(0)
  /* m_Image(Gtk::Stock::DIALOG_QUESTION, Gtk::ICON_SIZE_MENU) */
{
  set_title("popup example");
  set_default_size(200, 200);

  add(m_Box);

  //Add an event box that can catch button_press events:
  m_Box.pack_start(m_EventBox);
  m_EventBox.signal_button_press_event().connect(sigc::mem_fun(*this,
              &ExampleWindow::on_button_press_event) );

  m_EventBox.add(m_Label);

  //Create actions:

  //Fill menu:

  m_refActionGroup = Gtk::ActionGroup::create();

  //File|New sub menu:
  //These menu actions would normally already exist for a main menu, because a
  //context menu should not normally contain menu items that are only available
  //via a context menu.
  m_refActionGroup->add(Gtk::Action::create("ContextMenu", "Context Menu"));

  m_refActionGroup->add(Gtk::Action::create("ContextEdit", "Edit"),
          sigc::mem_fun(*this, &ExampleWindow::on_menu_file_popup_generic));

  m_refActionGroup->add(Gtk::Action::create("ContextProcess", "Process"),
          Gtk::AccelKey("<control>P"),
          sigc::mem_fun(*this, &ExampleWindow::on_menu_file_popup_generic));

  m_refActionGroup->add(Gtk::Action::create("ContextRemove", "Remove"),
          sigc::mem_fun(*this, &ExampleWindow::on_menu_file_popup_generic));

  //TODO:
  /*
    //Add a ImageMenuElem:
    menulist.push_back( Gtk::Menu_Helpers::ImageMenuElem("_Something", m_Image,
      sigc::mem_fun(*this, &ExampleWindow::on_menu_file_popup_generic) ) ) ;
  */

  m_refUIManager = Gtk::UIManager::create();
  m_refUIManager->insert_action_group(m_refActionGroup);

  add_accel_group(m_refUIManager->get_accel_group());

  //Layout the actions in a menubar and toolbar:
  Glib::ustring ui_info =
        "<ui>"
        "  <popup name='PopupMenu'>"
        "    <menuitem action='ContextEdit'/>"
        "    <menuitem action='ContextProcess'/>"
        "    <menuitem action='ContextRemove'/>"
        "  </popup>"
        "</ui>";

  try
  {
    m_refUIManager->add_ui_from_string(ui_info);
  }
  catch(const Glib::Error& ex)
  {
    std::cerr << "building menus failed: " <<  ex.what();
  }

  //Get the menu:
  m_pMenuPopup = dynamic_cast<Gtk::Menu*>(
          m_refUIManager->get_widget("/PopupMenu")); 
  if(!m_pMenuPopup)
    g_warning("menu not found");

  show_all_children();
}

ExampleWindow::~ExampleWindow()
{
}

void ExampleWindow::on_menu_file_popup_generic()
{
   std::cout << "A popup menu item was selected." << std::endl;
}

bool ExampleWindow::on_button_press_event(GdkEventButton* event)
{
  if( (event->type == GDK_BUTTON_PRESS) && (event->button == 3) )
  {
    if(m_pMenuPopup)
      m_pMenuPopup->popup(event->button, event->time);

    return true; //It has been handled.
  }
  else
    return false;
}