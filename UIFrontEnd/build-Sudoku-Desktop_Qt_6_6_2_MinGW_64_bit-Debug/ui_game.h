/********************************************************************************
** Form generated from reading UI file 'game.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_H
#define UI_GAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_game
{
public:
    QPushButton *QuitBtn;
    QPushButton *QuitAllBtn;
    QPushButton *grid1;
    QPushButton *grid2;
    QPushButton *numOneBtn;
    QPushButton *numTwoBtn;
    QPushButton *numThreeBtn;
    QPushButton *numFourBtn;
    QPushButton *pushFiveBtn;
    QPushButton *numSixBtn;
    QPushButton *numSevenBtn;
    QPushButton *numEightBtn;
    QPushButton *numNineBtn;

    void setupUi(QDialog *game)
    {
        if (game->objectName().isEmpty())
            game->setObjectName("game");
        game->resize(1143, 775);
        QuitBtn = new QPushButton(game);
        QuitBtn->setObjectName("QuitBtn");
        QuitBtn->setGeometry(QRect(980, 90, 111, 41));
        QFont font;
        font.setPointSize(15);
        QuitBtn->setFont(font);
        QuitAllBtn = new QPushButton(game);
        QuitAllBtn->setObjectName("QuitAllBtn");
        QuitAllBtn->setGeometry(QRect(980, 30, 111, 41));
        QuitAllBtn->setFont(font);
        grid1 = new QPushButton(game);
        grid1->setObjectName("grid1");
        grid1->setGeometry(QRect(110, 80, 51, 51));
        QFont font1;
        font1.setPointSize(30);
        grid1->setFont(font1);
        grid1->setAutoFillBackground(true);
        grid1->setAutoDefault(false);
        grid1->setFlat(true);
        grid2 = new QPushButton(game);
        grid2->setObjectName("grid2");
        grid2->setGeometry(QRect(170, 80, 51, 51));
        grid2->setFont(font1);
        grid2->setAutoFillBackground(true);
        grid2->setAutoDefault(false);
        grid2->setFlat(true);
        numOneBtn = new QPushButton(game);
        numOneBtn->setObjectName("numOneBtn");
        numOneBtn->setGeometry(QRect(120, 470, 61, 61));
        QFont font2;
        font2.setPointSize(33);
        numOneBtn->setFont(font2);
        numTwoBtn = new QPushButton(game);
        numTwoBtn->setObjectName("numTwoBtn");
        numTwoBtn->setGeometry(QRect(200, 470, 61, 61));
        numTwoBtn->setFont(font2);
        numThreeBtn = new QPushButton(game);
        numThreeBtn->setObjectName("numThreeBtn");
        numThreeBtn->setGeometry(QRect(280, 470, 61, 61));
        numThreeBtn->setFont(font2);
        numFourBtn = new QPushButton(game);
        numFourBtn->setObjectName("numFourBtn");
        numFourBtn->setGeometry(QRect(360, 470, 61, 61));
        numFourBtn->setFont(font2);
        pushFiveBtn = new QPushButton(game);
        pushFiveBtn->setObjectName("pushFiveBtn");
        pushFiveBtn->setGeometry(QRect(440, 470, 61, 61));
        pushFiveBtn->setFont(font2);
        numSixBtn = new QPushButton(game);
        numSixBtn->setObjectName("numSixBtn");
        numSixBtn->setGeometry(QRect(520, 470, 61, 61));
        numSixBtn->setFont(font2);
        numSevenBtn = new QPushButton(game);
        numSevenBtn->setObjectName("numSevenBtn");
        numSevenBtn->setGeometry(QRect(600, 470, 61, 61));
        numSevenBtn->setFont(font2);
        numEightBtn = new QPushButton(game);
        numEightBtn->setObjectName("numEightBtn");
        numEightBtn->setGeometry(QRect(680, 470, 61, 61));
        numEightBtn->setFont(font2);
        numNineBtn = new QPushButton(game);
        numNineBtn->setObjectName("numNineBtn");
        numNineBtn->setGeometry(QRect(760, 470, 61, 61));
        numNineBtn->setFont(font2);

        retranslateUi(game);

        grid1->setDefault(false);
        grid2->setDefault(false);


        QMetaObject::connectSlotsByName(game);
    } // setupUi

    void retranslateUi(QDialog *game)
    {
        game->setWindowTitle(QCoreApplication::translate("game", "Dialog", nullptr));
        QuitBtn->setText(QCoreApplication::translate("game", "Quit", nullptr));
        QuitAllBtn->setText(QCoreApplication::translate("game", "Quit All", nullptr));
        grid1->setText(QCoreApplication::translate("game", "9", nullptr));
        grid2->setText(QCoreApplication::translate("game", "8", nullptr));
        numOneBtn->setText(QCoreApplication::translate("game", "1", nullptr));
        numTwoBtn->setText(QCoreApplication::translate("game", "2", nullptr));
        numThreeBtn->setText(QCoreApplication::translate("game", "3", nullptr));
        numFourBtn->setText(QCoreApplication::translate("game", "4", nullptr));
        pushFiveBtn->setText(QCoreApplication::translate("game", "5", nullptr));
        numSixBtn->setText(QCoreApplication::translate("game", "6", nullptr));
        numSevenBtn->setText(QCoreApplication::translate("game", "7", nullptr));
        numEightBtn->setText(QCoreApplication::translate("game", "8", nullptr));
        numNineBtn->setText(QCoreApplication::translate("game", "9", nullptr));
    } // retranslateUi

};

namespace Ui {
    class game: public Ui_game {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_H
