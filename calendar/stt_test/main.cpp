#include <iostream>
#include <thread>
//#include <Python.h>
#include <python2.7/Python.h>
#include <unistd.h>
#include <stdlib.h>
#include <cstring>

#include <sys/ipc.h> 
#include <sys/shm.h> 

using namespace std;

int SttFunc(void);

int main(int argc, char* argv[]){

    printf("%d\n", SttFunc());

    return 0;
}


int SttFunc(){
	PyObject *pName, *pModule;	    //for load python script
	PyObject *pgoogle_stt;	        //for python functions
	PyObject *g_pArgs, *g_pValue;	//for get/set python function parameters
    PyObject *pstt_func;
	Py_Initialize();
	//start set path
	PyObject *sys = PyImport_ImportModule("sys");
	PyObject *path = PyObject_GetAttrString(sys, "path");
	PyList_Append(path, PyString_FromString("."));

	/* get python script */
    pName = PyString_FromString("stt");
    assert(pName != NULL);
    pModule = PyImport_Import(pName);
    assert(pModule != NULL);
    pgoogle_stt = PyObject_GetAttrString(pModule, "google_stt");
    assert(pgoogle_stt != NULL);

    if (!(pgoogle_stt && PyCallable_Check(pgoogle_stt)) )
    {
        if (PyErr_Occurred()) PyErr_Print();
        std::cout << "Cannot find function ''" << std::endl;
        return 1;
    }

    g_pArgs = PyTuple_New(100); 
    assert(g_pArgs != NULL);
    g_pArgs = PyObject_CallObject(pgoogle_stt, NULL); 
    assert(g_pArgs != NULL);

    cout << "stt start" <<endl;

    Py_DECREF(pName);
    Py_DECREF(pModule);

    Py_Finalize();
    cout << "stt finish" <<endl;

    return 0;
}
