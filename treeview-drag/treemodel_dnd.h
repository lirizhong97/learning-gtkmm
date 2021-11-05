#ifndef GTKMM_EXAMPLE_TREEMODEL_DND_H
#define GTKMM_EXAMPLE_TREEMODEL_DND_H

#include <gtkmm.h>

class TreeModel_Dnd : public Gtk::TreeStore
{
protected:
  TreeModel_Dnd();

public:

  //Tree model columns:
  class ModelColumns : public Gtk::TreeModel::ColumnRecord
  {
  public:

    ModelColumns()
    { add(m_col_id); add(m_col_name); add(m_col_draggable); add(m_col_receivesdrags); }

    Gtk::TreeModelColumn<int> m_col_id;
    Gtk::TreeModelColumn<Glib::ustring> m_col_name;
    Gtk::TreeModelColumn<bool> m_col_draggable;
    Gtk::TreeModelColumn<bool> m_col_receivesdrags;
  };

  ModelColumns m_Columns;

  static Glib::RefPtr<TreeModel_Dnd> create();

protected:
  //Overridden virtual functions:
  virtual bool row_draggable_vfunc(const Gtk::TreeModel::Path& path) const;
  virtual bool row_drop_possible_vfunc(const Gtk::TreeModel::Path& dest, const Gtk::SelectionData& selection_data) const;
  
};

#endif //GTKMM_EXAMPLE_TREEMODEL_DND_H