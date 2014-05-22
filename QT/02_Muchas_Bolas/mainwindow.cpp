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

void inicializarBolas(int numBolas, QVector<Bola> & lasBolas){
	for(int i = 0; i < numBolas; i++){
		float velocidadX = (float) (((rand() % 100 )/ 20) - 5);
		float velocidadY = (float) (((rand() % 100 )/ 20) - 5);
				
		float posicionX = (float) (rand() % 200);
		float posicionY = (float) (rand() % 200);
		
		lasBolas.push_back(Bola(posicionX,posicionY,velocidadX,velocidadY)); 
	}


}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    	resize(800,600);
	temporizador = new QTimer();
	temporizador->setInterval(50);
	temporizador->setSingleShot(false);
	connect(temporizador, SIGNAL(timeout()), this, SLOT(repintar()));
	temporizador->start();

	inicializarBolas(2,lasBolas);
}

MainWindow::~MainWindow()
{
	//destructor
}

void MainWindow::paintEvent(QPaintEvent *e){
	QPainter pintor(this);

	for(QVector<Bola>::iterator it=lasBolas.begin(); it != lasBolas.end(); it++){
		pintor.drawEllipse(it->posX,it->posY,100,100);

		it->posY += it->velY;
		it->posX += it->velX;

		if(it->posX <= 0){
			it->velX = fabs(it->velX);
		}
		if(it->posX >= width() - 100){
			it->velX = -fabs(it->velX);
		}

		if(it->posY <= 0){
			it->velY = fabs(it->velY);
		}
		if(it->posY >= height() - 100){
			it->velY = -fabs(it->velY);
		}
	}	
}	

void MainWindow::mousePressEvent(QMouseEvent *e){
	float velocidadX = (float) (((rand() % 100 )/ 20) - 5);
	float velocidadY = (float) (((rand() % 100 )/ 20) - 5);
				
		
	lasBolas.push_back(Bola(e->x() - 50, e->y() - 50,velocidadX,velocidadY));
}

void MainWindow::repintar(){
    this->update();
}




