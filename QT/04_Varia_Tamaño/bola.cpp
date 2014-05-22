#include "bola.h"
#include <stdlib.h>
#include <math.h>

int Bola::diametro; //2 CREAR VARIABLE DE CLASE

Bola::Bola(){}

Bola::Bola(float posicionX,float posicionY,float velocidadX,float velocidadY){
	posX = posicionX;
	posY = posicionY;
	velX = velocidadX;
	velY = velocidadY;
}

void Bola::mueve(){
	posY += velY;
	posX += velX;
}

void Bola::rebotan(int width, int height){
	if(posX <= 0){
		velX = fabs(velX);
	}
	if(posX >= width - diametro){
		velX = -fabs(velX);
	}

	if(posY <= 0){
		velY = fabs(velY);
	}
	if(posY >= height - diametro){
		velY = -fabs(velY);
	}
}

void Bola::bolasRebotan(Bola * bola){
	Bola *izquierda, *derecha, *arriba, *abajo;;
			
	izquierda = this;
	derecha = bola;

	if(posX > bola->posX){
		izquierda = bola;
		derecha = this;
	}

	if(izquierda->velX > derecha->velX){
		float temp = izquierda->velX;
		izquierda->velX = derecha->velX;
		derecha->velX = temp;
	}

	arriba = this;
	abajo = bola;

	if(posY > bola->posY){
		arriba = bola;
		abajo = this;
	}

	if(arriba->velY > abajo->velY){
		float temp = arriba->velY;
		arriba->velY = abajo->velY;
		abajo->velY = temp;
	}
}







