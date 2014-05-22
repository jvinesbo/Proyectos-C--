#include "mainwindow.h"
#include "bola.h"
#include "modeloTabla.h"

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
				
		float posicionX = (float) (rand() % 500) + Bola::diametro + 10;
		float posicionY = (float) (rand() % 300) + Bola::diametro + 20;
		
		lasBolas.push_back(Bola(posicionX,posicionY,velocidadX,velocidadY,10)); 
	}
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
	inicializaConfiguracion();
    	resize(laConfiguracion.anchuraPantalla,laConfiguracion.alturaPantalla);

	Bola::diametro = 100;//3 INICIALIZAR VARIABLE DE CLASE

	temporizador = new QTimer();
	temporizador->setInterval(laConfiguracion.intervaloAnimacion);
	temporizador->setSingleShot(false);
	connect(temporizador, SIGNAL(timeout()), this, SLOT(repintar()));
	temporizador->start();

	inicializarBolas(5,lasBolas);

	dialogoBolas = NULL;

	crearMenu();

	dialogoConf = new DialogoConfiguracion();
	
	connect(dialogoConf->sliderTamanyoBola, SIGNAL(valueChanged(int)), this, SLOT(cambiaTamanyoBola(int)));

	bolaUsuario = new Bola(600,600,0,0,10);

	dialogoSuperConfiguracion = NULL;
}

MainWindow::~MainWindow()
{
	//destructor
}

void MainWindow::crearMenu(){
	accionAbrir = new QAction(tr("Configuracion Bolas"),this);
	connect(accionAbrir, SIGNAL(triggered()),this, SLOT(abrirConfiguracion()));

	QMenu *menu;
	menu = menuBar()->addMenu(tr("&Configuracion"));
	menu->addAction(accionAbrir);

	accionConfiguracion = new QAction(tr("Configuracion General"),this);
	connect(accionConfiguracion, SIGNAL(triggered()),this, SLOT(abrirConfiguracionGeneral()));
	menu->addAction(accionConfiguracion);

	accionAbrirBolas = new QAction(tr("Configuracion Tab"),this);
	connect(accionAbrirBolas, SIGNAL(triggered()),this, SLOT(abrirConfiguracionBolas()));
	menu->addAction(accionAbrirBolas);

	accionGuardar = new QAction(tr("Guardar"),this);
	connect(accionGuardar, SIGNAL(triggered()),this, SLOT(guardar()));
	menu->addAction(accionGuardar);

	accionLeer = new QAction(tr("Leer"),this);
	connect(accionLeer, SIGNAL(triggered()),this, SLOT(leer()));
	menu->addAction(accionLeer);
}

void MainWindow::paintEvent(QPaintEvent *e){
	QPainter pintor(this);
	QColor rojo(255,0,0);
	QColor gris(120,120,120);
	QColor blanco(255,255,255);
	
	if(laConfiguracion.bolaJugadorSolida){
		pintor.setBrush(QBrush(gris));
		bolaUsuario->pintar(&pintor);
	}else{
		pintor.setBrush(QBrush(blanco));
		bolaUsuario->pintar(&pintor);
	}
	
	bolaUsuario->mueve();	
	bolaUsuario->rebotan(width(), height());
	pintor.setBrush(QBrush(rojo));

	if(laConfiguracion.vidas > 0){
		pintor.drawText(10,20,QString("Vidas del jugador: ") + QString("").setNum(laConfiguracion.vidas));
		pintor.drawText(10,40,QString("Gravedad: ") + QString("").setNum(laConfiguracion.configuracionGravedad));
	}else{
		bolaUsuario->vidas = laConfiguracion.vidas;
		pintor.drawText(10,20,QString("Vidas del jugador: ") + QString("").setNum(0));
		pintor.drawText(10,40,QString("Gravedad: ") + QString("").setNum(laConfiguracion.configuracionGravedad));
	}

	for(QVector<Bola>::iterator it=lasBolas.begin(); it != lasBolas.end(); it++){
		it->pintar(&pintor);

		it->mueve();
		it->rebotan(width(), height());

		bool aux = it->bolasRebotan(bolaUsuario);

		if(aux){
			bolaUsuario->vidas--;
			it->vidas--;
			laConfiguracion.vidas--;
			if(dialogoSuperConfiguracion != NULL){
				dialogoSuperConfiguracion->cambiaVidasJugador(laConfiguracion.vidas);
			}
		}

		for(QVector<Bola>::iterator it2 = it + 1; it2 != lasBolas.end(); it2++){	
			it->bolasRebotan(it2);
		}
	}

	///ATRAEN
	for(QVector<Bola>::iterator it=lasBolas.begin(); it != lasBolas.end(); it++){
		for(QVector<Bola>::iterator it2 = lasBolas.begin(); it2 != lasBolas.end(); it2++){	
			if(it != it2){			
				it->atraeBola(it2);
			}
		}
	}
}	



void MainWindow::mousePressEvent(QMouseEvent *e){
	if(laConfiguracion.activarControlRaton){
		float distanciaX = (e->x() - bolaUsuario->posX) / 150;
		float distanciaY = (e->y() - bolaUsuario->posY) / 150;	

		bolaUsuario->velX += distanciaX;
		bolaUsuario->velY += distanciaY;
	}else{
		float velocidadX = (float) (((rand() % Bola::diametro )/ 20) - 5);
		float velocidadY = (float) (((rand() % Bola::diametro )/ 20) - 5);
				
		
		lasBolas.push_back(Bola(e->x() - 50, e->y() - 50,velocidadX,velocidadY,10));
	}
}

