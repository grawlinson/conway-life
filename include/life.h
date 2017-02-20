/**
 * @file
 * @brief Header file for Game of Life functions
 */
#ifndef _LIFE_H
#define _LIFE_H

/* Cell status */
#define ALIVE 1 /**< @brief Alive cell state */
#define DEAD 0 /**< @brief Dead cell state */

#define NEIGHBOURS 8 /**< @brief Number of neighbours */

/**
 * @brief Convenience struct to map x & y co-ordinates
 */
struct Point{
    int x; /**< X co-ordinate */
    int y; /**< Y co-ordinate */
};

/**
 * @brief Get current cell state of matrix at given co-ordinate pair
 * @param matrix pointer to integer array containing the matrix
 * @param cols column dimension of the matrix
 * @param rows row dimension of the matrix
 * @param c column location of cell
 * @param r row location of cell
 * @return current cell state at given co-ordinate pair
 */
int get_cell_state(int *matrix, int cols, int rows, int c, int r);

/**
 * @brief Set current cell state of matrix at given co-ordinate pair
 * @param matrix pointer to integer array containing the matrix
 * @param cols column dimension of the matrix
 * @param rows row dimension of the matrix
 * @param c column location of cell
 * @param r row location of cell
 * @param state current cell state to set at given co-ordinate pair
 */
void set_cell_state(int *matrix, int cols, int rows, int c, int r, int state);

/**
 * @brief Get number of alive neighbours at given co-ordinate pair
 * @param matrix pointer to integer array containing the matrix
 * @param cols column dimension of the matrix
 * @param rows row dimension of the matrix
 * @param c column location of cell
 * @param r row location of cell
 * @return number of neighbours at given co-ordinate pair
 */
int get_neighbours(int *matrix, int cols, int rows, int c, int r);

/**
 * @brief Get next cell state of matrix at given co-ordinate pair
 * @param matrix pointer to integer array containing the matrix
 * @param cols column dimension of the matrix
 * @param rows row dimension of the matrix
 * @param c column location of cell
 * @param r row location of cell
 * @return next cell state at given co-ordinate pair
 */
int get_next_state(int *matrix, int cols, int rows, int c, int r);

/**
 * @brief Advance the game by one generation
 * @param matrix pointer to integer array containing the matrix
 * @param cols column dimension of the matrix
 * @param rows row dimension of the matrix
 */
void next_generation(int *matrix, int cols, int rows);

#endif /* _LIFE_H */
