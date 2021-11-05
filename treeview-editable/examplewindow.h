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
  void on_button_quit();

  void treeviewcolumn_validated_on_cell_data(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter);
  void cellrenderer_validated_on_editing_started(Gtk::CellEditable* cell_editable, const Glib::ustring& path);
  void cellrenderer_validated_on_edited(const Glib::ustring& path_string, const Glib::ustring& new_text);

  //Tree model columns:
  class ModelColumns : public Gtk::TreeModel::ColumnRecord
  {
  public:

    ModelColumns()
    { add(m_col_id); add(m_col_name); add(m_col_foo); add(m_col_number); add(m_col_number_validated); }

    Gtk::TreeModelColumn<unsigned int> m_col_id;
    Gtk::TreeModelColumn<Glib::ustring> m_col_name;
    Gtk::TreeModelColumn<bool> m_col_foo;
    Gtk::TreeModelColumn<int> m_col_number;
    Gtk::TreeModelColumn<int> m_col_number_validated;
  };

  ModelColumns m_Columns;

  //Child widgets:
  Gtk::VBox m_VBox;

  Gtk::ScrolledWindow m_ScrolledWindow;
  Gtk::TreeView m_TreeView;
  Glib::RefPtr<Gtk::ListStore> m_refTreeModel;

  Gtk::HButtonBox m_ButtonBox;
  Gtk::Button m_Button_Quit;

  //For the validated column:
  //You could also use a CellRendererSpin or a CellRendererProgress:
  Gtk::CellRendererText m_cellrenderer_validated;
  Gtk::TreeView::Column m_treeviewcolumn_validated;
  bool m_validate_retry;
  Glib::ustring m_invalid_text_for_retry;
};

#endif //GTKMM_EXAMPLEWINDOW_H