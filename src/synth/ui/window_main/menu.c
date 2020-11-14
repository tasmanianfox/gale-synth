#include "menu.h"

void gale_synth_ui_window_main_menu_draw(GtkWidget *window)
{
    GtkWidget *vbox = gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    GtkWidget *menubar = gtk_menu_bar_new();
    GtkWidget *file_menu = gtk_menu_new();

    // "Add" Start
    GtkWidget *menu_add = gtk_menu_item_new_with_label("Add");
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_add), file_menu);

    GtkWidget *menu_wave_generator = gtk_menu_item_new_with_label("Wave generator");
    gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), menu_wave_generator);

    GtkWidget *menu_effect = gtk_menu_item_new_with_label("Effect");
    gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), menu_effect);

    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), menu_add);
    // "Add" End

    gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);
}