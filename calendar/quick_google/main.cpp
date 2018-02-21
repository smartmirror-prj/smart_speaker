#include <iostream>
//#include <vector>
#include <Python.h>

using namespace std;


int main (int argc, char *const argv[])
{
	PyObject *pArgs, *pValue, *g_pArgs, *g_pValue;	//for get/set python function parameters
	PyObject *pget_list;
    PyObject *pModule, *pName, *pDict, *pFun;

    string eventString;

	Py_Initialize();

	//start set path
	PyObject *sys = PyImport_ImportModule("sys");
	PyObject *path = PyObject_GetAttrString(sys, "path");
	PyList_Append(path, PyString_FromString("."));

	//get python script
  	pName = PyString_FromString("quickstart");
	pModule = PyImport_Import(pName);
    pDict = PyModule_GetDict(pModule);

	Py_DECREF(pName);

	if (pModule != NULL)
	{
        pget_list	= PyObject_GetAttrString(pModule, "get_list");	
        pFun = PyDict_GetItemString(pDict, "get_list");
        if (PyCallable_Check(pFun)) 
        {
            PyObject_CallObject(pFun, NULL);
            printf("line 37 \n");
            if(pFun == NULL){
                printf("pFun == NULL");
                exit(0);
            }
            if(pget_list == NULL)
                printf("pget_list NULL\n");
            else 
                printf("Not null\n");
        }
        else 
        {
            PyErr_Print();
        }


        if (!(pget_list && PyCallable_Check(pget_list)) )
        {
            if (PyErr_Occurred()) PyErr_Print();
            std::cout << "Cannot find function ''" << std::endl;
            return 1;
        }

        g_pArgs = PyTuple_New(100);
        if(!g_pArgs)    printf("41 : g_pArgs == NULL\n");

        g_pArgs = PyObject_CallObject(pget_list, NULL);
        if(!g_pArgs)    printf("g_pArgs == NULL\n");

        printf("=======================\n %s\n",PyString_AsString(g_pArgs));
        
        // ========================== get str event ==========================
        
        printf("line 76\n");

//      eventString = PyString_AsString(g_pArgs);
//      pValue = PyObject_CallObject(pget_list, pArgs);
//      if(pValue != NULL)
//      {
//      }
	}
	else
	{
		PyErr_Print();
		std::cout << "Failed to load 'calendar??'" << std::endl;
		return 1;
	}
	
    Py_DECREF(pModule);
    Py_DECREF(pName);

    Py_DECREF(pDict);
    Py_DECREF(pFun);

	Py_Finalize();

	return 0;
}



