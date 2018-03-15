#include <stdio.h>
#include <Python.h>

int main(int argc, char * argv[])
{
    // initialize the interpreter
    Py_Initialize();
    // evaluate some code
    PyRun_SimpleString("import sys\n");
    //ignore line wrap on following line
    PyRun_SimpleString("sys.stdout.write('Hello from an embedded Python Script\\n')\n");
    // shut down the interpreter
    Py_Finalize();

    return 0;

}
