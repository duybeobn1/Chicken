#include <iostream>
#include <ctime>
#include <unistd.h>
using namespace std;

const int BOARD_WIDTH = 40;
const int BOARD_HEIGHT = 20;
const int PLAYER_Y = BOARD_HEIGHT - 1;
const int NUM_CHICKENS = 10;
const int NUM_MISSILES = 5;

char board[BOARD_HEIGHT][BOARD_WIDTH];
int playerX;
int score;
int chickenX[NUM_CHICKENS];
int chickenY[NUM_CHICKENS];
bool chickenAlive[NUM_CHICKENS];
int missileX[NUM_MISSILES];
int missileY[NUM_MISSILES];
bool missileAlive[NUM_MISSILES];

void PrintBoard()
{
    system("clear"); // Clear the console

    for (int i = 0; i < BOARD_HEIGHT; i++)
    {
        for (int j = 0; j < BOARD_WIDTH; j++)
        {
            cout << board[i][j];
        }
        cout << endl;
    }

    cout << "Score: " << score << endl;
}

void HandleInput()
{
    // simulate left and right arrow key presses
    if (rand() % 2 == 0 && playerX > 0)
    {
        playerX--;
    }
    if (rand() % 2 == 0 && playerX < BOARD_WIDTH - 1)
    {
        playerX++;
    }

    // simulate spacebar key press
    for (int i = 0; i < NUM_MISSILES; i++)
    {
        if (!missileAlive[i] && rand() % 10 == 0)
        {
            missileX[i] = playerX;
            missileY[i] = PLAYER_Y - 1;
            missileAlive[i] = true;
            break; 
        }
    }
}
//void HandleInput()
//{
//    if (GetAsyncKeyState(VK_LEFT) && playerX > 0) {
//        playerX--;
//    }
//    if (GetAsyncKeyState(VK_RIGHT) && playerX < BOARD_WIDTH - 1) {
//        playerX++;
//    }
//    if (GetAsyncKeyState(VK_SPACE)) {
//        // Fire a missile
//        for (int i = 0; i < NUM_MISSILES; i++) {
//            if (!missileAlive[i]) {
//                missileX[i] = playerX;
//                missileY[i] = PLAYER_Y - 1;
//                missileAlive[i] = true;
//                break;
//            }
//        }
//    }
//}

void UpdateBoard()
{
    // Clear the board
    for (int i = 0; i < BOARD_HEIGHT; i++)
    {
        for (int j = 0; j < BOARD_WIDTH; j++)
        {
            board[i][j] = ' ';
        }
    }

    // Draw the player's spaceship
    board[PLAYER_Y][playerX] = '^';

    // Draw the chickens
    for (int i = 0; i < NUM_CHICKENS; i++)
    {
        if (chickenAlive[i])
        {
            board[chickenY[i]][chickenX[i]] = '@';
        }
    }

    // Draw the missiles
    for (int i = 0; i < NUM_MISSILES; i++)
    {
        if (missileAlive[i])
        {
            board[missileY[i]][missileX[i]] = '|';
        }
    }
}

void InitGame()
{
    // Initialize the board
    for (int i = 0; i < BOARD_HEIGHT; i++)
    {
        for (int j = 0; j < BOARD_WIDTH; j++)
        {
            board[i][j] = ' ';
        }
    }

    // Initialize the player's spaceship
    playerX = BOARD_WIDTH / 2;

    // Initialize the chickens
    for (int i = 0; i < NUM_CHICKENS; i++)
    {
        chickenX[i] = rand() % BOARD_WIDTH;
        chickenY[i] = rand() % (BOARD_HEIGHT / 2);
        chickenAlive[i] = true;
    }

    // Initialize the missiles
    for (int i = 0; i < NUM_MISSILES; i++)
    {
        missileAlive[i] = false;
    }

    // Initialize the score
    score = 0;
}


void GameLoop()
{
    // Initialize the game
    InitGame();

    // Run the game loop
    while (true)
    {
        // Handle input
        HandleInput();

        // Update the board
        UpdateBoard();

        // Print the board
        PrintBoard();

        // Check for collisions between missiles and chickens
        for (int i = 0; i < NUM_MISSILES; i++)
        {
            if (missileAlive[i])
            {
                for (int j = 0; j < NUM_CHICKENS; j++)
                {
                    if (chickenAlive[j] && missileX[i] == chickenX[j] && missileY[i] == chickenY[j])
                    {
                        // A missile hit a chicken
                        missileAlive[i] = false;
                        chickenAlive[j] = false;
                        score++;
                    }
                }
            }
        }

        // Move the chickens down
        for (int i = 0; i < NUM_CHICKENS; i++)
        {
            if (chickenAlive[i])
            {
                chickenY[i]++;
                if (chickenY[i] >= BOARD_HEIGHT)
                {
                	int posX = chickenX[i];
                    chickenAlive[i] = false;
                    chickenX[i] = posX;
                    chickenY[i] = BOARD_HEIGHT / 2 - 5;
                    chickenAlive[i] = true;
                }
                if (chickenY[i] == PLAYER_Y && chickenX[i] == playerX)
                {
                    chickenAlive[i] = false;
                    cout << "Game over" << endl;
                    return;
                }
            }
        }
        

        // Move the missiles up
        for (int i = 0; i < NUM_MISSILES; i++)
        {
            if (missileAlive[i])
            {
                missileY[i]--;
                if (missileY[i] < 0)
                {
                    // A missile reached the top of the screen
                    missileAlive[i] = false;
                }
            }
        }

        // Spawn new chickens
         for (int i = 0; i < NUM_CHICKENS; i++)
         {
             if (!chickenAlive[i])
             {
                 chickenX[i] = rand() % BOARD_WIDTH;
                 chickenY[i] = rand() % (BOARD_HEIGHT / 2);
                 chickenAlive[i] = true;
             }
         }

        // Sleep for a short time to slow down the game
        usleep(100000);
    }
}

int main()
{
    srand(time(0)); // Seed the random number generator
    GameLoop();
    return 0;
}
