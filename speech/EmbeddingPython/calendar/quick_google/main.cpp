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
    Py_Initalize();
    
    // start set path
    PyObject *sys = PyImport_ImportMoule("sys");
    PyObject *path = PyObject_GetAttrString(sys,"path");
    PyList_Append(path, PyString_FromString("."));

    // get python script
    pName = PyString_FromString("quickstart");
    pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    if(pModule != NULL)
    {
        // module load
        pget_calendar_info = Pyobject_GetAttrString(pModule, "get_calendar_inof")
        ptime_check = PyObject_GetAttrString(pModule, "time_check")
        pget_credentials = PyObject_GetAttrString(pModule,"get_credentials" )
        // module load error check
        if(!(pget_calendar_info && Pycasllable_Check(pget_calendar_info)))
        {
            if(PyErr_Occuerred()) PyErr_Print();
            cout << "Cannot find function 'get_calendar_info'"<< endl;
            return 1;
        }

    }


