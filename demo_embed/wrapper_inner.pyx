
import numpy as np
cimport numpy as np

np.import_array()

from libcpp.vector cimport vector

import work_module

# Declare any Numpy C-API functions that I want to use.
cdef extern from "numpy/arrayobject.h":
     cdef object PyArray_SimpleNewFromData(int nd, np.npy_intp *dims, int typenum, void *data_ptr)


# Here is the Cython portion of the wrapper.
# Important: this function must be declared with "api" keyword!
cdef api void inner_work_1d(int num_x, double* data_ptr, double* answer_ptr):

    print('\nHello from Cython inner_work_1d!')

    # Convert input data into form useable by Python, with lots of help from Numpy.

    # http://www.mail-archive.com/cython-dev@codespeak.net/msg05823.html
    cdef int nd = 1
    cdef np.npy_intp* dims = [<np.npy_intp>num_x]  # analogous to: double a[4] = {0.5, 0.3, 0.1, 0.1}
    cdef int typenum = np.NPY_DOUBLE

    cdef np.ndarray data_np = PyArray_SimpleNewFromData(nd, dims, typenum, <void*>data_ptr)

    # Do the work.
    cdef double sum = work_module.do_awesome_work(data_np)

    # # Convert work results into a form useable by the calling C++ application.
    answer_ptr[0] = sum

    # Done.
    
    
cdef api void inner_work_2d(int num_x, int num_y, double* data_ptr, double* answer_ptr):

    print('\nHello from Cython inner_work_2d!')

    # Convert input data into form useable by Python, with lots of help from Numpy.
    cdef int nd = 2
    cdef np.npy_intp* dims = [<np.npy_intp>num_x, <np.npy_intp>num_y]
    cdef int typenum = np.NPY_DOUBLE

    cdef np.ndarray data_np = PyArray_SimpleNewFromData(nd, dims, typenum, <void*>data_ptr)

    # Do the work.
    cdef double sum = work_module.do_awesome_work(data_np)

    # # Convert work results into a form useable by the calling C++ application.
    answer_ptr[0] = sum

    
    # pure_py_test()

    # Done.

    

def pure_py_test():

    print('\nHello from a pure Python function inside the Cython module.')

    data = np.ones(5)
    work_module.do_awesome_work(data)
