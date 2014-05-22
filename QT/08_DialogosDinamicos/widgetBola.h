#ifndef WidgetBola_H
#define WidgetBola_H

#include <QWidget>

#include "ui_WidgetBola.h"
#include "bola.h"

class WidgetBola : public QWidget, public Ui::WidgetBola
{
	Q_OBJECT

	public:
	  	WidgetBola(QWidget *parent = 0);
	    	const Bola *laBola;

	public slots:
		void actualizaDatos();	   
};

#endif
