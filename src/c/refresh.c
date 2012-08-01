#include <gtk/gtk.h>
#include <Python.h>

void send_refresh_signal(void)
{
    GdkEventClient event;
    gtk_init(NULL, NULL);
    event.type = GDK_CLIENT_EVENT;
    event.send_event = TRUE;
    event.window = NULL;
    event.message_type = gdk_atom_intern("_GTK_READ_RCFILES", FALSE);
    event.data_format = 8;
    gdk_event_send_clientmessage_toall((GdkEvent *)&event);
}

static PyObject* py_refresh(PyObject* self, PyObject* args) {
    send_refresh_signal();
    Py_INCREF(Py_None);
    return Py_None;
}

static PyMethodDef refresh_methods[] = {
    {"refresh", py_refresh, METH_VARARGS, "Refresh GTK Session"},
    {NULL, NULL, 0, NULL}
};

PyMODINIT_FUNC initrefresh() {
    (void) Py_InitModule("refresh", refresh_methods);
}

