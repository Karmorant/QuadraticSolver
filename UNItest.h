#ifndef UNITEST_H
#define UNITEST_H

struct UNItests_t
{
    double     test_coefs[3];
    int     expected_n_roots;
    double                x1;
    double                x2;
}; 



void UNItests(quadratic_coeffs *coeffs, quadratic_roots *roots);

#endif /* UNITEST_H */
