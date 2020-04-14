    ///////////////////////////////////////////////////////////////////////////////////
    //                        Trolley Vision NX                               
    //                        Ubuntu Linux v20.0.4
    //                        Vande Berg Scales
    ///////////////////////////////////////////////////////////////////////////////////

#include <gtk/gtk.h>
#include <gst/gst.h>
#include <gdk/gdkkeysyms.h>
#include <gst/app/gstappsink.h>

#include "Event.h"

#ifdef HAVEOPENCV 
	#include "opencv2/opencv.hpp" 
#endif	 
 





/////////////////////////////////////////////////////////////////
// Event hanlders. Must be extern "C"

extern "C" 
{
///////////////////////////////////////////////////////////////////
// Called from menu
void filemenuend(GtkMenuItem *menuitem, gpointer data)
{
	CleanUpandEndProgram((GtkMessageCustomData*)data);
}

///////////////////////////////////////////////////////////////////
// Called from close window button
void mainwindow_destroy(GtkWidget *object, gpointer data)
{
	CleanUpandEndProgram((GtkMessageCustomData*)data);
}

///////////////////////////////////////////////////////////////////
// Called from save image menu
void on_menuSaveImage_activate(GtkWidget *object, gpointer data)
{
	SaveImage( (GtkMessageCustomData*)data );
}

} //extern "C"
