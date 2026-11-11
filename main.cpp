#include <iostream>
#include <omp.h>
using namespace std;
int main()
{
omp_set_dynamic(0); // keep requested thread count
#pragma omp parallel for num_threads(4) schedule(static, 2)
for (int i = 1; i <= 12; i++)
{
int tid = omp_get_thread_num(); #pragma omp critical // current thread ID
// one line at a time
{
cout << "Thread " << tid
<< " executes iteration " << i << endl;
}
}
return 0;
}