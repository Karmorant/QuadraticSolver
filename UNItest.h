#ifndef UNITEST_H
#define UNITEST_H

struct UNItests_t
{
    int      uni_n_roots;
    double            x1;
    double            x2;
    double  uni_coefs[5];
};



void UNItests(quadratic_coeffs *coeffs, quadratic_roots *roots);

#endif /* UNITEST_H */