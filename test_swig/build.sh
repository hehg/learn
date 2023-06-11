swig -python my_lib.i

#clean 
rm *.so *.pyc *_wrap.c

#user python2.7
python_libs_include=`python-config --includes`
python_libs_dir=`python-config --prefix`/lib
clang -o _my_lib.so -fpic -shared my_lib.c my_lib_wrap.c $python_libs_include -L$python_libs_dir -lpython

#user python3.9

#python_libs_include=/Library/Developer/CommandLineTools/Library/Frameworks/Python3.framework/Headers
#python_libs_dir=/Library/Developer/CommandLineTools/Library/Frameworks/Python3.framework/Versions/Current/lib/
#clang++ -o _my_lib.so -fpic -shared my_lib.c my_lib_wrap.c -I$python_libs_include -L$python_libs_dir -lpython3.8

