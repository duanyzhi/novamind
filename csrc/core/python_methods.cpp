#include "libs/python_methods.h"
#include "libs/ops.h"

//namespace novamind {
//
//void NovaMindToPythonMethods(py::module& m) {
//  m.def("relu");
//}
//}  // namespace novamind

PYBIND11_MODULE(nm, m) {
    m.doc() = "pybind11 novamind plugin"; // optional module docstring

    m.def("relu", &novamind::relu, "Relu function.");
}
