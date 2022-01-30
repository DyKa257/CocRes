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
#include "lib.h"
#include "Goods.h"
#include "Order.h"
#include "Booking.h"

Book table[13];

GtkBuilder *builder;
GtkWidget *window1;
GtkWidget *button1_1;
GtkWidget *button1_2;
GtkWidget *window2;
GtkWidget *entry2_1;
GtkWidget *button2_1;
GtkWidget *button2_2;
GtkWidget *label2_4;
GtkWidget *window3;
GtkWidget *button3_1;
GtkWidget *button3_2;
GtkWidget *button3_3;
GtkWidget *button3_4;
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
GtkWidget *button5_2;
GtkWidget *entry5_1;
GtkWidget *entry5_2;
GtkWidget *entry5_3;
GtkWidget *label5_5;
GtkWidget *window6;
GtkWidget *button6_1;
GtkWidget *button6_2;
GtkWidget *spin6_1;
GtkWidget *spin6_2;
GtkWidget *spin6_3;
GtkWidget *spin6_4;
GtkWidget *spin6_5;
GtkWidget *spin6_6;
GtkWidget *spin6_7;
GtkWidget *spin6_8;
GtkWidget *spin6_9;
GtkWidget *spin6_10;
GtkWidget *window7;
GtkWidget *button7_1;
GtkWidget *button7_2;
GtkWidget *entry7_1;
GtkWidget *entry7_2;
GtkWidget *label7_4;
GtkWidget *window8;
GtkWidget *button8_1;
GtkWidget *label8_4;
GtkWidget *label8_5;
GtkWidget *label8_6;
GtkWidget *label8_8;
GtkWidget *label8_12;
GtkWidget *label8_13;
GtkWidget *label8_14;
GtkWidget *viewport8_1;
GtkWidget *scrollbar8_1;
GtkWidget *grid8_1;
GtkWidget *label8[4][9];
GtkWidget *window9;
GtkWidget *button9_1;
GtkWidget *button9_2;
GtkWidget *entry9_1;
GtkWidget *entry9_2;
GtkWidget *label9_3;
GtkWidget *window10;
GtkWidget *button10_1;
GtkWidget *button10_2;
GtkWidget *entry10_1;
GtkWidget *entry10_2;
GtkWidget *entry10_3;
GtkWidget *entry10_4;
GtkWidget *window11;
GtkWidget *button11_1;
GtkWidget *button11_2;
GtkWidget *window12;
GtkWidget *button12_1;
GtkWidget *button12_2;
GtkWidget *entry12_1;
GtkWidget *entry12_2;
GtkWidget *entry12_3;
GtkWidget *label12_3;
GtkWidget *window13;
GtkWidget *button13_1;
GtkWidget *button13_2;
GtkWidget *entry13_1;
GtkWidget *entry13_2;
GtkWidget *entry13_3;
GtkWidget *entry13_4;

int row;
char *rowtext[4][100];
char table_booking[20];

