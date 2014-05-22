#ifndef DialogoBolas_H
#define DialogoBolas_H

#include <QDialog>

#include "ui_DialogoBolas.h"
#include "widgetBola.h"

class DialogoBolas : public QDialog, public Ui::DialogoBolas
{
	Q_OBJECT

	public:
	    	DialogoBolas(QWidget *parent = 0);
		QVector<Bola> *pBolas;


	public slots:
		void creaPestanyas();	 
		void actualizaWidgets();  
};

#endif
