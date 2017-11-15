/**
 *CS50 Homework below. Implementation of tile game - I coded the init(), draw(), move(), and won() functions.
 * fifteen.c
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */

#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = get_int();

        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }

    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).
 */
void init(void)
{
    // TODO
    //create board
    int count = 0;
    int max_tile = d*d-1;
    //iterate through rows and columns from top left to bottom right. assign a decrementing value to each position, ending on 0.
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            board[i][j] = max_tile - count;
            count++;
        }
    }
    //if the board has an odd number of tiles, the 1 and 2 tiles have to be swapped on the bottom row
    if (d % 2 == 0)
    {
        board[d-1][d-2] = 2;
        board[d-1][d-3] = 1;
    }

}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    // TODO - draw board.
    // iterate through the board. print each value followed by some spaces. if value is 0, print and underscore. (empty space).
    // put 3 line breaks after every row. this is outside the first loop, because the loop iterates through columns first.
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            int val = board[i][j];
            if (val == 0)
            {
                printf("_   ");
            }
            else
            {
                printf("%d   ", val);
            }
        }
        printf("\n\n\n");
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false.
 */
bool move(int tile)
{
    //to do
    //first assign values to these variables. we are looking for the position of the tile to move, and the zero tile.
    int row;
    int col;
    int zero_row;
    int zero_col;
    for (int i = 0; i<d; i++)
    {
        for (int j=0; j<d; j++)
        {
            if (board[i][j] == tile)
            {
                row = i;
                col = j;
            }
            if (board[i][j] == 0)
            {
                zero_row = i;
                zero_col = j;
            }
        }
    }
    // the below if statement translates to: if the tile is in the same column as 0, but in row +- 1 OR
    //                                       if the tile is in the same row as 0, but in colum +- 1, THEN
    // just swap their positions, else return false.
    if (((row + 1 == zero_row|| row - 1 == zero_row) && col == zero_col) ||
        ((col + 1 == zero_col|| col - 1 == zero_col) && row == zero_row))
    {
        board[zero_row][zero_col] = tile;
        board[row][col] = 0;
        return true;
    }
    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration),
 * else false.
 */
bool won(void)
{
    // TODO
    // this iterates through every position in the board from top left to bottom right, checking whether they increment from 1 - max_tile.
    // if this doesn't return false, and if the current_tile is the max_tile, we have to return true before it checks whether the bottom right tile is max_tile+1
    // which it would do, as the last iteration of the nested loops.
    int max_tile = d * d -1;
    int current_tile = 1;
    for (int i = 0; i<d;i++)
    {
        for (int j=0; j<d; j++)
        {
            if (board[i][j] != current_tile)
            {
                return false;
            }
            if (current_tile == max_tile)
            {
                return true;
            }
            current_tile++;
        }
    }
    return true;
}
