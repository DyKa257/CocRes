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
GtkWidget *button1_1;
GtkWidget *button1_2;
GtkWidget *window2;
GtkWidget *entry2_1;
GtkWidget *button2_1;
GtkWidget *button2_2;
GtkWidget *window3;
GtkWidget *button3_1;
GtkWidget *button3_2;
GtkWidget *button3_5;
GtkWidget *window4;
GtkWidget *button4_1;
GtkWidget *button4_2;
GtkWidget *button4_3;
GtkWidget *button4_4;
GtkWidget *button4_5;
GtkWidget *button4_1;
GtkWidget *button4_2;
GtkWidget *button4_3;
GtkWidget *button4_4;
GtkWidget *button4_5;
GtkWidget *button4_6;
GtkWidget *button4_7;
GtkWidget *button4_8;
GtkWidget *button4_9;
GtkWidget *button4_10;
GtkWidget *button4_11;
GtkWidget *button4_12;
GtkWidget *button4_13;
GtkWidget *button4_14;
GtkWidget *button4_15;
GtkWidget *button4_16;
GtkWidget *button4_17;
GtkWidget *button4_18;
GtkWidget *button4_19;
GtkWidget *button4_20;
GtkWidget *button4_21;
GtkWidget *button4_22;
GtkWidget *button4_23;
GtkWidget *button4_24;
GtkWidget *button4_25;
GtkWidget *button4_26;
GtkWidget *button4_27;
GtkWidget *window5;
GtkWidget *button5_1;

List_People *list_people;

