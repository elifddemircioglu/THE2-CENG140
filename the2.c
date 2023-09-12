#include <stdio.h>
#include <stdlib.h>

void put_star(int x, int y, int row, int col, char** lab,int *exit){

    if(x == 0 || y == 0 || x == row-1 || y == col - 1){
        *exit = 1;
        return ;
    }

    if ((x+1 < row) && (lab[y][x + 1] == ' ')) {
        lab[y][x+1] = '*';
        put_star(x+1,y,row,col,lab,exit);
        
    }

    if ((x-1 >= 0) && (lab[y][x - 1] == ' ')) {
        lab[y][x-1] = '*';
        put_star(x-1,y,row,col,lab,exit);
    }

    if ((y+1 < col) && (lab[y+1][x] == ' ')) {
        lab[y+1][x] = '*';
        put_star(x,y+1,row,col,lab,exit);
    }

    if ((y-1 >= 0) && (lab[y-1][x] == ' ')) {
        lab[y-1][x] = '*';
        put_star(x,y-1,row,col,lab,exit);
    }

}

int main(){

    int line_counter=0, *pexit, exit;
    int startx,starty,rowlength,collength,i,j;
    char temp,temparr[33334];
    char **lab;
    char tempchar;

    exit = 0;
    pexit = &exit;

    scanf("%d %d\n", &startx, &starty);

    /* finding out the row length */
    rowlength= 0;
    while (1) {
        scanf("%c",&temp);
        if (temp == '\n'){
            break;
        }
        temparr[rowlength] = temp;
        rowlength++;
    }

    /* finding the max column length */
    collength=100000/rowlength;

    /* allocating the lab */
    lab = (char **) malloc(sizeof(char *)*collength);
    for (i = 0; i < collength; i++) {
        lab[i] = (char*)malloc(rowlength * sizeof(char)); 
    }

    /* moving temparr to lab[0] */
    for (j=0;j<rowlength;j++){
        lab[0][j] = temparr[j];
    }

    /* scanninng the lab here */
    for(i=1; i<collength ;i++){
        
        scanf("%c",&tempchar);
        if (tempchar == '\n') {
            line_counter = i;
            if (scanf("%c",&tempchar)== EOF)
            {
                break; 
            }
        }

        lab[i][0] = tempchar;

        for(j=1;j<rowlength;j++){       
            scanf("%c",&lab[i][j]);
        }
    }

    lab[starty][startx] = '*';

    /* lets put stars everywhere */
    put_star(startx, starty, rowlength, line_counter, lab, pexit);

    if(exit!= 1){
        for (i = 0; i < line_counter; i++) {
            for (j = 0; j < rowlength; j++) {
                if(lab[i][j] == '*'){
                    lab[i][j] = '.';
                }
            }
        }
    }

    /* printing the lab here */
    for (i = 0; i < line_counter; i++) {
        for (j = 0; j < rowlength; j++) {
            printf("%c", lab[i][j]);
        }
            printf("\n");
    }


    /* freeing the lab here */
    for (i = 0; i < collength; i++) {
        free(lab[i]);
    }
    free(lab);

    return 0;
}
    


 /* collength = line_counter;
    reallocing the lab
    lab = (char**)realloc(lab, sizeof(char*) * line_counter);
    for (i = 0; i < line_counter; i++) {
        lab[i] = (char*)realloc(lab[i], sizeof(char) * rowlength);
    } */

