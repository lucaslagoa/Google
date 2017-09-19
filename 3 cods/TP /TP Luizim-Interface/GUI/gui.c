#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include "../entrada.h"
#include "gui.h"

static void changed_entry (GtkWidget *widget, gpointer   data);
static gboolean window_key_press_event_cb (GtkWidget *window, GdkEvent *event, GtkSearchBar *search_bar);
static void activate_cb (GtkApplication *app, gpointer user_data);
GtkTextBuffer *buffer;

int interface(gint argc, gchar *argv[]) {
	GtkApplication *app;

	app = gtk_application_new ("gtk.searchbar", G_APPLICATION_FLAGS_NONE);
	g_signal_connect (app, "activate", G_CALLBACK (activate_cb), NULL);
		
	return g_application_run (G_APPLICATION (app), argc, argv);
}

void get_entry(char* pala) {
	encontraPalavra(pala);	
}

void print_text_view (char* text){
	gtk_text_buffer_insert_at_cursor (buffer, text, -1);
}
void clean_text_view (){
	gtk_text_buffer_set_text (buffer, "", -1);
}


static void changed_entry (GtkWidget *widget, gpointer   data) {
	const gchar* texto_entry; 
	texto_entry = gtk_entry_get_text (data);  
	char * pala = strdup(texto_entry);

	get_entry(pala);
}


static gboolean window_key_press_event_cb (GtkWidget *window, GdkEvent *event, GtkSearchBar *search_bar) {
	return gtk_search_bar_handle_event (search_bar, event);
}

static void activate_cb (GtkApplication *app, gpointer user_data) {
	GtkWidget *window;
	GtkWidget *search_bar;
	GtkWidget *box;
	GtkWidget *entry;
	GtkWidget *menu_button;

	GtkWidget *view;
	GtkWidget* scrolledwindow = gtk_scrolled_window_new(NULL, NULL);
	
	GtkWidget * vbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
	
	window = gtk_application_window_new (app);
	gtk_window_set_title (GTK_WINDOW (window), "Window");
	gtk_window_set_default_size (GTK_WINDOW (window), 600, 400);
	gtk_widget_show (window);
	
	search_bar = gtk_search_bar_new ();
	gtk_box_pack_start (GTK_BOX (vbox), search_bar, FALSE, FALSE, 0);
	gtk_widget_show (search_bar);
	
	box = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 6);
	gtk_container_add (GTK_CONTAINER (search_bar), box);
	gtk_widget_show (box);

	entry = gtk_search_entry_new ();
	gtk_box_pack_start (GTK_BOX (box), entry, FALSE, FALSE, 0);
	gtk_widget_show (entry);

	menu_button = gtk_menu_button_new ();
	gtk_box_pack_start (GTK_BOX (box), menu_button, FALSE, FALSE, 0);
	gtk_widget_show (menu_button);
	
	view = gtk_text_view_new ();
	gtk_text_view_set_editable (GTK_TEXT_VIEW(view), FALSE);
	gtk_widget_show (view);
	
	buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (view));
	
	gtk_container_add(GTK_CONTAINER(scrolledwindow), view);
	gtk_box_pack_start (GTK_BOX (vbox), scrolledwindow, TRUE, TRUE, 0);
	gtk_widget_show (scrolledwindow);
	
	gtk_container_add (GTK_CONTAINER (window), vbox);
	gtk_widget_show (vbox);

	gtk_search_bar_connect_entry (GTK_SEARCH_BAR (search_bar), GTK_ENTRY (entry));
	g_signal_connect (window, "key-press-event", G_CALLBACK (window_key_press_event_cb), search_bar);
	g_signal_connect (entry, "changed", G_CALLBACK (changed_entry), entry);
}
