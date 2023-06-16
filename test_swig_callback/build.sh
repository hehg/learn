
#user python2.7
python_libs_include=`python-config --includes`
python_libs_dir=`python-config --prefix`/lib

swig -c++ -python -threads my_lib.i

clang++ -o _my_lib.so -fpic -std=c++11 -shared my_lib.cpp my_lib_wrap.cxx $python_libs_include -L$python_libs_dir -lpython