#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define FREE 2
#define SCALE 15
#define SHIFT 1

// function prototypes
void welcomeScreen ();
void displayExplicitCard();
void clearScreen();
void displayCard();
void displayRandomCard();

// main function
int main()
{
    // call function welcomeScreen
    welcomeScreen();
    // call function clearScreen
    clearScreen();
    // call function displayExplicitBingoCard
    displayExplicitCard();
    // call function clearScreen
    clearScreen();
    // call function displayCard()
    displayCard();
    // program executed successfully
    srand(time(0));

    displayRandomCard();
    return 0;
}

// welcomeScreen function displays the BINGO logo and rules of the game
void welcomeScreen ()
{
	printf ("\t\t\tBBBBB   II  NN     NN    GGGGG    OOOO  \n");
	printf ("\t\t\tBB  BB  II  NN N   NN  GG        OO  OO \n");
	printf ("\t\t\tBBBBB   II  NN  N  NN  GG        OO  OO \n");
	printf ("\t\t\tBB  BB  II  NN   N NN  GG  GGGG  OO  OO \n");
	printf ("\t\t\tBBBBB   II  NN     NN   GGGGGG    OOOO  \n");
	printf ("\n\n");//
	printf ("RULES OF THE GAME:\n");
    printf("1. A player receives a Bingo card\n");
    printf("2. Each card has a random placement of numbers for each column, B, I, N. G, O\n");
    printf("\t Column B contains values 1 - 15\n");
    printf("\t Column I contains values 16 - 30\n");
    printf("\t Column N contains values 31 - 45 in addition to a FREE space\n");
    printf("\t Column G contains values 46 - 60\n");
    printf("\t Column O contains values 61 - 75\n");
    printf("3. Various patterns are identified to accomplish a BINGO\n");
    printf("4. Each round of the game will identify which pattern should be accomplished to win a BINGO\n");
    printf("5. Winning numbers are randomly selected during play\n");
    printf("6. Good luck!\n");
}

// function displayExplicitBingoCard displays a hardcoded version of a bingo card
void displayExplicitCard()
{
    printf("|---------------------------------------|\n");
    printf("|   B   |   I   |   N   |   G   |   O   |\n");
    printf("|---------------------------------------|\n");
    printf("|   15  |   16  |   31  |   46  |   61  |\n");
    printf("|---------------------------------------|\n");
    printf("|   2   |   23  |   45  |   60  |   75  |\n");
    printf("|---------------------------------------|\n");
    printf("|   5   |   20  |  FREE |   51  |   68  |\n");
    printf("|---------------------------------------|\n");
    printf("|   12  |   27  |   40  |   55  |   70  |\n");
    printf("|---------------------------------------|\n");
    printf("|   9   |   30  |   37  |   49  |   64  |\n");
    printf("|---------------------------------------|\n");
}

void displayCard()
{
    int row;
    int col;
    int num;

    printf("|---------------------------------------|\n");
    printf("|   B   |   I   |   N   |   G   |   O   |\n");
    printf("|---------------------------------------|\n");

    for(row = 0; row < ROWS; row++)
    {
        printf("|");

        for(col = 0; col < COLS; col++)
        {
            num = (col + SHIFT) * SCALE - row;

            if(row == FREE && col == FREE)
            {
                printf("  FREE |");
            }
            else
            {
                printf("%s%-3d", "   ", num);
                printf(" |");
            }
        }

        printf("\n");
        printf("|---------------------------------------|\n");
    }
}

// function clearScreen clears the screen for display purposes
void clearScreen()
{
    printf("\n\t\t\t\tHit <ENTER> to continue!\n");

	char enter;
	scanf("%c", &enter );

	// send the clear screen command Windows
    system("cls");
    // send the clear screen command for UNIX flavor operating systems
    // system("clear");
}


void displayRandomCard()
{

   int row, col, num, base;


    printf("\n");
    printf("\n");
    printf("|---------------------------------------|\n");
    printf("|   B   |   I   |   N   |   G   |   O   |\n");
    printf("|---------------------------------------|\n");

    srand(time(0));
    for(int row = 0; row< ROWS; row++)
    {


        for(col =0; col < COLS; col++)

        {

           base = (col) * SCALE;
           num = (rand()%15 + base);

           printf("|  %d   ", num);

           if (row == FREE && col == FREE)

           {
               printf("\b\b\b\b\bFREE  ");

           }
           else;

           num = SCALE - (row*SHIFT) + (col*SCALE);
        }





        num = 1;
        printf("|");
        printf("\n");
        printf("|---------------------------------------|\n");
    }
}


