#include <gtk/gtk.h>

void pkillx(GtkWidget *widget, gpointer pointer){

    GtkDialogFlags flag = GTK_DIALOG_DESTROY_WITH_PARENT;
    gchar *get_kill = gtk_entry_get_text(GTK_ENTRY(pointer));
    gchar *token = strtok(get_kill, " ");
    gchar *title = NULL;
    gchar *text = NULL;

    if(isspace(get_kill[0]) || strlen(get_kill) < 2){
        title = "Alert";
        text = "Something went wrong!";
    } else {
        title = "I passed";
        text = "Programs have been killed";
    }
    
    GtkWidget *dialog = gtk_dialog_new_with_buttons(
        title, widget,flag, GTK_STOCK_OK, GTK_RESPONSE_NONE, NULL
    );
    gtk_widget_set_size_request(dialog, 200, 78);

    GtkWidget *label = gtk_label_new(text);
    GtkWidget *area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    gtk_container_add(GTK_CONTAINER(area), label);

    printf("\"Programs are being closed\"\n");
    while(token != NULL){
        if(!isspace(token[0]) && strlen(token) > 1){
            gchar pkill[20] = "pkill ";
            strcat(pkill, token);
            system(pkill);
            printf("> %s\n", pkill);
        }
        token = strtok(NULL, " ");
    }
    printf("\"%s\"\n", text);

    gtk_entry_set_text(GTK_ENTRY(pointer), "");
    gtk_widget_show_all(dialog);
    g_signal_connect_swapped(dialog, "response", G_CALLBACK(gtk_widget_destroy), dialog);

}
