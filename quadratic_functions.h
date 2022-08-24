#ifndef QUADRATIC_FUNCTIONS_H
#define QUADRATIC_FUNCTIONS_H
enum non_trivial_roots
{   
    INF_ROOTS  = -1
};

struct quadratic_coeffs
{
    double a = NAN;
    double b = NAN;
    double c = NAN;
};

void read_coeffs(quadratic_coeffs *coeffs);

int solve_linear(quadratic_coeffs *coeffs, double *x1);
int solve_quadratic(quadratic_coeffs *coeffs, double *x1, double *x2);

void give_answers (int n_roots);

#endif /* QUADRATIC_FUNCTIONS_H */