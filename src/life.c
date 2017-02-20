/**
 * @file
 * @brief Implementation file for Game of Life functions
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix.h"
#include  "life.h"

/**
 * Because the matrix is treated as toroidal, any c/r parameters
 * that are negative or out of bounds will result in the correct
 * toroidal parameters. For example, (-1,-1) will result in a
 * wrap-around to the end of the matrix (end_col,end_row).
 */
int get_cell_state(int *matrix, int cols, int rows, int c, int r)
{
    /* Ensure that x & y are not negative */
    while(c <= 0)
    {
        c += cols;
    }
    while(r <= 0)
    {
        r += rows;
    }

    /* Ensure that matrix is treated as toroidal */
    return get_matrix_element(matrix, cols, rows, (c % cols), (r % rows));
}

/**
 * Because the matrix is treated as toroidal, any c/r parameters
 * that are negative or out of bounds will result in the correct
 * toroidal parameters. For example, (-1,-1) will result in a
 * wrap-around to the end of the matrix (end_col,end_row).
 */
void set_cell_state(int *matrix, int cols, int rows, int c, int r, int state)
{
    /* Ensure that x & y are not negative */
    while(c <= 0)
    {
        c += cols;
    }
    while(r <= 0)
    {
        r += rows;
    }

    /* Ensure that matrix is treated as toroidal */
    set_matrix_element(matrix, cols, rows, (c % cols), (r % rows), state);
}

/**
 * Given a co-ordinate pair, this function checks the 8 adjacent cells
 * for alive neighbours.
 */
int get_neighbours(int *matrix, int cols, int rows, int c, int r)
{
    int n, neighbours;
    struct Point cell;
    struct Point neighbour[NEIGHBOURS] = {
        {-1,-1}, {-1,0}, {-1,1}, {0,-1},
        {0,1}, {1,-1}, {1,0}, {1,1}};

    /* Initial number of alive neighbours is not known */
    neighbours = 0;

    /* Check cell state of all neighbours (8-adjacency) */
    for(n = 0; n < NEIGHBOURS; n++)
    {
        cell.x = c + neighbour[n].x;
        cell.y = r + neighbour[n].y;

        /* Increment neighbour count if alive */
        if(get_cell_state(matrix, cols, rows, cell.x, cell.y) == ALIVE)
        {
            neighbours++;
        }
    }

    return neighbours;
}

/**
 * Returns either DEAD or ALIVE for that particular location.
 */
int get_next_state(int *matrix, int cols, int rows, int c, int r)
{
    int current_state, neighbours;

    /* Get current state & number of neighbours at matrix location (x,y) */
    current_state = get_cell_state(matrix, cols, rows, c, r);
    neighbours = get_neighbours(matrix, cols, rows, c, r);

    /*
     * Rules:
     * 1. Any live cell with fewer than 2 live neighbours dies. (Under-population)
     * 2. Any live cell with 2 or 3 live neighbours lives. (Healthy population)
     * 3. Any live cell with more than 3 live neighbours dies. (Over-population)
     * 4. Any dead cell with exactly 3 live neighbours becomes alive. (Reproduction)
     */
    if(current_state == ALIVE)
    {
        if(neighbours == 2 || neighbours == 3)
        {
            return ALIVE;
        }
        else
        {
            return DEAD;
        }
    }
    else
    {
        if(neighbours == 3)
        {
            return ALIVE;
        }
        else
        {
            return DEAD;
        }
    }
}

/**
 * This function mallocs a new matrix and frees it at the end of the
 * function, with the passed matrix being replaced with the new
 * matrix. Therefore, this function should be considered destructive.
 */
void next_generation(int *matrix, int cols, int rows)
{
    int r, c;
    int *next;

    /* Allocate memory for next generation's matrix */
    malloc_matrix(&next, cols, rows);

    /* Update cell state for each location */
    for(r = 0; r < rows; r++)
    {
        for(c = 0; c < cols; c++)
        {
            set_cell_state(next, cols, rows, c, r, get_next_state(matrix, cols, rows, c, r));
        }
    }

    /* Replace current matrix with next generation's matrix */
    memcpy(matrix, next, cols * rows * sizeof(int));

    /* Memory freed as not required anymore */
    free_matrix(&next);
}
