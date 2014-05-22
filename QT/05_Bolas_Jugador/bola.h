#ifndef BOLA_H
#define BOLA_H

#include <QVector>

class Bola{
	public:
		static int diametro; // 1 DECLARAR
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
