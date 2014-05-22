#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QTextEdit>
#include <QLabel>
#include <QStatusBar>
#include <QPaintEvent>
#include <QTimer>

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
    float posicionX;
    float posicionY;
    float velocidadX;
    float velocidadY;
    QTimer *temporizador;

    public:
        MainWindow(QWidget *parent = 0);
        ~MainWindow();
    private:

    protected:
	void paintEvent(QPaintEvent *e);

    public slots:
        void repintar();
};

#endif // MAINWINDOW_H
