#include "supplied.h"
#include "omp.h"

int main() 
{
    int array[SIZE];

    int num_data = fill_array(array);

    //Parallel overhead - setting everything up to be in parallel
    int N = 4;      //Number of threads
    int range = num_data/N; 
    int sum = 0;
    int total_sum = 0;
/*
  #pragma omp parallel private(sum) num_threads(N)
  {
    int first_index = omp_get_thread_num() * range;
    int last_index = first_index + range;
    sum = 0;

    for (int i = first_index; i < last_index && i < SIZE; ++i)
    {
       sum += array[i];
    }
   //#pragma omp critical
    {
      //let's see what the final count value is for each thread locally
      cout << omp_get_thread_num() <<" " <<sum <<endl;
      total_sum += sum;
    }
  }
  cout << "The total sum is: " <<total_sum <<endl;

  total_sum = 0;
    #pragma omp parallel num_threads(N)
  {
    #pragma omp for reduction (+:total_sum)
      for(int i = 0; i < num_data; ++i)
          total_sum += array[i];
  }
  cout << "The total sum is: " << total_sum << endl;

  total_sum = 0;
    #pragma omp parallel for reduction(+:total_sum)num_threads(N)
        for (int i =0; i < num_data; ++i)
            total_sum += array[i];
  cout << "The total sum is: " << total_sum << endl;
  */

    int local_max = 0;
    int max = 0;
    #pragma omp parallel private(local_max)num_threads(N)
    {
        int first_index = omp_get_thread_num() * range;
        int last_index = first_index + range;
        for(int i = first_index; i < last_index; ++i)
        {
            if(array[i] > local_max)
                local_max = array[i];
        }
    #pragma omp critical
    {
        cout << omp_get_thread_num() << " " << local_max << endl;
        if(local_max > max)
            max = local_max;
    }
    }
    cout << "The max is: " << max << endl;

  return 0;
}
