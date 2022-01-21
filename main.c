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
GtkWidget *fixed1;
GtkWidget *label1_1;
GtkWidget *label1_2;
GtkWidget *label1_3;
GtkWidget *button1_1;
GtkWidget *entry1_1;
GtkWidget *entry1_2;
GtkWidget *window2;
GtkWidget *fixed2;
GtkWidget *label2_1;
GtkWidget *label2_2;
GtkWidget *button2_1;
GtkWidget *button2_2;
GtkWidget *button2_3;
GtkWidget *button2_4;
GtkWidget *window3;
GtkWidget *fixed3;
GtkWidget *label3_1;
GtkWidget *label3_2;
GtkWidget *button3_1;
GtkWidget *button3_2;
GtkWidget *button3_3;
GtkWidget *button3_4;

List_People *list_people;

int main (int argc,char *argv[])
{
    list_people = List_People_Init();

    gtk_init (&argc, &argv);

    builder = gtk_builder_new();

    gtk_builder_add_from_file(builder, "CocRes.ui", NULL);

    window1 = GTK_WIDGET(gtk_builder_get_object (builder, "window1"));
    window2 = GTK_WIDGET(gtk_builder_get_object (builder, "window2"));
    window3 = GTK_WIDGET(gtk_builder_get_object (builder, "window3"));

    g_signal_connect(window1, "destroy", G_CALLBACK (gtk_main_quit), NULL);
    g_signal_connect(window2, "destroy", G_CALLBACK (gtk_main_quit), NULL);
    g_signal_connect(window3, "destroy", G_CALLBACK (gtk_main_quit), NULL);

    gtk_builder_connect_signals(builder, NULL);

    fixed1 = GTK_WIDGET(gtk_builder_get_object(builder, "fixed1"));
    label1_1 = GTK_WIDGET(gtk_builder_get_object (builder, "label1_1"));
    label1_2 = GTK_WIDGET(gtk_builder_get_object (builder, "label1_2"));
    label1_3 = GTK_WIDGET(gtk_builder_get_object (builder, "label1_3"));
    button1_1 = GTK_WIDGET(gtk_builder_get_object (builder, "button1_1"));
    entry1_1 = GTK_WIDGET(gtk_builder_get_object (builder, "entry1_1"));
    entry1_2 = GTK_WIDGET(gtk_builder_get_object (builder, "entry1_2"));

    fixed1 = GTK_WIDGET(gtk_builder_get_object(builder, "fixed2"));
    label2_1 = GTK_WIDGET(gtk_builder_get_object (builder, "label2_1"));
    label2_2 = GTK_WIDGET(gtk_builder_get_object (builder, "label2_2"));
    button2_1 = GTK_WIDGET(gtk_builder_get_object (builder, "button2_1"));
    button2_2 = GTK_WIDGET(gtk_builder_get_object (builder, "button2_2"));
    button2_3 = GTK_WIDGET(gtk_builder_get_object (builder, "button2_3"));
    button2_3 = GTK_WIDGET(gtk_builder_get_object (builder, "button2_4"));

    fixed1 = GTK_WIDGET(gtk_builder_get_object(builder, "fixed3"));
    label2_1 = GTK_WIDGET(gtk_builder_get_object (builder, "label3_1"));
    label2_2 = GTK_WIDGET(gtk_builder_get_object (builder, "label3_2"));
    button2_1 = GTK_WIDGET(gtk_builder_get_object (builder, "button3_1"));
    button3_2 = GTK_WIDGET(gtk_builder_get_object (builder, "button3_2"));
    button3_3 = GTK_WIDGET(gtk_builder_get_object (builder, "button3_3"));
    button2_3 = GTK_WIDGET(gtk_builder_get_object (builder, "button3_4"));

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
    if (list_people->check(list_people, tmp, tmp1) == 1) 
    {
        gtk_widget_show(window3);
        gtk_widget_hide(window1);
    } 
    else
    {
        gtk_widget_show(window2);
        gtk_widget_hide(window1);
    } 
}
void on_button2_4_clicked(GtkButton *b)
{
    gtk_widget_show(window1);
    gtk_widget_hide(window2);
}
void on_button3_4_clicked(GtkButton *b)
{
    gtk_widget_show(window1);
    gtk_widget_hide(window3);
}