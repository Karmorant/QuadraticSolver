#ifndef COMPARE_H
#define COMPARE_H

const double EPSILON = 2e-5;

int is_equal   (const double a, double d, const double epsilon = EPSILON);
int is_greater (const double a, double d, const double epsilon = EPSILON);


#endif /* COMPARE_H */