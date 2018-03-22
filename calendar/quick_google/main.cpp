#include <iostream>
#include <errno.h>
#include <string>
#include <python2.7/Python.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

#define UNSET   0
#define SET     1
#define STT     2
#define DBUG    SET

using namespace std;

//void run_main(void);
int record_input_wav_exe(void);
int file_checkFunction();
int event_tts(char* event_list);
int calendar(char* event_list);
int stt(void);

string pi_name = "파이";
pthread_mutex_t mutx;
int run = 1;

int main (int argc, char *const argv[])
{
    pid_t pid;
    pthread_t t1,t2;
    void *thread_result;
    int record_state = 0;
    int state = 0;

    cout << "sys start" << endl;
    system("python quickstart.py");

//  pthread_create(&t1,NULL,thread_increment, &);
//  state = pthread_mutex_init(&mutx, NULL);
//  pid = fork();

//  while(run != 0){
//      record_state = record_input_wav_exe();
//      run_main();
//  }

    return 0;
}

// =========================================
// main run program
// =========================================
//void run_main()
//{
//    int file_check = 0;
//    char inputfile[] = {"./input.wav"};
//
//    file_check = access(inputfile , F_OK);
//
//    switch(file_check)
//    {
//        // No file 
//        case -1:
//            puts("No file");
//            break;
//        // Ok file 
//        case 0:
//        // ================== file check function =================
//            if(file_checkFunction()){
//                puts("no record");
//                run = 0;
//                break;
//            }
//            else {
//                puts("file size 44 over");
//                stt();
//            }
//            break;
//        // No file 
//        default:
//            puts("input file ok");
//            break;
//    }
//    return;
//}

// =========================================
// file check function
// =========================================
int file_checkFunction()
{
    struct stat st;
    long long size;

    stat("./input.wav", &st);
    size = st.st_size;

    if(size <= 100){
        if(DBUG) printf("No record file %lld\n",size);
        return -1;
    } else {
        if(DBUG) printf("input.wav file size : %lld\n",size);
        return 1;
    }
}



// =========================================
// input.wav file create
// =========================================
int record_input_wav_exe()
{
    int check = 0;

    check = system("./record_to_wav_level_check");

    if(check != NULL)
    {
        perror("record program NULL error");
        exit (EXIT_FAILURE);
    }
    if(check == -1)
    {
        perror("fork error");
        return -1;
    }
    if(check == 0)
    {
        perror("No shell is available");
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

    Py_Finalize();
//  if(Py_FinalizeEx() < 0)
//      exit(120);
    return 1;

}

