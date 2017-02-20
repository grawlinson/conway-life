#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix.h"
#include "life.h"
#include "patterns.h"

/* RNG */
#include <time.h>

#define SLEEP_TIME 100000 /* roughly 0.1 seconds */

/* Function Declarations */
void display_game(int *matrix, int cols, int rows);
void display_usage(void);
void display_version(void);

int main(int argc, char *argv[])
{
    int nx, ny, i, n;
    int x, y, num_generations;
    int pad_width;
    int *matrix;
    char *ptr;

    /* Seed RNG */
    srand(time(NULL));

    /* Display version info, then quit */
    if(argc == 2)
    {
        int ret = strcmp(argv[1], "version");

        if(ret < 0 || ret > 0)
        {
            /* Do absolutely nothing */
        }
        else
        {
            display_version();
            return EXIT_SUCCESS;
        }
    }

    /* Check if right number of arguments passed */
    if(argc != 4)
    {
        display_usage();
        return EXIT_SUCCESS;
    }

    /* Convert argv to integer (base 10) */
    x = strtol(argv[1], &ptr, 10);
    y = strtol(argv[2], &ptr, 10);
    num_generations = strtol(argv[3], &ptr, 10);
    pad_width = strlen(argv[3]);

    if(x <= 0 || y <= 0 || num_generations < 0)
    {
        x = 60; y = 60; num_generations = 900;
    }

    /* Dynamically allocate memory for 2D matrix */
    malloc_matrix(&matrix, x, y);

    /* Populate 2D matrix with data */
    fill_matrix(matrix, x, y, DEAD);

    for(ny = 0; ny < y; ny++)
    {
        for(nx = 0; nx < x; nx++)
        {
            /* Reduce number of live cells generated via RNG*/
            if(rand() % 20 >= 17)
            {
                set_cell_state(matrix, x, y, nx, ny, ALIVE);
            }
            if(ny >= y || nx >= x)
            {
                fprintf(stderr, "[main] array out of bounds\n");
                exit(EXIT_FAILURE);
            }
        }
    }

    /* Iterate through generations */
    for(n = 0; n < num_generations; n++)
    {
        /* Delete previous world using VT-100 hacks */
        if(n > 0)
        {
            /* Forward a single generation */
            next_generation(matrix, x, y);
            for(i=0;i<y+3;i++)
            {
                fputs("\033[A\033[2K",stdout);
            }
        }

        /* Print Game of Life */
        printf("%0*d/%d\n", pad_width, n+1, num_generations);
        display_game(matrix, x, y);

        /* Sleep */
        usleep(SLEEP_TIME);
    }

    /* Free memory */
    free_matrix(&matrix);

    return EXIT_SUCCESS;
}

void display_usage(void)
{
    printf("Usage: conway-life [columns] [rows] [generations]\n");
}

void display_version(void)
{
    printf("GIT VERSION: %s\n", GIT_VERSION);
    printf("GIT COMMIT : %s\n", GIT_COMMIT);
    printf("GIT DATE   : %s\n", GIT_DATE);
    printf("BUILD DATE : %s\n", BUILD_DATE);
}

void display_game(int *matrix, int cols, int rows)
{
    #define CHAR_ALIVE 'o'
    #define CHAR_DEAD ' '
    #define CHAR_V_BORDER '|'
    #define CHAR_H_BORDER '-'
    #define CHAR_WHITESPACE ' '
    #define CHAR_TOP_LEFT_CORNER CHAR_WHITESPACE
    #define CHAR_TOP_RIGHT_CORNER CHAR_WHITESPACE
    #define CHAR_BOTTOM_LEFT_CORNER CHAR_WHITESPACE
    #define CHAR_BOTTOM_RIGHT_CORNER CHAR_WHITESPACE

    int r, c;
    char *matrix_row = malloc(2*cols+2*sizeof(*matrix_row));
    matrix_row[2*cols+1] = '\0';

    matrix_row[0] = CHAR_TOP_LEFT_CORNER;
    for (c = 1; c < 2*cols; c++)
    {
        matrix_row[c] = CHAR_H_BORDER;
    }
    matrix_row[2*cols] = CHAR_TOP_RIGHT_CORNER;
    puts(matrix_row);

    for (c = 0; c <= 2*cols; c+=2)
    {
        matrix_row[c] = CHAR_V_BORDER;
    }

    for (r = 0; r < rows; r++)
    {
        for (c = 0; c < cols; c++)
        {
            if(get_cell_state(matrix, cols, rows, c, r) == ALIVE)
            {
                matrix_row[2*c+1] = CHAR_ALIVE;
            }
            else
            {
                matrix_row[2*c+1] = CHAR_DEAD;
            }
        }
        puts(matrix_row);
    }

    matrix_row[0] = CHAR_BOTTOM_LEFT_CORNER;
    for (c = 1; c < 2*cols; c++)
    {
        matrix_row[c] = CHAR_H_BORDER;
    }
    matrix_row[2*cols] = CHAR_BOTTOM_RIGHT_CORNER;
    puts(matrix_row);

    free(matrix_row);
}
