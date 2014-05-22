/********************************************************************************
** Form generated from reading UI file 'DialogoBolas.ui'
**
** Created: Tue Feb 11 19:28:40 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGOBOLAS_H
#define UI_DIALOGOBOLAS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QTabWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogoBolas
{
public:
    QDialogButtonBox *buttonBox;
    QTabWidget *tabWidget;

    void setupUi(QDialog *DialogoBolas)
    {
        if (DialogoBolas->objectName().isEmpty())
            DialogoBolas->setObjectName(QString::fromUtf8("DialogoBolas"));
        DialogoBolas->resize(400, 300);
        buttonBox = new QDialogButtonBox(DialogoBolas);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        tabWidget = new QTabWidget(DialogoBolas);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(30, 20, 331, 181));

        retranslateUi(DialogoBolas);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogoBolas, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogoBolas, SLOT(reject()));

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(DialogoBolas);
    } // setupUi

    void retranslateUi(QDialog *DialogoBolas)
    {
        DialogoBolas->setWindowTitle(QApplication::translate("DialogoBolas", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogoBolas: public Ui_DialogoBolas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGOBOLAS_H
