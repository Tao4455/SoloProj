#include <iostream>
#include <ctime>
#include <cstdlib>


using namespace std;

// Creating structers for  three monsters in the maze
struct ResetMonster  
{
    int x, y;
    char rest;
};
struct KickerMonster
{
    int x, y;
    char kicker;
};
struct BlockMonster
{
    int x, y;
    char block;
};


char movement; // player's movements
const char arr_height = 11;
const char arr_width = 11;  // width and height of the simple maze
int playerPosX = 1, playerPosY = 1, goalPosX = 10, goalPosY = 9;  // Postions for player and the goal
const char chPlayer = 'o', enemy1 = 'K', enemy2 = 'S', enemy3 = 'R', myGoal = 'V';  // characters to represent the monsters and the goal

// generate 2-D text-based  maze map  
unsigned char mazeArr[arr_height][arr_width] = {
// 0   1  2  3  4  5  6  7  8  9  10
    '*','*','*','*','*','*','*','*','*','*','*', //0
    '*',' ',' ',' ','*',' ',' ',' ',' ',' ','*',                  //1
    '*',' ','*',' ','*',' ','*','*',' ','*','*',     //2
    '*',' ',' ',' ',' ',' ','*',' ',' ',' ','*',  // 3
    '*',' ','*','*',' ','*','*',' ','*',' ','*', //4
    '*',' ',' ',' ',' ',' ',' ',' ','*',' ','*', //5
    '*',' ','*','*','*',' ','*',' ','*',' ','*', //6
    '*',' ','*',' ','*',' ','*',' ','*',' ','*', //7
    '*',' ',' ',' ',' ',' ','*',' ','*',' ','*', //8
    '*',' ','*',' ','*',' ','*',' ',' ',' ','*', //9
    '*','*','*','*','*','*','*','*','*','*','*', //10
    };

int printMaze()
{
    mazeArr [playerPosX][playerPosY] = chPlayer;  //update player's location
    mazeArr[goalPosX][goalPosY] = myGoal; // update the target's location
    for(int i = 0; i < arr_height; ++i) {     // print out maze 
        cout << "\n";
            for(int j = 0; j < arr_width; ++j)
                cout << mazeArr[i][j];
    }
    return 0;
}

// function to spawn monsters
int mon_spwn1() 
{
    KickerMonster myEnemy1; // create monster 1
    myEnemy1.kicker = enemy1;
    srand(time(NULL)); //  seeding random number
    int mon_pos_x1 = myEnemy1.x;  // prop monsters at random positions
    mon_pos_x1 = (rand() % 9) + 1;   // random X spot for monster 1
    int mon_pos_y1 = myEnemy1.y;  
    mon_pos_y1 = (rand() % 9) + 1;   // random y spot for monster 1  
    
// making sure monsters do not overlap with walls or player   
 if(mazeArr[mon_pos_x1][mon_pos_y1] != '*' && mazeArr[mon_pos_x1][mon_pos_y1] != 'o' ) {   
        mazeArr[mon_pos_x1][mon_pos_y1] = enemy1;
    }
    
    return 0;
}

