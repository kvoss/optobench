#include <cmath>
#include <stdexcept>
#include "bss.h"

namespace {
const double e = std::exp(1.);
const double pi = std::acos(-1.);
}

double
ackley(const std::vector<double>& xs)
{
    double acc0 = 0., acc1 = 0.;
    for (auto &&x: xs) {
        acc0 += x*x;
        acc1 += std::cos(2.*pi*x);
    }
    acc0 /= xs.size();
    acc1 /= xs.size();

    double ret = -20*std::exp(-0.2*std::sqrt(acc0)) - std::exp(acc1) + 20 + e;
    return ret;
}


double
alpine(const std::vector<double>& xs)
{
    double acc0 = 0.;
    for (auto &&x: xs) {
        acc0 += std::abs(x*std::sin(x) + 0.1*x);
    }
    return acc0;
}


double
bukin_f6(const std::vector<double>& xs)
{
    // The function is usually evaluated on the rectangle x1 ∈ [-15, -5], x2 ∈ [-3, 3].
    double x1 = xs.at(0);
    double x2 = xs.at(1);

    double ret = 100.*std::sqrt(std::abs(x2 - 0.01*x1*x1)) \
                 + 0.01*std::abs(x1 + 10.);
    return ret;
}


double
cross_in_tray(const std::vector<double>& xs)
{
    // The function is usually evaluated on the square xi ∈ [-10, 10], for all i = 1, 2
    double x1 = xs.at(0);
    double x2 = xs.at(1);

    double ret = -0.0001*std::pow(std::abs( \
        std::sin(x1)*std::sin(x2)*std::exp(\
            std::abs(100. - std::sqrt(x1*x1 + x2*x2)/pi) \
        )) + 1., 0.1);
    return ret;
}


double
eggholder(const std::vector<double>& xs)
{
    // The function is usually evaluated on the square xi ∈ [-512, 512], for all i = 1, 2.
    double x1 = xs.at(0);
    double x2 = xs.at(1);

    double ret = -1.*(x2 + 47.)*std::sin(std::sqrt(std::abs(x2+x1/2.+47.))) \
                 - x1*std::sin(std::sqrt(std::abs(x1-(x2+47.))));
    return ret;
}


double
gramacy_lee(const std::vector<double>& xs)
{
    // The function is usually evaluated on the x ∈ [0.5, 2.5].
    double x1 = xs.at(0);

    double ret = std::sin(10.*pi*x1)/2.*x1 + std::pow(x1-1., 4);
    return ret;
}


double
holder_table(const std::vector<double>& xs)
{
    // The function is usually evaluated on the square xi ∈ [-10, 10], for all i = 1, 2
    double x1 = xs.at(0);
    double x2 = xs.at(1);

    double ret = -1.*std::abs(\
        std::sin(x1)*std::cos(x2)*std::exp(std::abs(1.-std::sqrt(x1*x1+x2*x2)/pi)));
    return ret;
}


double
six_hump_camel_back(const std::vector<double>& xs)
{
    double x1 = xs.at(0);
    double x12 = x1*x1;

    double x2 = xs.at(1);
    double x22 = x2*x2;

    double ret = (4. - 2.1*x12 + (x12*x12)/3.)*x12 + x1*x2 + (-4. + 4.*x22)*x22;
    return ret;
}

double 
dejong5(const std::vector<double>& xs)
{
    static const double a[] = {
        -32., -16., 0., 16., 32.,
        -32., -16., 0., 16., 32.,
        -32., -16., 0., 16., 32.,
        -32., -16., 0., 16., 32.,
        -32., -16., 0., 16., 32.,
    };
    static const double b[] = {
        -32., -32., -32., -32., -32.,
        -16., -16., -16., -16., -16.,
          0.,   0.,   0.,   0.,   0.,
         16.,  16.,  16.,  16.,  16.,
         32.,  32.,  32.,  32.,  32.,
    };

    double acc = 0.002;
    double x0 = xs.at(0);
    double x1 = xs.at(1);
    for (size_t idx = 0; idx < 25; ++idx) {
        acc += 1. / ((idx + 1) + std::pow(x0 - a[idx], 6) + std::pow(x1 - b[idx], 6));
    }
    acc = 1. / acc;
    return acc;
}


double
parabola(const std::vector<double>& xs)
{
    double acc = 0.;
    for (auto &&x: xs) {
        acc += x*x;
    }
    return acc;
}