void MainWindow::repintar(){
    	if(laConfiguracion.configuracionActualizada){
		temporizador->setInterval(laConfiguracion.intervaloAnimacion);
		Bola::gravedad = laConfiguracion.configuracionGravedad;
		laConfiguracion.configuracionActualizada = false;
    	}

	if(dialogoBolas != NULL){
		dialogoBolas->actualizaWidgets();
	}

    	if(laConfiguracion.vidas <= 0){
		laConfiguracion.bolaJugadorSolida = true;
    	}else{
		laConfiguracion.bolaJugadorSolida = false;
    	}
    	this->update();
}

void MainWindow::abrirConfiguracion(){
	dialogoConf->show();
}

void MainWindow::abrirConfiguracionBolas(){
	if(dialogoBolas == NULL){	
		dialogoBolas = new DialogoBolas();
		dialogoBolas->pBolas = & lasBolas;
		dialogoBolas->creaPestanyas();
	}
	dialogoBolas->show();
}

void MainWindow::abrirConfiguracionGeneral(){	
	if(dialogoSuperConfiguracion == NULL){	
		dialogoSuperConfiguracion = new DialogoSuperConfiguracion();
		dialogoSuperConfiguracion->configuracion = &laConfiguracion;	
		dialogoSuperConfiguracion->cambiaVidasJugador(laConfiguracion.vidas);
		dialogoSuperConfiguracion->sliderGravedad->setValue(Bola::gravedad);

		//crear modelo tabla y asignar a la vista
		ModeloTabla *modTabla = new ModeloTabla(&lasBolas);
		dialogoSuperConfiguracion->vistaBolas->setModel(modTabla);
	}
	dialogoSuperConfiguracion->show();
}

void MainWindow::cambiaTamanyoBola(int tamanyo){
	Bola::diametro = tamanyo;
}

void MainWindow::inicializaConfiguracion(){
	laConfiguracion.intervaloAnimacion = 30;
	laConfiguracion.ratonActuaJugador = false;
	laConfiguracion.diametroBolas = Bola::diametro = 100;
	laConfiguracion.anchuraPantalla = 900;
	laConfiguracion.alturaPantalla = 700;
	laConfiguracion.bolaJugadorSolida = false;
	laConfiguracion.activarControlRaton = false;
	laConfiguracion.configuracionActualizada = false;
	laConfiguracion.vidas = 10;
	laConfiguracion.configuracionGravedad = Bola::gravedad = 400;
}

void MainWindow::keyPressEvent(QKeyEvent *e){
	int pulsada = e->key();

	switch(pulsada){
		case Qt::Key_Right:
			bolaUsuario->velX += 0.3;
		break;

		case Qt::Key_Left:
			bolaUsuario->velX -= 0.3;
		break;

		case Qt::Key_Down:
			bolaUsuario->velY += 0.3;
		break;

		case Qt::Key_Up:
			bolaUsuario->velY -= 0.3;
		break;
	}
}


// GUARDAR
void MainWindow::guardar(){
	QString fileName = QFileDialog::getSaveFileName(this,tr("Save Bolas"), ".",tr("Bolas files (*.txt)"));

	if(fileName.isEmpty()){
		return;
	}else{
		writeFile(fileName);
	}
}

bool MainWindow::writeFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::warning(this, tr("Spreadsheet"),tr("Cannot write file %1:\n%2.").arg(file.fileName()).arg(file.errorString()));
        return false;
    }
    QTextStream out(&file);
    //out.setVersion(QDataStream::Qt_4_3);

    //out << quint32(MagicNumber);

    QApplication::setOverrideCursor(Qt::WaitCursor);
    for (int i = 0; i < lasBolas.size(); ++i) {
        out << QString().setNum(lasBolas[i].posX) << " " << QString().setNum(lasBolas[i].posY) << " " << QString().setNum(lasBolas[i].velX) << " " << QString().setNum(lasBolas[i].velY) << "\n";  
    }
    QApplication::restoreOverrideCursor();
    return true;
}


//LEER
void MainWindow::leer(){
	QString fileName = QFileDialog::getOpenFileName(this,tr("Save Bolas"), ".",tr("Bolas files (*.txt)"));

	if(fileName.isEmpty()){
		return;
	}else{
		lectura(fileName);
		return;	
	}
}

bool MainWindow::lectura(const QString &fileName){
	QFile file(fileName);
	if (!file.open(QIODevice::ReadOnly)) {
		QMessageBox::warning(this, tr("Spreadsheet"),tr("Cannot write file %1:\n%2.").arg(file.fileName()).arg(file.errorString()));
		return false;
	}
	QTextStream in(&file);
	//out.setVersion(QDataStream::Qt_4_3);

	//out << quint32(MagicNumber);

	QApplication::setOverrideCursor(Qt::WaitCursor);

	float posicionX;
	float posicionY;
	float velocidadX;
	float velocidadY;

	QString linea;

	lasBolas.clear(); //borrar todo el vector

	int contador = 0;

	while(!in.atEnd()){
		linea = in.readLine();

		QStringList lista = linea.split(" ");

		posicionX = lista.at(0).toFloat();
		posicionY = lista.at(1).toFloat();
		velocidadX = lista.at(2).toFloat();
		velocidadY = lista.at(3).toFloat();

		lasBolas.push_back(Bola(posicionX,posicionY,velocidadX,velocidadY,10)); 

		contador++;
	}
	QApplication::restoreOverrideCursor();
	return true;
}


























