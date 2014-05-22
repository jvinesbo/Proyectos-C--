#include "mainwindow.h"
#include "bola.h"

#include <QTextEdit>
#include <QtGui>
#include <QLabel>
#include <QStatusBar>
#include <QTextCursor>
#include <QPainter>
#include <QTimer>
#include <stdlib.h>
#include <math.h>

//variable = (condicion) ? valorTRUE : valorFALSE; es similar al IF{}ELSE{}

void inicializarBolas(int numBolas, QVector<Bola> & lasBolas){
	for(int i = 0; i < numBolas; i++){
		float velocidadX = (float) (((rand() % Bola::diametro )/ 20) - 5);
		float velocidadY = (float) (((rand() % Bola::diametro )/ 20) - 5);
				
		float posicionX = (float) (rand() % 200);
		float posicionY = (float) (rand() % 200);
		
		lasBolas.push_back(Bola(posicionX,posicionY,velocidadX,velocidadY)); 
	}
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    	resize(800,600);

	Bola::diametro = 100;

	temporizador = new QTimer();
	temporizador->setInterval(50);
	temporizador->setSingleShot(false);
	connect(temporizador, SIGNAL(timeout()), this, SLOT(repintar()));
	temporizador->start();

	inicializarBolas(5,lasBolas);
}

MainWindow::~MainWindow()
{
	//destructor
}

void MainWindow::paintEvent(QPaintEvent *e){
	QPainter pintor(this);

	for(QVector<Bola>::iterator it=lasBolas.begin(); it != lasBolas.end(); it++){
		pintor.drawEllipse(it->posX,it->posY,Bola::diametro,Bola::diametro);

		it->mueve();
		it->rebotan(width(), height());

		for(QVector<Bola>::iterator it2 = it + 1; it2 != lasBolas.end(); it2++){
			float distancia = sqrtf(powf(it->posX - it2->posX, 2) + powf(it->posY - it2->posY, 2));				

			if(distancia > Bola::diametro) continue;
				
			it->bolasRebotan(it2);
		}
	}
}	

void MainWindow::mousePressEvent(QMouseEvent *e){
	float velocidadX = (float) (((rand() % Bola::diametro )/ 20) - 5);
	float velocidadY = (float) (((rand() % Bola::diametro )/ 20) - 5);
				
		
	lasBolas.push_back(Bola(e->x() - 50, e->y() - 50,velocidadX,velocidadY));
}

void MainWindow::repintar(){
    this->update();
}




