#include <gtk-3.0/gtk/gtk.h>
#include <stdlib.h>


static void set_us(GtkWidget *widget, gpointer data) {
    system("setxkbmap us");
}

static void set_se(GtkWidget *widget, gpointer data) {
    system("setxkbmap se");
}

static void activate (GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *button_us;
    GtkWidget *button_se;
    GtkWidget *button_box;

    window = gtk_application_window_new (app);
    gtk_window_set_title (GTK_WINDOW (window), "Window");
    gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);

    button_box = gtk_button_box_new (GTK_ORIENTATION_HORIZONTAL);
    gtk_container_add (GTK_CONTAINER (window), button_box);

    button_us = gtk_button_new_with_label ("US");
    g_signal_connect (button_us, "clicked", G_CALLBACK (set_us), NULL);
    g_signal_connect_swapped (button_us, "clicked", G_CALLBACK (gtk_widget_destroy), window);
    gtk_container_add (GTK_CONTAINER (button_box), button_us);

    button_se = gtk_button_new_with_label ("SE");
    g_signal_connect (button_se, "clicked", G_CALLBACK (set_se), NULL);
    g_signal_connect_swapped (button_se, "clicked", G_CALLBACK (gtk_widget_destroy), window);
    gtk_container_add (GTK_CONTAINER (button_box), button_se);

    gtk_widget_show_all (window);
}

int main (int argc, char **argv) {
    GtkApplication *app;
    int status;

    app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
    status = g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);

    return status;
}
