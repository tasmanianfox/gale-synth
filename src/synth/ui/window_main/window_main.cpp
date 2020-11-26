#include "window_main.hpp"

WindowMain::WindowMain()
{
	this->set_size_request(800, 600);
    this->set_title("Gale");
}

WindowMain::~WindowMain()
{

}

// void gale_synth_ui_window_main_render(int argc, char* argv[])
// {
// 	gtk_init(&argc, &argv);

// 	GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
// 	gtk_widget_set_size_request (GTK_WIDGET (window), 800, 600);
// 	gtk_window_set_title (GTK_WINDOW (window), "Gale");

// 	gale_synth_ui_window_main_menu_draw(window);

// 	gtk_widget_show_all(window);
// 	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);  

// 	gtk_main();
// }