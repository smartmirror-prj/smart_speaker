#include <iostream>
#include <Python.h>

using namespace std;

int main (int argc, char *const argv[])
{

    PyObject *pName, *pModule;  //for load python script
    PyObject *pgetCredentials, *pprint_calendar; //for python functions
//    PyObject *pArgs, *pValue;

    //get python script
    pName = PyString_FromString("quickstart");

    Py_Initialize();

    //start set path
    PyObject *sys = PyImport_ImportModule("sys");
    cout << "sys : "<< sys << endl;
    PyObject *path = PyObject_GetAttrString(sys, "path");
    cout << "path : "<< path << endl;
    PyList_Append(path, PyString_FromString("."));

    pModule = PyImport_Import(pName);
    Py_DECREF(pName);
                                
    if (pModule != NULL)
    {
        //module load
        pgetCredentials = PyObject_GetAttrString(pModule, "get_credentials");
        pprint_calendar = PyObject_GetAttrString(pModule, "print_calendar");

        //module load error check
        if ( !(pgetCredentials && PyCallable_Check(pgetCredentials)) )
        {
            if (PyErr_Occurred()) PyErr_Print();
            std::cout << "Cannot find function 'get_credeni'" << std::endl;
            return 1;
        }
        if ( !(pprint_calendar && PyCallable_Check(pprint_calendar)))
        {
            if (PyErr_Occurred()) PyErr_Print();
            cout << "Cannot find function 'calendar'" << std::endl;
            return 1;
        }

        PyObject_CallObject(pgetCredentials, NULL);
    }
    else {
        PyErr_Print();
        exit(1);
    }

    Py_Finalize();

    return 0;
}
