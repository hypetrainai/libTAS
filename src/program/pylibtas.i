%module pylibtas

%{
#include "../shared/AllInputs.h"
#include "../shared/messages.h"
#include "../shared/SharedConfig.h"
#include "../shared/sockethelpers.h"

#include "GameLoop.h"
#include "MovieFile.h"
#define SWIG_FILE_WITH_INIT
#define SWIGWORDSIZE64
%}

%init %{
import_array();
%}

%include "stdint.i"
%include "std_string.i"
%include "std_vector.i"
%include "typemaps.i"
%include "numpy.i"

%typemap(in) int [ANY] (int temp[$1_dim0]) {
  int i;
  if (!PySequence_Check($input)) {
    PyErr_SetString(PyExc_ValueError,"Expected a sequence");
    return NULL;
  }
  if (PySequence_Length($input) != $1_dim0) {
    PyErr_SetString(PyExc_ValueError,"Size mismatch. Expected $1_dim0 elements");
    return NULL;
  }
  for (i = 0; i < $1_dim0; i++) {
    PyObject *o = PySequence_GetItem($input,i);
    if (PyInt_Check(o)) {
      temp[i] = (int) PyInt_AsLong(o);
    } else {
      PyErr_SetString(PyExc_ValueError,"Sequence elements must be numbers");      
      return NULL;
    }
  }
  $1 = temp;
}

%typemap(memberin) int [ANY] {
  int i;
  for (i = 0; i < $1_dim0; i++) {
      $1[i] = $input[i];
  }
}

%typemap(out) int [ANY] {
  int i;
  $result = PyList_New($1_dim0);
  for (i = 0; i < $1_dim0; i++) {
    PyObject *o = PyInt_FromLong((long) $1[i]);
    PyList_SetItem($result,i,o);
  }
}

%include "../shared/AllInputs.h"
%include "../shared/lcf.h"
%include "../shared/messages.h"
%include "../shared/SharedConfig.h"
%include "../shared/SingleInput.h"

%ignore receiveData;
%apply int* OUTPUT { int* elem };
%apply unsigned long* OUTPUT { unsigned long* elem };
%apply (unsigned char* ARGOUT_ARRAY1, int DIM1) { (unsigned char* elem, int size) };
%include "../shared/sockethelpers.h"

%include "MovieFile.h"

void launchGameThread(
    const std::string& gamepath,
    const std::string& libtaspath,
    const std::string& gameargs = "",
    int startframe = 0,
    const std::string& libdir = "",
    const std::string& rundir = "",
    int logging_status = SharedConfig::LOGGING_TO_CONSOLE,
    bool opengl_soft = true,
    const std::string& llvm_perf = "",
    bool attach_gdb = false);
