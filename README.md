# Benchmark Functions for Optimization

Fast implementation of common benchmarks for testing numerical optimization methods.

This project attempts to provide a Python module for C++ implementation of
benchmarks.
These functions often are the most time-consuming part of evaluating new
optimization methods, so any improvements to this part help speed-up such
research.

## Quick Start

```python
import cbench as cb

xs = [.1, .2, .3, .4, .5]
print(cb.michalewicz(xs))
```

## List of functions

```
_ dejong2 # this would be the same as parabola
x dejong5
x ackley
x alpine
x six_hump_camel_back
x deceptive3
x drop_wave
x easom
x penalty1
T griewank
x goldstein_price
T axis_parallel_hyperellipsoid
x michalewicz
x noncontinuous_rastrigin
x rastrigin
x parabola
x rosenbrock
x schaffers_f6
T schwefels_p222
x shubert
x sphere
T step
x tripod
x trefethen4
```

## TODO:
* check for empty lists in the benchmark functions
* add unit tests


## References

- [K.Voss 2016](https://harvest.usask.ca/handle/10388/7746)
    pythOPT: A problem-solving environment for optimization methods

- [Jamil, Yang 2013](https://arxiv.org/abs/1308.4008)
    A Literature Survey of Benchmark Functions For Global Optimization Problems
    Momin Jamil, Xin-She Yang, 2013

- [Extending Python](https://docs.python.org/3/extending/extending.html)

- [C++ cmath](https://www.cplusplus.com/reference/cmath/)

