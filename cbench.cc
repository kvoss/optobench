#define PY_SSIZE_T_CLEAN  /* Make "s#" use Py_ssize_t rather than int. */
#include "Python.h"
#include "bss.h"


static PyObject *
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

#ifndef PYWRAP
#define PYWRAP( name ) static PyObject *py_ ## name (PyObject *self, PyObject *args) {return py_bench(self, args, name);}
#endif

PYWRAP(ackley);
PYWRAP(alpine);
PYWRAP(bohachevsky1);
PYWRAP(bohachevsky2);
PYWRAP(bohachevsky3);
PYWRAP(bukin_f6);
PYWRAP(cross_in_tray);
PYWRAP(eggholder);
PYWRAP(gramacy_lee);
PYWRAP(holder_table);
PYWRAP(langermann);
PYWRAP(levy);
PYWRAP(levy13);
PYWRAP(six_hump_camel_back);
PYWRAP(dejong5);
PYWRAP(deceptive3);
PYWRAP(drop_wave);
PYWRAP(easom);
PYWRAP(penalty1);
PYWRAP(parabola);
PYWRAP(michalewicz);
PYWRAP(non_cont_rastrigin);
PYWRAP(rastrigin);
PYWRAP(rosenbrock);
PYWRAP(griewank);
PYWRAP(goldstein_price);
PYWRAP(axis_parallel_hyperellipsoid);
PYWRAP(step);
PYWRAP(schaffers_f2);
PYWRAP(schaffers_f4);
PYWRAP(schaffers_f6);
PYWRAP(schwefels);
PYWRAP(schwefels_p222);
PYWRAP(shubert);
PYWRAP(sphere);
PYWRAP(tripod);
PYWRAP(trefethen4);


static PyMethodDef
CBenchMethods[] = {
    {"ackley", py_ackley, METH_VARARGS, "Ackley function"},
    {"alpine", py_alpine, METH_VARARGS, "Alpine function"},
    {"bohachevsky1", py_bohachevsky1, METH_VARARGS, "bohachevsky1 function"},
    {"bohachevsky2", py_bohachevsky2, METH_VARARGS, "bohachevsky2 function"},
    {"bohachevsky3", py_bohachevsky3, METH_VARARGS, "bohachevsky3 function"},
    {"bukin_f6", py_bukin_f6, METH_VARARGS, "Bukin function 6"},
    {"cross_in_tray", py_cross_in_tray, METH_VARARGS, "cross_in_tray function"},
    {"eggholder", py_eggholder, METH_VARARGS, "eggholder function"},
    {"gramacy_lee", py_gramacy_lee, METH_VARARGS, "Gramacy Lee function"},
    {"holder_table", py_holder_table, METH_VARARGS, "holder table function"},
    {"langermann", py_langermann, METH_VARARGS, "langermann function"},
    {"levy", py_levy, METH_VARARGS, "levy function"},
    {"levy13", py_levy13, METH_VARARGS, "levy13 function"},
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
    {"schaffers_f2", py_schaffers_f2, METH_VARARGS, "schaffers_f2 function"},
    {"schaffers_f4", py_schaffers_f4, METH_VARARGS, "schaffers_f4 function"},
    {"schaffers_f6", py_schaffers_f6, METH_VARARGS, "schaffers_f6 function"},
    {"schwefels", py_schwefels, METH_VARARGS, "schwefels function"},
    {"schwefels_p222", py_schwefels_p222, METH_VARARGS, "schwefels_p222 function"},
    {"shubert", py_shubert, METH_VARARGS, "shubert function"},
    {"sphere", py_sphere, METH_VARARGS, "sphere function"},
    {"tripod", py_tripod, METH_VARARGS, "tripod function"},
    {"trefethen4", py_trefethen4, METH_VARARGS, "trefethen4 function"},
    {NULL, NULL, 0, NULL}
};

// Module definition
static struct PyModuleDef
cModPyDem = {
    PyModuleDef_HEAD_INIT,
    "cbench", /* name of the module */
    "Python interface for the C++ benchmark optimization functions",  /* module documentation, may be NULL */
    -1,       /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    CBenchMethods
};


// Module initialization
// Python 3.x
PyMODINIT_FUNC
PyInit_cbench(void)
{
    PyObject *module = PyModule_Create(&cModPyDem);
    PyModule_AddStringConstant(module, "__version__", "0.1.0");
    return module;
}

// Python 2.x
// PyMODINIT_FUNC
// initcbench(void)
// {
//     (void) Py_InitModule("cbench", CBenchMethods);
// }

