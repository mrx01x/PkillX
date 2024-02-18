#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define USR_BIN_PKILL "/usr/bin/pkill"
#define USR_LOCAL_BIN_PKILL "/usr/local/bin/pkill"
#define USR_SHARE_PKILLX_ICON "/usr/share/pkillx/icon/pkillx_icon.png"

extern void pkillx(GtkWidget *widget, gpointer pointer);

int main(int argc, char* argv[]){

    FILE *pkill_bin = fopen(USR_BIN_PKILL, "r");
    FILE *pkill_local_bin = fopen(USR_LOCAL_BIN_PKILL, "r");

    if(!pkill_bin){
        if(!pkill_local_bin){
            printf("\"pkill is not exists\"\n");
            return EXIT_SUCCESS;
        }
    }

    if(argc < 2){

        gtk_init(&argc, &argv);
        GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_title(GTK_WINDOW(window), "PKILLX");
        gtk_window_set_default_size(GTK_WINDOW(window), 300, 80);
        gtk_window_set_resizable(GTK_WINDOW(window), 0);
        gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

        gchar *get_icon = USR_SHARE_PKILLX_ICON;
        GdkPixbuf *icon = gdk_pixbuf_new_from_file(get_icon, NULL);
        FILE *file = fopen(get_icon, "r");
        if(file){
            gtk_window_set_icon(GTK_WINDOW(window), icon);
        }

        GtkWidget *vbox = gtk_vbox_new(0,0);
        GtkWidget *fixed = gtk_fixed_new();

        GtkWidget *entry = gtk_entry_new();
        gtk_widget_set_tooltip_text(entry, "Enter the name of the program you want to close");

        GtkWidget *button = gtk_button_new();
        gtk_button_set_label(GTK_BUTTON(button), "KILL");
        gtk_widget_set_size_request(button, 70, 35);
        gtk_widget_set_tooltip_text(button, "pkill");

        gtk_fixed_put(GTK_FIXED(fixed), button, 115, 10);

        gtk_box_pack_start(GTK_BOX(vbox), entry, 0,0,0);
        gtk_box_pack_start(GTK_BOX(vbox), fixed, 0,0,0);

        gtk_container_add(GTK_CONTAINER(window), vbox);
    
        g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
        g_signal_connect(G_OBJECT(entry), "activate", G_CALLBACK(pkillx), entry);
        g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(pkillx), entry);
        gtk_widget_show_all(window);
        gtk_main();

    } else {
        int x = 1;
        printf("\"Programs are being closed\"\n");
        while(x < argc){
            if(!isspace(argv[x][0]) && strlen(argv[x]) > 1){
                char pkill_argv[20] = "pkill ";
                strcat(pkill_argv, argv[x]);
                system(pkill_argv);
                printf("> %s\n", pkill_argv);
            }
            x++;
        }
        printf("\"Programs have been killed\"\n");
    }
    return 0;
}
