#include "examplewindow.h"
#include <gtkmm/stock.h>
#include <iostream>

ExampleWindow::ExampleWindow()
: m_Combo(true /* has_entry */)
{
  set_title("ComboBox example");

  //Create the Tree model:
  //m_refTreeModel = Gtk::TreeStore::create(m_Columns);
  m_refTreeModel = Gtk::ListStore::create(m_Columns);
  m_Combo.set_model(m_refTreeModel);

  //Fill the ComboBox's Tree Model:
  Gtk::TreeModel::Row row = *(m_refTreeModel->append());
  row[m_Columns.m_col_id] = "1";
  row[m_Columns.m_col_name] = "Billy Bob";
  /*
  Gtk::TreeModel::Row childrow = *(m_refTreeModel->append(row.children()));
  childrow[m_Columns.m_col_id] = 11;
  childrow[m_Columns.m_col_name] = "Billy Bob Junior";

  childrow = *(m_refTreeModel->append(row.children()));
  childrow[m_Columns.m_col_id] = 12;
  childrow[m_Columns.m_col_name] = "Sue Bob";
  */

  row = *(m_refTreeModel->append());
  row[m_Columns.m_col_id] = "2";
  row[m_Columns.m_col_name] = "Joey Jojo";


  row = *(m_refTreeModel->append());
  row[m_Columns.m_col_id] = "3";
  row[m_Columns.m_col_name] = "Rob McRoberts";

  /*
  childrow = *(m_refTreeModel->append(row.children()));
  childrow[m_Columns.m_col_id] = 31;
  childrow[m_Columns.m_col_name] = "Xavier McRoberts";
  */

  //Add the model columns to the Combo (which is a kind of view),
  //rendering them in the default way:
  //This is automatically rendered when we use set_entry_text_column().
  //m_Combo.pack_start(m_Columns.m_col_id);
  m_Combo.pack_start(m_Columns.m_col_name);

  m_Combo.set_entry_text_column(m_Columns.m_col_id);

  //Add the ComboBox to the window.
  add(m_Combo);

  //Connect signal handler:
  m_Combo.signal_changed().connect(sigc::mem_fun(*this,
              &ExampleWindow::on_combo_changed) );

  show_all_children();
}

ExampleWindow::~ExampleWindow()
{
}

void ExampleWindow::on_combo_changed()
{
  Gtk::Entry* entry = m_Combo.get_entry();
  //Note: to get changes only when the entry has been completed,
  //instead of on every key press, connect to Entry::signal_changed()
  //instead of ComboBoxEntry::signal_changed.

  if(entry)
  {
    std::cout << " ID=" << entry->get_text() << std::endl;
  }
}