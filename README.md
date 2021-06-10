# Benchmark Functions for Optimization

Fast benchmarks for testing numerical optimization methods with Python interface.

This project provides a Python module with C++ implementations of benchmark functions for optimization.
These functions often are the most time-consuming part of evaluating new
optimization methods, so any improvements to this part help speed-up such
research.


## Quick Start

```python
import cbench as cb

xs = [.1, .2, .3, .4, .5]
print(cb.michalewicz(xs))
```

### Requirements

- Python 3.8
- g++ / clang with support for C++17


### Installation

```sh
# Load your python environment
make install
```


## List of functions

```
x dejong2 # this is the same as parabola
x dejong5
x ackley
x alpine
x bukin_f6
x cross_in_tray
x eggholder
x gramacy_lee
x holder_table
x langermann
x levy
x levy13
x six_hump_camel_back
x deceptive3
x drop_wave
x easom
x penalty1
x griewank
x goldstein_price
x axis_parallel_hyperellipsoid
x michalewicz
x noncontinuous_rastrigin
x rastrigin
x parabola
x rosenbrock
x schaffers_f2
x schaffers_f4
x schaffers_f6
x schwefels
x schwefels_p222
x shubert
x sphere
x step
x tripod
x trefethen4
```

## TODO:
- [X] check for empty lists in the benchmark functions
- [ ] add unit tests


## References

- [K.Voss 2016](https://harvest.usask.ca/handle/10388/7746)
    pythOPT: A problem-solving environment for optimization methods

- [Momin Jamil, Xin-She Yang 2013](https://arxiv.org/abs/1308.4008)
    A Literature Survey of Benchmark Functions For Global Optimization Problems

- [Optimization Test Problems, SFU](https://www.sfu.ca/~ssurjano/optimization.html)

- [Extending Python](https://docs.python.org/3/extending/extending.html)

- [C++ cmath](https://www.cplusplus.com/reference/cmath/)

- [CppCoreGuidelines](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md)

- [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)
