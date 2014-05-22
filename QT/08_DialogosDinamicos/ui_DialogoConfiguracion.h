/********************************************************************************
** Form generated from reading UI file 'DialogoConfiguracion.ui'
**
** Created: Tue Feb 11 19:28:40 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGOCONFIGURACION_H
#define UI_DIALOGOCONFIGURACION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSlider>

QT_BEGIN_NAMESPACE

class Ui_DialogoConfiguracion
{
public:
    QDialogButtonBox *buttonBox;
    QSlider *sliderTamanyoBola;
    QLabel *label;

    void setupUi(QDialog *DialogoConfiguracion)
    {
        if (DialogoConfiguracion->objectName().isEmpty())
            DialogoConfiguracion->setObjectName(QString::fromUtf8("DialogoConfiguracion"));
        DialogoConfiguracion->resize(400, 300);
        buttonBox = new QDialogButtonBox(DialogoConfiguracion);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        sliderTamanyoBola = new QSlider(DialogoConfiguracion);
        sliderTamanyoBola->setObjectName(QString::fromUtf8("sliderTamanyoBola"));
        sliderTamanyoBola->setGeometry(QRect(20, 40, 160, 29));
        sliderTamanyoBola->setMinimum(1);
        sliderTamanyoBola->setMaximum(100);
        sliderTamanyoBola->setValue(50);
        sliderTamanyoBola->setOrientation(Qt::Horizontal);
        label = new QLabel(DialogoConfiguracion);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 101, 17));

        retranslateUi(DialogoConfiguracion);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogoConfiguracion, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogoConfiguracion, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogoConfiguracion);
    } // setupUi

    void retranslateUi(QDialog *DialogoConfiguracion)
    {
        DialogoConfiguracion->setWindowTitle(QApplication::translate("DialogoConfiguracion", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DialogoConfiguracion", "Tama\303\261o Bolas", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogoConfiguracion: public Ui_DialogoConfiguracion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGOCONFIGURACION_H
