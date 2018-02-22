#include <iostream>
#include <Python.h>

using namespace std;


int main (int argc, char *const argv[])
{
	PyObject *pArgs, *g_pArgs;	//for get/set python function parameters
	PyObject *pget_list;
    PyObject *pModule, *pName;
    string eventString;

    char* test;


    Py_Initialize();

	/* start set path */
	PyObject *sys = PyImport_ImportModule("sys");
	PyObject *path = PyObject_GetAttrString(sys, "path");
	PyList_Append(path, PyString_FromString("."));

	/* get python script */
  	pName = PyString_FromString("quickstart");
	pModule = PyImport_Import(pName);

	if (pModule != NULL)
	{
        pget_list	= PyObject_GetAttrString(pModule, "get_list");	

        if (!(pget_list && PyCallable_Check(pget_list)) )
        {
            if (PyErr_Occurred()) PyErr_Print();
            std::cout << "Cannot find function ''" << std::endl;
            return 1;
        }

        g_pArgs = PyTuple_New(100); if(!g_pArgs)    printf("41 : g_pArgs == NULL\n");
        g_pArgs = PyObject_CallObject(pget_list, NULL); if(!g_pArgs)    printf("g_pArgs == NULL\n");

        /* python module implementaion */
        puts("============================================================");
        puts("\t\t\t\t cpp start");
        puts("============================================================");
        if(!PyString_AsString(g_pArgs))
        // No event
            printf("No upcoming events found\n");
        else 
        // One or more events
           // printf("%s\n",PyString_AsString(g_pArgs));
            test = PyString_AsString(g_pArgs);
        if(!test)
            exit(0);
        printf("string test :\n %s\n",test);
        puts("============================================================");
        puts("\t\t\t\t cpp finish");
        puts("============================================================");
	}
	else
	{
		PyErr_Print();
		std::cout << "Failed to load 'calendar??'" << std::endl;
		return 1;
	}
	
    Py_DECREF(pget_list);
    printf("decref 0 \n");
    Py_DECREF(pModule);
    printf("decref 1 \n");
    Py_DECREF(pName);
    printf("decref 2 \n");
    Py_DECREF(g_pArgs);
    printf("decref 3 \n");
	Py_DECREF(pName);
    printf("decref 4 \n");

    Py_Finalize();

    printf("cpp End\n");

	return 0;
}



