/**
 * @file
 * @brief Implementation file for patterns used in Game of Life
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "patterns.h"

/* Shape of each pattern */
struct Point block[] = {{0,0}, {0,1}, {1,0}, {1,1}};
struct Point beehive[] = {{0,1}, {1,0}, {1,2}, {2,0}, {2,2}, {3,1}};
struct Point loaf[] = {{0,1}, {1,0}, {1,2}, {2,0}, {2,3}, {3,1}, {3,2}};
struct Point boat[] = {{0,0}, {0,1}, {1,0}, {1,2}, {2,1}};
struct Point blinker[] = {{0,0}, {1,0}, {2,0}};
struct Point toad[] = {{0,1}, {1,0}, {1,1}, {2,0}, {2,1}, {3,0}};
struct Point beacon[] = {{0,0}, {1,0}, {0,1}, {3,2}, {2,3}, {3,3}};
struct Point pulsar[] = {
    {4,0}, {4,1}, {4,2}, {5,2}, /* L block - first row, left */
    {9,2}, {10,0}, {10,1}, {10,2}, /* L block - first row, right */
    {5,4}, {6,4}, {4,5}, {6,5}, {4,6}, {5,6}, /* Diamond - second row, left */
    {8,4}, {9,4}, {8,5}, {10,5}, {9,6}, {10,6}, /* Diamond - second row, right */
    {0,4}, {1,4}, {2,4}, {2,5}, /* L block - second row, left */
    {12,4}, {13,4}, {14,4}, {12,5}, /* L block - second row, right */
    {9,8}, {10,8}, {8,9}, {10,9}, {8,10}, {9,10}, /* Diamond - third row, left */
    {4,8}, {5,8}, {4,9}, {6,9}, {5,10}, {6,10}, /* Diamond - third row, right */
    {2,9}, {0,10}, {1,10}, {2,10}, /* L block - third row, left */
    {12,9}, {12,10}, {13,10}, {14,10}, /* L block - third row, right */
    {4,12}, {5,12}, {4,13}, {4,14}, /* L block - fourth row, left */
    {9,12}, {10,12}, {10,13}, {10,14} /* L block - fourth row, left */
};
struct Point pentadecathlon[] = {
    {0,0}, {1,0}, {2,0}, {1,1}, {1,2}, {0,3}, {1,3}, {2,3}, /* Top shape */
    {0,5}, {1,5}, {2,5}, {0,6}, {1,6}, {2,6}, /* Middle shape */
    {0,8}, {1,8}, {2,8}, {1,9}, {1,10}, {0,11}, {1,11}, {2,11}, /* Bottom shape */
};
struct Point glider[] = {{1,0}, {2,1}, {0,2}, {1,2}, {2,2}};
struct Point lwss[] = {
    {0,0}, {3,0}, {4,1}, {0,2}, {4,2},
    {1,3}, {2,3}, {3,3}, {4,3}
};
struct Point rpentomino[] = {{1,0}, {2,0}, {0,1}, {1,1}, {1,2}};
struct Point diehard[] = {{6,0}, {0,1}, {1,1}, {1,2}, {5,2}, {6,2}, {7,2}};
struct Point acorn[] = {{1,0}, {3,1}, {0,2}, {1,2}, {4,2}, {5,2}, {6,2}};
struct Point gosper[] = {
    {0,4}, {1,4}, {0,5}, {1,5}, /* First block */
    {12,2}, {13,2}, {11,3}, {15,3}, {10,4}, {16,4}, /* Second shape */
    {10,5}, {14,5}, {16,5}, {17,5}, {10,6}, {16,6},
    {11,7}, {15,7}, {12,8}, {13,8},
    {24,0}, {22,1}, {24,1}, {20,2}, {21,2}, {20,3}, /* Third shape */
    {21,3}, {20,4}, {21,4}, {22,5}, {24,5}, {24,6},
    {34,2}, {35,2}, {34,3}, {35,3}, /* Last block */
};
struct Point inf1[] = {
    {6,0}, {4,1}, {6,1}, {7,1}, {4,2},
    {6,2}, {4,3}, {2,4}, {0,5}, {2,5}
};
struct Point inf2[] = {
    {0,0}, {1,0}, {2,0}, {4,0}, {0,1}, {3,2}, {4,2},
    {1,3}, {2,3}, {4,3}, {0,4}, {2,4}, {4,4}
};
struct Point inf3[] = {
    {0,0}, {1,0}, {2,0}, {3,0}, {4,0}, {5,0}, {6,0}, {7,0}, /* First line */
    {9,0}, {10,0}, {11,0}, {12,0}, {13,0}, /* Second line */
    {17,0}, {18,0}, {19,0}, /* Third line */
    {26,0}, {27,0}, {28,0}, {29,0}, {30,0}, {31,0}, {32,0}, /* Fourth line */
    {34,0}, {35,0}, {36,0}, {37,0}, {38,0} /* Fifth line */
};

