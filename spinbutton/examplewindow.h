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
  void on_checkbutton_snap();
  void on_checkbutton_numeric();
  void on_spinbutton_digits_changed();
  void on_button_close();

  enum enumValueFormats
  {
    VALUE_FORMAT_INT,
    VALUE_FORMAT_FLOAT
  };
  void on_button_getvalue(enumValueFormats display);

  //Child widgets:
  Gtk::Frame m_Frame_NotAccelerated, m_Frame_Accelerated;
  Gtk::HBox m_HBox_NotAccelerated, m_HBox_Accelerated,
      m_HBox_Buttons;
  Gtk::VBox m_VBox_Main, m_VBox, m_VBox_Day, m_VBox_Month, m_VBox_Year,
      m_VBox_Accelerated, m_VBox_Value, m_VBox_Digits;
  Gtk::Label m_Label_Day, m_Label_Month, m_Label_Year,
      m_Label_Value, m_Label_Digits,
      m_Label_ShowValue;
  Glib::RefPtr<Gtk::Adjustment> m_adjustment_day, m_adjustment_month, m_adjustment_year,
      m_adjustment_value, m_adjustment_digits;
  Gtk::SpinButton m_SpinButton_Day, m_SpinButton_Month, m_SpinButton_Year,
      m_SpinButton_Value, m_SpinButton_Digits;
  Gtk::CheckButton m_CheckButton_Snap, m_CheckButton_Numeric;
  Gtk::Button m_Button_Int, m_Button_Float, m_Button_Close;
};

#endif //GTKMM_EXAMPLEWINDOW_H
