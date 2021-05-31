unsigned short int showx[12];
unsigned short int showy[12];
char moves[12];

#include <stdio.h>
#include <stdlib.h>
#include "headers/brain.h"

int main(int argc, char **argv){
    unsigned short int i, j, k, x=3, y=2, count=0;
    char ch, starter, tmp;
    while(starter != 'X' &&  starter != 'O'){
        printf("Choose your bit[X/O]: ");
        scanf("%c", &starter);
    }
    while(ch != '1'){
	system("$PREFIX/bin/stty cooked;clear;");
	printf("\t     -----Move for %c-----\n", starter);
        if(ch == 'k'){
            x = x -4;
            if(x < 3){
                x = 11;
            }
        }
        else if(ch == 'j'){
            y = y - 4;
            if(y < 2){
                y = 10;
            }
        }
        else if(ch == 'm'){
            x = x+4;
            if(x > 12){
                x = 3;
            }
        }
        else if(ch == 'l'){
            y = y+4;
            if(y > 12){
                y=2;
            }
        }
	else if(ch == ' ' && count <= 9){
            if(1 == dif(x, y)){
	        printf("You cannot place your move here.\n");
            }
            else{
		moves[count] = starter;
                showx[count] = x;
                showy[count] = y;
                count++;
		starter = (starter == 'X')?'O':'X';
		short int tmp = win();
                if(1 == tmp){
                    printf("Player %c has won!\n", moves[0]);
		    system("$PREFIX/bin/stty cooked");
		    return 0;
                }
		else if(2 == tmp){
			printf("Player %c has won!\n", moves[1]);
			system("$PREFIX/bin/stty cooked");
			return 0;
		}
		else if(3 == tmp){
			printf("Tie! Press 1 to exit.\n");
		}

            }
        }
	else{ help(); };
        for(i=1;i<=13;i++){
            printf("\t\t\33[1;35m!\33[0m");
            for(j=1;j<=12;j++){
                for(k=0;showx[k]!=0;k++){
                    if(i == showx[k] && j == showy[k]){
                        if(i == x && j == y){
		 	    printf("\33[7;31m%c\33[0m", moves[k]);
			}
			else{
			    printf("\33[1;31m%c\33[0m", moves[k]);
			}
                        goto label;
                    }
                }
                if(j == 12 || j==4 || j==8){
                    printf("\33[1;35m!\33[0m");
                }
                else if(i==1 || i==5 || i==9 || i==13){
                    printf("\33[1;32m=\33[0m");
                }
                else if(i==x && j==y){
                    printf("\33[1;37m%c\33[0m", starter);
                }
                else{
                    printf(" ");
                }
                label: continue;
            }
            printf("\n");
        }
        system("$PREFIX/bin/stty raw");
        scanf("%c", &ch);
//	system("clear;");
    }
    system("$PREFIX/bin/stty cooked");
}
