#include <stdlib.h>
#include <stdio.h>

#define TRUE  1
#define FALSE 0

int filter(int *arr, int size, int (*to_bool)(int));
int over_5(int n);
int under_5(int n);
void print_int_arr(int *arr, int size);

/* Main tests the filter method. */
int main(int argc, char const *argv[])
{
    int arr0[10] = {1, 5, 3, 8, -6, 3, -11, -7, 1, 9};
    int arr0_size = 10;
    int arr1[10] = {1, 5, 3, 8, -6, 3, -11, -7, 1, 9};
    int arr1_size = 10;

    arr0_size = filter(arr0, arr0_size, over_5);
    print_int_arr(arr0, arr0_size);

    arr1_size = filter(arr1, arr1_size, under_5);
    print_int_arr(arr1, arr1_size);

    return 0;
}

/* Filter takes an array of values and a function and return an array of the
 * values where the function applied to those values return true.  It is
 * implemented here as only working on int's as it is only example code to be
 * translated to MIPS assembly in the code generator.  The return value from the
 * functions is the length of the new array. */
int filter(int *arr, int size, int (*to_bool)(int))
{
    int i;
    int j = 0; /* The next free space in the result array. */

    for (i = 0; i < size; i++)
        if (to_bool(arr[i]))
            arr[j++] = arr[i];

    return j; /* Size of the "new" array. */
}

int over_5(int n)
{
    return n > 5;
}

int under_5(int n)
{
    return n < 5;
}

void print_int_arr(int *arr, int size)
{
    int i;

    for (i = 0; i < size-1; i++)
        printf("%d, ", arr[i]);
    printf("%d\n", arr[size-1]); /* Print last element with no comma. */
}
