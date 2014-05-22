#include "modeloTabla.h"
#include <QVector>
#include <QString>

ModeloTabla::ModeloTabla(QVector<Bola> *pABolas){
	bolas = pABolas;
}

int ModeloTabla::rowCount(const QModelIndex & parent) const{
	int aux = bolas->size();
		
	return aux;
}

int ModeloTabla::columnCount(const QModelIndex & parent) const{
	return 4;
}

QVariant ModeloTabla::data(const QModelIndex & index, int role) const{

	QString aux;

	if(index.column() == 0){
		 aux = QString("").setNum(bolas->at(index.row()).posX);
	}

	if(index.column() == 1){
		 aux = QString("").setNum(bolas->at(index.row()).posY);
	}

	if(index.column() == 2){
		 aux = QString("").setNum(bolas->at(index.row()).velX);
	}else{
		 aux = QString("").setNum(bolas->at(index.row()).velY);
	}		
	
	return aux;
}
