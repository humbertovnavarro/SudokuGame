#ifndef VICTORYSCREEN_H
#define VICTORYSCREEN_H

#include <QDialog>
#include <QPixmap>
#include <QMovie>

namespace Ui {
class VictoryScreen;
}

class VictoryScreen : public QDialog
{
    Q_OBJECT

public:
    explicit VictoryScreen(QWidget *parent, unsigned difficulty);
    ~VictoryScreen();

private:
    void displayVictoryScreen();

    void displayStars();

    void displayConfetti();

    void displayEvilGifsImgs();

    unsigned difficulty;
    Ui::VictoryScreen *ui;
};

#endif // VICTORYSCREEN_H
