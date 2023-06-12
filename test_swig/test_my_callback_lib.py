import my_callback_lib as lib
import time
class my_rsp(lib.my_rsp_class):
    def __init__(self):
        lib.my_rsp_class.__init__(self)
    def on_callback(self, id, size):
        print("data")
        exit(0)
if __name__=="__main__":
    my=my_rsp()
    lib.set_callback_obj(my)
    lib.start()
   