double
michalewicz(const std::vector<double>& xs)
{
    const double M = 10.;
    double acc = .0;
    double y = 0;

    std::size_t len_xs = xs.size();
    for (std::size_t i=0; i < len_xs; ++i) {
        y = xs[i];
        acc += sin(y) * pow(sin(i * y * y / pi), M+M);
    }
    acc *= -1.;
    return acc;
}

double
non_cont_rastrigin(const std::vector<double>& xs)
{
    double acc = .0;
    double y = 0;

    std::size_t len_xs = xs.size();
    acc = 10. * len_xs;
    for (std::size_t i=0; i < len_xs; ++i) {
        y = xs[i];
        if (y >= .5) y = round(2. * y) / 2.;
        acc += y * y - 10. * cos(2.*pi*y);
    }
    return acc;
}


double
rastrigin(const std::vector<double>& xs)
{
    double acc = .0;

    std::size_t len_xs = xs.size();
    acc = 10. * len_xs;
    for (std::size_t i=0; i < len_xs; ++i) {
        acc += xs[i] * xs[i]\
               - 10. * cos(2.*pi*xs[i]);
    }
    return acc;
}


double
rosenbrock(const std::vector<double>& xs)
{
    double acc = .0;

    std::size_t len_xs = xs.size();
    for (std::size_t i=0; i < len_xs -1; ++i) {
        acc += 100. * (xs[i+1] - xs[i] * xs[i]) * (xs[i+1] - xs[i] * xs[i])\
               + (xs[i] - 1.) * (xs[i] - 1.);
    }
    return acc;
}


double
deceptive3(const std::vector<double>& xs)
{
    static const double c[] = {
        0.56, 0.65, 0.12, 0.98, 0.44,
        0.34, 0.59, 0.79, 0.88, 0.04,
        0.25, 0.81, 0.30, 0.49, 0.53,
        0.21, 0.61, 0.86, 0.31, 0.29,
        0.84, 0.72, 0.92, 0.77, 0.39,
        0.11, 0.01, 0.03, 0.43, 0.80
    };

    auto g = [](const double xd, const double cd) -> double {
        if (0. <= xd and xd <= cd * 4./5)
            return (4. / 5) - (xd / cd);
        else if (cd * 4./5 < xd and xd <= cd)
            return (5. * xd / cd) - 4.;
        else if (cd < xd and xd <= (1 + 4 * cd) / 5.)
            return 1. + (5. * (xd - cd)) / (cd - 1.);
        else if ((1. + 4 * cd) / 5. < xd and xd <= 1.)
            return (4. / 5) + (xd - 1.) / (1. - cd);
        else
            throw std::invalid_argument("argument outside of the domain");
    };

    double acc = 0.;
    int i = 0;
    for (auto &&x: xs) {
        acc += g(x, c[i++]);
    }
    acc /= 30.;
    acc = -1. * std::pow(acc, 2.5);
    return acc;
}

double
drop_wave(const std::vector<double>& xs)
{
    double x1 = xs.at(0);
    double x12 = x1*x1;

    double x2 = xs.at(1);
    double x22 = x2*x2;

    double ret = -(1. + std::cos(12. + std::sqrt(x12 + x22))) / (.5 * (x12 + x22) + 2.);
    return ret;
}

double
easom(const std::vector<double>& xs)
{
    double x1 = xs.at(0);
    double x1mpi2 = (x1 - pi) * (x1 - pi);

    double x2 = xs.at(1);
    double x2mpi2 = (x2 - pi) * (x2 - pi);

    double ret = -std::cos(x1) * std::cos(x2) * std::exp( - x1mpi2 - x2mpi2);
    return ret;
}

double
penalty1(const std::vector<double>& xs)
{
    double acc = 0.;
    double y, yn;

    auto u = [](const double xi) -> double {
        const double a = 10.;
        const double k = 100.;
        const double m = 4.;
        if (xi > a)
            return k * pow(xi - a, m);
        else if (xi < (-1*a))
            return k * pow(-1*xi - a, m);
        else
            return 0.;
    };

    std::size_t len_xs = xs.size();

    y = 1. + (xs[0] + 1.) / 4.;
    yn = 1. + (xs[len_xs-1] + 1.) / 4.;
    acc = 10. * sin(pi * y) * sin(pi * y) + (yn - 1.) * (yn - 1.);
    for (std::size_t i=0; i < len_xs - 1; ++i) {
        y = 1. + (xs[i] + 1.) / 4.;
        yn = 1. + (xs[i+1] + 1.) / 4.;
        acc += (y - 1) * (y - 1) \
               * (1. + 10. * sin(pi * yn) * sin(pi * yn));
    }
    acc *= pi / len_xs;

    for (std::size_t i=0; i < len_xs; ++i) {
        acc += u(xs[i]);
    }

    return acc;
}

