#include "trem.h"
#include <QtCore>

//Construtor
Trem::Trem(int ID, int x, int y){
    this->ID = ID;
    this->x = x;
    this->y = y;
    velocidade = 0;
}

void Trem::setVelocidade(int vel){
    this->velocidade = vel;
}

//Função a ser executada após executar trem->START
void Trem::run(){
    int direcao;
    while(true){

        switch(ID){
        case 1:
            if(this->velocidade != 0) {
                if (y == 30 && x < 483){ // andar para a direita
                    x+=10;
                    direcao = 1;
                }
                else if (x == 483 && y < 220){ // andar para baixo
                    y+=10;
                    direcao = 2;
                }
                else if (x > 310 && y == 220){ // andar para a esquerda
                    x-=10;
                    direcao = 3;
                }
                else{
                    y-=10; // andar para cima
                    direcao = 4;
                }
            }
            emit updateGUI(ID, x, y, direcao);    //Emite um sinal
            break;
        case 2:
            if(this->velocidade != 0) {
                if (y == 30 && x < 664){ // andar para a direitas
                    x+=10;
                    direcao = 1;
                } else if (x == 664 && y < 220){ // andar para baixo
                    y+=10;
                    direcao = 2;
                }else if (x > 490 && y == 220){ // andar para a esquerda
                    x-=10;
                    direcao = 3;
                }else{
                    y-=10; // andar para cima
                    direcao = 4;
                }
            }
            emit updateGUI(ID, x, y, direcao);    //Emite um sinal
            break;
        case 3:
            if(this->velocidade != 0) {
                if (y == 220 && x < 393){ // andar para a direitas
                    x+=10;
                    direcao = 1;
                }else if (x == 393 && y < 410){ // andar para baixo
                    y+=10;
                    direcao = 2;
                }else if (x > 220 && y == 410){ // andar para a esquerda
                    x-=10;
                    direcao = 3;
                }else{
                    y-=10; // andar para cima
                    direcao = 4;
                }
            }
            emit updateGUI(ID, x, y, direcao);    //Emite um sinal
            break;
        case 4:
            if(this->velocidade != 0) {
                if (y == 220 && x < 570){ // andar para a direitas
                    x+=10;
                    direcao = 1;
                }else if (x == 570 && y < 410){ // andar para baixo
                    y+=10;
                    direcao = 2;
                }else if (x > 397 && y == 410){ // andar para a esquerda
                    x-=10;
                    direcao = 3;
                }else{
                    y-=10; // andar para cima
                    direcao = 4;
                }
            }
            emit updateGUI(ID, x, y, direcao);    //Emite um sinal
            break;
        case 5:
            if(this->velocidade != 0) {
                if (y == 220 && x < 750){ // andar para a direitas
                    x+=10;
                    direcao = 1;
                }else if (x == 750 && y < 410){ // andar para baixo
                    y+=10;
                    direcao = 2;
                }else if (x > 577 && y == 410){ // andar para a esquerda
                    x-=10;
                    direcao = 3;
                }else{
                    y-=10; // andar para cima
                    direcao = 4;
                }
            }
            emit updateGUI(ID, x, y, direcao);    //Emite um sinal
            break;
        default:
            break;
        }
        msleep(200 - velocidade);
    }
}




