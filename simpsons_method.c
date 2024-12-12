#include <stdio.h>
#include <math.h>

int GetInput(long double *var_addr, char *prompt);
int FindXs(long double *xs, long double low_bound, int segms, long double step);
int FindFuncs(long double *funcs, long double *xs, int segms);
long double SumMiddles(long double *funcs, int segms);
long double SumLefts(long double *funcs, int segms);

int main(void) {
    long double down_boundary, up_boundary, error;
    GetInput(&down_boundary, "Enter the down boundary of the integral: ");
    GetInput(&up_boundary,  "Enter the up boundary of the integral: ");
    GetInput(&error, "Enter the error value of the integral: ");
    if (down_boundary > up_boundary) {
        long double tmp = up_boundary;
        up_boundary = down_boundary;
        down_boundary = tmp;
    }

    long double max_of_fourth_derivative = fabs(fmax(-(6 / pow(down_boundary, 4)), -(6 / pow(up_boundary, 4))));
    int segments = 1 + ceil(pow(((max_of_fourth_derivative * pow((up_boundary - down_boundary), 5)) / (2880 * error)), 0.25));
    long double step = (up_boundary - down_boundary) / (2 * segments);

    long double xs[segments * 2];
    FindXs(xs, down_boundary, segments, step);

    long double funcs[segments * 2];
    FindFuncs(funcs, xs, segments);

    long double lefts_sigma = SumLefts(funcs, segments);
    long double middles_sigma = SumMiddles(funcs, segments);
    
    long double simpsons_method = (step / 3) * (funcs[0] + 4 * lefts_sigma + 2 * middles_sigma + funcs[2 * segments]);
    printf("a: %Lf\nb: %Lf\nE: %Lf\nmax_of_4_derivative: %Lf\nsegments: %d\nstep: %Lf\nlefts_sigma: %Lf\nmiddles_sigma: %Lf\n", down_boundary, up_boundary, error, max_of_fourth_derivative, segments, step, lefts_sigma, middles_sigma);
    printf("Integral value from %Lf to %Lf with error value of %Lf is ~%Lf\n", down_boundary, up_boundary, error, simpsons_method);

    return 0;
}


int GetInput(long double *var_addr, char *prompt) {
    int input_successfull;

    printf("%s", prompt);
    do {
        input_successfull = scanf("%Lf", &*var_addr);
        while (getchar() != '\n');
    } while (!(input_successfull));
    return 0;
}

int FindXs(long double *xs, long double low_bound, int segms, long double step) {
    for (int i = 0; i < segms * 2 + 1; ++i) xs[i] = low_bound + i * step;
    return 0;
}

int FindFuncs(long double *funcs, long double *xs, int segms) {
    for (int i = 0; i < segms * 2 + 1; ++i) funcs[i] = log(xs[i]);
    return 0;
}

long double SumLefts(long double *funcs, int segms) {
    long double sum = 0;
    for (int i = 1; i < segms + 1; ++i) sum += funcs[2 * i - 1];
    return sum;
}

long double SumMiddles(long double *funcs, int segms) {
    long double sum = 0;
    for (int i = 1; i < segms; ++i) sum += funcs[2 * i];
    return sum;
}