int mon_spwn2() 
{
    BlockMonster myEnemy2; // create monster 2
    myEnemy2.block = enemy2;
    srand(time(NULL)); //  seeding random number
    int mon_pos_x2 = myEnemy2.x;  // prop monsters at random positions
    mon_pos_x2 = (rand() % 9) + 1;   // random X spot for monster 2
    int mon_pos_y2 = myEnemy2.y;  
    mon_pos_y2 = (rand() % 9) + 1;   // random y spot for monster 2  
    
// making sure monsters do not overlap with walls or player   
 if(mazeArr[mon_pos_x2][mon_pos_y2] != '*' && mazeArr[mon_pos_x2][mon_pos_y2] != 'o' ) {   
        mazeArr[mon_pos_x2][mon_pos_y2] = enemy2;
    }
    
    return 0;
}
int mon_spwn3() 
{
    ResetMonster myEnemy3; // create monster 3
    myEnemy3.rest = enemy3;
    srand(time(NULL)); //  seeding random number
    int mon_pos_x3 = myEnemy3.x;  // prop monsters at random positions
    mon_pos_x3 = (rand() % 9) + 1;   // random X spot for monster 3
    int mon_pos_y3 = myEnemy3.y;  
    mon_pos_y3 = (rand() % 9) + 1;   // random y spot for monster 3  
    
// making sure monsters do not overlap with walls or player   
 if(mazeArr[mon_pos_x3][mon_pos_y3] != '*' && mazeArr[mon_pos_x3][mon_pos_y3] != 'o' ) {   
        mazeArr[mon_pos_x3][mon_pos_y3] = enemy3;
    }
    
    return 0;
}
int playerDirection()
{
    while(1>0){
        cin >> movement;  // input movement from user
        switch(movement) {
            case 'w':   // up direction
                if(mazeArr[playerPosX-1][playerPosY] != '*' && mazeArr[playerPosX-1][playerPosY] != enemy2) {
                    mazeArr[playerPosX][playerPosY] = ' ';
                    playerPosX--;
                    }
                if(mazeArr[playerPosX][playerPosY] == enemy3) {
                mazeArr[playerPosX][playerPosY] = ' ';
                playerPosX = 1;
                playerPosY = 1;
            }
                if(mazeArr[playerPosX][playerPosY] == enemy1){
                    mazeArr[playerPosX][playerPosY] = ' ';
                    cout << "Boom! Gotcha!!!" << endl;
            }
             break;
             case 's':   // down direction
                if(mazeArr[playerPosX][playerPosY+1] != '*' && mazeArr[playerPosX][playerPosY+1] != enemy2) {
                    mazeArr[playerPosX][playerPosY] = ' ';
                    playerPosY++;
                    }
                if(mazeArr[playerPosX][playerPosY] == enemy3) {
                mazeArr[playerPosX][playerPosY] = ' ';
                playerPosX = 1;
                playerPosY = 1;
            }
                if(mazeArr[playerPosX][playerPosY] == enemy1){
                    mazeArr[playerPosX][playerPosY] = ' ';
                    cout << "Boom! Gotcha!!!" << endl;
            }
                if(mazeArr[playerPosX][playerPosY] == myGoal)
                    cout << "Victory!";
             break;
             case 'a':   // Left direction
                if(mazeArr[playerPosX][playerPosY-1] != '*' && mazeArr[playerPosX][playerPosY-1] != enemy2) {
                    mazeArr[playerPosX][playerPosY] = ' ';
                    playerPosY--;
                    }
                if(mazeArr[playerPosX][playerPosY] == enemy3) {
                mazeArr[playerPosX][playerPosY] = ' ';
                playerPosX = 1;
                playerPosY = 1;
            }
                if(mazeArr[playerPosX][playerPosY] == enemy1){
                    mazeArr[playerPosX][playerPosY] = ' ';
                    cout << "Boom! Gotcha!!!" << endl;
            }
             break;
             case 'd':   // right direction
                if(mazeArr[playerPosX][playerPosY+1] != '*' && mazeArr[playerPosX][playerPosY+1] != enemy2) {
                    mazeArr[playerPosX][playerPosY] = ' ';
                    playerPosY++;
                    }
                if(mazeArr[playerPosX][playerPosY] == enemy3) {
                mazeArr[playerPosX][playerPosY] = ' ';
                playerPosX = 1;
                playerPosY = 1;
            }
                if(mazeArr[playerPosX][playerPosY] == enemy1){
                    mazeArr[playerPosX][playerPosY] = ' ';
                    cout << "Boom! Gotcha!!!" << endl;
            }
             break;
             default:
             cout << "Invalid key. Press again!";
        }
       cout << mon_spwn1();
       cout << mon_spwn3();
       cout << mon_spwn2();
       printMaze();
        }
    return 0;
}

int main()
{
    
    cout << "\nGreetings! Explorer. Welcome to the 10X10 Maze\n\nPress your Q key to exit game. Otherwise, press: \n\n";
    cout << "W - UP\nS - Down\nA - Left\nD - Right\n\nReach letter V to claim your victory!\n";
    cout << "Be aware of three monsters, they meddle with your game in their own ways!\nPlay to find out. Good Luck!\n\n";
    cout << mon_spwn1();
    cout << mon_spwn2();
    cout << mon_spwn3();
    printMaze();
    cout << endl;
    playerDirection();
       
    return 0;
}