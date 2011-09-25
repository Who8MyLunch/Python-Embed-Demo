
#include "wrapper_outer.hpp"
#include <iostream>


double* make_some_data_1d(int num)
{
    double* data = new double[num];

    for (int k=0; k < num; k++)
      {
         data[k] = (double)k;
      }
      
    return data;
}


double* make_some_data_2d(int num_x, int num_y)
{
    double* data = new double[num_x*num_y];

    for (int j=0; j < num_y; j++)
    {
        for (int i=0; i < num_x; i++)
        {
            data[i + num_x*j] = (double)(i + j);
        }
    }
      
    return data;
}



int main()
{
    std::cout << "\nHello from example_application.main!" << std::endl;

    // get ready for work.
    int num_x = 15;
    int num_y = 20;
    
    double* some_1d_data = make_some_data_1d(num_x);
    double* some_2d_data = make_some_data_2d(num_x, num_y);
    
    double* answer = new double[1];
    
    // Do some work.
    outer_work_1d(num_x, some_1d_data, answer);
    std::cout << "\nexample_application.main: answer_1d = " << *answer << std::endl;

    // Do more work on different data.
    outer_work_2d(num_x, num_y, some_2d_data, answer);
    std::cout << "\nexample_application.main: answer_2d = " << *answer << std::endl;
    

    // Done.
    return 0;
}



