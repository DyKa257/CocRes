#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <gtk/gtkx.h>
#include <math.h>
#include <ctype.h>
#include "List_People.h"

GtkBuilder *builder;
GtkWidget *window1;
GtkWidget *window2;
GtkWidget *fixed1;
GtkWidget *label1_1;
GtkWidget *label1_2;
GtkWidget *label1_3;
GtkWidget *button1_1;
GtkWidget *entry1_1;
GtkWidget *entry1_2;

List_People *list_people;

int main (int argc,char *argv[])
{
    list_people = List_People_Init();

    gtk_init (&argc, &argv);

    builder = gtk_builder_new();

    gtk_builder_add_from_file(builder, "CocRes.ui", NULL);

    window1 = GTK_WIDGET(gtk_builder_get_object (builder, "window1"));

    g_signal_connect(window1, "destroy", G_CALLBACK (gtk_main_quit), NULL);

    gtk_builder_connect_signals(builder, NULL);

    fixed1 = GTK_WIDGET(gtk_builder_get_object(builder, "fixed1"));
    label1_1 = GTK_WIDGET(gtk_builder_get_object (builder, "label1_1"));
    label1_2 = GTK_WIDGET(gtk_builder_get_object (builder, "label1_2"));
    label1_3 = GTK_WIDGET(gtk_builder_get_object (builder, "label1_3"));
    button1_1 = GTK_WIDGET(gtk_builder_get_object (builder, "button1_1"));
    entry1_1 = GTK_WIDGET(gtk_builder_get_object (builder, "entry1_1"));
    entry1_2 = GTK_WIDGET(gtk_builder_get_object (builder, "entry1_2"));

    g_object_unref(G_OBJECT(builder));

    gtk_widget_show(window1);

    gtk_main ();

    return EXIT_SUCCESS;
}

void on_button1_1_clicked(GtkButton *b)
{
    char tmp[100], tmp1[100];
    sprintf(tmp, "%s", gtk_entry_get_text((GtkEntry*)entry1_1));
    sprintf(tmp1, "%s", gtk_entry_get_text((GtkEntry*)entry1_2));
    list_people->inp(list_people); 
    if (list_people->check(list_people, tmp, tmp1)) g_print("True\n"); else g_print("False\n");
}