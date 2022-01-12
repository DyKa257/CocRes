#include <gtk/gtk.h>

static void
print_hello (GtkWidget *widget,
             gpointer   data)
{
  g_print ("Hello World\n");
}

int
main (int   argc,
      char *argv[])
{
  GtkBuilder *builder;
  GtkWidget *window;
  //GtkWidget *fixed;
  GtkWidget *button;

  gtk_init (&argc, &argv);

  builder = gtk_builder_new ();
  gtk_builder_add_from_file (builder, "builder.ui", NULL);

  window = GTK_WIDGET(gtk_builder_get_object (builder, "window1"));
  g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);

  //fixed = GTK_WIDGET(gtk_builder_get_object(builder, "fixed1"));

  button = GTK_WIDGET(gtk_builder_get_object (builder, "button1"));
  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);

  button = GTK_WIDGET(gtk_builder_get_object (builder, "button2"));
  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);

  button = GTK_WIDGET(gtk_builder_get_object (builder, "button3"));
  g_signal_connect (button, "clicked", G_CALLBACK (gtk_main_quit), NULL);

  gtk_main ();

  return 0;
}