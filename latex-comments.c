/*This Plugin has the purpose of displaying comments written in latex as a compiled graphic*
 * Authors: Michelle Rausch*/


#include <geanyplugin.h>


static void item_activate_cb(GtkMenuItem *menuitem, gpointer user_data)
{
    dialogs_show_msgbox(GTK_MESSAGE_INFO, _("Hello World"));
} 
static gboolean latexcomments_init(GeanyPlugin *plugin, gpointer pdata)
{
    GtkWidget *main_menu_item;
    // Create a new menu item and show it
    main_menu_item = gtk_menu_item_new_with_mnemonic("Latex-Comments");
    gtk_widget_show(main_menu_item);
    // Attach the new menu item to the Tools menu
    gtk_container_add(GTK_CONTAINER(plugin->geany_data->main_widgets->tools_menu),
        main_menu_item);
    // Connect the menu item with a callback function
    // which is called when the item is clicked
    g_signal_connect(main_menu_item, "activate",
        G_CALLBACK(item_activate_cb), NULL);
    return TRUE;
}
 
 
static void latexcomments_cleanup(GeanyPlugin *plugin, gpointer pdata)
{
    printf("Bye World :-(\n");
}
 
 
G_MODULE_EXPORT
void geany_load_module(GeanyPlugin *plugin)
{
    /* Step 1: Set metadata */
    plugin->info->name = _("Latex-Comments");
    plugin->info->description = _("Displays latex-comments as graphic");
    plugin->info->version = "0.0";
    plugin->info->author = _("Michelle Rausch <michelle.rausch@protonmail.com>");
 
    /* Step 2: Set functions */
    plugin->funcs->init = latexcomments_init;
    plugin->funcs->cleanup = latexcomments_cleanup;
 
    /* Step 3: Register! */
    GEANY_PLUGIN_REGISTER(plugin, 225);
    /* alternatively:
    GEANY_PLUGIN_REGISTER_FULL(plugin, 225, data, free_func); */
}
