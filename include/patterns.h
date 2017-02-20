/**
 * @file
 * @brief Header file for patterns used in Game of Life
 */
#ifndef _PATTERNS_H
#define _PATTERNS_H

#include "life.h"

/* Pattern: Still Lifes */
#define BLOCK 0 /**< @brief Block. Still life pattern. */
#define BEEHIVE 1 /**< @brief Beehive. Still life pattern. */
#define LOAF 2 /**< @brief Loaf. Still life pattern. */
#define BOAT 3 /**< @brief Boat. Still life pattern. */

/* Pattern: Oscillators */
#define BLINKER 4 /**< @brief Blinker. Oscillator pattern. */
#define TOAD 5 /**< @brief Toad. Oscillator pattern. */
#define BEACON 6 /**< @brief Beacon. Oscillator pattern. */
#define PULSAR 7 /**< @brief Pulsar. Oscillator pattern. */
#define PENTADECATHLON 8 /**< @brief Pentadecathlon. Oscillator pattern. */

/* Pattern: Spaceships */
#define GLIDER 9 /**< @brief Glider. Spaceship pattern. */
#define LIGHTWEIGHT_SPACESHIP 10 /**< @brief Lightweight Spaceship. Spaceship pattern. */

/* Pattern: Methuselahs */
#define R_PENTOMINO 11 /**< @brief R Pentomino. Methuselah pattern. */
#define DIEHARD 12 /**< @brief Diehard. Methuselah pattern. */
#define ACORN 13 /**< @brief Acorn. Methuselah pattern. */

/* Pattern: Infinite */
#define GOSPER_GLIDER_GUN 14 /**< @brief Gosper Glider Gun. Infinite pattern. */
#define INF_1 15 /**< @brief Infinite pattern #1 */
#define INF_2 16 /**< @brief Infinite pattern #2 */
#define INF_3 17 /**< @brief Infinite pattern #3 */

extern struct Point block[4]; /**< @brief Used to store co-ordinates of block pattern. */
extern struct Point beehive[6]; /**< @brief Used to store co-ordinates of beehive pattern. */
extern struct Point loaf[7]; /**< @brief Used to store co-ordinates of loaf pattern. */
extern struct Point boat[5]; /**< @brief Used to store co-ordinates of boat pattern. */
extern struct Point blinker[3]; /**< @brief Used to store co-ordinates of blinker pattern. */
extern struct Point toad[6]; /**< @brief Used to store co-ordinates of toad pattern. */
extern struct Point beacon[6]; /**< @brief Used to store co-ordinates of beacon pattern. */
extern struct Point pulsar[56]; /**< @brief Used to store co-ordinates of pulsar pattern. */
extern struct Point pentadecathlon[22]; /**< @brief Used to store co-ordinates of pentadecathlon pattern. */
extern struct Point glider[5]; /**< @brief Used to store co-ordinates of glider pattern. */
extern struct Point lwss[9]; /**< @brief Used to store co-ordinates of lightweight spaceship pattern. */
extern struct Point rpentomino[5]; /**< @brief Used to store co-ordinates of r pentomino pattern. */
extern struct Point diehard[7]; /**< @brief Used to store co-ordinates of diehard pattern. */
extern struct Point acorn[7]; /**< @brief Used to store co-ordinates of acorn pattern. */
extern struct Point gosper[36]; /**< @brief Used to store co-ordinates of gosper glider gun pattern. */
extern struct Point inf1[10]; /**< @brief Used to store co-ordinates of infinite pattern 1. */
extern struct Point inf2[13]; /**< @brief Used to store co-ordinates of infinite pattern 2. */
extern struct Point inf3[28]; /**< @brief Used to store co-ordinates of infinite pattern 3. */

/**
 * @brief Put specified pattern in the matrix at given co-ordinate pair
 * @param matrix pointer to integer array containing the matrix
 * @param cols amount of columns the matrix has
 * @param rows amount of rows the matrix has
 * @param c column location of matrix
 * @param r row location of matrix
 * @param pattern to put in matrix at given co-ordinate pair
 */
void put_pattern(int *matrix, int cols, int rows, int c, int r, int pattern);

#endif /* _PATTERNS_H */
