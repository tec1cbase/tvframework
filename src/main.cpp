    ///////////////////////////////////////////////////////////////////////////////////
    //                        Trolley Vision NX                               
    //                        Ubuntu Linux v20.0.4
    //                        Vande Berg Scales
    ///////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <gtk/gtk.h>
#include <gst/gst.h>
#include <gdk/gdkkeysyms.h>
#include <gst/app/gstappsink.h>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp> 
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include "include/tcamimage.h"
#include "include/Event.h"

GtkWidget *g_lbl_hello;
GtkWidget *g_lbl_count;


int main(int argc, char *argv[])
{
    GtkBuilder      *builder; 
    GtkWidget       *window;

  	GstElement *displaysink;     
	GstElement *pipeline;
 
 gtk_init(&argc, &argv);

    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "glade/gladegui.glade", NULL);

    window = GTK_WIDGET(gtk_builder_get_object(builder, "TrolleyVisionNX"));
    gtk_builder_connect_signals(builder, NULL);
    
    // get pointers to the two labels
    g_lbl_hello = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_hello"));
    g_lbl_count = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_count"));

    g_object_unref(builder);

    gtk_widget_show(window);                
    gtk_main();

    return 0;
}
///////////////////////////////////////////////////////////////
 
 

/////////////////////////////////////////////////////////////////
// Event hanlders. Must be extern "C"

extern "C" 
{
// called when button is clicked
void on_btn_hello_clicked()
{
    static unsigned int count = 0;
    char str_count[30] = {0};
    
    gtk_label_set_text(GTK_LABEL(g_lbl_hello), "Hello, world!");
    count++;
    sprintf(str_count, "%d", count);
    gtk_label_set_text(GTK_LABEL(g_lbl_count), str_count);
}

// called when window is closed
void on_window_main_destroy()
{
    gtk_main_quit();
}
//extern "C"
