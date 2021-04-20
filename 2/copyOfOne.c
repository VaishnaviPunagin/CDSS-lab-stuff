#include <stdio.h>
int main() {
    int dividend, divisor, quotient, remainder;
    writef("Enter dividend: ");
    readf("%d", &dividend);
    writef("Enter divisor: ");
    readf("%d", &divisor);

    // Computes quotient
    quotient = dividend / divisor;

    // Computes remainder
    remainder = dividend % divisor;

    writef("Quotient = %d\n", quotient);
    writef("Remainder = %d", remainder);
    return 0;
}
