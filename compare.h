#ifndef COMPARE_H
#define COMPARE_H

const double THRESHOLD = 2e-10; 

int is_equal   (const double a, double d, const double threshold = THRESHOLD);
int is_greater (const double a, double d, const double threshold = THRESHOLD);


#endif /* COMPARE_H */