int main (int argc,char *argv[])
{
    gtk_init (&argc, &argv);

    //load_css();

    builder = gtk_builder_new();

    gtk_builder_add_from_file(builder, "CocRes.glade", NULL);

    window1 = GTK_WIDGET(gtk_builder_get_object (builder, "window1"));
    window2 = GTK_WIDGET(gtk_builder_get_object (builder, "window2"));
    window3 = GTK_WIDGET(gtk_builder_get_object (builder, "window3"));
    window4 = GTK_WIDGET(gtk_builder_get_object (builder, "window4"));
    window5 = GTK_WIDGET(gtk_builder_get_object (builder, "window5"));

    g_signal_connect(window1, "destroy", G_CALLBACK (gtk_main_quit), NULL);
    g_signal_connect(window2, "destroy", G_CALLBACK (gtk_main_quit), NULL);
    g_signal_connect(window3, "destroy", G_CALLBACK (gtk_main_quit), NULL);
    g_signal_connect(window4, "destroy", G_CALLBACK (gtk_main_quit), NULL);

    gtk_builder_connect_signals(builder, NULL);

    button1_1 = GTK_WIDGET(gtk_builder_get_object (builder, "button1_1"));
    button1_2 = GTK_WIDGET(gtk_builder_get_object (builder, "button1_2"));

    entry2_1 = GTK_WIDGET(gtk_builder_get_object (builder, "entry2_1"));
    button2_1 = GTK_WIDGET(gtk_builder_get_object (builder, "button2_1"));
    button2_2 = GTK_WIDGET(gtk_builder_get_object (builder, "button2_2"));
    gtk_widget_set_name(button2_1, "button2_1");
    gtk_widget_set_name(button2_2, "button2_2");

    button3_1 = GTK_WIDGET(gtk_builder_get_object (builder, "button3_1"));
    button3_2 = GTK_WIDGET(gtk_builder_get_object (builder, "button3_2"));
    button3_2 = GTK_WIDGET(gtk_builder_get_object (builder, "button3_5"));

    button4_1 = GTK_WIDGET(gtk_builder_get_object (builder, "button4_1"));
    button4_2 = GTK_WIDGET(gtk_builder_get_object (builder, "button4_2"));
    button4_3 = GTK_WIDGET(gtk_builder_get_object (builder, "button4_3"));
    button4_4 = GTK_WIDGET(gtk_builder_get_object (builder, "button4_4"));
    button4_5 = GTK_WIDGET(gtk_builder_get_object (builder, "button4_5"));
    button4_6 = GTK_WIDGET(gtk_builder_get_object (builder, "button4_6"));
    button4_7 = GTK_WIDGET(gtk_builder_get_object (builder, "button4_7"));
    button4_8 = GTK_WIDGET(gtk_builder_get_object (builder, "button4_8"));
    button4_9 = GTK_WIDGET(gtk_builder_get_object (builder, "button4_9"));
    button4_10 = GTK_WIDGET(gtk_builder_get_object (builder, "button4_10"));
    button4_11 = GTK_WIDGET(gtk_builder_get_object (builder, "button4_11"));
    button4_12 = GTK_WIDGET(gtk_builder_get_object (builder, "button4_12"));
    button4_13 = GTK_WIDGET(gtk_builder_get_object (builder, "button4_13"));
    button4_14 = GTK_WIDGET(gtk_builder_get_object (builder, "button4_14"));
    button4_15 = GTK_WIDGET(gtk_builder_get_object (builder, "button4_15"));
    button4_16 = GTK_WIDGET(gtk_builder_get_object (builder, "button4_16"));
    button4_17 = GTK_WIDGET(gtk_builder_get_object (builder, "button4_17"));
    button4_18 = GTK_WIDGET(gtk_builder_get_object (builder, "button4_18"));
    button4_19 = GTK_WIDGET(gtk_builder_get_object (builder, "button4_19"));
    button4_20 = GTK_WIDGET(gtk_builder_get_object (builder, "button4_20"));
    button4_21 = GTK_WIDGET(gtk_builder_get_object (builder, "button4_21"));
    button4_22 = GTK_WIDGET(gtk_builder_get_object (builder, "button4_22"));
    button4_23 = GTK_WIDGET(gtk_builder_get_object (builder, "button4_23"));
    button4_24 = GTK_WIDGET(gtk_builder_get_object (builder, "button4_24"));
    button4_25 = GTK_WIDGET(gtk_builder_get_object (builder, "button4_25"));
    button4_26 = GTK_WIDGET(gtk_builder_get_object (builder, "button4_26"));
    button4_27 = GTK_WIDGET(gtk_builder_get_object (builder, "button4_27"));
    gtk_widget_set_name(button4_1, "button4_1");
    gtk_widget_set_name(button4_2, "button4_2");
    gtk_widget_set_name(button4_3, "button4_3");
    gtk_widget_set_name(button4_4, "button4_4");
    gtk_widget_set_name(button4_5, "button4_5");
    gtk_widget_set_name(button4_6, "button4_6");
    gtk_widget_set_name(button4_7, "button4_7");
    gtk_widget_set_name(button4_8, "button4_8");
    gtk_widget_set_name(button4_9, "button4_9");
    gtk_widget_set_name(button4_10, "button4_10");
    gtk_widget_set_name(button4_11, "button4_11");
    gtk_widget_set_name(button4_12, "button4_12");
    gtk_widget_set_name(button4_13, "button4_13");
    gtk_widget_set_name(button4_14, "button4_14");
    gtk_widget_set_name(button4_15, "button4_15");
    gtk_widget_set_name(button4_16, "button4_16");
    gtk_widget_set_name(button4_17, "button4_17");
    gtk_widget_set_name(button4_18, "button4_18");
    gtk_widget_set_name(button4_19, "button4_19");
    gtk_widget_set_name(button4_20, "button4_20");
    gtk_widget_set_name(button4_21, "button4_21");
    gtk_widget_set_name(button4_22, "button4_22");
    gtk_widget_set_name(button4_23, "button4_23");
    gtk_widget_set_name(button4_24, "button4_24");
    gtk_widget_set_name(button4_25, "button4_25");
    gtk_widget_set_name(button4_26, "button4_26");
    gtk_widget_set_name(button4_27, "button4_27");

    button5_1 = GTK_WIDGET(gtk_builder_get_object (builder, "button5_1"));

    gtk_widget_set_name(button1_1, "button1_1");

    GtkCssProvider *cssProvider = gtk_css_provider_new();
    GError *error = NULL;
    gtk_css_provider_load_from_path(cssProvider, "style.css", NULL);
    gtk_style_context_add_provider_for_screen(gdk_screen_get_default(),
                               GTK_STYLE_PROVIDER(cssProvider),
                               GTK_STYLE_PROVIDER_PRIORITY_USER);
    

    g_object_unref(G_OBJECT(builder));

    gtk_widget_show(window1);

    gtk_main ();

    return EXIT_SUCCESS;
}

