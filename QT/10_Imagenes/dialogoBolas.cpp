#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

#include "dialogoBolas.h"
#include "widgetBola.h"

DialogoBolas::DialogoBolas(QWidget *parent) : QDialog(parent)
{
	setupUi(this);
	pBolas = NULL;
}

void DialogoBolas::creaPestanyas(){
	if(pBolas == NULL){
		return;
	}
	for(int i = 0; i < pBolas->size(); i++){
		WidgetBola *w = new WidgetBola();
		w->laBola = &(pBolas->at(i));
		w->actualizaDatos();
		tabWidget->addTab(w, QString().setNum(i) + "" );
	}
}

void DialogoBolas::actualizaWidgets(){
	WidgetBola *w;
	for(int i = 0; i < tabWidget->count(); i++){
		w = qobject_cast <WidgetBola *> (tabWidget->widget(i));
		w->actualizaDatos();
	}
}
