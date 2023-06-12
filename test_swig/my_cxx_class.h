#ifndef MY_CXX_CLASS
#define MY_CXX_CLASS

class my_rsp_class
{
public:
   // my_rsp_class(){};
    virtual ~my_rsp_class(){};
    virtual void on_callback(int id,int size){};
};

extern void start();
extern void set_callback_obj(my_rsp_class*rsp);

#endif
