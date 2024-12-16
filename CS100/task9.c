#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define FOOD_SCORE 10
#define MAX_GHOSTS 30

typedef enum gameState{losing, onGoing, winning} GameState;
typedef enum direction{up, down, left, right, idle} Direction;

typedef struct game {
    char** grid;
    int columns;
    int rows;
    int foodCount;
    int score;
    GameState state;
} Game;

/* Creates a new game, with given rows and columns.
 * The left-upper corner is at row 0 and column 0.
 * Boundary is not included in either rows or columns.
 * You should dynamically allocate space for a Game pointer,
 * dynamically allocate a 2-dimensional char grid,
 * and initialize any other value in your Game structure.
 * Return that pointer to the game you created.
 */
Game* NewGame(int rows, int columns){ 
    Game* game = (Game*)malloc(sizeof(Game));
    game->rows = rows;
    game->columns = columns;
    game->grid = (char**)malloc(sizeof(char*)*rows);
    for(int i=0;i<rows;i++){
        game->grid[i] = (char*)malloc(columns*sizeof(char));
    }
    for(int i = 0; i<game->rows;i++){
        for(int j =0;j<game->columns;j++){
            game->grid[i][j] = ' ';
        }
    }
    game->foodCount = 0;
    game->score = 0;
    game->state = onGoing;
    return game;
}

/* Ends your game by freeing any memory
 * you dynamically created.
 * After that, free the game pointer,
 * as it is also dynamically created.
 */
void EndGame(Game* game){
    for(int i=0;i<game->rows;i++){
      free(game->grid[i]);
    }
    free(game->grid);
    free(game);
    return;
}

/* Adds a wall to the game, at row = r, column = c.
 * Walls should be added only to an empty place.
 * After you successfully add a wall, 
 * you should modify the `grid' to represent
 * the wall by '#'. Then, return true.
 * Return false on failures.
 */
bool AddWall(Game* game, int r, int c){
    if(r<0||r>=game->rows||c<0||c>=game->columns){
        return false;
    }
    if(game->grid[r][c]==' '){
        game->grid[r][c]='#';
        return true;
    }
    else{
        return false;
    }
}

/* Adds a food to the game, at row = r, column = c.
 * Foods should be added only to an empty place.
 * After you successfully add a food, 
 * you should modify the `grid' to represent
 * the food by '.', also update the `foodCount'
 * correctly. Then, return true.
 * Return false on failures.
 *
 * FOR PART 2:
 * It's not allowed to add a food on a ghost.
 * It's allowed, however, conversely.
 */
bool AddFood(Game* game, int r, int c){
    if(r<0||r>=game->rows||c<0||c>=game->columns){
        return false;
    }
    if(game->grid[r][c]==' '){
        game->grid[r][c]='.';
        game->foodCount+=1;
        return true;
    }
    else{
        return false;
    }
}


/* Adds a Pacman to the game! At row = r, column = c.
 * If there is already a Pacman, return false.
 * Pacman should be added only to an empty place.
 * After you successfully add a Pacman,
 * you should modify the `grid' to represent
 * the Pacman by 'C'. Then, return true.
 * Return false on failures.
 */
bool AddPacman(Game* game, int r, int c){
    if(r<0||r>=game->rows||c<0||c>=game->columns){
        return false;
    }
    for(int i = 0; i<game->rows;i++){
        for(int j =0;j<game->columns;j++){
            if(game->grid[i][j]=='C'){
                return false;
            }
        }
    }

    if(game->grid[r][c]==' '){
        game->grid[r][c]='C';
        return true;
    }
    else{
        return false;
    }
}

/* Moves Pacman in the given direction.
 * The direction will always be valid.
 * Pacman should stay still if this move
 * will let him hit a wall or boundaries.
 * No matter what move is performed, the
 * game score should decrease by 1.
 *
 * FOR PART 2:
 * Pacman is allowed to move onto a grid
 * with a ghost. In that case, Pacman loses,
 * and will not be able to eat the food
 * under that ghost, if any. Score should
 * still decrease by 1.
 */
void MovePacman(Game* game, Direction direction){
    int x,y;
    for(int i=0;i<game->rows;i++){
        for(int j=0;j<game->columns;j++){
            if(game->grid[i][j]=='C'){
                x = i;
                y = j;
            }
        }
    }


    switch(direction){
        case up:
            game->score-=1;
            if(x-1<0){
                break;
            }

            if( game->grid[x-1][y]=='.'){
                game->score+=FOOD_SCORE;
                game->foodCount-=1;
            }

            if( game->grid[x-1][y]==' '||game->grid[x-1][y]=='.'){
                game->grid[x-1][y]='C';
                game->grid[x][y]=' ';
            }

            break;

        case down:
            game->score-=1;
            if(x+1>=game->rows){
                break;
            }

            if(game->grid[x+1][y]=='.'){
                game->score+=FOOD_SCORE;
                game->foodCount-=1;
            }

            if( game->grid[x+1][y]==' '||game->grid[x+1][y]=='.'){
                game->grid[x+1][y]='C';
                game->grid[x][y]=' ';
            }

            break;

        case left:
            game->score-=1;
            if(y-1<0){
                break;
            }

            if(game->grid[x][y-1]=='.'){
                game->score+=FOOD_SCORE;
                game->foodCount-=1;
            }

            if( game->grid[x][y-1]==' '||game->grid[x][y-1]=='.'){
                game->grid[x][y-1]='C';
                game->grid[x][y]=' ';
            }

            break;

        case right:
            game->score-=1;
            if(y+1>=game->columns){
                break;
            }
                     
            if(game->grid[x][y+1]=='.'){
                game->score+=FOOD_SCORE;
                game->foodCount-=1;
            }

            if( game->grid[x][y+1]==' '||game->grid[x][y+1]=='.'){
                game->grid[x][y+1]='C';
                game->grid[x][y]=' ';
            }

            break;
        case idle:
            game->score-=1;
            break;
    }

    if(game->foodCount==0){game->state=winning;}
    else{game->state=onGoing;}
    return;
}

