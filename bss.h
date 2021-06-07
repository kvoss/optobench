#ifndef _BSS_H
#define _BSS_H

#include <vector>

double ackley(const std::vector<double>& xs);
double alpine(const std::vector<double>& xs);
double six_hump_camel_back(const std::vector<double>& xs);
double dejong5(const std::vector<double>& xs);
double deceptive3(const std::vector<double>& xs);
double drop_wave(const std::vector<double>& xs);
double easom(const std::vector<double>& xs);
double penalty1(const std::vector<double>& xs);
double parabola(const std::vector<double>& xs);
double michalewicz(const std::vector<double>& xs);
double non_cont_rastrigin(const std::vector<double>& xs);
double rastrigin(const std::vector<double>& xs);
double rosenbrock(const std::vector<double>& xs);
double griewank(const std::vector<double>& xs);
double goldstein_price(const std::vector<double>& xs);
double axis_parallel_hyperellipsoid(const std::vector<double>& xs);
double step(const std::vector<double>& xs);
double schaffers_f6(const std::vector<double>& xs);
double schwefels_p222(const std::vector<double>& xs);
double shubert(const std::vector<double>& xs);
double sphere(const std::vector<double>& xs);
double tripod(const std::vector<double>& xs);
double trefethen4(const std::vector<double>& xs);

#endif // _BSS_H

