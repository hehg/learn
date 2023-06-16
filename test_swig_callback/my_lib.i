%module (directors="1",threads="1") my_lib
%{
#include "my_lib.h"
%}

%feature("director") my_api_responder;

%include "my_lib.h"