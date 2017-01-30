#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QtCore>
#include <QLabel>
#include <QBrush>
#include <QPixmap>
#include <QWidget>
#include <QBitmap>
#include <QKeyEvent>
#include <QTime>
#include <QPainter>
#include <QCoreApplication>
#include <ctime>
#include <QMovie>
#include <QApplication>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/qsound.h>
#include <QtMultimedia/QSound>
#include <QMessageBox>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QtMultimedia>
#include <QtMultimediaWidgets/QtMultimediaWidgets>
#include <QUrl>
#include <QMediaPlayer>
#include <QWidget>
#include <QSound>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QSize>
#include <QFont>
#include <QLineEdit>
#include <QTextBrowser>
#include <QLabel>
#include <QString>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QTimer *timer;

public slots:
    void MySlot();

private slots:
    void on_Start_Button_clicked();
    void on_Exit_Button_clicked();
    void on_Replay_Button_clicked();
    void on_Drum_Button1_clicked();
    void on_Drum_Button2_clicked();
    void on_Drum_Button3_clicked();
    void on_Drum_Button4_clicked();
    void on_Drum_Button5_clicked();
    void on_Drum_Button6_clicked();
    void on_Drum_Button7_clicked();
    void on_Drum_Button8_clicked();
    void On_OK_Button_clicked();
    void On_Cancel_Button_clicked();
    void on_Drum_Gold_clicked();

private:
    Ui::MainWindow *ui;
    QMediaPlayer* Music = new QMediaPlayer;
    QMediaPlayer* Jump = new QMediaPlayer;
    void keyPressEvent(QKeyEvent *event);
    QGraphicsScene *scene = new QGraphicsScene();
    QGraphicsPixmapItem *item = new QGraphicsPixmapItem();
    QGraphicsView *view = new QGraphicsView();
    QPushButton *OK_Button = new QPushButton();
    QPushButton *Cancel_Button = new QPushButton();
    QLineEdit *Catch_Name = new QLineEdit();
    QLabel *Show_Name = new QLabel();
    QLabel *Show_Score = new QLabel();
    QMovie *movie;
    QMovie *movie1;
    int Now_time = -200;
    int Score = 0;
    int Combo = 0;
    int Combo_Sign_Life = 0;
    int Red_Drum_Life = 0;
    int Blue_Drum_Life = 0;
    int Drum_Gold_Life=0;
    int Drum_Gold_Period=0;
    int Speed_Level = 5;
    int Drum_Size = 0;
    int Play_Mode = 0;
    int Impact[10]={0};
    int Move_Moed[10]={0};
    bool IsShow_Combo = false;
    bool IsPlaying = false;
    bool IsPause = false;
    bool IsDancer = false;
};

#endif // MAINWINDOW_H
