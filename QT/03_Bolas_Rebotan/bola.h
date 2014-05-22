#ifndef BOLA_H
#define BOLA_H

#include <QVector>

class Bola{
	public:
		//static const int diametro = 100; declarar una variable de clase constante
		static int diametro;
		float posX;
		float posY;
		float velX;
		float velY;	
		
		Bola();
		Bola(float posX,float posY,float velX,float velY);

		void mueve();
		void rebotan(int width, int height);
		void bolasRebotan(Bola * bola);
};

#endif