double
griewank(const std::vector<double>& xs)
{
    double ret = 0.;
    for (auto &&x: xs) {
        ret += x * x;
    }
    ret /= 4000.;

    double prod = 1.;
    int index = 1;
    for (auto &&x: xs) {
        double tprod = std::cos(x / std::sqrt(double(index)));
        prod *= tprod;
        ++index;
    }
    ret -= prod;
    ret += 1.0;
    return ret;
}

double
goldstein_price(const std::vector<double>& xs)
{
    double ret = 0.;
    double acc1 = 0, acc2 = 0;

    double x1 = xs.at(0);
    double x2 = xs.at(1);

    acc1 = 1\
           + (x1 + x2 + 1) * (x1 + x2 + 1)\
           * (19. - 14*x1 + 3*x1*x1 - 14*x2 + 6*x1*x2 + 3*x2*x2);
    acc2 = 30.\
           + (2*x1 - 3*x2) * (2*x1 - 3*x2)
           * (18. - 32*x1 + 12*x1*x1 + 48*x2 - 36*x1*x2 + 27*x2*x2);
    ret = acc1 * acc2;
    return ret;
}

double
axis_parallel_hyperellipsoid(const std::vector<double>& xs)
{
    double ret = 0.;
    int index = 1;
    for (auto &&x: xs) {
        ret += index * x * x;
        ++index;
    }
    return ret;
}

double
step(const std::vector<double>& xs)
{
    double ret = 0.;
    for (auto &&x: xs) {
        double t = std::floor(x) + 0.5;
        ret += t * t;
    }
    return ret;
}

double
schaffers_f6(const std::vector<double>& xs)
{
    double ret = 0.;
    double x1 = xs.at(0);
    double x2 = xs.at(1);

    ret = sin(sqrt(x1 * x1 + x2 * x2));
    ret = ret * ret - 0.5;
    ret /= pow((1. + .001 * (x1*x1 + x2*x2)), 2);
    ret += 0.5;

    return ret;
}


double
schwefels_p222(const std::vector<double>& xs)
{
    double ret = 0.;
    for (auto &&x: xs) {
        ret += std::fabs(x);
    }

    double prod = 1.;
    for (auto &&x: xs) {
        prod *= std::fabs(x);
    }
    ret += prod;
    return ret;
}


double
shubert(const std::vector<double>& xs)
{
    double ret = 0.;
    double acc1 = 0, acc2 = 0;

    double x1 = xs.at(0);
    double x2 = xs.at(1);
    for (unsigned short d=1; d <= 5; ++d) {
        acc1 += (double)d * std::cos( (d + 1) * x1 + d);
        acc2 += (double)d * std::cos( (d + 1) * x2 + d);
    }
    ret = acc1 + acc2;
    return ret;
}

double
sphere(const std::vector<double>& xs)
{
    double ret = 0.;
    for (auto &&x: xs) {
        ret += x * x;
    }
    return ret;
}

double
tripod(const std::vector<double>& xs)
{
    double ret = 0.;
    double x1 = xs.at(0);
    double x2 = xs.at(1);

    double y1 = 1., y2 = 1.;
    if (x1 < 0.) y1 = 0;
    if (x2 < 0.) y2 = 0;

    ret = y2 * (1. + y1) \
        + std::abs(x1 + 50. * y2 * (1. - 2.*y1)) \
        + std::abs(x2 + 50. * 1. * (1. - 2.*y2));

    return ret;
}

double
trefethen4(const std::vector<double>& xs)
{
    double ret = 0.;
    double x1 = xs.at(0);
    double x2 = xs.at(1);

    ret = 0.25 * x1 * x1 \
        + 0.25 * x2 * x2 \
        + std::exp(std::sin(50. * x1)) \
        - std::sin(10. * x1 + 10. * x2) \
        + std::sin(60. * std::exp(x2)) \
        + std::sin(70. * std::sin(x1)) \
        + std::sin(80. * std::sin(x2));

    return ret;
}

// int
// main (int argc, char** argv)
// {
//     double sum = 0.;
//     std::vector<double> v{-3., 17.};
//     std::vector<double> v2{-3., 17., 18};
// 
//     for (size_t n=0; n<1'000'000; ++n) {
//         sum += ackley(v2);
//         sum += alpine(v2);
//         sum += six_hump_camel_back(v);
//         sum += dejong5(v);
//     }
//     std::cout << sum << std::endl;
//     return 0;
// }

