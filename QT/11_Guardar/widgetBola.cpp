#include "widgetBola.h"

WidgetBola::WidgetBola(QWidget *parent) : QWidget(parent)
{ 
	setupUi(this);

	laBola = NULL;
}

void WidgetBola::actualizaDatos(){
	if(laBola == NULL){
		return;
	}
	labelPosX->setText(QString().setNum(laBola->posX));
	labelPosY->setText(QString().setNum(laBola->posY));
}	   
