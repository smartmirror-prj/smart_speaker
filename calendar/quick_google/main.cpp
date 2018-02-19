#include <iostream>
#include <Python.h>

using namespace std;

int main (int argc, char *const argv[])
{
	PyObject *pName, *pModule;	//for load python script
	PyObject *get_eventTodayList_standnowtime;	//for python functions 현재시간기준 calendar event
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
        get_eventTodayList_standnowtime	= PyObject_GetAttrString(pModule, "get_eventTodayList_standnowtime");	
	
        if ( !(get_eventTodayList_standnowtime && PyCallable_Check(get_eventTodayList_standnowtime)) )
        {
            if (PyErr_Occurred()) PyErr_Print();
            std::cout << "Cannot find function ''" << std::endl;
            return 1;
        }
        //pget_eventTodayList : function without input/output
        PyObject_CallObject(get_eventTodayList_standnowtime, NULL); //should be "get event list -the event alram on state"
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
