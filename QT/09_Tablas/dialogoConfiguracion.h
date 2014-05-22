#ifndef DialogoConfiguracion_H
#define DialogoConfiguracion_H

#include <QDialog>

#include "ui_DialogoConfiguracion.h"

class DialogoConfiguracion : public QDialog, public Ui::DialogoConfiguracion
{
	Q_OBJECT

	public:
	    DialogoConfiguracion(QWidget *parent = 0);

	public slots:
	   
};

#endif
