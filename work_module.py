
import numpy as np
import pvlib

def do_awesome_work(data):


    print('\nHello from Python work function!')

    data = np.asanyarray(data)
    
    print('data properties:')
    print(' shape: %s' % str(data.shape))
    print(' dtype: %s' % data.dtype)
    print(' values: %s' % data)


    # Do some work.
    value = np.sum(data)
    print('sending back the answer: %d' % value)
    
    
    return value
    
    
# def example_np_sum(data):
    # s = data.sum()
    
    # print('the sum from Python: %s' % s)
    
    # return s
    
    
    
# def example_np_change(data):
    # data[0] = 25.
    
    # return 1
    
    