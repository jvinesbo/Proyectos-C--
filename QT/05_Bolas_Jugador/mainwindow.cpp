#include "mainwindow.h"
#include "bola.h"

#include <QTextEdit>
#include <QtGui>
#include <QLabel>
#include <QStatusBar>
#include <QTextCursor>
#include <QPainter>
#include <QTimer>
#include <QMenu>
#include <QBrush>
#include <QColor>
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

	Bola::diametro = 100;//3 INICIALIZAR VARIABLE DE CLASE

	temporizador = new QTimer();
	temporizador->setInterval(50);
	temporizador->setSingleShot(false);
	connect(temporizador, SIGNAL(timeout()), this, SLOT(repintar()));
	temporizador->start();

	inicializarBolas(5,lasBolas);

	crearMenu();

	dialogoConf = new DialogoConfiguracion();

	connect(dialogoConf->sliderTamanyoBola, SIGNAL(valueChanged(int)), this, SLOT(cambiaTamanyoBola(int)));

	bolaUsuario = new Bola(20,20,0,0);
}

MainWindow::~MainWindow()
{
	//destructor
}

void MainWindow::crearMenu(){
	accionAbrir = new QAction(tr("&Configuracion"),this);
	connect(accionAbrir, SIGNAL(triggered()),this, SLOT(abrirConfiguracion()));

	QMenu *menu;
	menu = menuBar()->addMenu(tr("&Configuracion"));
	menu->addAction(accionAbrir);
}

void MainWindow::paintEvent(QPaintEvent *e){
	QPainter pintor(this);
	QColor rojo(255,0,0);
	QColor amarillo(120,120,120);
	
	pintor.setBrush(QBrush(amarillo));
	pintor.drawEllipse(bolaUsuario->posX,bolaUsuario->posY,Bola::diametro,Bola::diametro);
	bolaUsuario->mueve();	
	bolaUsuario->rebotan(width(), height());
	pintor.setBrush(QBrush(rojo));

	for(QVector<Bola>::iterator it=lasBolas.begin(); it != lasBolas.end(); it++){
		pintor.drawEllipse(it->posX,it->posY,Bola::diametro,Bola::diametro);

		it->mueve();
		it->rebotan(width(), height());

		it->bolasRebotan(bolaUsuario);

		for(QVector<Bola>::iterator it2 = it + 1; it2 != lasBolas.end(); it2++){	
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

void MainWindow::abrirConfiguracion(){
	dialogoConf->show();
}

void MainWindow::cambiaTamanyoBola(int tamanyo){
	Bola::diametro = tamanyo;
}

void MainWindow::keyPressEvent(QKeyEvent *e){
	int pulsada = e->key();

	/*if(pulsada == Qt::Key_Right){
		bolaUsuario->posX += 3;
	}
	if(pulsada == Qt::Key_Left){
		bolaUsuario->posX -= 3;
	}
	
	if(pulsada == Qt::Key_Down){
		bolaUsuario->posY += 3;
	}
	if(pulsada == Qt::Key_Up){
		bolaUsuario->posY -= 3;
	}*/

	switch(pulsada){
		case Qt::Key_Right:
			bolaUsuario->posX += 3;
		break;

		case Qt::Key_Left:
			bolaUsuario->posX -= 3;
		break;

		case Qt::Key_Down:
			bolaUsuario->posY += 3;
		break;

		case Qt::Key_Up:
			bolaUsuario->posY -= 3;
		break;
	}
}


