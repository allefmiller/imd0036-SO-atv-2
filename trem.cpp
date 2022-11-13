#include "trem.h"
#include <QtCore>
#include <semaphore.h>

sem_t sem0,sem1, sem2, sem3, sem4, sem5, sem6;

//Construtor
Trem::Trem(int ID, int x, int y){
    this->ID = ID;
    this->x = x;
    this->y = y;
    velocidade = 0;

    sem_init(&sem0, 0, 0);
    sem_init(&sem1, 0, 1);
    sem_init(&sem2, 0, 0);
    sem_init(&sem3, 0, 0);
    sem_init(&sem4, 0, 0);
    sem_init(&sem5, 0, 0);
    sem_init(&sem6, 0, 0);
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
            if(y == 30 && x == 453)
                sem_wait(&sem0);
            if(y == 220 && x == 453)
                sem_post(&sem0);

            if(y == 190 && x == 483)
                sem_wait(&sem3);
            if(y == 220 && x == 363)
                sem_post(&sem3);

            if(y == 190 && x == 303)
                sem_post(&sem1);
            if(y == 220 && x == 423)
                sem_wait(&sem1);



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
                    if(x >= 450)
                        direcao = 1;
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
            if(y == 30 && x == 514)
                sem_post(&sem0);
            if(y == 220 && x == 514)
                sem_wait(&sem0);



            if(this->velocidade != 0) {
                if (y == 30 && x < 664){ // andar para a direita
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
            if(y == 220 && x == 273)
                sem_wait(&sem1);
            if(y == 250 && x == 393)
                sem_post(&sem1);

            if(y == 220 && x == 363)
                sem_wait(&sem2);
            if(y == 410 && x == 363)
                sem_post(&sem2);
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
            if(y == 250 && x == 390)
                sem_wait(&sem3);
            if(y == 220 && x == 520)
                sem_post(&sem3);

            if(y == 220 && x == 443)
                sem_post(&sem1);
            if(y == 410 && x == 443)
                sem_wait(&sem1);

            if(y == 410 && x == 420)
                sem_wait(&sem2);
            if(y == 220 && x == 420)
                sem_post(&sem2);

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

    sem_destroy(&sem0);
    sem_destroy(&sem1);
    sem_destroy(&sem2);
    sem_destroy(&sem3);
    sem_destroy(&sem4);
    sem_destroy(&sem5);
    sem_destroy(&sem6);
}




