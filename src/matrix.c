/**
 * @file
 * @brief Implementation file for matrix manipulation functions
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix.h"

/**
 * Wrapper around malloc() with error checking.
 * Will check for non-positive matrix parameters and if the
 * memory was successfully allocated.
 *
 * If non-positive parameters are passed or if the memory was
 * not successfully allocated, an error message will be printed
 * to stderr then the program exits.
 *
 * It is important to note that the arrays used in this library
 * are one dimensional.
 */
void malloc_matrix(int **matrix, int cols, int rows)
{
    /* Check for non-positive parameters */
    if(cols <= 0 || rows <= 0)
    {
        fprintf(stderr, "[malloc_matrix] non-positive matrix parameters\n");
        exit(EXIT_FAILURE);
    }

    /* Allocate required memory for matrix */
    *matrix = malloc(cols * rows * sizeof(*matrix));

    /* If null pointer, system memory is probably full */
    if(*matrix == NULL)
    {
        fprintf(stderr, "[malloc_matrix] could not allocate memory\n");
        exit(EXIT_FAILURE);
    }
}

/**
 * Wrapper around free() with error checking.
 * Will check if the matrix pointer is valid before freeing.
 *
 * If the matrix pointer is null, an error message will be
 * printed to stderr and then the program exits.
 * Otherwise, the passed pointer's memory will be freed
 * and then the pointer will be set to null.
 */
void free_matrix(int **matrix)
{
    /* Why are you double-freeing pointers!? */
    if(*matrix == NULL)
    {
        fprintf(stderr, "[free_matrix] already free\n");
        exit(EXIT_FAILURE);
    }

    free(*matrix);

    /* Set null pointer */
    *matrix = NULL;
}

/**
 * Simple debug utility to print matrix to stdout.
 * The output is not padded or formatted in any way.
 * Will check if the matrix pointer is valid and if the
 * matrix parameters are non-positive.
 *
 * If the matrix pointer is null, or the matrix parameters
 * are non-positive, an error message is printed to stderr
 * then the program exits.
 */
void print_matrix(int *matrix, int cols, int rows)
{
    int r, c;

    /* Let's not read from undefined memory addresses */
    if(matrix == NULL)
    {
        fprintf(stderr, "[print_matrix] null pointer error\n");
        exit(EXIT_FAILURE);
    }

    /* Check for non-positive parameters */
    if(cols <= 0 || rows <= 0)
    {
        fprintf(stderr, "[print_matrix] non-positive matrix parameters\n");
        exit(EXIT_FAILURE);
    }

    /* Print matrix */
    for(r = 0; r < rows; r++)
    {
        for(c = 0; c < cols; c++)
        {
            printf("%d ", matrix[cols * r + c]);
        }
        printf("\n");
    }
}
/**
 * Wrapper around memset() with error checking.
 * Will check if the matrix pointer is valid and if the
 * matrix parameters are non-positive.
 *
 * If the matrix pointer is null or if the matrix
 * parameters are non-positive, an error message will be
 * printed to stderr and then the program exits.
 */
void fill_matrix(int *matrix, int cols, int rows, int value)
{
    /* Let's not write to undefined memory addresses */
    if(matrix == NULL)
    {
        fprintf(stderr, "[fill_matrix] null pointer error\n");
        exit(EXIT_FAILURE);
    }

    /* Check for non-positive parameters */
    if(cols <= 0 || rows <= 0)
    {
        fprintf(stderr, "[fill_matrix] non-positive matrix parameters\n");
        exit(EXIT_FAILURE);
    }

    /* Fill matrix with passed value */
    memset(matrix, value, cols * rows * sizeof(int));
}

/**
 * Will check the validity of the matrix pointer and parameters.
 *
 * If the matrix pointer is null or the matrix parameters are not
 * valid (i.e. not positive or out of matrix bounds), an
 * error message is printed to stderr then the program exits.
 */
void set_matrix_element(int *matrix, int cols, int rows, int c, int r, int value)
{
    /* Let's not write to undefined memory addresses */
    if(matrix == NULL)
    {
        fprintf(stderr, "[set_matrix_element] null pointer error\n");
        exit(EXIT_FAILURE);
    }

    /* Check for non-positive parameters */
    if(cols <= 0 || rows <= 0)
    {
        fprintf(stderr, "[set_matrix_element] non-positive matrix parameters\n");
        exit(EXIT_FAILURE);
    }

    /* Let's not attempt to write out of bounds */
    if(c >= cols || r >= rows)
    {
        fprintf(stderr, "[set_matrix_element] out of bounds access\n");
        exit(EXIT_FAILURE);
    }

    /* Set element with passed value */
    matrix[cols * r + c] = value;
}

/**
 * Will check the validity of the matrix pointer and parameters.
 *
 * If the matrix pointer is null or the matrix parameters are not
 * valid (i.e. not positive or out of matrix bounds), an
 * error message is printed to stderr then the program exits.
 */
int get_matrix_element(int *matrix, int cols, int rows, int c, int r)
{
    /* Let's not read from undefined memory addresses */
    if(matrix == NULL)
    {
        fprintf(stderr, "[get_matrix_element] null pointer error\n");
        exit(EXIT_FAILURE);
    }

    /* Check for non-positive parameters */
    if(cols <= 0 || rows <= 0)
    {
        fprintf(stderr, "[get_matrix_element] non-positive matrix parameters\n");
        exit(EXIT_FAILURE);
    }

    /* Let's not attempt to read out of bounds */
    if(c >= cols || r >= rows)
    {
        fprintf(stderr, "[get_matrix_element] out of bounds access\n");
        exit(EXIT_FAILURE);
    }

    /* Return element at specified location */
    return matrix[cols * r + c];
}