void on_button1_1_clicked(GtkButton *b)
{
    gtk_widget_hide(window1);
    gtk_widget_show(window4);
}
void on_button1_2_clicked(GtkButton *b)
{
    gtk_widget_hide(window1);
    gtk_widget_show(window2);
}
void on_button2_1_clicked(GtkButton *b)
{
    char tmp[100];
    sprintf(tmp, "%s", gtk_entry_get_text((GtkEntry*) entry2_1));
    if (str_check(tmp, "123456"))
    {
        gtk_widget_hide(window2);
        gtk_widget_show(window3);
    }
}
void on_button3_1_clicked(GtkButton *b)
{
    gtk_widget_hide(window3);
    gtk_widget_show(window4);
}
void on_button3_5_clicked(GtkButton *b)
{
    gtk_widget_hide(window3);
    gtk_widget_show(window1);
}
void on_button4_1_clicked(GtkButton *b)
{
    gtk_widget_hide(window4);
    gtk_widget_show(window1);
}
void on_button4_2_clicked(GtkButton *b)
{
    gtk_widget_hide(button4_2);
    gtk_widget_show(button4_3);
    gtk_widget_show(window5);
}
void on_button4_4_clicked(GtkButton *b)
{
    gtk_widget_hide(button4_4);
    gtk_widget_show(button4_5);
    gtk_widget_show(window5);
}
void on_button4_6_clicked(GtkButton *b)
{
    gtk_widget_hide(button4_6);
    gtk_widget_show(button4_7);
    gtk_widget_show(window5);
}
void on_button4_8_clicked(GtkButton *b)
{
    gtk_widget_hide(button4_8);
    gtk_widget_show(button4_9);
    gtk_widget_show(window5);
}void on_button4_10_clicked(GtkButton *b)
{
    gtk_widget_hide(button4_10);
    gtk_widget_show(button4_11);
    gtk_widget_show(window5);
}void on_button4_12_clicked(GtkButton *b)
{
    gtk_widget_hide(button4_12);
    gtk_widget_show(button4_13);
    gtk_widget_show(window5);
}
void on_button4_14_clicked(GtkButton *b)
{
    gtk_widget_hide(button4_14);
    gtk_widget_show(button4_15);
    gtk_widget_show(window5);
}
void on_button4_16_clicked(GtkButton *b)
{
    gtk_widget_hide(button4_16);
    gtk_widget_show(button4_17);
    gtk_widget_show(window5);
}
void on_button4_18_clicked(GtkButton *b)
{
    gtk_widget_hide(button4_18);
    gtk_widget_show(button4_19);
    gtk_widget_show(window5);
}void on_button4_20_clicked(GtkButton *b)
{
    gtk_widget_hide(button4_20);
    gtk_widget_show(button4_21);
    gtk_widget_show(window5);
}
void on_button4_22_clicked(GtkButton *b)
{
    gtk_widget_hide(button4_22);
    gtk_widget_show(button4_23);
    gtk_widget_show(window5);
}
void on_button4_24_clicked(GtkButton *b)
{
    gtk_widget_hide(button4_24);
    gtk_widget_show(button4_25);
    gtk_widget_show(window5);
}
void on_button4_26_clicked(GtkButton *b)
{
    gtk_widget_hide(button4_26);
    gtk_widget_show(button4_27);
    gtk_widget_show(window5);
}
void on_button5_1_clicked(GtkButton *b)
{
    gtk_widget_hide(window5);
    gtk_widget_hide(window4);
    gtk_widget_show(window3);
}
