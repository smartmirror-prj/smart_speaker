#include <iostream>
#include <Python.h>

using namespace std;

int main (int argc, char *const argv[])
{
	PyObject *pName, *pModule;	//for load python script
	PyObject *pget_eventTodayList;	//for python functions
	PyObject *pArgs, *pValue, *g_pArgs, *g_pValue;	//for get/set python function parameters

	Py_Initialize();

	//start set path
	PyObject *sys = PyImport_ImportModule("sys");
	PyObject *path = PyObject_GetAttrString(sys, "path");
	PyList_Append(path, PyString_FromString("."));

	//get python script
  	pName = PyString_FromString("quickstart");
	pModule = PyImport_Import(pName);
	Py_DECREF(pName);

	if (pModule != NULL)
	{
		pget_eventTodayList = PyObject_GetAttrString(pModule, "get_eventTodayList");	
	
        if ( !(pget_eventTodayList && PyCallable_Check(pget_eventTodayList)) )
        {
            if (PyErr_Occurred()) PyErr_Print();
            std::cout << "Cannot find function ''" << std::endl;
            return 1;
        }
        //pHelloworld : function without input/output

        PyObject_CallObject(pget_eventTodayList, NULL); //should be "get event list"
	}
	else
	{
		PyErr_Print();
		std::cout << "Failed to load 'calendar??'" << std::endl;
		return 1;
	}
	
	Py_Finalize();
	return 0;
}