/**
 * TODO: Pattern zero point. Top left starting point.
 */
void put_pattern(int *matrix, int cols, int rows, int c, int r, int pattern)
{
    int i, pattern_size = 0;
    struct Point *p_Point = NULL;
    struct Point n;

    switch (pattern) {
        case BLOCK:
            pattern_size = sizeof(block)/sizeof(struct Point);
            p_Point = block;
            break;
        case BEEHIVE:
            pattern_size = sizeof(beehive)/sizeof(struct Point);
            p_Point = beehive;
            break;
        case LOAF:
            pattern_size = sizeof(loaf)/sizeof(struct Point);
            p_Point = loaf;
            break;
        case BOAT:
            pattern_size = sizeof(boat)/sizeof(struct Point);
            p_Point = boat;
            break;
        case BLINKER:
            pattern_size = sizeof(blinker)/sizeof(struct Point);
            p_Point = blinker;
            break;
        case TOAD:
            pattern_size = sizeof(toad)/sizeof(struct Point);
            p_Point = toad;
            break;
        case BEACON:
            pattern_size = sizeof(beacon)/sizeof(struct Point);
            p_Point = beacon;
            break;
        case PULSAR:
            pattern_size = sizeof(pulsar)/sizeof(struct Point);
            p_Point = pulsar;
            break;
        case PENTADECATHLON:
            pattern_size = sizeof(pentadecathlon)/sizeof(struct Point);
            p_Point = pentadecathlon;
            break;
        case GLIDER:
            pattern_size = sizeof(glider)/sizeof(struct Point);
            p_Point = glider;
            break;
        case LIGHTWEIGHT_SPACESHIP:
            pattern_size = sizeof(lwss)/sizeof(struct Point);
            p_Point = lwss;
            break;
        case R_PENTOMINO:
            pattern_size = sizeof(rpentomino)/sizeof(struct Point);
            p_Point = rpentomino;
            break;
        case DIEHARD:
            pattern_size = sizeof(diehard)/sizeof(struct Point);
            p_Point = diehard;
            break;
        case ACORN:
            pattern_size = sizeof(acorn)/sizeof(struct Point);
            p_Point = acorn;
            break;
        case GOSPER_GLIDER_GUN:
            pattern_size = sizeof(gosper)/sizeof(struct Point);
            p_Point = gosper;
            break;
        case INF_1:
            pattern_size = sizeof(inf1)/sizeof(struct Point);
            p_Point = inf1;
            break;
        case INF_2:
            pattern_size = sizeof(inf2)/sizeof(struct Point);
            p_Point = inf2;
            break;
        case INF_3:
            pattern_size = sizeof(inf3)/sizeof(struct Point);
            p_Point = inf3;
            break;
        default:
            fprintf(stderr, "[put_pattern] invalid pattern selected\n");
            exit(EXIT_FAILURE);
            break;
    }

    if(p_Point == NULL)
    {
        fprintf(stderr,"[put_pattern] pointer not assigned\n");
        exit(EXIT_FAILURE);
    }

    for(i = 0; i < pattern_size; i++)
    {
        n.x = c + p_Point[i].x;
        n.y = r + p_Point[i].y;

        set_cell_state(matrix, cols, rows, n.x, n.y, ALIVE);
    }
}
