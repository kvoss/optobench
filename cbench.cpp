#include "Python.h"
#include <vector>
#include "bss.hpp"

namespace {
PyObject *
py_bench(PyObject *, PyObject *args, double (*fun)(const std::vector<double>&))
{
    PyObject *lst;
    if (!PyArg_ParseTuple(args, "O", &lst))
        return NULL;
    if (!PyList_Check(lst)) {
        PyErr_SetString(PyExc_TypeError, "expected a list");
        return NULL;
    }

    Py_ssize_t len = PyList_Size(lst);
    if (len < 2) {
        PyErr_SetString(PyExc_ValueError, "expected a list of length >=2");
        return NULL;
    }

    std::vector<double> xs;
    xs.reserve(len);
    for (Py_ssize_t idx = 0; idx < len; ++idx) {
        PyObject *px = PyList_GetItem(lst, idx);
        double d = PyFloat_AsDouble(px);
        xs.push_back(d);
    }

    double ret = fun(xs);
    PyObject *v = Py_BuildValue("d", ret);
    return v;
}
}

PyObject *
py_ackley(PyObject *self, PyObject *args)
{
    return py_bench(self, args, ackley);
}

PyObject *
py_alpine(PyObject *self, PyObject *args)
{
    return py_bench(self, args, alpine);
}

PyObject *
py_six_hump_camel_back(PyObject *self, PyObject *args)
{
    return py_bench(self, args, six_hump_camel_back);
}

PyObject *
py_dejong5(PyObject *self, PyObject *args)
{
    return py_bench(self, args, dejong5);
}

PyObject *
py_deceptive3(PyObject *self, PyObject *args)
{
    return py_bench(self, args, deceptive3);
}

PyObject *
py_drop_wave(PyObject *self, PyObject *args)
{
    return py_bench(self, args, drop_wave);
}

PyObject *
py_easom(PyObject *self, PyObject *args)
{
    return py_bench(self, args, easom);
}

PyObject *
py_penalty1(PyObject *self, PyObject *args)
{
    return py_bench(self, args, penalty1);
}

PyObject *
py_parabola(PyObject *self, PyObject *args)
{
    return py_bench(self, args, parabola);
}

PyObject *
py_michalewicz(PyObject *self, PyObject *args)
{
    return py_bench(self, args, michalewicz);
}

PyObject *
py_non_cont_rastrigin(PyObject *self, PyObject *args)
{
    return py_bench(self, args, rastrigin);
}

PyObject *
py_rastrigin(PyObject *self, PyObject *args)
{
    return py_bench(self, args, rastrigin);
}

PyObject *
py_rosenbrock(PyObject *self, PyObject *args)
{
    return py_bench(self, args, rosenbrock);
}

PyObject *
py_griewank(PyObject *self, PyObject *args)
{
    return py_bench(self, args, griewank);
}

PyObject *
py_goldstein_price(PyObject *self, PyObject *args)
{
    return py_bench(self, args, goldstein_price);
}

PyObject *
py_axis_parallel_hyperellipsoid(PyObject *self, PyObject *args)
{
    return py_bench(self, args, axis_parallel_hyperellipsoid);
}

PyObject *
py_step(PyObject *self, PyObject *args)
{
    return py_bench(self, args, step);
}

PyObject *
py_schaffers_f6(PyObject *self, PyObject *args)
{
    return py_bench(self, args, schaffers_f6);
}

PyObject *
py_schwefels_p222(PyObject *self, PyObject *args)
{
    return py_bench(self, args, schwefels_p222);
}

PyObject *
py_shubert(PyObject *self, PyObject *args)
{
    return py_bench(self, args, shubert);
}

PyObject *
py_sphere(PyObject *self, PyObject *args)
{
    return py_bench(self, args, sphere);
}

PyObject *
py_tripod(PyObject *self, PyObject *args)
{
    return py_bench(self, args, tripod);
}

PyObject *
py_trefethen4(PyObject *self, PyObject *args)
{
    return py_bench(self, args, trefethen4);
}

static PyMethodDef CBenchMethods[] = {
    {"ackley", py_ackley, METH_VARARGS, "Ackley function"},
    {"alpine", py_alpine, METH_VARARGS, "Alpine function"},
    {"six_hump_camel_back", py_six_hump_camel_back, METH_VARARGS, "six_hump_camel_back function"},
    {"dejong5", py_dejong5, METH_VARARGS, "dejong5 function"},
    {"deceptive3", py_deceptive3, METH_VARARGS, "deceptive3 function"},
    {"drop_wave", py_drop_wave, METH_VARARGS, "drop_wave function"},
    {"easom", py_easom, METH_VARARGS, "easom function"},
    {"penalty1", py_penalty1, METH_VARARGS, "penalty1 function"},
    {"parabola", py_parabola, METH_VARARGS, "parabola function"},
    {"michalewicz", py_michalewicz, METH_VARARGS, "michalewicz function"},
    {"non_cont_rastrigin", py_non_cont_rastrigin, METH_VARARGS, "non-continuous rastrigin function"},
    {"rastrigin", py_rastrigin, METH_VARARGS, "rastrigin function"},
    {"rosenbrock", py_rosenbrock, METH_VARARGS, "rosenbrock function"},
    {"griewank", py_griewank, METH_VARARGS, "griewank function"},
    {"goldstein_price", py_goldstein_price, METH_VARARGS, "griewank function"},
    {"axis_parallel_hyperellipsoid", py_axis_parallel_hyperellipsoid, METH_VARARGS, "axis_parallel_hyperellipsoid function"},
    {"step", py_step, METH_VARARGS, "step function"},
    {"schaffers_f6", py_schaffers_f6, METH_VARARGS, "schaffers_f6 function"},
    {"schwefels_p222", py_schwefels_p222, METH_VARARGS, "schwefels_p222 function"},
    {"shubert", py_shubert, METH_VARARGS, "shubert function"},
    {"sphere", py_sphere, METH_VARARGS, "sphere function"},
    {"tripod", py_tripod, METH_VARARGS, "tripod function"},
    {"trefethen4", py_trefethen4, METH_VARARGS, "trefethen4 function"},
    {NULL, NULL, 0, NULL}
};

// Module definition
static struct PyModuleDef cModPyDem =
{
    PyModuleDef_HEAD_INIT,
    "cbench", /* name of module */
    "",          /* module documentation, may be NULL */
    -1,          /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    CBenchMethods
};


// Module initialization
// Python 3.x
PyMODINIT_FUNC PyInit_cbench(void)
{
    return PyModule_Create(&cModPyDem);
}

// Python 2.x
// PyMODINIT_FUNC
// initcbench(void)
// {
//     (void) Py_InitModule("cbench", CBenchMethods);
// }

