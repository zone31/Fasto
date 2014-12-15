#include <stdlib.h>
#include <stdio.h>

int * scan(int *arr, int neutral, int arr_size, int (*func)(int, int));
void print_int_arr(int *arr, int arr_size);
int add(int a, int b);

int main(int argc, char const *argv[])
{
    int i;
    int arr_size = 20;
    int arr[arr_size];
    int *arr_res;

    for (i = 0; i < arr_size; i++)
        arr[i] = i;

    arr_res = scan(arr, 0, arr_size, add);

    print_int_arr(arr_res, arr_size);
}

int * scan(int *arr, int neutral, int arr_size, int (*func)(int, int))
{
    int i, res;
    int *arr_res = malloc(sizeof(int) * arr_size + 1); /* Plus 1 neutral el. */

    arr_res[0] = neutral;

    for (i = 0; i < arr_size; i++) {
        res = func(arr_res[i], arr[i]);

        arr_res[i+1] = res;
    }

    return arr_res;
}

void print_int_arr(int *arr, int size)
{
    int i;

    for (i = 0; i < size-1; i++)
        printf("%d, ", arr[i]);
    printf("%d\n", arr[size-1]); /* Print last element with no comma. */
}

int add(int a, int b)
{
    return a + b;
}
