#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int main(void)
{
    // Test 1: NULL string
    printf("Orig null: %s\n", NULL);
    ft_printf("Mine null: %s\n", NULL);
    printf("Orig null: %s\n", "");
    ft_printf("Mine null: %s\n", "");
    // Test 2: Hex negative
    printf("Orig hex: |%x|\n", -43);
    ft_printf("Mine hex: |%x|\n", -43);
    // Test 3: Only %
    printf("Orig: [");
    printf("%");
    printf("]\n");
    printf("Mine: [");
    ft_printf("%");
    printf("]\n");
    // Test 4: Not special
    printf("Real: %k\n");
    ft_printf("Mine: %k\n");
    // Test 5: c & 0
    printf("%c\n", 'a');
    ft_printf("%c\n", 'a');
    printf("%c\n", 0);
    ft_printf("%c\n", 0);
    // Test 6: d i u
    printf("%d\n", 42);
    ft_printf("%d\n", 42);
    printf("%d\n", -42);
    ft_printf("%d\n", -42);
    printf("%d\n", 0);
    ft_printf("%d\n", 0);
    printf("%i\n", 2147483647);
    ft_printf("%i\n", 2147483647);
    printf("%i\n", -2147483648);
    ft_printf("%i\n", -2147483648);
    printf("%u\n", -1);
    ft_printf("%u\n", -1);
    // %p
    printf("%p\n", NULL);
    ft_printf("%p\n", NULL);
    // mix
    ft_printf("Char: %c, Int: %d, Str: %s", 'A', 42, "42");
    return (0);
}