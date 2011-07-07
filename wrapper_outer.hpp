
#include <Python.h>              // needed for Py_Initialize() and Py_Finalize()
#include "wrapper_inner_api.h"   // needed for import_cython_demo(), which imports the work module.
#include <iostream>


int init_python()
{
    // Start the Python interpreter if it is not already running.
    if( !Py_IsInitialized() )
    {
        std::cout << "Starting Python interpreter" << std::endl;
        Py_Initialize();
    }
    
    // Make sure Python really is up and running.
    if( !Py_IsInitialized() )
    {
        // Oops!
        std::cout << "Unable to initialize Python interpreter." << std::endl;
        return 1;
    }

    // Done.
    return 0;
}




int outer_work_1d(int num_x, double* some_1d_data, double* answer)
{
    std::cout << "\nHello from outer_work_1d!" << std::endl;

    
    // Start Python.
    init_python();
    
    // Import the Cython-based Python extension module.
    import_wrapper_inner();

    // Call into the Python module and do some work.
    inner_work_1d(num_x, some_1d_data, answer);    // Defined in wrapper_inner_api.h
    
    //
    // NOTE: the following command will shut down the Python interpreter.  The problem is
    // that any DLLs used are not always released.  This will cause a crash if the interpreter
    // is restarted later from within the same process.  So far my "solution" is to simply not
    // shut down the interpreter programatically.  Instead it should shut down by itself when
    // the host application exits or the process is terminated.
    //    
    // Shutdown the Python interpreter.
    // std::cout << "Shutting down Python" << std::endl;    
    // Py_Finalize();

    return 0;
}




int outer_work_2d(int num_x, int num_y, double* some_2d_data, double* answer)
{
    std::cout << "\nHello from outer_work_2d!" << std::endl;
    
    // Start Python.
    init_python();
    
    // Import the Cython-based Python extension module.
    import_wrapper_inner();

    // Call into the Python module and do some work.
    inner_work_2d(num_x, num_y, some_2d_data, answer);    // Defined in wrapper_inner_api.h

    // Done.
    return 0;
}