/* Adds a ghost to the game,
 * at row = r, column = c, with given initial direction.
 * you should modify the `grid' to represent the ghost by '@'.
 * Ghosts can be added to an empty place or on a food.
 * For the latter case, the ghost will cover that food on display,
 * represented also by an '@'. 
 * That food must still exist, and that grid should 
 * display '.' when the ghost leaves.
 */
bool AddGhost(Game* game, int r, int c, Direction direction){
    return false;
}

/* Moves all ghosts in their own directions.
 * Ghosts should be moved in the order they were added.
 * If a ghost will bump into a wall, another ghost, or a boundary,
 * Its direction will reverse, and it will try to move
 * in the new direction immediately this turn.
 * If it bumps into another wall/ghost/boundary,
 * it won't move for this turn.
 */
void MoveGhosts(Game* game){
    return;
}


///////////////////////////////////////////////////////////////////////////////
/////////////////// Please submit all code above to OJ ////////////////////////
///////////////////////////////////////////////////////////////////////////////

// Declarations of provided functions
void PrintGame(Game* game);
void PlayGame(Game* game);

int main(){
    Game* game = NewGame(8, 8);

    // Add walls, foods, and pacman here.
    AddWall(game,1,1);
    AddWall(game,3,3);
    AddPacman(game,6,6);
    AddFood(game, 2, 2);
    

    PlayGame(game);

    EndGame(game);
}

///////////////////////////////////////////////////////////////////////////////
//////////////////////// DO NOT MODIFY ANY CODE BELOW! ////////////////////////
///////////////////////////////////////////////////////////////////////////////

/* This function prints the game grid with boundary,
 * and any message depending on game state.
 * Please make sure that, after any action is done,
 * game->state, game->score, and game->foodCount
 * are correctly updated.
 */
#ifdef _MSC_VER

#include <windows.h>

#endif // _MSC_VER

void PrintGame(Game* game){
    if(!game || !game->grid) return;

// If visual C++, clear console.
#ifdef _MSC_VER 
    system("cls");
#else
// Clears terminal screen
#ifndef _ONLINE_JUDGE
    fflush(stdout);
    system("clear");
#endif

#endif
    
    // The game grid
    printf(" ");
    for(int i = 0; i < game->columns; i++)
        printf("_");
    printf(" \n");

    for(int i = 0; i < game->rows; i++){
        printf("|");
        for(int j = 0; j < game->columns; j++)
            printf("%c", game->grid[i][j]);
        printf("|\n");
    }
    printf("\\");
    for(int i = 0; i < game->columns; i++)
        printf("-");
    printf("/\n\n");

    // Messages on different states
    switch(game->state){
    case losing:
        printf("Pacman died! Your score: %d\n", game->score);
        break;
    case onGoing:
        printf("Score: %d\n", game->score);
        printf("There are %d foods remaining!\n", game->foodCount);
        printf("Pacman wants food! (control by w/a/s/d/i, confirm by Enter)\n\n");
        break;
    case winning:
        printf("Victory! Your score: %d\n", game->score);
        break;
    default:
        printf("ERROR: invalid game state!\n");
    }
}

void PlayGame(Game* game){
    if(!game) return;
    
    // Prints the initial grid
    PrintGame(game);

    // Main loop of game. Terminates when the game ends.
    while(true){
        // We only care about one charater, but should eat the whole line of input.
        char input[127];
        scanf("%s", input);
        Direction direction;
        switch(input[0]){
        case 'w':
        case 'W':
            direction = up; break;
        case 'a':
        case 'A':
            direction = left; break;
        case 's':
        case 'S':
            direction = down; break;
        case 'd':
        case 'D':
            direction = right; break;
        case 'i':
        case 'I':
            direction = idle; break;
        default:
            PrintGame(game);
            continue;
        }

        // Pacman moves first
        MovePacman(game, direction);

        // Loses if Pacman bumps into a ghost
        if(game->state != onGoing){
            break;
        }
        
        // If you haven't implemented ghosts, this does nothing.
        MoveGhosts(game);

        // Loses if a ghost kills Pacman
        if(game->state != onGoing){
            break;
        }
        PrintGame(game);
    }

    // End game message
    PrintGame(game);
    printf("Press any key to exit.\n");
    getchar();
    getchar();
}