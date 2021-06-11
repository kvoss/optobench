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
x ackley
x alpine
x bohachevsky1
x bohachevsky2
x bohachevsky3
x bukin_f6
x cross_in_tray
x dejong5
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
x rotated_hyperellipsoid
x sum_powers
x sum_squares # alias for axis_parallel_hyperellipsoid
x trid
x michalewicz
x perm0db
x noncontinuous_rastrigin
x rastrigin
x parabola # alias for sphere
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

## Contributions

After forking the repo and cloning it locally, use `make && make test`.

`make test` runs the `testit.sh` script, which evaluates functions and dumps the result to `sanity-test-instance.log` file.
Next, that result is compared against golden results in `sanity-test-golden.log`.

When your changes are ready and golden data updated, submit a pull request.


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
