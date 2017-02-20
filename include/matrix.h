/**
 * @file
 * @brief Header file for matrix manipulation functions
*/
#ifndef _MATRIX_H
#define _MATRIX_H

/**
 * @brief Allocate memory for matrix
 * @param matrix pointer to integer array containing the matrix
 * @param cols number of columns the matrix has
 * @param rows number of rows the matrix has
 */
void malloc_matrix(int **matrix, int cols, int rows);

/**
 * @brief Free memory associated with matrix
 * @param matrix pointer to integer array containing the matrix
 */
void free_matrix(int **matrix);

/**
 * @brief Print matrix to stdout
 * @param matrix pointer to integer array containing the matrix
 * @param cols number of columns the matrix has
 * @param rows number of rows the matrix has
 */
void print_matrix(int *matrix, int cols, int rows);

/**
 * @brief Fill matrix with specified value
 * @param matrix pointer to integer array containing the matrix
 * @param cols number of columns the matrix has
 * @param rows number of rows the matrix has
 * @param value value to fill matrix with
 */
void fill_matrix(int *matrix, int cols, int rows, int value);

/**
 * @brief Set matrix element at given co-ordinate pair
 * @param matrix pointer to integer array containing the matrix
 * @param cols number of columns the matrix has
 * @param rows number of rows the matrix has
 * @param c column location of element to fill
 * @param r row location of element to fill
 * @param value value to set location with
 */
void set_matrix_element(int *matrix, int cols, int rows, int c, int r, int value);

/**
 * @brief Get matrix element at given co-ordinate pair
 * @param matrix pointer to integer array containing the matrix
 * @param cols number of columns the matrix has
 * @param rows number of rows the matrix has
 * @param c column location of element
 * @param r row location of element
 * @return matrix element at given co-ordinate pair
 */
int get_matrix_element(int *matrix, int cols, int rows, int c, int r);

#endif /* _MATRIX_H */
