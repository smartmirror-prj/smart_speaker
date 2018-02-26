#include <iostream>
#include <string>
#include <Python.h>

#define UNSET   0
#define SET     1

using namespace std;

int event_tts(char* event_list);


int main (int argc, char *const argv[])
{
	PyObject *pArgs, *g_pArgs;	//for get/set python function parameters
	PyObject *pget_list;
    PyObject *pModule, *pName;
    string eventString;
    int pyRun = SET, result= 0;

    char* event_list = NULL;

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
        pget_list = PyObject_GetAttrString(pModule, "get_list");	

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
        puts("\t\t\tmain.cpp start                                          ");
        puts("============================================================");
        if(!PyString_AsString(g_pArgs)) // No event
            printf("No upcoming events found\n");
        else // One or more events
           // printf("%s\n",PyString_AsString(g_pArgs));
            event_list = PyString_AsString(g_pArgs);
        if(!event_list)
        {
            cout <<"event_list NULL " << event_list <<endl;
            return(-1);
        }
        else{
            printf("python -> cpp : %s\n",event_list);
        } 
	}
	else
	{
		PyErr_Print();
		cout << "Failed to load 'calendar??'" << endl;
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

    Py_Finalize();
    printf("cpp End\n");

    switch(pyRun){
        case UNSET:
            printf("case UNSET : %d\n",pyRun);
            break;
        case SET:
            result = event_tts(event_list);
            printf("function event_tts resut : %d \n",result);
            break;
        default:
            printf("case default : %d\n",pyRun);
            break;
    }


	return 0;
}


int event_tts(char* event_list)
{
    PyObject *pModule, *pName;
    PyObject *pttsNaver, *test, * pClass, *pInstance;

    printf("event_tts in : %s\n",event_list);

    Py_Initialize();

	/* start set path */
  	PyObject *sys = PyImport_ImportModule("sys");
  	PyObject *path = PyObject_GetAttrString(sys, "path");
  	PyList_Append(path, PyString_FromString("."));

	/* get python script */
  	pName = PyString_FromString("naverTTS");
	pModule = PyImport_Import(pName);
    pClass = PyObject_GetAttrString(pmodule, "NaverTTS");
    assert(pClass != NULL);
    pInstance = PyInstance_New(pClass,NULL,NULL);

	if (pModule != NULL)
	{
        test = PyObject_GetAttrString(pModule, "test");	

//        if (!(pget_list && PyCallable_Check(pget_list)) )
//        {
//            if (PyErr_Occurred()) PyErr_Print();
//            std::cout << "Cannot find function ''" << std::endl;
//            return -1;
//        }
    } else {
        assert(pModule == NULL);
    }

//    result = PyObject_CallMethod(instance,"","()",  );
//    printf("result : %lf\n",PyInt_AsLong(result);

    Py_Finalize();

    return 1;
}