int main (int argc,char *argv[])
{
    reset_table();
    reset_bill();
    gtk_init (&argc, &argv);

    //load_css();

    builder = gtk_builder_new();

    gtk_builder_add_from_file(builder, "CocRes.glade", NULL);

    window1 = GTK_WIDGET(gtk_builder_get_object (builder, "window1"));
    window2 = GTK_WIDGET(gtk_builder_get_object (builder, "window2"));
    window3 = GTK_WIDGET(gtk_builder_get_object (builder, "window3"));
    window4 = GTK_WIDGET(gtk_builder_get_object (builder, "window4"));
    window5 = GTK_WIDGET(gtk_builder_get_object (builder, "window5"));
    window6 = GTK_WIDGET(gtk_builder_get_object (builder, "window6"));
    window7 = GTK_WIDGET(gtk_builder_get_object (builder, "window7"));
    window8 = GTK_WIDGET(gtk_builder_get_object (builder, "window8"));
    window9 = GTK_WIDGET(gtk_builder_get_object (builder, "window9"));
    window9 = GTK_WIDGET(gtk_builder_get_object (builder, "window9"));
    window10 = GTK_WIDGET(gtk_builder_get_object (builder, "window10"));
    window11 = GTK_WIDGET(gtk_builder_get_object (builder, "window11"));
    window12 = GTK_WIDGET(gtk_builder_get_object (builder, "window12"));
    window13 = GTK_WIDGET(gtk_builder_get_object (builder, "window13"));
    gtk_widget_set_name(window4, "window4");

    g_signal_connect(window1, "destroy", G_CALLBACK (gtk_main_quit), NULL);
    g_signal_connect(window2, "destroy", G_CALLBACK (gtk_main_quit), NULL);
    g_signal_connect(window3, "destroy", G_CALLBACK (gtk_main_quit), NULL);
    g_signal_connect(window4, "destroy", G_CALLBACK (gtk_main_quit), NULL);
    g_signal_connect(window6, "destroy", G_CALLBACK (gtk_main_quit), NULL);
    g_signal_connect(window8, "destroy", G_CALLBACK (gtk_main_quit), NULL);
    g_signal_connect(window10, "destroy", G_CALLBACK (gtk_main_quit), NULL);

    gtk_builder_connect_signals(builder, NULL);

    button1_1 = GTK_WIDGET(gtk_builder_get_object (builder, "button1_1"));
    button1_2 = GTK_WIDGET(gtk_builder_get_object (builder, "button1_2"));

    entry2_1 = GTK_WIDGET(gtk_builder_get_object (builder, "entry2_1"));
    button2_1 = GTK_WIDGET(gtk_builder_get_object (builder, "button2_1"));
    button2_2 = GTK_WIDGET(gtk_builder_get_object (builder, "button2_2"));
    label2_4 = GTK_WIDGET(gtk_builder_get_object (builder, "label2_4"));
    gtk_widget_set_name(button2_1, "button2_1");
    gtk_widget_set_name(button2_2, "button2_2");
    gtk_widget_set_name(entry2_1, "entry2_1");

    button3_1 = GTK_WIDGET(gtk_builder_get_object (builder, "button3_1"));
    button3_2 = GTK_WIDGET(gtk_builder_get_object (builder, "button3_2"));
    button3_3 = GTK_WIDGET(gtk_builder_get_object (builder, "button3_3"));
    button3_4 = GTK_WIDGET(gtk_builder_get_object (builder, "button3_4"));
    button3_5 = GTK_WIDGET(gtk_builder_get_object (builder, "button3_5"));

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
    button5_2 = GTK_WIDGET(gtk_builder_get_object (builder, "button5_2"));
    entry5_1 = GTK_WIDGET(gtk_builder_get_object (builder, "entry5_1"));
    entry5_2 = GTK_WIDGET(gtk_builder_get_object (builder, "entry5_2"));
    entry5_3 = GTK_WIDGET(gtk_builder_get_object (builder, "entry5_3"));
    label5_5 = GTK_WIDGET(gtk_builder_get_object (builder, "label5_5"));
    
    button6_1 = GTK_WIDGET(gtk_builder_get_object (builder, "button6_1"));
    button6_2 = GTK_WIDGET(gtk_builder_get_object (builder, "button6_2"));
    spin6_1 = GTK_WIDGET(gtk_builder_get_object (builder, "spin6_1"));
    spin6_2 = GTK_WIDGET(gtk_builder_get_object (builder, "spin6_2"));
    spin6_3 = GTK_WIDGET(gtk_builder_get_object (builder, "spin6_3"));
    spin6_4 = GTK_WIDGET(gtk_builder_get_object (builder, "spin6_4"));
    spin6_5 = GTK_WIDGET(gtk_builder_get_object (builder, "spin6_5"));
    spin6_6 = GTK_WIDGET(gtk_builder_get_object (builder, "spin6_6"));
    spin6_7 = GTK_WIDGET(gtk_builder_get_object (builder, "spin6_7"));
    spin6_8 = GTK_WIDGET(gtk_builder_get_object (builder, "spin6_8"));
    spin6_9 = GTK_WIDGET(gtk_builder_get_object (builder, "spin6_9"));
    spin6_10 = GTK_WIDGET(gtk_builder_get_object (builder, "spin6_10"));

    button7_1 = GTK_WIDGET(gtk_builder_get_object (builder, "button7_1"));
    button7_2 = GTK_WIDGET(gtk_builder_get_object (builder, "button7_2"));
    entry7_1 = GTK_WIDGET(gtk_builder_get_object (builder, "entry7_1"));
    entry7_2 = GTK_WIDGET(gtk_builder_get_object (builder, "entry7_2"));
    label7_4 = GTK_WIDGET(gtk_builder_get_object (builder, "label7_4"));
  
    button8_1 = GTK_WIDGET(gtk_builder_get_object (builder, "button8_1"));
    label8_4 = GTK_WIDGET(gtk_builder_get_object (builder, "label8_4"));
    label8_5 = GTK_WIDGET(gtk_builder_get_object (builder, "label8_5"));
    label8_6 = GTK_WIDGET(gtk_builder_get_object (builder, "label8_6"));
    label8_8 = GTK_WIDGET(gtk_builder_get_object (builder, "label8_8"));
    label8_12 = GTK_WIDGET(gtk_builder_get_object (builder, "label8_12"));
    label8_13 = GTK_WIDGET(gtk_builder_get_object (builder, "label8_13"));
    label8_14 = GTK_WIDGET(gtk_builder_get_object (builder, "label8_14"));
    viewport8_1 = GTK_WIDGET(gtk_builder_get_object (builder, "viewport8_1")) ;
    scrollbar8_1 = GTK_WIDGET(gtk_builder_get_object (builder, "scrollbar8_1"));
    grid8_1 = GTK_WIDGET(gtk_builder_get_object (builder, "grid8_1"));

    button9_1 = GTK_WIDGET(gtk_builder_get_object (builder, "button9_1"));
    button9_2 = GTK_WIDGET(gtk_builder_get_object (builder, "button9_2"));
    entry9_1 = GTK_WIDGET(gtk_builder_get_object (builder, "entry9_1"));
    entry9_2 = GTK_WIDGET(gtk_builder_get_object (builder, "entry9_2"));
    label9_3 = GTK_WIDGET(gtk_builder_get_object (builder, "label9_3"));

    button10_1 = GTK_WIDGET(gtk_builder_get_object (builder, "button10_1"));
    button10_2 = GTK_WIDGET(gtk_builder_get_object (builder, "button10_2"));
    entry10_1 = GTK_WIDGET(gtk_builder_get_object (builder, "entry10_1"));
    entry10_2 = GTK_WIDGET(gtk_builder_get_object (builder, "entry10_2"));
    entry10_3 = GTK_WIDGET(gtk_builder_get_object (builder, "entry10_3"));
    entry10_4 = GTK_WIDGET(gtk_builder_get_object (builder, "entry10_4"));

    button11_1 = GTK_WIDGET(gtk_builder_get_object (builder, "button11_1"));
    button11_2 = GTK_WIDGET(gtk_builder_get_object (builder, "button11_2"));

    button12_1 = GTK_WIDGET(gtk_builder_get_object (builder, "button12_1"));
    button12_2 = GTK_WIDGET(gtk_builder_get_object (builder, "button12_2"));
    entry12_1 = GTK_WIDGET(gtk_builder_get_object (builder, "entry12_1"));
    entry12_2 = GTK_WIDGET(gtk_builder_get_object (builder, "entry12_2"));
    entry12_3 = GTK_WIDGET(gtk_builder_get_object (builder, "entry12_3"));
    label12_3 = GTK_WIDGET(gtk_builder_get_object (builder, "label12_3"));
    
    button13_1 = GTK_WIDGET(gtk_builder_get_object (builder, "button13_1"));
    button13_2 = GTK_WIDGET(gtk_builder_get_object (builder, "button13_2"));
    entry13_1 = GTK_WIDGET(gtk_builder_get_object (builder, "entry13_1"));
    entry13_2 = GTK_WIDGET(gtk_builder_get_object (builder, "entry13_2"));
    entry13_3 = GTK_WIDGET(gtk_builder_get_object (builder, "entry13_3"));
    entry13_4 = GTK_WIDGET(gtk_builder_get_object (builder, "entry13_4"));

    for (int i = 0; i < 8; i++)
    {
        label8[0][i] = gtk_label_new("");
        label8[1][i] = gtk_label_new("");
        label8[2][i] = gtk_label_new("");
        label8[3][i] = gtk_label_new("");
    }

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
    gtk_widget_show(window6);
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
        gtk_label_set_text((GtkLabel*) label2_4, "");
    } else
    {
        gtk_label_set_text((GtkLabel*) label2_4, "Wrong password!");
    }
    gtk_entry_set_text((GtkEntry*) entry2_1, "");
}
void on_button2_2_clicked(GtkButton *b)
{
    gtk_widget_hide(window2);
    gtk_widget_show(window1);
}
void on_button3_1_clicked(GtkButton *b)
{
    gtk_widget_hide(window3);
    gtk_widget_show(window4);
}
void on_button3_2_clicked(GtkButton *b)
{
    gtk_widget_hide(window3);
    gtk_widget_show(window9);
}
void on_button3_3_clicked(GtkButton *b)
{
    gtk_widget_hide(window3);
    gtk_widget_show(window11);
}
void on_button3_4_clicked(GtkButton *b)
{
    gtk_widget_hide(window3);
    gtk_widget_show(window10);
}
void on_button3_5_clicked(GtkButton *b)
{
    gtk_widget_hide(window3);
    gtk_widget_show(window1);
}
void on_button4_1_clicked(GtkButton *b)
{
    gtk_widget_hide(window4);
    gtk_widget_show(window3);
}
void on_button4_2_clicked(GtkButton *b)
{
    gtk_widget_hide(button4_2);
    gtk_widget_show(button4_3);
    gtk_widget_show(window5);
    strcpy(table_booking, "1");
}
void on_button4_4_clicked(GtkButton *b)
{
    gtk_widget_hide(button4_4);
    gtk_widget_show(button4_5);
    gtk_widget_show(window5);
    strcpy(table_booking, "2");
}
void on_button4_6_clicked(GtkButton *b)
{
    gtk_widget_hide(button4_6);
    gtk_widget_show(button4_7);
    gtk_widget_show(window5);
    strcpy(table_booking, "3");
}
void on_button4_8_clicked(GtkButton *b)
{
    gtk_widget_hide(button4_8);
    gtk_widget_show(button4_9);
    gtk_widget_show(window5);
    strcpy(table_booking, "4");
}
void on_button4_10_clicked(GtkButton *b)
{
    gtk_widget_hide(button4_10);
    gtk_widget_show(button4_11);
    gtk_widget_show(window5);
    strcpy(table_booking, "5");
}
void on_button4_12_clicked(GtkButton *b)
{
    gtk_widget_hide(button4_12);
    gtk_widget_show(button4_13);
    gtk_widget_show(window5);
    strcpy(table_booking, "6");
}
void on_button4_14_clicked(GtkButton *b)
{
    gtk_widget_hide(button4_14);
    gtk_widget_show(button4_15);
    gtk_widget_show(window5);
    strcpy(table_booking, "7");
}
void on_button4_16_clicked(GtkButton *b)
{
    gtk_widget_hide(button4_16);
    gtk_widget_show(button4_17);
    gtk_widget_show(window5);
    strcpy(table_booking, "8");
}
void on_button4_18_clicked(GtkButton *b)
{
    gtk_widget_hide(button4_18);
    gtk_widget_show(button4_19);
    gtk_widget_show(window5);
    strcpy(table_booking, "9");
}
void on_button4_20_clicked(GtkButton *b)
{
    gtk_widget_hide(button4_20);
    gtk_widget_show(button4_21);
    gtk_widget_show(window5);
    strcpy(table_booking, "10");
}
void on_button4_22_clicked(GtkButton *b)
{
    gtk_widget_hide(button4_22);
    gtk_widget_show(button4_23);
    gtk_widget_show(window5);
    strcpy(table_booking, "11");
}
void on_button4_24_clicked(GtkButton *b)
{
    gtk_widget_hide(button4_24);
    gtk_widget_show(button4_25);
    gtk_widget_show(window5);
    strcpy(table_booking, "12");
}
void on_button4_26_clicked(GtkButton *b)
{
    gtk_widget_hide(button4_26);
    gtk_widget_show(button4_27);
    gtk_widget_show(window5);
    strcpy(table_booking, "13");
}
void on_button5_1_clicked(GtkButton *b)
{
    char tmp1[100], tmp2[100], tmp3[100];
    sprintf(tmp1, "%s", gtk_entry_get_text((GtkEntry*) entry5_1));
    sprintf(tmp2, "%s", gtk_entry_get_text((GtkEntry*) entry5_2));
    if (!str_check1(tmp1))
    {
        gtk_label_set_text((GtkLabel*) label5_5, "Invalid Name!");
    } else
    if (!str_check2(tmp2))
    {
        gtk_label_set_text((GtkLabel*) label5_5, "Invalid Phone Number!");
    } else
    {
        booking(tmp1, tmp2, table_booking);
        gtk_widget_hide(window5);
        gtk_widget_hide(window4);
        gtk_widget_show(window6);
        gtk_label_set_text((GtkLabel*) label5_5, "");
        gtk_entry_set_text((GtkEntry*) entry5_1, "");
        gtk_entry_set_text((GtkEntry*) entry5_2, "");
        gtk_entry_set_text((GtkEntry*) entry5_3, "");
    }
}
void on_button5_2_clicked(GtkButton *b)
{
    gtk_widget_hide(window5);
    if (!strcmp(table_booking, "1"))
    {
        gtk_widget_hide(button4_3);
        gtk_widget_show(button4_2);
    }
    if (!strcmp(table_booking, "2"))
    {    
        gtk_widget_hide(button4_5);
        gtk_widget_show(button4_4);
    }
    if (!strcmp(table_booking, "3"))
    {    
        gtk_widget_hide(button4_7);
        gtk_widget_show(button4_6);
    }
    if (!strcmp(table_booking, "4"))
    {    
        gtk_widget_hide(button4_9);
        gtk_widget_show(button4_8);
    }
    if (!strcmp(table_booking, "5"))
    {
        gtk_widget_hide(button4_11);
        gtk_widget_show(button4_10);
    }
    if (!strcmp(table_booking, "6"))
    {    
        gtk_widget_hide(button4_13);
        gtk_widget_show(button4_12);
    }
    if (!strcmp(table_booking, "7"))
    {    
        gtk_widget_hide(button4_15);
        gtk_widget_show(button4_14);
    }
    if (!strcmp(table_booking, "8"))
    {    
        gtk_widget_hide(button4_17);
        gtk_widget_show(button4_16);
    }
    if (!strcmp(table_booking, "9"))
    {    
        gtk_widget_hide(button4_19);
        gtk_widget_show(button4_18);
    }
    if (!strcmp(table_booking, "10"))
    {    
        gtk_widget_hide(button4_21);
        gtk_widget_show(button4_20);
    }
    if (!strcmp(table_booking, "11"))
    {    
        gtk_widget_hide(button4_23);
        gtk_widget_show(button4_22);
    }
    if (!strcmp(table_booking, "12"))
    {    
        gtk_widget_hide(button4_25);
        gtk_widget_show(button4_24);
    }
    if (!strcmp(table_booking, "13"))
    {    
        gtk_widget_hide(button4_27);
        gtk_widget_show(button4_26);
    }
}
void on_button6_1_clicked(GtkButton *b)
{
    gtk_widget_hide(window6);
    gtk_widget_show(window1);
}
void on_button6_2_clicked(GtkButton *b)
{
    gtk_widget_show(window7);
}
void on_button7_1_clicked(GtkButton *b)
{
    char tmp1[100], tmp2[100];
    sprintf(tmp1, "%s", gtk_entry_get_text((GtkEntry*) entry7_1));
    sprintf(tmp2, "%s", gtk_entry_get_text((GtkEntry*) entry7_2));  
    if(!check_table(tmp1, tmp2))
    {
        gtk_label_set_text((GtkLabel*) label7_4, "Invalid Table or Phone number!");
    } else
    {
        items tmp[500];
        FILE *Menu = fopen("txt/Menu.txt", "r");
        for (int i = 0; i < 10; i++)
            fscanf(Menu, "%s%f", &tmp[i].item, &tmp[i].price);
        tmp[0].qty = (int)gtk_spin_button_get_value(GTK_SPIN_BUTTON(spin6_1));
        tmp[1].qty = (int)gtk_spin_button_get_value(GTK_SPIN_BUTTON(spin6_2));
        tmp[2].qty = (int)gtk_spin_button_get_value(GTK_SPIN_BUTTON(spin6_3));
        tmp[3].qty = (int)gtk_spin_button_get_value(GTK_SPIN_BUTTON(spin6_4));
        tmp[4].qty = (int)gtk_spin_button_get_value(GTK_SPIN_BUTTON(spin6_5));
        tmp[5].qty = (int)gtk_spin_button_get_value(GTK_SPIN_BUTTON(spin6_6));
        tmp[6].qty = (int)gtk_spin_button_get_value(GTK_SPIN_BUTTON(spin6_7));
        tmp[7].qty = (int)gtk_spin_button_get_value(GTK_SPIN_BUTTON(spin6_8));
        tmp[8].qty = (int)gtk_spin_button_get_value(GTK_SPIN_BUTTON(spin6_9));
        tmp[9].qty = (int)gtk_spin_button_get_value(GTK_SPIN_BUTTON(spin6_10));
        
        if (check_goods("carrot", 220 * (tmp[0].qty + tmp[2].qty + tmp[5].qty + tmp[7].qty), "grams") &&
            check_goods("ginger", 53 * (tmp[1].qty + tmp[7].qty + tmp[8].qty), "grams") &&
            check_goods("beef", 454 * (tmp[1].qty + tmp[2].qty), "grams") &&
            check_goods("coconut", 53 * (tmp[3].qty + tmp[4].qty + tmp[6].qty + tmp[9].qty), "grams"))
        {
            export_goods("carrot", 220 * (tmp[0].qty + tmp[2].qty + tmp[5].qty + tmp[7].qty), "grams");
            export_goods("ginger", 53 * (tmp[1].qty + tmp[7].qty + tmp[8].qty), "grams");
            export_goods("beef", 454 * (tmp[1].qty + tmp[2].qty), "grams");
            export_goods("coconut", 53 * (tmp[3].qty + tmp[4].qty + tmp[6].qty + tmp[9].qty), "grams");

            order(tmp2, 10, tmp);

            gtk_widget_hide(window7);   
            gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin6_1), 0);
            gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin6_2), 0);
            gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin6_3), 0);
            gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin6_4), 0);
            gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin6_5), 0);
            gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin6_6), 0);
            gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin6_7), 0);
            gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin6_8), 0);
            gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin6_9), 0);
            gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin6_10), 0);
            gtk_label_set_text((GtkLabel*) label7_4, "");
        } else
        {
            gtk_label_set_text((GtkLabel*) label7_4, "Sorry, your ordered items are now out-of-stock.");
        }
    }
    gtk_entry_set_text((GtkEntry*) entry7_1, "");
    gtk_entry_set_text((GtkEntry*) entry7_2, "");
}
void on_button7_2_clicked(GtkButton *b)
{
    gtk_widget_hide(window7);
    gtk_widget_show(window6);
}
void on_button8_1_clicked(GtkButton *b)
{
    gtk_widget_hide(window8);
    gtk_widget_show(window3);
}
void on_scrollbar8_1_value_changed(GtkRange *r)
{
    int i = (int) gtk_range_get_value(r);

    if (i + 8 <= row)
        for (int j = i; j < i + 8; j++)
        {
            gtk_label_set_text((GtkLabel*) label8[0][j-i], rowtext[0][j]);
            gtk_label_set_text((GtkLabel*) label8[1][j-i], rowtext[1][j]);
            gtk_label_set_text((GtkLabel*) label8[2][j-i], rowtext[2][j]);
            gtk_label_set_text((GtkLabel*) label8[3][j-i], rowtext[3][j]);
        }
}
void on_button9_1_clicked(GtkButton *b)
{
    for (int i = 0; i < 8; i++)
    {
        gtk_label_set_text((GtkLabel*) label8[0][i], "");
        gtk_label_set_text((GtkLabel*) label8[0][i], "");
        gtk_label_set_text((GtkLabel*) label8[0][i], "");
        gtk_label_set_text((GtkLabel*) label8[0][i], "");
    }
    char tmp[100];
    sprintf(tmp, "%s", gtk_entry_get_text((GtkEntry*) entry9_2));
    
    int invoiceFound = 0;
	float total = 0;
	orders order;
    row = 0;
	FILE *printBill = fopen("dat/printBill.dat", "rb");
	while(fread(&order, sizeof(orders), 1, printBill))
	{
		g_print("%s,%s\n", order.table, tmp);
		if(!strcmp(order.table, tmp))
        {
			for(int i=0; i<order.numOfItems; i++){
				char tmp2[100];
				strcpy(tmp2, "Table: ");
				strcat(tmp2, order.table);
				gtk_label_set_text((GtkLabel*) label8_4, tmp2);
				strcpy(tmp2, order.date);
				gtk_label_set_text((GtkLabel*) label8_5, tmp2);
				strcpy(tmp2, "Customer's name: ");
				strcat(tmp2, get_name(order.table));
				gtk_label_set_text((GtkLabel*) label8_6, tmp2);
    			char tmp3[100];
    			sprintf(tmp3, "%s", gtk_entry_get_text((GtkEntry*) entry9_1));
				strcpy(tmp2, "Staff's name: ");
				strcat(tmp2, tmp3);
				gtk_label_set_text((GtkLabel*) label8_8, tmp2);
				total += order.itm[i].qty * order.itm[i].price;
                char tmp4[100];
                sprintf(tmp4, "%d", row + 1);
                rowtext[0][row] = malloc(strlen(tmp4)+1);
                strcpy(rowtext[0][row], tmp4);
                rowtext[1][row] = malloc(strlen(order.itm[i].item)+1);
                strcpy(rowtext[1][row], order.itm[i].item);
                sprintf(tmp4, "x%d", order.itm[i].qty);
                rowtext[2][row] = malloc(strlen(tmp4)+1);
                strcpy(rowtext[2][row], tmp4);
                sprintf(tmp4, "%.2f$ ", order.itm[i].qty * order.itm[i].price);
                rowtext[3][row] = malloc(strlen(tmp4)+1);
                strcpy(rowtext[3][row], tmp4);
                if (row < 8)
                {
                    gtk_grid_insert_row(GTK_GRID(grid8_1), row);
                    gtk_label_set_text((GtkLabel*) label8[0][row], rowtext[0][row]);
                    gtk_label_set_text((GtkLabel*) label8[1][row], rowtext[1][row]);
                    gtk_label_set_text((GtkLabel*) label8[2][row], rowtext[2][row]);
                    gtk_label_set_text((GtkLabel*) label8[3][row], rowtext[3][row]);
                    gtk_widget_set_name(label8[0][row], "label8");
                    gtk_widget_set_name(label8[1][row], "label8");
                    gtk_widget_set_name(label8[2][row], "label8");
                    gtk_widget_set_name(label8[3][row], "label8");
                    gtk_label_set_xalign((GtkLabel*) label8[1][row], 0.2);
                    gtk_label_set_xalign((GtkLabel*) label8[1][row], 0);
                    gtk_label_set_xalign((GtkLabel*) label8[2][row], 0);
                    gtk_label_set_xalign((GtkLabel*) label8[3][row], 1);
                    gtk_label_set_width_chars((GtkLabel*) label8[0][row], 4);
                    gtk_label_set_width_chars((GtkLabel*) label8[1][row], 23);
                    gtk_label_set_width_chars((GtkLabel*) label8[2][row], 4);
                    gtk_label_set_width_chars((GtkLabel*) label8[3][row], 15);
                    gtk_grid_attach(GTK_GRID(grid8_1), label8[0][row], 0, row, 1, 1);
                    gtk_grid_attach(GTK_GRID(grid8_1), label8[1][row], 1, row, 1, 1);
                    gtk_grid_attach(GTK_GRID(grid8_1), label8[2][row], 2, row, 1, 1);
                    gtk_grid_attach(GTK_GRID(grid8_1), label8[3][row], 3, row, 1, 1);
                }
                row++;
			}
			invoiceFound = 1;

            if (!strcmp(order.table, "1"))
            {
                gtk_widget_hide(button4_3);
                gtk_widget_show(button4_2);
            }
            if (!strcmp(order.table, "2"))
            {    
                gtk_widget_hide(button4_5);
                gtk_widget_show(button4_4);
            }
            if (!strcmp(order.table, "3"))
            {    
                gtk_widget_hide(button4_7);
                gtk_widget_show(button4_6);
            }
            if (!strcmp(order.table, "4"))
            {    
                gtk_widget_hide(button4_9);
                gtk_widget_show(button4_8);
            }
            if (!strcmp(order.table, "5"))
            {
                gtk_widget_hide(button4_11);
                gtk_widget_show(button4_10);
            }
            if (!strcmp(order.table, "6"))
            {    
                gtk_widget_hide(button4_13);
                gtk_widget_show(button4_12);
            }
            if (!strcmp(order.table, "7"))
            {    
                gtk_widget_hide(button4_15);
                gtk_widget_show(button4_14);
            }
            if (!strcmp(order.table, "8"))
            {    
                gtk_widget_hide(button4_17);
                gtk_widget_show(button4_16);
            }
            if (!strcmp(order.table, "9"))
            {    
                gtk_widget_hide(button4_19);
                gtk_widget_show(button4_18);
            }
            if (!strcmp(order.table, "10"))
            {    
                gtk_widget_hide(button4_21);
                gtk_widget_show(button4_20);
            }
            if (!strcmp(order.table, "11"))
            {    
                gtk_widget_hide(button4_23);
                gtk_widget_show(button4_22);
            }
            if (!strcmp(order.table, "12"))
            {    
                gtk_widget_hide(button4_25);
                gtk_widget_show(button4_24);
            }
            if (!strcmp(order.table, "13"))
            {    
                gtk_widget_hide(button4_27);
                gtk_widget_show(button4_26);
            }
		} else {
			FILE *copyBill = fopen("dat/copyBill.dat", "ab");
			fwrite(&order, sizeof(struct orders), 1, copyBill);
			fclose(copyBill);
		}
	}		        
    g_print("A\n");
	if(!invoiceFound){
		g_print("Sorry the invoice doesnot exists\n");
	} else
    {
        char tmp2[100];
        sprintf(tmp2, "%.2f", total);
        strcat(tmp2, "$");
        gtk_label_set_text((GtkLabel*) label8_12, tmp2);
        sprintf(tmp2, "%.2f", total*0.04);
        strcat(tmp2, "$");
        gtk_label_set_text((GtkLabel*) label8_13, tmp2);
        sprintf(tmp2, "%.2f", total*1.04);
        strcat(tmp2, "$");
        gtk_label_set_text((GtkLabel*) label8_14, tmp2);
        gtk_widget_hide(window9);
        gtk_widget_show_all(window8);
    }
	fclose(printBill);
	FILE *fileDel = fopen("dat/printBill.dat", "wb");
	fwrite(NULL, sizeof(NULL), 1, fileDel);
	fclose(fileDel);
	// copy file
	FILE *readCopy = fopen("dat/copyBill.dat", "rb");
	while(fread(&order, sizeof(struct orders), 1, readCopy)){
		FILE *copyBill = fopen("dat/printBill.dat", "ab");
		fwrite(&order, sizeof(struct orders), 1, copyBill);
		fclose(copyBill);
	}
	fclose(readCopy);
	FILE *fileDel1 = fopen("dat/copyBill.dat", "wb");
	fwrite(NULL, sizeof(NULL), 1, fileDel1);
	fclose(fileDel1);
}
void on_button9_2_clicked(GtkButton *b)
{
    gtk_widget_hide(window9);
    gtk_widget_show(window3);
}
void on_button10_1_clicked(GtkButton *b)
{   
    char tmp1[100], tmp2[100], tmp3[100], tmp4[100];
    sprintf(tmp1, "%s", gtk_entry_get_text((GtkEntry*) entry10_1));
    sprintf(tmp2, "%s", gtk_entry_get_text((GtkEntry*) entry10_2));
    sprintf(tmp3, "%s", gtk_entry_get_text((GtkEntry*) entry10_3));
    sprintf(tmp4, "%s", gtk_entry_get_text((GtkEntry*) entry10_4));
    report(tmp1, tmp3, tmp2, tmp4);
    system("RestaurantBill.csv");   
}
void on_button10_2_clicked(GtkButton *b)
{
    gtk_widget_hide(window10);
    gtk_widget_show(window3);
}
void on_button11_1_clicked(GtkButton *b)
{
    gtk_widget_hide(window11);
    gtk_widget_show(window12);
}
void on_button11_2_clicked(GtkButton *b)
{
    gtk_widget_hide(window11);
    gtk_widget_show(window13);
}
void on_button12_1_clicked(GtkButton *b)
{
    char tmp1[100], tmp2[100], tmp3[100];
    sprintf(tmp1, "%s", gtk_entry_get_text((GtkEntry*) entry12_1));
    sprintf(tmp2, "%s", gtk_entry_get_text((GtkEntry*) entry12_2));
    sprintf(tmp3, "%s", gtk_entry_get_text((GtkEntry*) entry12_3));
    gtk_entry_set_text((GtkEntry*) entry12_1, "");
    gtk_entry_set_text((GtkEntry*) entry12_2, "");
    gtk_entry_set_text((GtkEntry*) entry12_3, "");
    import_goods(tmp1, atoi(tmp2), tmp3);
}
void on_button12_2_clicked(GtkButton *b)
{
    gtk_widget_hide(window12);
    gtk_widget_show(window3);
}
void on_button13_1_clicked(GtkButton *b)
{
    char tmp1[100], tmp2[100], tmp3[100], tmp4[100];
    sprintf(tmp1, "%s", gtk_entry_get_text((GtkEntry*) entry13_1));
    sprintf(tmp2, "%s", gtk_entry_get_text((GtkEntry*) entry13_2));
    sprintf(tmp3, "%s", gtk_entry_get_text((GtkEntry*) entry13_3));
    sprintf(tmp4, "%s", gtk_entry_get_text((GtkEntry*) entry13_4));
    report2(tmp1, tmp3, tmp2, tmp4);
    system("Manage.csv");   
}
void on_button13_2_clicked(GtkButton *b)
{
    gtk_widget_hide(window13);
    gtk_widget_show(window3); 
}