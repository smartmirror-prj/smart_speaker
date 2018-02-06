#include <iostream>
#include <Python.h>


#if defined(__APPLE__)
	#include <Python/Python.h>	//for compile in OSX
#else
	#include <Python.h>	//for compole in Linux
#endif

using namespace std;

int main(int argc,char** argv)
{
    PyObject *pName, *pModule;
    PyObject *pget_calendar_info, *ptime_check, *pget_credentials;

    Py_Initialize();
    
    // start set path
    PyObject *sys = PyImport_ImportModule("sys");
    PyObject *path = PyObject_GetAttrString(sys,"path");
    PyList_Append(path, PyString_FromString("."));

    // get python script
    pName = PyString_FromString("quickstart");
    pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    if(pModule != NULL)
    {
        // module load
        pget_calendar_info = PyObject_GetAttrString(pModule, "get_calendar_info");
        ptime_check = PyObject_GetAttrString(pModule, "time_check");
        pget_credentials = PyObject_GetAttrString(pModule,"get_credentials" );
        // module load error check
        if(!(pget_calendar_info && PyCallable_Check(pget_calendar_info)))
        {
            if(PyErr_Occurred()) PyErr_Print();
            cout << "Cannot find function 'get_calendar_info'"<< endl;
            return 1;
        }
        if(!(ptime_check && PyCallable_Check(ptime_check)))
        {
            if(PyErr_Occurred()) PyErr_Print();
            cout<< "Cannot find function 'time_check '"<< endl;
            return 1;
        }
        if(!(pget_credentials && PyCallable_Check(pget_credentials)))
        {
            if(PyErr_Occurred()) PyErr_Print();
            cout << "Cannot find function 'get_credentials'" <<endl;
            return 1;
        }
    }
    return 1;
}


