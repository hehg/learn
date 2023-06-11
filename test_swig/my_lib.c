
#include "my_lib.h"
#include <time.h>
 int     my_int_variable=100;
 double  my_double_variable = 3.0;
static const char* val="hh";
int get_int_variable(int val)
{
    int v=my_int_variable+val;
    return v;
}

double get_double_variable(double val)
{
    double v=my_double_variable+val;
    return v;
}
const char *get_my_time()
{
    time_t ltime;
    time(&ltime);
    return ctime(&ltime);
}