#include "window_main.hpp"

static Glib::ustring ui_info = 
    "<ui>"
    "  <menubar name='MenuBar'>"
    "    <menu action='FileMenu'>"
    "      <menuitem action='FileNew'/>"
    "      <menuitem action='FileSave'/>"
    "      <menuitem action='FileOpen' />"
    "      <menuitem action='FileQuit' sensitive='0'/>"
    "    </menu>"
    "  </menubar>"
    "</ui>";

void WindowMain::initMenu()
{
	this->add(m_Box);

    auto m_refActionGroup = Gtk::ActionGroup::create();
    m_refActionGroup->add(Gtk::Action::create("FileMenu", "File"));
    m_refActionGroup->add(Gtk::Action::create("FileNew", Gtk::Stock::NEW));
    m_refActionGroup->add(Gtk::Action::create("FileSave", Gtk::Stock::SAVE));
    m_refActionGroup->add(Gtk::Action::create("FileOpen", Gtk::Stock::OPEN));
    m_refActionGroup->add(Gtk::Action::create("FileQuit", Gtk::Stock::QUIT),
                        sigc::mem_fun(*this, &WindowMain::on_menu_file_quit));

    auto m_refUIManager = Gtk::UIManager::create();
    m_refUIManager->insert_action_group(m_refActionGroup);

    try
    {
        m_refUIManager->add_ui_from_string(ui_info);
    }
    catch(const Glib::Error& ex)
    {
        std::cerr << "building menus failed: " <<  ex.what();
    }

    //Get the menubar and toolbar widgets, and add them to a container widget:
    Gtk::Widget* pMenubar = m_refUIManager->get_widget("/MenuBar");
    if(pMenubar)
        m_Box.pack_start(*pMenubar, Gtk::PACK_SHRINK);

    show_all_children();
}

void WindowMain::on_menu_file_quit()
{
    hide();
}