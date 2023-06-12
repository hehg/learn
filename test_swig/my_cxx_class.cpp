#include "my_cxx_class.h"
#include <unistd.h>
#include <stdio.h>
#include <thread>
static my_rsp_class *s_my_rsp = nullptr;
void start()
{
    std::thread t([]()
                  {
    for(int i=0;i<5;i++){
        sleep(1);
        if(s_my_rsp){
            char data[128];
            sprintf(data,"this is test %d\n",i);
            printf("callback\n");
            s_my_rsp->on_callback(i,128);
        }
    } });
    t.join();
}
void set_callback_obj(my_rsp_class *rsp)
{
    printf("set callback obj\n");
    s_my_rsp = rsp;
}