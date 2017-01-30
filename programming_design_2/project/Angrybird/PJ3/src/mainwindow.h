#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QList>
#include <QDesktopWidget>
#include <QTimer>
#include <Box2D/Box2D.h>
#include <QMouseEvent>
#include <iostream>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QCursor>
#include <ctime>
#include <cmath>
#include <QLineEdit>
#include <QMessageBox>
#include <QUrl>
#include <QMediaPlayer>
#include <cstdlib>

#include <gameitem.h>
#include <bird_generator.h>
#include <bird.h>
#include <land.h>
#include <wall.h>
#include <pig.h>
#include <sling.h>
#include <bird_red.h>
#include <bird_blue.h>
#include <wall_iron.h>
#include <wall_glass.h>
#include <wall_wood.h>
#include <wall_fake.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showEvent(QShowEvent *);
    bool eventFilter(QObject *,QEvent *event);
    void closeEvent(QCloseEvent *);
signals:
    // Signal for closing the game
    void quitGame();

private slots:
    void tick();
    // For debug slot
    void QUITSLOT();
    void Exit();
    void Replay();
    void Description();
    void On_OK_Button_clicked();
    void On_Cancel_Button_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    b2World *world;
    QList<GameItem *> itemList;
    QTimer timer;
    int Mouse_Press_x,Mouse_Press_y;
    bool Is_Hit_Pig[5];
    bool Is_Dead_Pig[5];
    bool Is_Delete_Pig[5];
    int Dead_Pig_Count[5];
    Pig *pig[5];
    Bird *Bird_Bullet[100];
    Bird * Rain[20];
    bool Is_Delete_Bird[100];
    Wall *wall[15];
    bool Is_Hit_Wall[15];
    bool Is_Dead_Wall[15];
    bool Is_Delete_Wall[15];
    int Birds_Color[100];
    int Dead_Wall_Count[15];
    Sling * sling;
    Wall_Fake *Fake;
    int Release_Time;
    int Skill_Time;
    int Bird_Control;
    int Score;
    int Bird_Change_Color;
    int Bomb_Life;
    int More_Bird;
    int Raining_Time;
    bool Is_Press;
    bool Is_Flying;
    bool Is_Skill;
    bool Can_Play;
    bool Is_Show;
    QPushButton *Replay_Button = new QPushButton();
    QPushButton *Exit_Button = new QPushButton();
    QPushButton *Pause_Button = new QPushButton();
    QLabel *Show_Score;
    QLabel *Bomb_Cloud;
    QLabel *Description_Message = new QLabel();
    QGraphicsScene *scene3 = new QGraphicsScene();
    QGraphicsView *view3 = new QGraphicsView();



    QMediaPlayer* Music = new QMediaPlayer;
    QGraphicsScene *scene2 = new QGraphicsScene();
    QGraphicsPixmapItem *item2 = new QGraphicsPixmapItem();
    QGraphicsView *view = new QGraphicsView();
    QPushButton *OK_Button = new QPushButton();
    QPushButton *Cancel_Button = new QPushButton();
    QLineEdit *Catch_Name = new QLineEdit();
    QLabel *Show_Name = new QLabel();
    QLabel *Show_Score2 = new QLabel();
    void keyPressEvent(QKeyEvent *event);
};

#endif // MAINWINDOW_H
