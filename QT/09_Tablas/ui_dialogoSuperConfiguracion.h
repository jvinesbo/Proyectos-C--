/********************************************************************************
** Form generated from reading UI file 'dialogoSuperConfiguracion.ui'
**
** Created: Fri Feb 14 15:53:28 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGOSUPERCONFIGURACION_H
#define UI_DIALOGOSUPERCONFIGURACION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QTableView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogoSuperConfiguracion
{
public:
    QDialogButtonBox *buttonBox;
    QTabWidget *pestanyas;
    QWidget *pestanyaBolaJugador;
    QCheckBox *checkBoxRaton;
    QLabel *label;
    QCheckBox *checkSolido;
    QSpinBox *spinBoxVidas;
    QLabel *label_2;
    QWidget *pestanyaGeneral;
    QGroupBox *groupBox;
    QRadioButton *rbLenta;
    QRadioButton *rbMedia;
    QRadioButton *rbRapida;
    QSlider *sliderGravedad;
    QLabel *label_3;
    QTableView *vistaBolas;

    void setupUi(QDialog *DialogoSuperConfiguracion)
    {
        if (DialogoSuperConfiguracion->objectName().isEmpty())
            DialogoSuperConfiguracion->setObjectName(QString::fromUtf8("DialogoSuperConfiguracion"));
        DialogoSuperConfiguracion->resize(519, 632);
        buttonBox = new QDialogButtonBox(DialogoSuperConfiguracion);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(100, 570, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        pestanyas = new QTabWidget(DialogoSuperConfiguracion);
        pestanyas->setObjectName(QString::fromUtf8("pestanyas"));
        pestanyas->setGeometry(QRect(30, 29, 341, 201));
        pestanyaBolaJugador = new QWidget();
        pestanyaBolaJugador->setObjectName(QString::fromUtf8("pestanyaBolaJugador"));
        checkBoxRaton = new QCheckBox(pestanyaBolaJugador);
        checkBoxRaton->setObjectName(QString::fromUtf8("checkBoxRaton"));
        checkBoxRaton->setGeometry(QRect(20, 20, 121, 22));
        label = new QLabel(pestanyaBolaJugador);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 40, 66, 17));
        checkSolido = new QCheckBox(pestanyaBolaJugador);
        checkSolido->setObjectName(QString::fromUtf8("checkSolido"));
        checkSolido->setGeometry(QRect(20, 50, 97, 22));
        spinBoxVidas = new QSpinBox(pestanyaBolaJugador);
        spinBoxVidas->setObjectName(QString::fromUtf8("spinBoxVidas"));
        spinBoxVidas->setGeometry(QRect(160, 80, 60, 27));
        spinBoxVidas->setMinimum(-10);
        label_2 = new QLabel(pestanyaBolaJugador);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 90, 121, 17));
        pestanyas->addTab(pestanyaBolaJugador, QString());
        pestanyaGeneral = new QWidget();
        pestanyaGeneral->setObjectName(QString::fromUtf8("pestanyaGeneral"));
        groupBox = new QGroupBox(pestanyaGeneral);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 10, 171, 121));
        rbLenta = new QRadioButton(groupBox);
        rbLenta->setObjectName(QString::fromUtf8("rbLenta"));
        rbLenta->setGeometry(QRect(0, 30, 116, 22));
        rbMedia = new QRadioButton(groupBox);
        rbMedia->setObjectName(QString::fromUtf8("rbMedia"));
        rbMedia->setGeometry(QRect(0, 60, 116, 22));
        rbRapida = new QRadioButton(groupBox);
        rbRapida->setObjectName(QString::fromUtf8("rbRapida"));
        rbRapida->setGeometry(QRect(0, 90, 116, 22));
        sliderGravedad = new QSlider(pestanyaGeneral);
        sliderGravedad->setObjectName(QString::fromUtf8("sliderGravedad"));
        sliderGravedad->setGeometry(QRect(160, 130, 160, 29));
        sliderGravedad->setMinimum(100);
        sliderGravedad->setMaximum(12000);
        sliderGravedad->setSingleStep(20);
        sliderGravedad->setPageStep(100);
        sliderGravedad->setValue(100);
        sliderGravedad->setOrientation(Qt::Horizontal);
        sliderGravedad->setTickPosition(QSlider::TicksBothSides);
        sliderGravedad->setTickInterval(100);
        label_3 = new QLabel(pestanyaGeneral);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 140, 131, 17));
        pestanyas->addTab(pestanyaGeneral, QString());
        vistaBolas = new QTableView(DialogoSuperConfiguracion);
        vistaBolas->setObjectName(QString::fromUtf8("vistaBolas"));
        vistaBolas->setGeometry(QRect(30, 260, 461, 281));

        retranslateUi(DialogoSuperConfiguracion);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogoSuperConfiguracion, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogoSuperConfiguracion, SLOT(reject()));

        pestanyas->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(DialogoSuperConfiguracion);
    } // setupUi

    void retranslateUi(QDialog *DialogoSuperConfiguracion)
    {
        DialogoSuperConfiguracion->setWindowTitle(QApplication::translate("DialogoSuperConfiguracion", "Dialog", 0, QApplication::UnicodeUTF8));
        checkBoxRaton->setText(QApplication::translate("DialogoSuperConfiguracion", "Activar Rat\303\263n", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        checkSolido->setText(QApplication::translate("DialogoSuperConfiguracion", "S\303\263lido", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DialogoSuperConfiguracion", "N\303\272mero de vidas:", 0, QApplication::UnicodeUTF8));
        pestanyas->setTabText(pestanyas->indexOf(pestanyaBolaJugador), QApplication::translate("DialogoSuperConfiguracion", "Bola Jugador", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("DialogoSuperConfiguracion", "Velocidad Animaci\303\263n", 0, QApplication::UnicodeUTF8));
        rbLenta->setText(QApplication::translate("DialogoSuperConfiguracion", "Lenta", 0, QApplication::UnicodeUTF8));
        rbMedia->setText(QApplication::translate("DialogoSuperConfiguracion", "Media", 0, QApplication::UnicodeUTF8));
        rbRapida->setText(QApplication::translate("DialogoSuperConfiguracion", "R\303\241pida", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("DialogoSuperConfiguracion", "Cambiar Gravedad:", 0, QApplication::UnicodeUTF8));
        pestanyas->setTabText(pestanyas->indexOf(pestanyaGeneral), QApplication::translate("DialogoSuperConfiguracion", "Configuraci\303\263n General", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogoSuperConfiguracion: public Ui_DialogoSuperConfiguracion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGOSUPERCONFIGURACION_H
