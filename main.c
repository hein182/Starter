#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>

    void reverseString(char a[]){
        int i = 0;
        int j = 0;
        char temp;
        while(a[i] != '\0'){
            i++;
        }
        i--;
        while(i > j){
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i--;
            j++;
        }
    };

    void checkLimit(int *a){
        if(*a > 2){
            *a = 0;
        }
        if(*a < 0){
            *a = 2;
        }
    }



int main(void)
{
    int random_num, random_num2;
    char ch;
    int i = 0;
    int j = 0;
    int turn = 0;

    char matrix[3][3] = {
        {'_', '_', '_'},
        {'_', '_', '_'},
        {'_', '_', '_'}
    };
    int write[3][3] = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}
    };

    initscr();
    noecho();
    curs_set(0); // hide the cursor

    while (1){
    //print matrix
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printw("%c", matrix[i][j]);
        }
        printw("\n");
    }
    ch = getch();
    refresh();

    printw("You pressed '%c'\n", ch);

    switch(ch){
        case 'w':
            if(write[i][j] == 1){
            matrix[i][j] = '_';
            }
            i--;
            checkLimit(&i);
            break;
        case 's':
            if(write[i][j] == 1){
            matrix[i][j] = '_';
            }
            i++;
            checkLimit(&i);
            break;
        case 'a':
            if(write[i][j] == 1){
            matrix[i][j] = '_';
            }
            j--;
            checkLimit(&j);
            break;
        case 'd':
            if(write[i][j] == 1){
            matrix[i][j] = '_';
            }
            j++;
            checkLimit(&j);
            break;
        case 'q':
            endwin();
            return 0;

        case 'e':
            //write to write entered spot
            write[i][j] = '0';
            //increment turn
            turn++;

            // /* Initialize the random number generator with the current time */
            // srand(time(NULL));
            
            // /* Generate a random number between 0 and 2 */
            // while(matrix[random_num][random_num2]!='_'){
            // random_num = rand() % 3;
            // random_num2 = rand() % 3;
            // }
            // matrix[random_num][random_num2] = 'O';
            // write[random_num][random_num2] = '0';
            break;
        default:
            break;
    }
    if(write[i][j] == 1){
    if(turn % 2 == 0){    
    matrix[i][j] = 'X';
    }
    else{
        matrix[i][j] = 'O';
    }
    }
    //clear screen
    clear();
    }
    endwin();


    return 0;
}