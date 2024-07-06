#include <iostream>
#include "windows.h"
#include "time.h"
using namespace std;

//Mapa do game
char Map[20][20] = {
"###################",
"#                 #",
"#  @ @ @ @ @ @ @  #",
"#   @ @ @ @ @ @   #",
"#                 #",
"#                 #",
"#                 #",
"#                 #",
"#                 #",
"#                 #",
"#                 #",
"#                 #",
"#                 #",
"#                 #",
"#                 #",
"#                 #",
"#                 #",
"#        w        #",
"###################"
};
//variaveis do game
bool endgame = false;
int gamespeed=  50;
int randomNum;
int maxHealth = 20;
int youHealth = maxHealth;
int op;

int main() {
		
			//cor do terminal
	system("color 0a");

	while(endgame == false){
		system("cls");
		srand(time(0));
		for(int y = 0; y < 20; y++){
			
			cout << Map[y] << endl;
		}
		
		cout << "Health " << youHealth << "/" << maxHealth;
		for (int y =0; y< 20; y++ ){
			for(int x = 0; x < 20; x++){
				switch(Map[y][x]){
					//esquerda
					case 'w':
						if(GetAsyncKeyState(VK_LEFT) != 0){
						
						int newX = x-1;
						
						switch(Map[y][newX]) {
							case ' ':
							Map[y][x] = ' ';
							x--;
							Map[y][newX] = 'w';
						break;
						}
					}
					//direita
					if(GetAsyncKeyState(VK_RIGHT) != 0){
						int newX = x+1;
						
						switch(Map[y][newX]) {
							
							case ' ':
							Map[y][x] = ' ';
							x++;
							Map[y][newX] = 'w';
						break;
						}
					}
					
						if(GetAsyncKeyState(VK_SPACE) != 0 ){
							y--;
							Map[y][x] = '^';
						}
						break;
						
						case '^':
					
						Map[y][x] = ' ';
						y--;
						if(Map[y][x] != '#' && Map[y][x] != '@') {
							Map[y][x] = '^';
						}else if(Map[y][x] == '@'){
							Map[y][x] =' ';
						}
					break;
					
					case '@':
						randomNum = rand() %10 + 1;
						if(randomNum == 1){
							
							y++;
							Map[y][x] = '*';
						}
						break;
					case '*':
						
						Map[y][x] = ' ';
						y++;
						if (Map[y][x] != '#' && Map[y][x] !='w'){
							Map[y][x] = '*';
						}else if (Map[y][x] == 'w'){
							youHealth -= 20;
						}
						break;
					}
				}
			}
			
			if(youHealth <= 0){
				endgame = true;
			}	
		Sleep(gamespeed);
		}
		
		system("cls");
		cout << "You Lost" << endl;
		cout << "Continue?" << endl;
		
		system("PAUSE");
	}



