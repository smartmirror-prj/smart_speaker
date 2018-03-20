#include <iostream>
#include <string>
#include <python2.7/Python.h>
#include <assert.h>

#define UNSET   0
#define SET     1
#define STT     2

using namespace std;

int event_tts(char* event_list);
int calendar(char* event_list);
int stt(void);


//    switch(pid)
//    {
//        case -1:
//            printf("fork faile\n");
//            return -1;
//            break;
//        case 0:
//            break;
//        default:
//            break;
//    }

int main (int argc, char *const argv[])
{
    pid_t pid;
//  char* event_list = NULL;

    record_check();

    // =========================================
    // file create check
    // =========================================

    return 0;
}


// =========================================
// file create check
// =========================================
int record_check()
{
    if(!system("./record_to_wav_level_check"))
        exit (EXIT_FAILURE);
    if(system("./record_to_wav_level_check") == -1)
    {
        //error(_("fork error: %s"), snd_strerror(err));
        error("fork error");
        return -1;
    }
    if(system("./record_to_wav_level_check") == 0)
    {
        error("No shell is available");
        return 0;
    }
}

int calendar(char* event_list)
{
	PyObject *pArgs, *g_pArgs;	//for get/set python function parameters
	PyObject *pget_list;
    PyObject *pModule, *pName;

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
            cout << "Cannot find function ''" << endl;
            return 1;
        }

        g_pArgs = PyTuple_New(100);                      
		assert(g_pArgs != NULL);
        g_pArgs = PyObject_CallObject(pget_list, NULL); 
        assert(g_pArgs != NULL);

 	    /* python module implementaion */
        puts("============================================================");
        puts("\t\t\tmain.cpp start                                        ");
        puts("============================================================");
        if(!PyString_AsString(g_pArgs)) // No event
            printf("No upcoming events found\n");
        else {// One or more events
            printf("%s\n",PyString_AsString(g_pArgs));
            event_list = PyString_AsString(g_pArgs);
        }
        if(!event_list)
        {
            cout <<"event_list NULL " << event_list <<endl;
            return(-1);
        }
        else printf("python -> cpp : %s\n",event_list);
    }
    else
    {
        PyErr_Print();
        cout << "Failed to load google_stt" << endl;
        return 1;
    }

    Py_DECREF(pget_list);
    Py_DECREF(pModule);
    Py_DECREF(pName);
    Py_DECREF(g_pArgs);

    Py_Finalize();
    printf("cpp End\n");
}

int stt()
{
    char* buf;
    PyObject *pModule, *pName;
    PyObject *pGoogle_stt;

    cout << "stt func start\n" << endl;

    //Py_Initialize();
    Py_IsInitialized();

    /* start set path */
    PyObject *sys = PyImport_ImportModule("sys");
    PyObject *path = PyObject_GetAttrString(sys, "path");
    PyList_Append(path, PyString_FromString("."));

    pName = PyString_FromString("stt");
    assert(pName != NULL);
    pModule = PyImport_Import(pName);
    assert(pModule != NULL);
    pGoogle_stt = PyObject_GetAttrString(pModule, "google_stt");
    cout << "return : " << pGoogle_stt << endl;
    assert(pGoogle_stt != NULL);

    if (!(pGoogle_stt && PyCallable_Check(pGoogle_stt)) )
    {
        if (PyErr_Occurred()) PyErr_Print();
        std::cout << "Cannot find function 'stt'" << std::endl;
        return 1;
    }

    PyObject_CallObject(pGoogle_stt, NULL);

    Py_DECREF(pName);
    Py_DECREF(pModule);
    Py_DECREF(pGoogle_stt);
    Py_DECREF(sys);
    Py_DECREF(path);

    Py_Finalize();
    cout << "function finish "<<endl;

    return 0;
}

int event_tts(char* event_list)
{
    PyObject *pModule, *pName;
    PyObject *pttsNaver, *test, *pClass, *pInstance, *pCalendar_tts;
    PyObject *set_string;

    int buf = 0;

    char type[]="s";
    char pyFunc_tts[] = "calendar_tts";

    printf("event_tts function : %s\n",event_list);

//  Py_Initialize();
    Py_InitializeEx(0);

    /* start set path */
    PyObject *sys = PyImport_ImportModule("sys");
    PyObject *path = PyObject_GetAttrString(sys, "path");
    PyList_Append(path, PyString_FromString("."));

    pName = PyString_FromString("tts_naver");
    assert(pName != NULL);
    pModule = PyImport_Import(pName);
    assert(pName != NULL);
    pClass = PyObject_GetAttrString(pModule, "tts_class");
    assert(pClass != NULL);
    pInstance = PyInstance_New(pClass,NULL,NULL);
    assert(pInstance != NULL);

    pCalendar_tts = PyObject_CallMethod(pInstance, pyFunc_tts, type, event_list);
    assert(pCalendar_tts != NULL);

    Py_DECREF(pName);
    Py_DECREF(pClass);
    Py_DECREF(pInstance);
    Py_DECREF(pCalendar_tts);

//  Py_Finalize();
    if(Py_FinalizeEx() < 0)
        exit(120);
    return 1;

}


//for(int i=0;i<2;i++)
//{
//    switch(pyRun){
//        case UNSET:
//            printf("case UNSET : %d\n",pyRun);
//            break;
//        case SET:
//            result = event_tts(event_list);
//            printf("function event_tts resut : %d \n",result);
//            break;
//        case STT:
//            puts("============ stt test =============");
//            result = stt();
////            printf("function stt resut : %d  i: %d\n",result,i);
//            printf("function stt resut : %d  \n",result);
//            break;
//        default:
//            printf("case default : %d\n",pyRun);
//            break;
//    }
//}
