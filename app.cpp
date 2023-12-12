#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

bool gameOver;
const int height = 20;
const int width = 20;


void Setup(){
    gameOver = false;
}
void Draw(){

    system("cls");

    for(int i = 0; i < width; i++){
        cout <<"#";
    }cout << endl;

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            if(j == 0 || j == width-1){
                cout << "#";
            }else{
                cout<< "#";
            }
        }cout<<endl;
    }

    for(int i = 0; i < width; i++){
        cout << "#";
    }cout<<endl;
}

void Input(){}
void Logic(){}

int main() {
  
  Setup();
  while(!gameOver){
    Draw();
    Input();
    Logic();
    Sleep(50);
  }
}