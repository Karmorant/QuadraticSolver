#include <stdio.h>
#include <math.h>



int main() {

    double a, b, c, D;
    printf("Enter the first coefficient ");
    scanf("%lf", &a);
    printf("Enter the first coefficient ");
    scanf("%lf", &b);
    printf("Enter the first coefficient ");
    scanf("%lf", &c);

    if (c == 0) {
        printf("Equation roots:\n");
        printf("0, %lf", (-b)/a);
    }
    else {
        D = b * b - 4 * a * c;
        if (D < 0)  {
            printf("Equation roots:\n");
            printf("%lf + %lfi, %lf%lfi", (-b)/(2 * a), (sqrt(D*(-1)))/(2 * a), (-b)/(2 * a), ((-1)*sqrt(D*(-1)))/(2 * a));

        }
        else {
           printf("Equation roots:\n");
            printf("%lf, %lf", ((-b) + sqrt(D)) / (2 * a), ((-b) - sqrt(D)) / (2 * a));
        }

    }
    return  0;
}
