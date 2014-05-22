#include "bola.h"
#include <stdlib.h>
#include <math.h>

int Bola::diametro; //2 CREAR VARIABLE DE CLASE
int Bola::gravedad;

Bola::Bola(){}

Bola::Bola(float posicionX,float posicionY,float velocidadX,float velocidadY, int v){
	posX = posicionX;
	posY = posicionY;
	velX = velocidadX;
	velY = velocidadY;
	vidas = v;
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

bool Bola::bolasRebotan(Bola * bola){
	float distancia = sqrtf(powf(posX - bola->posX, 2) + powf(posY - bola->posY, 2));				

	bool aux = false;

	if(distancia < Bola::diametro){		
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
			aux = true;
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
			aux = true;
		}
	}

	return aux;
}

void Bola::atraeBola(Bola * otraBola){
	float distancia = sqrtf(powf(posX - otraBola->posX, 2) + powf(posY - otraBola->posY, 2));	

	distancia = (distancia < diametro) ? diametro : distancia;

	float fuerzaTotal = gravedad / (distancia * distancia);

	float fuerzaX = fuerzaTotal * ((otraBola->posX - posX) / distancia);

	float fuerzaY = fuerzaTotal * ((otraBola->posY - posY) / distancia);

	velX += fuerzaX; 
	velY += fuerzaY;
}

void Bola::pintar(QPainter * pintor){
	QBrush color = pintor->brush();
	
	pintor->drawEllipse(posX,posY,Bola::diametro,Bola::diametro);

	if(vidas >= 0){
		QColor verde(0,255,0);
		pintor->setBrush(QBrush(verde));
		pintor->drawRect(posX, posY - 10, vidas * 10, 10 );
		pintor->setBrush(QBrush(QColor(255,0,0)));
		pintor->drawRect(posX + vidas * 10, posY - 10, (10 - vidas) * 10, 10);
	}	
	pintor->setBrush(color);
}







