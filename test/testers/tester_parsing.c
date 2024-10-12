/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marta <marta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:52:00 by marta             #+#    #+#             */
/*   Updated: 2024/10/12 19:56:11 by marta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0m"

void print_result(const char *test_name, int success)
{
    if (success)
        printf("%s[PASS]%s %s\n", GREEN, RESET, test_name);
    else
        printf("%s[FAIL]%s %s\n", RED, RESET, test_name);
}

int compare_arrays(int *arr1, int *arr2, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr1[i] != arr2[i])
            return 0;
    }
    return 1;
}

void test_parse_args(int argc, char **argv, int *expected, int expected_size)
{
    int *numbers;
    int new_argc = argc;

    numbers = parse_args(&new_argc, argv);
    if (numbers == NULL)
    {
        if (expected == NULL)
            print_result(argv[1], 1);
        else
            print_result(argv[1], 0);
        return;
    }

    if (expected == NULL)
    {
        print_result(argv[1], 0);
        free(numbers);
        return;
    }

    if (new_argc - 1 != expected_size)
    {
        print_result(argv[1], 0);
        free(numbers);
        return;
    }

    int success = compare_arrays(numbers, expected, expected_size);
    print_result(argv[1], success);

    printf("  Expected: ");
    for (int i = 0; i < expected_size; i++)
        printf("%d ", expected[i]);
    printf("\n  Got:      ");
    for (int i = 0; i < new_argc - 1; i++)
        printf("%d ", numbers[i]);
    printf("\n");

    free(numbers);
}

void run_predefined_tests(void)
{
    char *test1[] = {"./push_swap", "1", "2", "3", "4", "5"};
    int expected1[] = {1, 2, 3, 4, 5};
    test_parse_args(6, test1, expected1, 5);

    char *test2[] = {"./push_swap", "42"};
    int expected2[] = {42};
    test_parse_args(2, test2, expected2, 1);

    char int_min_str[12], int_max_str[11];
    snprintf(int_min_str, sizeof(int_min_str), "%d", INT_MIN);
    snprintf(int_max_str, sizeof(int_max_str), "%d", INT_MAX);
    char *test3[] = {"./push_swap", int_min_str, "0", int_max_str};
    int expected3[] = {INT_MIN, 0, INT_MAX};
    test_parse_args(4, test3, expected3, 3);

    char *test4[] = {"./push_swap", "10 -5 7 3 -2"};
    int expected4[] = {10, -5, 7, 3, -2};
    test_parse_args(2, test4, expected4, 5);

    char *test5[] = {"./push_swap", "1", "2", "2"}; // Duplicate
    test_parse_args(4, test5, NULL, 0);

    char *test6[] = {"./push_swap", "1", "abc", "3"}; // Invalid input
    test_parse_args(4, test6, NULL, 0);

    // Test with INT_MIN - 1 (should fail)
    char int_min_minus_one[13];
    snprintf(int_min_minus_one, sizeof(int_min_minus_one), "%lld", (long long)INT_MIN - 1);
    char *test7[] = {"./push_swap", int_min_minus_one};
    test_parse_args(2, test7, NULL, 0);

    // Test with INT_MAX + 1 (should fail)
    char int_max_plus_one[12];
    snprintf(int_max_plus_one, sizeof(int_max_plus_one), "%lld", (long long)INT_MAX + 1);
    char *test8[] = {"./push_swap", int_max_plus_one};
    test_parse_args(2, test8, NULL, 0);
}

void run_random_test(int count)
{
    char **argv = malloc((count + 2) * sizeof(char *));
    int *expected = malloc(count * sizeof(int));
    
    argv[0] = "./push_swap";
    argv[1] = malloc(count * 12); // Allocate space for all numbers in one string
    argv[1][0] = '\0';
    
    srand(time(NULL));
    for (int i = 0; i < count; i++)
    {
        expected[i] = (rand() % INT_MAX) - (rand() % INT_MAX);
        char temp[12];
        snprintf(temp, 12, "%d ", expected[i]);
        strcat(argv[1], temp);
    }
    
    printf("Random test with %d numbers\n", count);
    test_parse_args(2, argv, expected, count);
    
    free(argv[1]);
    free(argv);
    free(expected);
}

void run_custom_test(int argc, char **argv)
{
    printf("%sRunning custom test with provided arguments:%s\n", YELLOW, RESET);
    for (int i = 1; i < argc; i++)
    {
        printf("%s ", argv[i]);
    }
    printf("\n");

    int *numbers;
    int new_argc = argc;

    numbers = parse_args(&new_argc, argv);
    if (numbers == NULL)
    {
        printf("%s[PASS]%s Custom test correctly returned NULL for invalid input\n", GREEN, RESET);
        printf("Expected output: Error\n");
        return;
    }

    printf("%s[FAIL]%s Custom test passed when it should have failed. Parsed numbers:\n", RED, RESET);
    for (int i = 0; i < new_argc - 1; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    free(numbers);
}

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        // Custom test based on command line arguments
        run_custom_test(argc, argv);
    }
    else
    {
        // Run predefined tests
        run_predefined_tests();
        
        // Run random tests
        run_random_test(10);
        run_random_test(100);
        run_random_test(500);
    }
    return (0);
}