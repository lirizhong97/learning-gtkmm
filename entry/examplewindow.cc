#include "examplewindow.h"
#include <iostream>

ExampleWindow::ExampleWindow()
    : m_Button_Close("Close"),
      m_CheckButton_Editable("Editable"),
      m_CheckButton_Visible("Visible")
{
        set_size_request(200, 100);
        set_title("Gtk::Entry");

        m_Entry.set_max_length(50);
        m_Entry.set_text("hello");
        m_Entry.set_text(m_Entry.get_text() + " world");
        m_Entry.select_region(0, m_Entry.get_text_length());
        
        m_CheckButton_Editable.signal_toggled().connect(sigc::mem_fun(*this, &ExampleWindow::on_checkbox_editable_toggled));
        m_CheckButton_Editable.set_active(true);
        
        m_CheckButton_Visible.signal_toggled().connect(sigc::mem_fun(*this, &ExampleWindow::on_checkbox_visibility_toggled));
        m_CheckButton_Visible.set_active(true);

        m_Button_Close.signal_clicked().connect(sigc::mem_fun(*this, &ExampleWindow::on_button_close));
        m_Button_Close.set_can_default();
        m_Button_Close.grab_default();

        m_HBox.pack_start(m_CheckButton_Editable);
        m_HBox.pack_start(m_CheckButton_Visible);

        m_VBox.pack_start(m_Entry);
        // Note that add() can also be used instead of pack_xxx()
        m_VBox.add(m_HBox);
        m_VBox.pack_start(m_Button_Close);

        add(m_VBox);

        show_all_children();
}

ExampleWindow::~ExampleWindow()
{
}

void ExampleWindow::on_checkbox_editable_toggled()
{
        m_Entry.set_editable(m_CheckButton_Editable.get_active());
}

void ExampleWindow::on_checkbox_visibility_toggled()
{
        m_Entry.set_visibility(m_CheckButton_Visible.get_active());
}

void ExampleWindow::on_button_close()
{
        hide();
}
