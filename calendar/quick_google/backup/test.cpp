#include <iostream>
#include <Python.h>

using namespace std;

int main(int argc,char** argv)
{
    PyObject *pName, *pModule; 
    PyObject *hello;

    Py_Initialize();

    PyObject *sys = PyImport_ImportModule("sys");
    PyObject *path = PyObject_GetAttrString(sys,"path");
    PyList_Append(path, PyString_FromString("."));

    pName = PyString_FromString("ptest");
    pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    if(pModule != NULL)   
    {
        hello = PyObject_GetAttrString(pModule, "hello");

    }
    return 1;
}
