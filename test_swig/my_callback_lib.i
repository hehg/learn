%module(directors="1") my_callback_lib
%feature("director") my_cxx_class;

%{
#include "my_cxx_class.h"
%}

%include "my_cxx_class.h"
