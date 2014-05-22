/********************************************************************************
** Form generated from reading UI file 'WidgetBola.ui'
**
** Created: Tue Feb 18 18:04:58 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETBOLA_H
#define UI_WIDGETBOLA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetBola
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *labelPosX;
    QLabel *labelPosY;

    void setupUi(QWidget *WidgetBola)
    {
        if (WidgetBola->objectName().isEmpty())
            WidgetBola->setObjectName(QString::fromUtf8("WidgetBola"));
        WidgetBola->resize(312, 142);
        label = new QLabel(WidgetBola);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 50, 81, 17));
        label_2 = new QLabel(WidgetBola);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 80, 66, 17));
        labelPosX = new QLabel(WidgetBola);
        labelPosX->setObjectName(QString::fromUtf8("labelPosX"));
        labelPosX->setGeometry(QRect(170, 50, 66, 17));
        labelPosY = new QLabel(WidgetBola);
        labelPosY->setObjectName(QString::fromUtf8("labelPosY"));
        labelPosY->setGeometry(QRect(170, 80, 66, 17));

        retranslateUi(WidgetBola);

        QMetaObject::connectSlotsByName(WidgetBola);
    } // setupUi

    void retranslateUi(QWidget *WidgetBola)
    {
        WidgetBola->setWindowTitle(QApplication::translate("WidgetBola", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("WidgetBola", "Posici\303\263n X", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("WidgetBola", "Poscion Y", 0, QApplication::UnicodeUTF8));
        labelPosX->setText(QApplication::translate("WidgetBola", "TextLabel", 0, QApplication::UnicodeUTF8));
        labelPosY->setText(QApplication::translate("WidgetBola", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class WidgetBola: public Ui_WidgetBola {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETBOLA_H
