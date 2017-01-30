#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Taiko");
    srand(time(NULL));

    Music->setMedia(QUrl("qrc:/img/Super_mario_BackMusic.mp3"));
    Music->setVolume(70);

    Jump->setMedia(QUrl("qrc:/img/Super_mario_Jump.mp3"));
    Jump->setVolume(90);

    ui->Pause_Message->setGeometry(QRect(380,110,550,550));
    ui->Pause_Message->hide();

    item->setPixmap(QPixmap(":/background/img/resultbg_failure.png"));
    scene->addItem(item);
    OK_Button->setGeometry(QRect(300,160,70,30));
    OK_Button->setText("OK");
    Cancel_Button->setGeometry(QRect(400,160,70,30));
    Cancel_Button->setText("Cancel");
    Cancel_Button->setFont(QFont("Monotype Corsiva", 16, QFont::Bold));
    Cancel_Button->setStyleSheet("border-top: 0px transparent;border-bottom: 0px transparent; border- right: 0px transparent;border-left: 0px transparent;");
    OK_Button->setFont(QFont("Monotype Corsiva", 16, QFont::Bold));
    OK_Button->setStyleSheet("border-top: 0px transparent;border-bottom: 0px transparent; border- right: 0px transparent;border-left: 0px transparent;");
    scene->addWidget(OK_Button);
    scene->addWidget(Cancel_Button);
    Show_Name->setText("Please Enter Your Name.");
    Show_Name->setFont(QFont("Monotype Corsiva", 16, QFont::Bold));
    Show_Name->setGeometry(QRect(180,50,250,30));
    Show_Score->setGeometry(QRect(120,160,120,30));
    Show_Score->setFont(QFont("Monotype Corsiva", 16, QFont::Bold));
    Catch_Name->setGeometry(QRect(180,100,250,30));
    scene->addWidget(Show_Score);
    scene->addWidget(Show_Name);
    scene->addWidget(Catch_Name);
    view->setScene(scene);
    connect(OK_Button, SIGNAL (clicked()),this, SLOT (On_OK_Button_clicked()));
    connect(Cancel_Button, SIGNAL (clicked()),this, SLOT (On_Cancel_Button_clicked()));

    movie = new QMovie(":/dancer/img/GIF/Ugly_Dancer.gif");
    ui->Dancer_Ugly1->setMovie(movie);
    ui->Dancer_Ugly1->setGeometry(QRect(1030,400,200,280));
    ui->Dancer_Ugly1->hide();

    movie1 = new QMovie(":/dancer/img/GIF/Dancer1.gif");
    ui->Dancer_Ugly2->setMovie(movie1);
    ui->Dancer_Ugly2->setGeometry(QRect(90,400,200,280));
    ui->Dancer_Ugly2->hide();

    QPixmap pixmap(":/background/img/btn2.png");
    //按鈕
    {
    QIcon ButtonIcon(pixmap);
    ui->Start_Button->setIcon(ButtonIcon);
    ui->Start_Button->setIconSize(pixmap.rect().size());
    ui->Start_Button->setGeometry(QRect(500, 570, 330, 110));
    ui->Start_Button->setStyleSheet("border-top: 0px transparent;border-bottom: 0px transparent; border- right: 0px transparent;border-left: 0px transparent;");

    pixmap.load(":/background/img/Exitt.png");
    QIcon ButtonIcon1(pixmap);
    ui->Exit_Button->setIcon(ButtonIcon1);
    ui->Exit_Button->setIconSize(QSize(100,100));
    ui->Exit_Button->setGeometry(QRect(1130, 600, 100, 100));
    ui->Exit_Button->setStyleSheet("border-top: 0px transparent;border-bottom: 0px transparent; border- right: 0px transparent;border-left: 0px transparent;");

    pixmap.load(":/background/img/replay_button.png");
    QIcon ButtonIcon2(pixmap);
    ui->Replay_Button->setIcon(ButtonIcon2);
    ui->Replay_Button->setIconSize(QSize(600,600));
    ui->Replay_Button->setGeometry(QRect(350, 50, 600, 600));
    ui->Replay_Button->setStyleSheet("border-top: 0px transparent;border-bottom: 0px transparent; border- right: 0px transparent;border-left: 0px transparent;");
    ui->Replay_Button->hide();
    }
    //移動的鼓
    {
    pixmap.load(":/drum/img/OK/Drum_1.png");
    QIcon ButtonIcon3(pixmap);
    ui->Drum_Button1->setIcon(ButtonIcon3);
    ui->Drum_Button1->setIconSize(QSize(120,120));
    ui->Drum_Button1->setGeometry(rand()%1400*3184%1400+1400,225,120,120);
    ui->Drum_Button1->setStyleSheet("border-top: 0px transparent;border-bottom: 0px transparent; border- right: 0px transparent;border-left: 0px transparent;");
    ui->Drum_Button1->hide();

    pixmap.load(":/drum/img/OK/Drum_2.png");
    QIcon ButtonIcon4(pixmap);
    ui->Drum_Button2->setIcon(ButtonIcon4);
    ui->Drum_Button2->setIconSize(QSize(120,120));
    ui->Drum_Button2->setGeometry(rand()%1400*1842%1400+1400,225,120,120);
    ui->Drum_Button2->setStyleSheet("border-top: 0px transparent;border-bottom: 0px transparent; border- right: 0px transparent;border-left: 0px transparent;");
    ui->Drum_Button2->hide();

    pixmap.load(":/drum/img/OK/Drum_3.png");
    QIcon ButtonIcon5(pixmap);
    ui->Drum_Button3->setIcon(ButtonIcon5);
    ui->Drum_Button3->setIconSize(QSize(120,120));
    ui->Drum_Button3->setGeometry(rand()%1400*5824%1400+1400,225,120,120);
    ui->Drum_Button3->setStyleSheet("border-top: 0px transparent;border-bottom: 0px transparent; border- right: 0px transparent;border-left: 0px transparent;");
    ui->Drum_Button3->hide();

    pixmap.load(":/drum/img/OK/Drum_4.png");
    QIcon ButtonIcon6(pixmap);
    ui->Drum_Button4->setIcon(ButtonIcon6);
    ui->Drum_Button4->setIconSize(QSize(120,120));
    ui->Drum_Button4->setGeometry(rand()%1400*7257%1400+1400,225,120,120);
    ui->Drum_Button4->setStyleSheet("border-top: 0px transparent;border-bottom: 0px transparent; border- right: 0px transparent;border-left: 0px transparent;");
    ui->Drum_Button4->hide();

    pixmap.load(":/drum/img/OK/Drum_5.png");
    QIcon ButtonIcon7(pixmap);
    ui->Drum_Button5->setIcon(ButtonIcon7);
    ui->Drum_Button5->setIconSize(QSize(120,120));
    ui->Drum_Button5->setGeometry(rand()%1400*6247%1400+1400,225,120,120);
    ui->Drum_Button5->setStyleSheet("border-top: 0px transparent;border-bottom: 0px transparent; border- right: 0px transparent;border-left: 0px transparent;");
    ui->Drum_Button5->hide();

    pixmap.load(":/drum/img/OK/Drum_6.png");
    QIcon ButtonIcon8(pixmap);
    ui->Drum_Button6->setIcon(ButtonIcon8);
    ui->Drum_Button6->setIconSize(QSize(120,120));
    ui->Drum_Button6->setGeometry(rand()%1400*7625%1400+1400,225,120,120);
    ui->Drum_Button6->setStyleSheet("border-top: 0px transparent;border-bottom: 0px transparent; border- right: 0px transparent;border-left: 0px transparent;");
    ui->Drum_Button6->hide();

    pixmap.load(":/drum/img/OK/Drum_7.png");
    QIcon ButtonIcon9(pixmap);
    ui->Drum_Button7->setIcon(ButtonIcon9);
    ui->Drum_Button7->setIconSize(QSize(120,120));
    ui->Drum_Button7->setGeometry(rand()%1400*6667%1400+1400,225,120,120);
    ui->Drum_Button7->setStyleSheet("border-top: 0px transparent;border-bottom: 0px transparent; border- right: 0px transparent;border-left: 0px transparent;");
    ui->Drum_Button7->hide();

    pixmap.load(":/drum/img/OK/Drum_8.png");
    QIcon ButtonIcon10(pixmap);
    ui->Drum_Button8->setIcon(ButtonIcon10);
    ui->Drum_Button8->setIconSize(QSize(120,120));
    ui->Drum_Button8->setGeometry(rand()%1400*9627%1400+1400,225,120,120);
    ui->Drum_Button8->setStyleSheet("border-top: 0px transparent;border-bottom: 0px transparent; border- right: 0px transparent;border-left: 0px transparent;");
    ui->Drum_Button8->hide();

    pixmap.load(":/drum/img/OK/Gold.png");
    QIcon ButtonIcon11(pixmap);
    ui->Drum_Gold->setIcon(ButtonIcon11);
    ui->Drum_Gold->setIconSize(QSize(420,280));
    ui->Drum_Gold->setGeometry(rand()%800,rand()%430,420,280);
    ui->Drum_Gold->setStyleSheet("border-top: 0px transparent;border-bottom: 0px transparent; border- right: 0px transparent;border-left: 0px transparent;");
    ui->Drum_Gold->hide();
    }
    //鼓面敲打物件
    {
    pixmap.load(":/drum/img/OK/Drum_13.png");
    ui->Hit_Drum_Position->setPixmap(pixmap);
    ui->Hit_Drum_Position->setGeometry(QRect(300,210,150,150));
    ui->Hit_Drum_Position->hide();

    pixmap.load(":/background/img/comboballoon_p2.png");
    ui->Combo_Image->setPixmap(pixmap);
    ui->Combo_Image->setGeometry(QRect(500,100,300,100));
    ui->Combo_Image->hide();

    pixmap.load(":/background/img/OK/Blue_Drum_Left.png");
    ui->Hit_Drum_Blue1->setPixmap(pixmap);
    ui->Hit_Drum_Blue1->setGeometry(QRect(280,180,95,195));
    ui->Hit_Drum_Blue1->hide();

    pixmap.load(":/background/img/OK/Red_Drum_Left.png");
    ui->Hit_Drum_Red1->setPixmap(pixmap);
    ui->Hit_Drum_Red1->setGeometry(QRect(280,185,95,195));
    ui->Hit_Drum_Red1->hide();

    pixmap.load(":/background/img/OK/Blue_Drum_Right.png");
    ui->Hit_Drum_Blue2->setPixmap(pixmap);
    ui->Hit_Drum_Blue2->setGeometry(QRect(375,180,95,195));
    ui->Hit_Drum_Blue2->hide();

    pixmap.load(":/background/img/OK/Red_Drum_Right.png");
    ui->Hit_Drum_Red2->setPixmap(pixmap);
    ui->Hit_Drum_Red2->setGeometry(QRect(375,185,95,195));
    ui->Hit_Drum_Red2->hide();

    pixmap.load(":/background/img/Drum_Man1.jpg");
    ui->Drum_Man1->setPixmap(pixmap);
    ui->Drum_Man1->setGeometry(QRect(0,175,290,213));
    ui->Drum_Man1->hide();

    pixmap.load(":/background/img/Drum_Man2.jpg");
    ui->Drum_Man2->setPixmap(pixmap);
    ui->Drum_Man2->setGeometry(QRect(0,175,290,213));
    ui->Drum_Man2->hide();

    pixmap.load(":/background/img/Drum_Man3.jpg");
    ui->Drum_Man3->setPixmap(pixmap);
    ui->Drum_Man3->setGeometry(QRect(0,175,290,213));
    ui->Drum_Man3->hide();

    pixmap.load(":/background/img/Drum_Man4.jpg");
    ui->Drum_Man4->setPixmap(pixmap);
    ui->Drum_Man4->setGeometry(QRect(0,175,290,213));
    ui->Drum_Man4->hide();

    pixmap.load(":/drum/img/OK/Hit_point1.png");
    ui->Hit_Point1->setPixmap(pixmap);
    ui->Hit_Point1->setGeometry(QRect(390,120,147,93));
    ui->Hit_Point1->hide();

    pixmap.load(":/drum/img/OK/Hit_point2.png");
    ui->Hit_Point2->setPixmap(pixmap);
    ui->Hit_Point2->setGeometry(QRect(390,120,147,93));
    ui->Hit_Point2->hide();

    pixmap.load(":/drum/img/OK/Hit_point3.png");
    ui->Hit_Point3->setPixmap(pixmap);
    ui->Hit_Point3->setGeometry(QRect(390,120,147,93));
    ui->Hit_Point3->hide();
    }
    //背景
    {
    pixmap.load(":/background/img/2946671.jpg");
    ui->Start_Menu->setPixmap(pixmap);
    ui->Start_Menu->setGeometry(QRect(0,0,1280,730));

    pixmap.load(":/background/img/bg.png");
    ui->Play_background1->setPixmap(pixmap);
    ui->Play_background1->setGeometry(QRect(0,0,1280,730));
    ui->Play_background1->hide();

    pixmap.load(":/background/img/bg_miss.png");
    ui->Play_background2->setPixmap(pixmap);
    ui->Play_background2->setGeometry(QRect(0,0,1280,730));
    ui->Play_background2->hide();

    pixmap.load(":/background/img/bg_black.png");
    ui->Dead_Background->setPixmap(pixmap);
    ui->Dead_Background->setGeometry(QRect(0,0,1280,730));
    ui->Dead_Background->hide();

    pixmap.load(":/background/img/OK/Life_Green.jpg");
    ui->Life_Green->setPixmap(pixmap);
    ui->Life_Green->setGeometry(QRect(128,141,255,10));
    ui->Life_Green->hide();

    pixmap.load(":/background/img/OK/Life_Red.jpg");
    ui->Life_Red->setPixmap(pixmap);
    ui->Life_Red->setGeometry(QRect(128,141,70,10));
    ui->Life_Red->hide();

    }
    //數字1 for 連擊
    {
        pixmap.load(":/num/img/OK/num1_0.png");
        ui->Num1_0->setPixmap(pixmap);
        ui->Num1_0->setGeometry(QRect(630,105,54,90));
        ui->Num1_0->hide();
        pixmap.load(":/num/img/OK/num1_0.png");
        ui->Num1_00->setPixmap(pixmap);
        ui->Num1_00->setGeometry(QRect(570,105,54,90));
        ui->Num1_00->hide();
        pixmap.load(":/num/img/OK/num1_1.png");
        ui->Num1_1->setPixmap(pixmap);
        ui->Num1_1->setGeometry(QRect(630,105,54,90));
        ui->Num1_1->hide();
        pixmap.load(":/num/img/OK/num1_1.png");
        ui->Num1_10->setPixmap(pixmap);
        ui->Num1_10->setGeometry(QRect(570,105,54,90));
        ui->Num1_10->hide();
        pixmap.load(":/num/img/OK/num1_2.png");
        ui->Num1_2->setPixmap(pixmap);
        ui->Num1_2->setGeometry(QRect(630,105,54,90));
        ui->Num1_2->hide();
        pixmap.load(":/num/img/OK/num1_2.png");
        ui->Num1_20->setPixmap(pixmap);
        ui->Num1_20->setGeometry(QRect(570,105,54,90));
        ui->Num1_20->hide();
        pixmap.load(":/num/img/OK/num1_3.png");
        ui->Num1_3->setPixmap(pixmap);
        ui->Num1_3->setGeometry(QRect(630,105,54,90));
        ui->Num1_3->hide();
        pixmap.load(":/num/img/OK/num1_3.png");
        ui->Num1_30->setPixmap(pixmap);
        ui->Num1_30->setGeometry(QRect(570,105,54,90));
        ui->Num1_30->hide();
        pixmap.load(":/num/img/OK/num1_4.png");
        ui->Num1_4->setPixmap(pixmap);
        ui->Num1_4->setGeometry(QRect(630,105,54,90));
        ui->Num1_4->hide();
        pixmap.load(":/num/img/OK/num1_4.png");
        ui->Num1_40->setPixmap(pixmap);
        ui->Num1_40->setGeometry(QRect(570,105,54,90));
        ui->Num1_40->hide();
        pixmap.load(":/num/img/OK/num1_5.png");
        ui->Num1_5->setPixmap(pixmap);
        ui->Num1_5->setGeometry(QRect(630,105,54,90));
        ui->Num1_5->hide();
        pixmap.load(":/num/img/OK/num1_5.png");
        ui->Num1_50->setPixmap(pixmap);
        ui->Num1_50->setGeometry(QRect(570,105,54,90));
        ui->Num1_50->hide();
        pixmap.load(":/num/img/OK/num1_6.png");
        ui->Num1_6->setPixmap(pixmap);
        ui->Num1_6->setGeometry(QRect(630,105,54,90));
        ui->Num1_6->hide();
        pixmap.load(":/num/img/OK/num1_6.png");
        ui->Num1_60->setPixmap(pixmap);
        ui->Num1_60->setGeometry(QRect(570,105,54,90));
        ui->Num1_60->hide();
        pixmap.load(":/num/img/OK/num1_7.png");
        ui->Num1_7->setPixmap(pixmap);
        ui->Num1_7->setGeometry(QRect(630,105,54,90));
        ui->Num1_7->hide();
        pixmap.load(":/num/img/OK/num1_7.png");
        ui->Num1_70->setPixmap(pixmap);
        ui->Num1_70->setGeometry(QRect(570,105,54,90));
        ui->Num1_70->hide();
        pixmap.load(":/num/img/OK/num1_8.png");
        ui->Num1_8->setPixmap(pixmap);
        ui->Num1_8->setGeometry(QRect(630,105,54,90));
        ui->Num1_8->hide();
        pixmap.load(":/num/img/OK/num1_8.png");
        ui->Num1_80->setPixmap(pixmap);
        ui->Num1_80->setGeometry(QRect(570,105,54,90));
        ui->Num1_80->hide();
        pixmap.load(":/num/img/OK/num1_9.png");
        ui->Num1_9->setPixmap(pixmap);
        ui->Num1_9->setGeometry(QRect(630,105,54,90));
        ui->Num1_9->hide();
        pixmap.load(":/num/img/OK/num1_9.png");
        ui->Num1_90->setPixmap(pixmap);
        ui->Num1_90->setGeometry(QRect(570,105,54,90));
        ui->Num1_90->hide();
    }
    //數字2 for 倒數時間
    {
        pixmap.load(":/num/img/Life.png");
        ui->Time_Life->setPixmap(pixmap);
        ui->Time_Life->setGeometry(QRect(40,80,350,80));
        ui->Time_Life->hide();

        pixmap.load(":/num/img/OK/num2_3.png");
        ui->Count_Num3->setPixmap(pixmap);
        ui->Count_Num3->setGeometry(QRect(490,80,300,500));
        ui->Count_Num3->hide();

        pixmap.load(":/num/img/OK/num2_2.png");
        ui->Count_Num2->setPixmap(pixmap);
        ui->Count_Num2->setGeometry(QRect(490,80,300,500));
        ui->Count_Num2->hide();

        pixmap.load(":/num/img/OK/num2_1.png");
        ui->Count_Num1->setPixmap(pixmap);
        ui->Count_Num1->setGeometry(QRect(490,80,300,500));
        ui->Count_Num1->hide();

        pixmap.load(":/num/img/OK/num2_0.png");
        ui->Num2_0->setPixmap(pixmap);
        ui->Num2_0->setGeometry(QRect(270,20,54,90));
        ui->Num2_0->hide();
        pixmap.load(":/num/img/OK/num2_0.png");
        ui->Num2_00->setPixmap(pixmap);
        ui->Num2_00->setGeometry(QRect(210,20,54,90));
        ui->Num2_00->hide();
        pixmap.load(":/num/img/OK/num2_1.png");
        ui->Num2_1->setPixmap(pixmap);
        ui->Num2_1->setGeometry(QRect(270,20,54,90));
        ui->Num2_1->hide();
        pixmap.load(":/num/img/OK/num2_1.png");
        ui->Num2_10->setPixmap(pixmap);
        ui->Num2_10->setGeometry(QRect(210,20,54,90));
        ui->Num2_10->hide();
        pixmap.load(":/num/img/OK/num2_2.png");
        ui->Num2_2->setPixmap(pixmap);
        ui->Num2_2->setGeometry(QRect(270,20,54,90));
        ui->Num2_2->hide();
        pixmap.load(":/num/img/OK/num2_2.png");
        ui->Num2_20->setPixmap(pixmap);
        ui->Num2_20->setGeometry(QRect(210,20,54,90));
        ui->Num2_20->hide();
        pixmap.load(":/num/img/OK/num2_3.png");
        ui->Num2_3->setPixmap(pixmap);
        ui->Num2_3->setGeometry(QRect(270,20,54,90));
        ui->Num2_3->hide();
        pixmap.load(":/num/img/OK/num2_3.png");
        ui->Num2_30->setPixmap(pixmap);
        ui->Num2_30->setGeometry(QRect(210,20,54,90));
        ui->Num2_30->hide();
        pixmap.load(":/num/img/OK/num2_4.png");
        ui->Num2_4->setPixmap(pixmap);
        ui->Num2_4->setGeometry(QRect(270,20,54,90));
        ui->Num2_4->hide();
        pixmap.load(":/num/img/OK/num2_4.png");
        ui->Num2_40->setPixmap(pixmap);
        ui->Num2_40->setGeometry(QRect(210,20,54,90));
        ui->Num2_40->hide();
        pixmap.load(":/num/img/OK/num2_5.png");
        ui->Num2_5->setPixmap(pixmap);
        ui->Num2_5->setGeometry(QRect(270,20,54,90));
        ui->Num2_5->hide();
        pixmap.load(":/num/img/OK/num2_5.png");
        ui->Num2_50->setPixmap(pixmap);
        ui->Num2_50->setGeometry(QRect(210,20,54,90));
        ui->Num2_50->hide();
        pixmap.load(":/num/img/OK/num2_6.png");
        ui->Num2_6->setPixmap(pixmap);
        ui->Num2_6->setGeometry(QRect(270,20,54,90));
        ui->Num2_6->hide();
        pixmap.load(":/num/img/OK/num2_6.png");
        ui->Num2_60->setPixmap(pixmap);
        ui->Num2_60->setGeometry(QRect(210,20,54,90));
        ui->Num2_60->hide();
        pixmap.load(":/num/img/OK/num2_7.png");
        ui->Num2_7->setPixmap(pixmap);
        ui->Num2_7->setGeometry(QRect(270,20,54,90));
        ui->Num2_7->hide();
        pixmap.load(":/num/img/OK/num2_7.png");
        ui->Num2_70->setPixmap(pixmap);
        ui->Num2_70->setGeometry(QRect(210,20,54,90));
        ui->Num2_70->hide();
        pixmap.load(":/num/img/OK/num2_8.png");
        ui->Num2_8->setPixmap(pixmap);
        ui->Num2_8->setGeometry(QRect(270,20,54,90));
        ui->Num2_8->hide();
        pixmap.load(":/num/img/OK/num2_8.png");
        ui->Num2_80->setPixmap(pixmap);
        ui->Num2_80->setGeometry(QRect(210,20,54,90));
        ui->Num2_80->hide();
        pixmap.load(":/num/img/OK/num2_9.png");
        ui->Num2_9->setPixmap(pixmap);
        ui->Num2_9->setGeometry(QRect(270,20,54,90));
        ui->Num2_9->hide();
        pixmap.load(":/num/img/OK/num2_9.png");
        ui->Num2_90->setPixmap(pixmap);
        ui->Num2_90->setGeometry(QRect(210,20,54,90));
        ui->Num2_90->hide();
    }
    //數字3 for 分數
    {
        pixmap.load(":/num/img/OK/num3_0.png");
        ui->Fix_Num1->setPixmap(pixmap);
        ui->Fix_Num1->setGeometry(QRect(1100,20,54,90));
        ui->Fix_Num1->hide();
        pixmap.load(":/num/img/OK/num3_0.png");
        ui->Fix_Num2->setPixmap(pixmap);
        ui->Fix_Num2->setGeometry(QRect(1040,20,54,90));
        ui->Fix_Num2->hide();
        pixmap.load(":/num/img/OK/num3_0.png");
        ui->Fix_Num3->setPixmap(pixmap);
        ui->Fix_Num3->setGeometry(QRect(980,20,54,90));
        ui->Fix_Num3->hide();
        pixmap.load(":/num/img/OK/num3_9.png");
        ui->Fix_Num4->setPixmap(pixmap);
        ui->Fix_Num4->setGeometry(QRect(1100,20,54,90));
        ui->Fix_Num4->hide();
        pixmap.load(":/num/img/OK/num3_9.png");
        ui->Fix_Num5->setPixmap(pixmap);
        ui->Fix_Num5->setGeometry(QRect(1040,20,54,90));
        ui->Fix_Num5->hide();
        pixmap.load(":/num/img/OK/num3_9.png");
        ui->Fix_Num6->setPixmap(pixmap);
        ui->Fix_Num6->setGeometry(QRect(980,20,54,90));
        ui->Fix_Num6->hide();

        pixmap.load(":/num/img/OK/num3_0.png");
        ui->Num3_0->setPixmap(pixmap);
        ui->Num3_0->setGeometry(QRect(920,20,54,90));
        ui->Num3_0->hide();
        pixmap.load(":/num/img/OK/num3_0.png");
        ui->Num3_00->setPixmap(pixmap);
        ui->Num3_00->setGeometry(QRect(860,20,54,90));
        ui->Num3_00->hide();
        pixmap.load(":/num/img/OK/num3_0.png");
        ui->Num3_000->setPixmap(pixmap);
        ui->Num3_000->setGeometry(QRect(800,20,54,90));
        ui->Num3_000->hide();
        pixmap.load(":/num/img/OK/num3_1.png");
        ui->Num3_1->setPixmap(pixmap);
        ui->Num3_1->setGeometry(QRect(920,20,54,90));
        ui->Num3_1->hide();
        pixmap.load(":/num/img/OK/num3_1.png");
        ui->Num3_10->setPixmap(pixmap);
        ui->Num3_10->setGeometry(QRect(860,20,54,90));
        ui->Num3_10->hide();
        pixmap.load(":/num/img/OK/num3_1.png");
        ui->Num3_100->setPixmap(pixmap);
        ui->Num3_100->setGeometry(QRect(800,20,54,90));
        ui->Num3_100->hide();
        pixmap.load(":/num/img/OK/num3_2.png");
        ui->Num3_2->setPixmap(pixmap);
        ui->Num3_2->setGeometry(QRect(920,20,54,90));
        ui->Num3_2->hide();
        pixmap.load(":/num/img/OK/num3_2.png");
        ui->Num3_20->setPixmap(pixmap);
        ui->Num3_20->setGeometry(QRect(860,20,54,90));
        ui->Num3_20->hide();
        pixmap.load(":/num/img/OK/num3_2.png");
        ui->Num3_200->setPixmap(pixmap);
        ui->Num3_200->setGeometry(QRect(800,20,54,90));
        ui->Num3_200->hide();
        pixmap.load(":/num/img/OK/num3_3.png");
        ui->Num3_3->setPixmap(pixmap);
        ui->Num3_3->setGeometry(QRect(920,20,54,90));
        ui->Num3_3->hide();
        pixmap.load(":/num/img/OK/num3_3.png");
        ui->Num3_30->setPixmap(pixmap);
        ui->Num3_30->setGeometry(QRect(860,20,54,90));
        ui->Num3_30->hide();
        pixmap.load(":/num/img/OK/num3_3.png");
        ui->Num3_300->setPixmap(pixmap);
        ui->Num3_300->setGeometry(QRect(800,20,54,90));
        ui->Num3_300->hide();
        pixmap.load(":/num/img/OK/num3_4.png");
        ui->Num3_4->setPixmap(pixmap);
        ui->Num3_4->setGeometry(QRect(920,20,54,90));
        ui->Num3_4->hide();
        pixmap.load(":/num/img/OK/num3_4.png");
        ui->Num3_40->setPixmap(pixmap);
        ui->Num3_40->setGeometry(QRect(860,20,54,90));
        ui->Num3_40->hide();
        pixmap.load(":/num/img/OK/num3_4.png");
        ui->Num3_400->setPixmap(pixmap);
        ui->Num3_400->setGeometry(QRect(800,20,54,90));
        ui->Num3_400->hide();
        pixmap.load(":/num/img/OK/num3_5.png");
        ui->Num3_5->setPixmap(pixmap);
        ui->Num3_5->setGeometry(QRect(920,20,54,90));
        ui->Num3_5->hide();
        pixmap.load(":/num/img/OK/num3_5.png");
        ui->Num3_50->setPixmap(pixmap);
        ui->Num3_50->setGeometry(QRect(860,20,54,90));
        ui->Num3_50->hide();
        pixmap.load(":/num/img/OK/num3_5.png");
        ui->Num3_500->setPixmap(pixmap);
        ui->Num3_500->setGeometry(QRect(800,20,54,90));
        ui->Num3_500->hide();
        pixmap.load(":/num/img/OK/num3_6.png");
        ui->Num3_6->setPixmap(pixmap);
        ui->Num3_6->setGeometry(QRect(920,20,54,90));
        ui->Num3_6->hide();
        pixmap.load(":/num/img/OK/num3_6.png");
        ui->Num3_60->setPixmap(pixmap);
        ui->Num3_60->setGeometry(QRect(860,20,54,90));
        ui->Num3_60->hide();
        pixmap.load(":/num/img/OK/num3_6.png");
        ui->Num3_600->setPixmap(pixmap);
        ui->Num3_600->setGeometry(QRect(800,20,54,90));
        ui->Num3_600->hide();
        pixmap.load(":/num/img/OK/num3_7.png");
        ui->Num3_7->setPixmap(pixmap);
        ui->Num3_7->setGeometry(QRect(920,20,54,90));
        ui->Num3_7->hide();
        pixmap.load(":/num/img/OK/num3_7.png");
        ui->Num3_70->setPixmap(pixmap);
        ui->Num3_70->setGeometry(QRect(860,20,54,90));
        ui->Num3_70->hide();
        pixmap.load(":/num/img/OK/num3_7.png");
        ui->Num3_700->setPixmap(pixmap);
        ui->Num3_700->setGeometry(QRect(800,20,54,90));
        ui->Num3_700->hide();
        pixmap.load(":/num/img/OK/num3_8.png");
        ui->Num3_8->setPixmap(pixmap);
        ui->Num3_8->setGeometry(QRect(920,20,54,90));
        ui->Num3_8->hide();
        pixmap.load(":/num/img/OK/num3_8.png");
        ui->Num3_80->setPixmap(pixmap);
        ui->Num3_80->setGeometry(QRect(860,20,54,90));
        ui->Num3_80->hide();
        pixmap.load(":/num/img/OK/num3_8.png");
        ui->Num3_800->setPixmap(pixmap);
        ui->Num3_800->setGeometry(QRect(800,20,54,90));
        ui->Num3_800->hide();
        pixmap.load(":/num/img/OK/num3_9.png");
        ui->Num3_9->setPixmap(pixmap);
        ui->Num3_9->setGeometry(QRect(920,20,54,90));
        ui->Num3_9->hide();
        pixmap.load(":/num/img/OK/num3_9.png");
        ui->Num3_90->setPixmap(pixmap);
        ui->Num3_90->setGeometry(QRect(860,20,54,90));
        ui->Num3_90->hide();
        pixmap.load(":/num/img/OK/num3_9.png");
        ui->Num3_900->setPixmap(pixmap);
        ui->Num3_900->setGeometry(QRect(800,20,54,90));
        ui->Num3_900->hide();
    }
    //Dancer
    {
        pixmap.load(":/dancer/img/dancer/dancer_1n14.png");
        ui->Dancer1->setPixmap(pixmap);
        ui->Dancer1->setGeometry(QRect(430,430,128,195));
        ui->Dancer1->hide();

        pixmap.load(":/dancer/img/dancer/dancer_2a12.png");
        ui->Dancer2->setPixmap(pixmap);
        ui->Dancer2->setGeometry(QRect(280,430,128,195));
        ui->Dancer2->hide();

        pixmap.load(":/dancer/img/dancer/dancer_3n7.png");
        ui->Dancer3->setPixmap(pixmap);
        ui->Dancer3->setGeometry(QRect(730,430,128,195));
        ui->Dancer3->hide();

        pixmap.load(":/dancer/img/dancer/dancer_4d2.png");
        ui->Dancer4->setPixmap(pixmap);
        ui->Dancer4->setGeometry(QRect(580,430,128,195));
        ui->Dancer4->hide();

        pixmap.load(":/dancer/img/dancer/dancer_5a14.png");
        ui->Dancer5->setPixmap(pixmap);
        ui->Dancer5->setGeometry(QRect(880,430,128,195));
        ui->Dancer5->hide();
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::MySlot()
{
    QPixmap pixmap;
    srand(time(NULL));
    --Combo_Sign_Life;
    --Red_Drum_Life;
    --Blue_Drum_Life;
    ++Drum_Gold_Life;
    ++Now_time;
    ui->Drum_Gold->setGeometry(rand()%800*4621%800,rand()%430*9824%430,420,280);
    //倒數3，2，1
    {
    if(Now_time==-199)
    {
        ui->Count_Num3->show();
    }
    else if(Now_time==-132)
    {
        ui->Count_Num3->hide();
        ui->Count_Num2->show();
    }
    else if(Now_time==-66)
    {
        ui->Count_Num2->hide();
        ui->Count_Num1->show();
    }
    else if(Now_time==-5)
    {
        ui->Count_Num1->hide();
    }
    }
    //鼓面跑動
    if(Play_Mode==0)
    {
        int x1 = ui->Drum_Button1->x();
        int y1 = ui->Drum_Button1->y();
        ui->Drum_Button1->move(QPoint(x1-Speed_Level,y1));
        int x2 = ui->Drum_Button2->x();
        int y2 = ui->Drum_Button2->y();
        ui->Drum_Button2->move(QPoint(x2-Speed_Level,y2));
        int x3 = ui->Drum_Button3->x();
        int y3 = ui->Drum_Button3->y();
        ui->Drum_Button3->move(QPoint(x3-Speed_Level,y3));
        int x4 = ui->Drum_Button4->x();
        int y4 = ui->Drum_Button4->y();
        ui->Drum_Button4->move(QPoint(x4-Speed_Level,y4));
        int x5 = ui->Drum_Button5->x();
        int y5 = ui->Drum_Button5->y();
        ui->Drum_Button5->move(QPoint(x5-Speed_Level,y5));
        int x6 = ui->Drum_Button6->x();
        int y6 = ui->Drum_Button6->y();
        ui->Drum_Button6->move(QPoint(x6-Speed_Level,y6));
        int x7 = ui->Drum_Button7->x();
        int y7 = ui->Drum_Button7->y();
        ui->Drum_Button7->move(QPoint(x7-Speed_Level,y7));
        int x8 = ui->Drum_Button8->x();
        int y8 = ui->Drum_Button8->y();
        ui->Drum_Button8->move(QPoint(x8-Speed_Level,y8));
    //鼓面接近
        if(abs(x1-x2)<200 || abs(x1-x3)<200 || abs(x1-x4)<200 || abs(x1-x5)<200 || abs(x1-x6)<200 || abs(x1-x7)<200 || abs(x1-x8)<200)
        {
            ui->Drum_Button1->move(QPoint(rand()%1400*8526%1400+1400,y1));
        }
        if(abs(x2-x3)<200 || abs(x2-x4)<200 || abs(x2-x5)<200 || abs(x2-x6)<200 || abs(x2-x7)<200 || abs(x2-x8)<200)
        {
            ui->Drum_Button2->move(QPoint(rand()%1400*5721%1400+1400,y2));
        }
        if(abs(x3-x4)<200 || abs(x3-x5)<200 || abs(x3-x6)<200 || abs(x3-x7)<200 || abs(x3-x8)<200)
        {
            ui->Drum_Button3->move(QPoint(rand()%1400*1583%1400+1400,y3));
        }
        if(abs(x4-x5)<200 || abs(x4-x6)<200 || abs(x4-x7)<200 || abs(x4-x8)<200)
        {
            ui->Drum_Button4->move(QPoint(rand()%1400*4328%1400+1400,y4));
        }
        if(abs(x5-x6)<200 || abs(x5-x7)<200 || abs(x5-x8)<200)
        {
            ui->Drum_Button5->move(QPoint(rand()%1400*5842%1400+1400,y5));
        }
        if(abs(x6-x7)<200 || abs(x6-x8)<200)
        {
            ui->Drum_Button6->move(QPoint(rand()%1400*4569%1400+1400,y6));
        }
        if(abs(x7-x8)<200)
        {
            ui->Drum_Button7->move(QPoint(rand()%1400*2547%1400+1400,y7));
        }
    //鼓面超過打擊點
        if(x1<200)
        {
            if(ui->Drum_Button1->isVisible())
            {
                Combo=0;
            }
            ui->Drum_Button1->show();
            ui->Drum_Button1->move(QPoint(rand()%1400*5460%1400+1400,y1));
        }
        if(x2<200)
        {
            if(ui->Drum_Button2->isVisible())
            {
                Combo=0;
            }
            ui->Drum_Button2->show();
            ui->Drum_Button2->move(QPoint(rand()%1400*4890%1400+1400,y2));
        }
        if(x3<200)
        {
            if(ui->Drum_Button3->isVisible())
            {
                Combo=0;
            }
            ui->Drum_Button3->show();
            ui->Drum_Button3->move(QPoint(rand()%1400*3060%1400+1400,y3));
        }
        if(x4<200)
        {
            if(ui->Drum_Button4->isVisible())
            {
                Combo=0;
            }
            ui->Drum_Button4->show();
            ui->Drum_Button4->move(QPoint(rand()%1400*4536%1400+1400,y4));
        }
        if(x5<200)
        {
            if(ui->Drum_Button5->isVisible())
            {
                Combo=0;
            }
            ui->Drum_Button5->show();
            ui->Drum_Button5->move(QPoint(rand()%1400*9251%1400+1400,y5));
        }
        if(x6<200)
        {
            if(ui->Drum_Button6->isVisible())
            {
                Combo=0;
            }
            ui->Drum_Button6->show();
            ui->Drum_Button6->move(QPoint(rand()%1400*7254%1400+1400,y6));
        }
        if(x7<200)
        {
            if(ui->Drum_Button7->isVisible())
            {
                Combo=0;
            }
            ui->Drum_Button7->show();
            ui->Drum_Button7->move(QPoint(rand()%1400*6724%1400+1400,y7));
        }
        if(x8<200)
        {
            if(ui->Drum_Button8->isVisible())
            {
                Combo=0;
            }
            ui->Drum_Button8->show();
            ui->Drum_Button8->move(QPoint(rand()%1400*1283%1400+1400,y8));
        }

    }
    else if(Play_Mode==1)
    {
            switch(rand()%8)
            {
                case 0:
                    ui->Drum_Button1->show();
                    ui->Drum_Button4->show();
                    ui->Drum_Button7->show();
                break;
                case 1:
                    ui->Drum_Button2->show();
                    ui->Drum_Button5->show();
                    ui->Drum_Button8->show();
                break;
                case 2:
                    ui->Drum_Button3->show();
                    ui->Drum_Button6->show();
                    ui->Drum_Button1->show();
                break;
                case 3:
                    ui->Drum_Button4->show();
                    ui->Drum_Button7->show();
                    ui->Drum_Button2->show();
                break;
                case 4:
                    ui->Drum_Button5->show();
                    ui->Drum_Button8->show();
                    ui->Drum_Button3->show();
                break;
                case 5:
                    ui->Drum_Button6->show();
                    ui->Drum_Button1->show();
                    ui->Drum_Button4->show();
                break;
                case 6:
                    ui->Drum_Button7->show();
                    ui->Drum_Button2->show();
                    ui->Drum_Button5->show();
                break;
                case 7:
                    ui->Drum_Button8->show();
                    ui->Drum_Button3->show();
                    ui->Drum_Button6->show();
                break;
            default: ;
            }
        int x1 = ui->Drum_Button1->x();
        int y1 = ui->Drum_Button1->y();
        switch(Move_Moed[1])
        {
            case 0:
                ui->Drum_Button1->move(QPoint(x1-Speed_Level,y1-Speed_Level));
            break;
            case 1:
                ui->Drum_Button1->move(QPoint(x1-Speed_Level,y1+Speed_Level));
            break;
            case 2:
                ui->Drum_Button1->move(QPoint(x1+Speed_Level,y1+Speed_Level));
            break;
            case 3:
                ui->Drum_Button1->move(QPoint(x1+Speed_Level,y1-Speed_Level));
            break;
        default: ;
        }
        int x2 = ui->Drum_Button2->x();
        int y2 = ui->Drum_Button2->y();
        switch(Move_Moed[2])
        {
            case 0:
                ui->Drum_Button2->move(QPoint(x2-Speed_Level,y2-Speed_Level));
            break;
            case 1:
                ui->Drum_Button2->move(QPoint(x2-Speed_Level,y2+Speed_Level));
            break;
            case 2:
                ui->Drum_Button2->move(QPoint(x2+Speed_Level,y2+Speed_Level));
            break;
            case 3:
                ui->Drum_Button2->move(QPoint(x2+Speed_Level,y2-Speed_Level));
            break;
        default: ;
        }
        int x3 = ui->Drum_Button3->x();
        int y3 = ui->Drum_Button3->y();
        switch(Move_Moed[3])
        {
            case 0:
                ui->Drum_Button3->move(QPoint(x3-Speed_Level,y3-Speed_Level));
            break;
            case 1:
                ui->Drum_Button3->move(QPoint(x3-Speed_Level,y3+Speed_Level));
            break;
            case 2:
                ui->Drum_Button3->move(QPoint(x3+Speed_Level,y3+Speed_Level));
            break;
            case 3:
                ui->Drum_Button3->move(QPoint(x3+Speed_Level,y3-Speed_Level));
            break;
        default: ;
        }
        int x4 = ui->Drum_Button4->x();
        int y4 = ui->Drum_Button4->y();
        switch(Move_Moed[4])
        {
            case 0:
                ui->Drum_Button4->move(QPoint(x4-Speed_Level,y4-Speed_Level));
            break;
            case 1:
                ui->Drum_Button4->move(QPoint(x4-Speed_Level,y4+Speed_Level));
            break;
            case 2:
                ui->Drum_Button4->move(QPoint(x4+Speed_Level,y4+Speed_Level));
            break;
            case 3:
                ui->Drum_Button4->move(QPoint(x4+Speed_Level,y4-Speed_Level));
            break;
        default: ;
        }
        int x5 = ui->Drum_Button5->x();
        int y5 = ui->Drum_Button5->y();
        switch(Move_Moed[5])
        {
            case 0:
                ui->Drum_Button5->move(QPoint(x5-Speed_Level,y5-Speed_Level));
            break;
            case 1:
                ui->Drum_Button5->move(QPoint(x5-Speed_Level,y5+Speed_Level));
            break;
            case 2:
                ui->Drum_Button5->move(QPoint(x5+Speed_Level,y5+Speed_Level));
            break;
            case 3:
                ui->Drum_Button5->move(QPoint(x5+Speed_Level,y5-Speed_Level));
            break;
        default: ;
        }
        int x6 = ui->Drum_Button6->x();
        int y6 = ui->Drum_Button6->y();
        switch(Move_Moed[6])
        {
            case 0:
                ui->Drum_Button6->move(QPoint(x6-Speed_Level,y6-Speed_Level));
            break;
            case 1:
                ui->Drum_Button6->move(QPoint(x6-Speed_Level,y6+Speed_Level));
            break;
            case 2:
                ui->Drum_Button6->move(QPoint(x6+Speed_Level,y6+Speed_Level));
            break;
            case 3:
                ui->Drum_Button6->move(QPoint(x6+Speed_Level,y6-Speed_Level));
            break;
        default: ;
        }
        int x7 = ui->Drum_Button7->x();
        int y7 = ui->Drum_Button7->y();
        switch(Move_Moed[7])
        {
            case 0:
                ui->Drum_Button7->move(QPoint(x7-Speed_Level,y7-Speed_Level));
            break;
            case 1:
                ui->Drum_Button7->move(QPoint(x7-Speed_Level,y7+Speed_Level));
            break;
            case 2:
                ui->Drum_Button7->move(QPoint(x7+Speed_Level,y7+Speed_Level));
            break;
            case 3:
                ui->Drum_Button7->move(QPoint(x7+Speed_Level,y7-Speed_Level));
            break;
        default: ;
        }
        int x8 = ui->Drum_Button8->x();
        int y8 = ui->Drum_Button8->y();
        switch(Move_Moed[8])
        {
            case 0:
                ui->Drum_Button8->move(QPoint(x8-Speed_Level,y8-Speed_Level));
            break;
            case 1:
                ui->Drum_Button8->move(QPoint(x8-Speed_Level,y8+Speed_Level));
            break;
            case 2:
                ui->Drum_Button8->move(QPoint(x8+Speed_Level,y8+Speed_Level));
            break;
            case 3:
                ui->Drum_Button8->move(QPoint(x8+Speed_Level,y8-Speed_Level));
            break;
        default: ;
        }
    //鼓面超過打擊點
        if(x1<0)
        {
            if(Move_Moed[1]==1)
                Move_Moed[1]=2;
            else
                Move_Moed[1]=3;
            ++Impact[1];
        }
        else if(x1>1280)
        {
            if(Move_Moed[1]==3)
                Move_Moed[1]=0;
            else
                Move_Moed[1]=1;
            ++Impact[1];
        }
        else if(y1<0)
        {
            if(Move_Moed[1]==0)
                Move_Moed[1]=1;
            else
                Move_Moed[1]=2;
            ++Impact[1];
        }
        else if(y1>730)
        {
            if(Move_Moed[1]==2)
                Move_Moed[1]=3;
            else
                Move_Moed[1]=0;
            ++Impact[1];
        }

        if(x2<0)
        {
            if(Move_Moed[2]==1)
                Move_Moed[2]=2;
            else
                Move_Moed[2]=3;
            ++Impact[2];
        }
        else if(x2>1280)
        {
            if(Move_Moed[2]==3)
                Move_Moed[2]=0;
            else
                Move_Moed[2]=1;
            ++Impact[2];
        }
        else if(y2<0)
        {
            if(Move_Moed[2]==0)
                Move_Moed[2]=1;
            else
                Move_Moed[2]=2;
            ++Impact[2];
        }
        else if(y2>730)
        {
            if(Move_Moed[2]==2)
                Move_Moed[2]=3;
            else
                Move_Moed[2]=0;
            ++Impact[2];
        }

        if(x3<0)
        {
            if(Move_Moed[3]==1)
                Move_Moed[3]=2;
            else
                Move_Moed[3]=3;
            ++Impact[3];
        }
        else if(x3>1280)
        {
            if(Move_Moed[3]==3)
                Move_Moed[3]=0;
            else
                Move_Moed[3]=1;
            ++Impact[3];
        }
        else if(y3<0)
        {
            if(Move_Moed[3]==0)
                Move_Moed[3]=1;
            else
                Move_Moed[3]=2;
            ++Impact[3];
        }
        else if(y3>730)
        {
            if(Move_Moed[3]==2)
                Move_Moed[3]=3;
            else
                Move_Moed[3]=0;
            ++Impact[3];
        }

        if(x4<0)
        {
            if(Move_Moed[4]==1)
                Move_Moed[4]=2;
            else
                Move_Moed[4]=3;
            ++Impact[4];
        }
        else if(x4>1280)
        {
            if(Move_Moed[4]==3)
                Move_Moed[4]=0;
            else
                Move_Moed[4]=1;
            ++Impact[4];
        }
        else if(y4<0)
        {
            if(Move_Moed[4]==0)
                Move_Moed[4]=1;
            else
                Move_Moed[4]=2;
            ++Impact[4];
        }
        else if(y4>730)
        {
            if(Move_Moed[4]==2)
                Move_Moed[4]=3;
            else
                Move_Moed[4]=0;
            ++Impact[4];
        }

        if(x5<0)
        {
            if(Move_Moed[5]==1)
                Move_Moed[5]=2;
            else
                Move_Moed[5]=3;
            ++Impact[5];
        }
        else if(x5>1280)
        {
            if(Move_Moed[5]==3)
                Move_Moed[5]=0;
            else
                Move_Moed[5]=1;
            ++Impact[5];
        }
        else if(y5<0)
        {
            if(Move_Moed[5]==0)
                Move_Moed[5]=1;
            else
                Move_Moed[5]=2;
            ++Impact[5];
        }
        else if(y5>730)
        {
            if(Move_Moed[5]==2)
                Move_Moed[5]=3;
            else
                Move_Moed[5]=0;
            ++Impact[5];
        }

        if(x6<0)
        {
            if(Move_Moed[6]==1)
                Move_Moed[6]=2;
            else
                Move_Moed[6]=3;
            ++Impact[6];
        }
        else if(x6>1280)
        {
            if(Move_Moed[6]==3)
                Move_Moed[6]=0;
            else
                Move_Moed[6]=1;
            ++Impact[6];
        }
        else if(y6<0)
        {
            if(Move_Moed[6]==0)
                Move_Moed[6]=1;
            else
                Move_Moed[6]=2;
            ++Impact[6];
        }
        else if(y6>730)
        {
            if(Move_Moed[6]==2)
                Move_Moed[6]=3;
            else
                Move_Moed[6]=0;
            ++Impact[6];
        }

        if(x7<0)
        {
            if(Move_Moed[7]==1)
                Move_Moed[7]=2;
            else
                Move_Moed[7]=3;
            ++Impact[7];
        }
        else if(x7>1280)
        {
            if(Move_Moed[7]==3)
                Move_Moed[7]=0;
            else
                Move_Moed[7]=1;
            ++Impact[7];
        }
        else if(y7<0)
        {
            if(Move_Moed[7]==0)
                Move_Moed[7]=1;
            else
                Move_Moed[7]=2;
            ++Impact[7];
        }
        else if(y7>730)
        {
            if(Move_Moed[7]==2)
                Move_Moed[7]=3;
            else
                Move_Moed[7]=0;
            ++Impact[7];
        }

        if(x8<0)
        {
            if(Move_Moed[8]==1)
                Move_Moed[8]=2;
            else
                Move_Moed[8]=3;
            ++Impact[8];
        }
        else if(x8>1280)
        {
            if(Move_Moed[8]==3)
                Move_Moed[8]=0;
            else
                Move_Moed[8]=1;
            ++Impact[8];
        }
        else if(y8<0)
        {
            if(Move_Moed[8]==0)
                Move_Moed[8]=1;
            else
                Move_Moed[8]=2;
            ++Impact[8];
        }
        else if(y8>730)
        {
            if(Move_Moed[8]==2)
                Move_Moed[8]=3;
            else
                Move_Moed[8]=0;
            ++Impact[8];
        }


        if(Impact[1]>10)
        {
            ui->Drum_Button1->hide();
            ui->Drum_Button1->move(QPoint(rand()%1280*185%1280,rand()%1280*137%730));
//            Combo=0;
            Impact[1]=0;
            Move_Moed[1]=rand()%4;
        }
        if(Impact[2]>10)
        {
            ui->Drum_Button2->hide();
            ui->Drum_Button2->move(QPoint(rand()%1280*875%1280,rand()%1280*246%730));
//            Combo=0;
            Impact[2]=0;
            Move_Moed[2]=rand()%4;
        }
        if(Impact[3]>10)
        {
            ui->Drum_Button3->hide();
            ui->Drum_Button3->move(QPoint(rand()%1280*186%1280,rand()%1280*754%730));
//            Combo=0;
            Impact[3]=0;
            Move_Moed[3]=rand()%4;
        }
        if(Impact[4]>10)
        {
            ui->Drum_Button4->hide();
            ui->Drum_Button4->move(QPoint(rand()%1280*235%1280,rand()%1280*674%730));
//            Combo=0;
            Impact[4]=0;
            Move_Moed[4]=rand()%4;
        }
        if(Impact[5]>10)
        {
            ui->Drum_Button5->hide();
            ui->Drum_Button5->move(QPoint(rand()%1280*587%1280,rand()%1280*876%730));
//            Combo=0;
            Impact[5]=0;
            Move_Moed[5]=rand()%4;
        }
        if(Impact[6]>10)
        {
            ui->Drum_Button6->hide();
            ui->Drum_Button6->move(QPoint(rand()%1280*123%1280,rand()%1280*321%730));
//            Combo=0;
            Impact[6]=0;
            Move_Moed[6]=rand()%4;
        }
        if(Impact[7]>10)
        {
            ui->Drum_Button7->hide();
            ui->Drum_Button7->move(QPoint(rand()%1280*456%1280,rand()%1280*654%730));
//            Combo=0;
            Impact[7]=0;
            Move_Moed[7]=rand()%4;
        }
        if(Impact[8]>10)
        {
            ui->Drum_Button8->hide();
            ui->Drum_Button8->move(QPoint(rand()%1280*789%1280,rand()%1280*987%730));
//            Combo=0;
            Impact[8]=0;
            Move_Moed[8]=rand()%4;
        }
    }
    //連擊跳動
    if(Combo_Sign_Life > 0 && Combo > 99 && !IsShow_Combo)
    {
        IsShow_Combo=true;
        ui->Combo_Image->show();
        ui->Num1_9->show();
        ui->Num1_90->show();
    }
    else if(Combo_Sign_Life > 0 && Combo && !IsShow_Combo)
    {
        IsShow_Combo=true;
        ui->Combo_Image->show();
        switch(Combo%10)
        {
            case 0:
                ui->Num1_0->show();
                ui->Num1_9->hide();
            break;
            case 1:
                ui->Num1_1->show();
                ui->Num1_0->hide();
                break;
            case 2:
                ui->Num1_2->show();
                ui->Num1_1->hide();
            break;
            case 3:
                ui->Num1_3->show();
                ui->Num1_2->hide();
            break;
            case 4:
                ui->Num1_4->show();
                ui->Num1_3->hide();
            break;
            case 5:
                ui->Num1_5->show();
                ui->Num1_4->hide();
            break;
            case 6:
                ui->Num1_6->show();
                ui->Num1_5->hide();
            break;
            case 7:
                ui->Num1_7->show();
                ui->Num1_6->hide();
            break;
            case 8:
                ui->Num1_8->show();
                ui->Num1_7->hide();
            break;
            case 9:
                ui->Num1_9->show();
                ui->Num1_8->hide();
            break;
            default:;
        }
        switch(Combo/10)
        {
            case 1:
                ui->Num1_10->show();
                ui->Num1_00->hide();
            break;
            case 2:
                ui->Num1_20->show();
                ui->Num1_10->hide();
            break;
            case 3:
                ui->Num1_30->show();
                ui->Num1_20->hide();
            break;
            case 4:
                ui->Num1_40->show();
                ui->Num1_30->hide();
            break;
            case 5:
                ui->Num1_50->show();
                ui->Num1_40->hide();
            break;
            case 6:
                ui->Num1_60->show();
                ui->Num1_50->hide();
            break;
            case 7:
                ui->Num1_70->show();
                ui->Num1_60->hide();
            break;
            case 8:
                ui->Num1_80->show();
                ui->Num1_70->hide();
            break;
            case 9:
                ui->Num1_90->show();
                ui->Num1_80->hide();
            break;
            default:;
        }
    }
    else if (Combo_Sign_Life == 0)
    {
        IsShow_Combo=false;
        ui->Num1_0->hide();ui->Num1_00->hide();
        ui->Num1_1->hide();ui->Num1_10->hide();
        ui->Num1_2->hide();ui->Num1_20->hide();
        ui->Num1_3->hide();ui->Num1_30->hide();
        ui->Num1_4->hide();ui->Num1_40->hide();
        ui->Num1_5->hide();ui->Num1_50->hide();
        ui->Num1_6->hide();ui->Num1_60->hide();
        ui->Num1_7->hide();ui->Num1_70->hide();
        ui->Num1_8->hide();ui->Num1_80->hide();
        ui->Num1_9->hide();ui->Num1_90->hide();
        ui->Combo_Image->hide();

        ui->Hit_Point1->hide();
        ui->Hit_Point2->hide();
        ui->Hit_Point3->hide();
    }
    if(Red_Drum_Life==0)
    {
        ui->Hit_Drum_Red1->hide();
        ui->Hit_Drum_Red2->hide();
        ui->Hit_Point3->hide();
    }
    if(Blue_Drum_Life==0)
    {
        ui->Hit_Drum_Blue1->hide();
        ui->Hit_Drum_Blue2->hide();
        ui->Hit_Point3->hide();
    }
    //時間
    if(Now_time>0)
    {
        int Now_time_sec=29-Now_time*3/200;
        switch(Now_time_sec/10)
        {
            case 0:
                ui->Num2_10->hide();
            break;
            case 1:
                ui->Num2_10->show();
                ui->Num2_20->hide();
            break;
            case 2:
                ui->Num2_20->show();
                ui->Num2_30->hide();
            break;
            case 3:
                ui->Num2_30->show();
                ui->Num2_40->hide();
            break;
            case 4:
                ui->Num2_40->show();
                ui->Num2_50->hide();
            break;
            case 5:
                ui->Num2_50->show();
                ui->Num2_60->hide();
            break;
            case 6:
                ui->Num2_60->show();
                ui->Num2_70->hide();
            break;
            case 7:
                ui->Num2_70->show();
                ui->Num2_80->hide();
            break;
            case 8:
                ui->Num2_80->show();
                ui->Num2_90->hide();
            break;
            case 9:
                ui->Num2_90->show();
                ui->Num2_00->hide();
            break;
            default: ;
        }

        switch(Now_time_sec%10)
        {
            case 0:
                ui->Num2_0->show();
                ui->Num2_1->hide();
            break;
            case 1:
                ui->Num2_1->show();
                ui->Num2_2->hide();
            break;
            case 2:
                ui->Num2_2->show();
                ui->Num2_3->hide();
            break;
            case 3:
                ui->Num2_3->show();
                ui->Num2_4->hide();
            break;
            case 4:
                ui->Num2_4->show();
                ui->Num2_5->hide();
            break;
            case 5:
                ui->Num2_5->show();
                ui->Num2_6->hide();
            break;
            case 6:
                ui->Num2_6->show();
                ui->Num2_7->hide();
            break;
            case 7:
                ui->Num2_7->show();
                ui->Num2_8->hide();
            break;
            case 8:
                ui->Num2_8->show();
                ui->Num2_9->hide();
            break;
            case 9:
                ui->Num2_9->show();
                ui->Num2_0->hide();
            break;
            default: ;
        }

        if(Now_time_sec<=8)
        {
            ui->Life_Green->hide();
            ui->Life_Red->setGeometry(QRect(128,141,(70-(Now_time-1467)*0.1275),10));
        }
        else
        {
            ui->Life_Green->setGeometry(QRect(128,141,255-Now_time*0.1275,10));
        }
    }
    //Dancer
    switch(Now_time/5%48)
    {
        case 0:
            pixmap.load(":/dancer/img/dancer/dancer_1a1.png");
            ui->Dancer1->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_2a1.png");
            ui->Dancer2->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_3a1.png");
            ui->Dancer3->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_4a1.png");
            ui->Dancer4->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_5a1.png");
            ui->Dancer5->setPixmap(pixmap);
        break;
        case 1:
            pixmap.load(":/dancer/img/dancer/dancer_1a2.png");
            ui->Dancer1->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_2a2.png");
            ui->Dancer2->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_3a2.png");
            ui->Dancer3->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_4a2.png");
            ui->Dancer4->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_5a2.png");
            ui->Dancer5->setPixmap(pixmap);
        break;
        case 2:
            pixmap.load(":/dancer/img/dancer/dancer_1a3.png");
            ui->Dancer1->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_2a3.png");
            ui->Dancer2->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_3a3.png");
            ui->Dancer3->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_4a3.png");
            ui->Dancer4->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_5a3.png");
            ui->Dancer5->setPixmap(pixmap);
        break;
        case 3:
            pixmap.load(":/dancer/img/dancer/dancer_1a4.png");
            ui->Dancer1->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_2a4.png");
            ui->Dancer2->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_3a4.png");
            ui->Dancer3->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_4a4.png");
            ui->Dancer4->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_5a4.png");
            ui->Dancer5->setPixmap(pixmap);
        break;
        case 4:
            pixmap.load(":/dancer/img/dancer/dancer_1a5.png");
            ui->Dancer1->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_2a5.png");
            ui->Dancer2->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_3a5.png");
            ui->Dancer3->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_4a5.png");
            ui->Dancer4->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_5a5.png");
            ui->Dancer5->setPixmap(pixmap);
        break;
        case 5:
            pixmap.load(":/dancer/img/dancer/dancer_1a6.png");
            ui->Dancer1->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_2a6.png");
            ui->Dancer2->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_3a6.png");
            ui->Dancer3->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_4a6.png");
            ui->Dancer4->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_5a6.png");
            ui->Dancer5->setPixmap(pixmap);
        break;
        case 6:
            pixmap.load(":/dancer/img/dancer/dancer_1a7.png");
            ui->Dancer1->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_2a7.png");
            ui->Dancer2->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_3a7.png");
            ui->Dancer3->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_4a7.png");
            ui->Dancer4->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_5a7.png");
            ui->Dancer5->setPixmap(pixmap);
        break;
        case 7:
            pixmap.load(":/dancer/img/dancer/dancer_1a8.png");
            ui->Dancer1->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_2a8.png");
            ui->Dancer2->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_3a8.png");
            ui->Dancer3->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_4a8.png");
            ui->Dancer4->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_5a8.png");
            ui->Dancer5->setPixmap(pixmap);
        break;
        case 8:
            pixmap.load(":/dancer/img/dancer/dancer_1a9.png");
            ui->Dancer1->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_2a9.png");
            ui->Dancer2->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_3a9.png");
            ui->Dancer3->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_4a9.png");
            ui->Dancer4->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_5a9.png");
            ui->Dancer5->setPixmap(pixmap);
        break;
        case 9:
            pixmap.load(":/dancer/img/dancer/dancer_1a10.png");
            ui->Dancer1->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_2a10.png");
            ui->Dancer2->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_3a10.png");
            ui->Dancer3->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_4a10.png");
            ui->Dancer4->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_5a10.png");
            ui->Dancer5->setPixmap(pixmap);
        break;
        case 10:
            pixmap.load(":/dancer/img/dancer/dancer_1a11.png");
            ui->Dancer1->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_2a11.png");
            ui->Dancer2->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_3a11.png");
            ui->Dancer3->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_4a11.png");
            ui->Dancer4->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_5a11.png");
            ui->Dancer5->setPixmap(pixmap);
        break;
        case 11:
            pixmap.load(":/dancer/img/dancer/dancer_1a12.png");
            ui->Dancer1->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_2a12.png");
            ui->Dancer2->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_3a12.png");
            ui->Dancer3->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_4a12.png");
            ui->Dancer4->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_5a12.png");
            ui->Dancer5->setPixmap(pixmap);
        break;
        case 12:
            pixmap.load(":/dancer/img/dancer/dancer_1a13.png");
            ui->Dancer1->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_2a13.png");
            ui->Dancer2->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_3a13.png");
            ui->Dancer3->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_4a13.png");
            ui->Dancer4->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_5a13.png");
            ui->Dancer5->setPixmap(pixmap);
        break;
        case 13:
            pixmap.load(":/dancer/img/dancer/dancer_1a14.png");
            ui->Dancer1->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_2a14.png");
            ui->Dancer2->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_3a14.png");
            ui->Dancer3->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_4a14.png");
            ui->Dancer4->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_5a14.png");
            ui->Dancer5->setPixmap(pixmap);
        break;
        case 14:
            pixmap.load(":/dancer/img/dancer/dancer_1a15.png");
            ui->Dancer1->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_2a15.png");
            ui->Dancer2->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_3a15.png");
            ui->Dancer3->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_4a15.png");
            ui->Dancer4->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_5a15.png");
            ui->Dancer5->setPixmap(pixmap);
        break;
        case 15:
            pixmap.load(":/dancer/img/dancer/dancer_1a16.png");
            ui->Dancer1->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_2a16.png");
            ui->Dancer2->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_3a16.png");
            ui->Dancer3->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_4a16.png");
            ui->Dancer4->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_5a16.png");
            ui->Dancer5->setPixmap(pixmap);
        break;
        case 16:
            pixmap.load(":/dancer/img/dancer/dancer_1n1.png");
            ui->Dancer1->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_2n1.png");
            ui->Dancer2->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_3n1.png");
            ui->Dancer3->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_4n1.png");
            ui->Dancer4->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_5n1.png");
            ui->Dancer5->setPixmap(pixmap);
        break;
        case 17:
            pixmap.load(":/dancer/img/dancer/dancer_1n2.png");
            ui->Dancer1->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_2n2.png");
            ui->Dancer2->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_3n2.png");
            ui->Dancer3->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_4n2.png");
            ui->Dancer4->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_5n2.png");
            ui->Dancer5->setPixmap(pixmap);
        break;
        case 18:
            pixmap.load(":/dancer/img/dancer/dancer_1n3.png");
            ui->Dancer1->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_2n3.png");
            ui->Dancer2->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_3n3.png");
            ui->Dancer3->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_4n3.png");
            ui->Dancer4->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_5n3.png");
            ui->Dancer5->setPixmap(pixmap);
        break;
        case 19:
            pixmap.load(":/dancer/img/dancer/dancer_1n4.png");
            ui->Dancer1->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_2n4.png");
            ui->Dancer2->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_3n4.png");
            ui->Dancer3->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_4n4.png");
            ui->Dancer4->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_5n4.png");
            ui->Dancer5->setPixmap(pixmap);
        break;
        case 20:
            pixmap.load(":/dancer/img/dancer/dancer_1n5.png");
            ui->Dancer1->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_2n5.png");
            ui->Dancer2->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_3n5.png");
            ui->Dancer3->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_4n5.png");
            ui->Dancer4->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_5n5.png");
            ui->Dancer5->setPixmap(pixmap);
        break;
        case 21:
            pixmap.load(":/dancer/img/dancer/dancer_1n6.png");
            ui->Dancer1->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_2n6.png");
            ui->Dancer2->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_3n6.png");
            ui->Dancer3->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_4n6.png");
            ui->Dancer4->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_5n6.png");
            ui->Dancer5->setPixmap(pixmap);
        break;
        case 22:
            pixmap.load(":/dancer/img/dancer/dancer_1n7.png");
            ui->Dancer1->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_2n7.png");
            ui->Dancer2->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_3n7.png");
            ui->Dancer3->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_4n7.png");
            ui->Dancer4->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_5n7.png");
            ui->Dancer5->setPixmap(pixmap);
        break;
        case 23:
            pixmap.load(":/dancer/img/dancer/dancer_1n8.png");
            ui->Dancer1->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_2n8.png");
            ui->Dancer2->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_3n8.png");
            ui->Dancer3->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_4n8.png");
            ui->Dancer4->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_5n8.png");
            ui->Dancer5->setPixmap(pixmap);
        break;
        case 24:
            pixmap.load(":/dancer/img/dancer/dancer_1n9.png");
            ui->Dancer1->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_2n9.png");
            ui->Dancer2->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_3n9.png");
            ui->Dancer3->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_4n9.png");
            ui->Dancer4->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_5n9.png");
            ui->Dancer5->setPixmap(pixmap);
        break;
        case 25:
            pixmap.load(":/dancer/img/dancer/dancer_1n10.png");
            ui->Dancer1->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_2n10.png");
            ui->Dancer2->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_3n10.png");
            ui->Dancer3->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_4n10.png");
            ui->Dancer4->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_5n10.png");
            ui->Dancer5->setPixmap(pixmap);
        break;
        case 26:
            pixmap.load(":/dancer/img/dancer/dancer_1n11.png");
            ui->Dancer1->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_2n11.png");
            ui->Dancer2->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_3n11.png");
            ui->Dancer3->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_4n11.png");
            ui->Dancer4->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_5n11.png");
            ui->Dancer5->setPixmap(pixmap);
        break;
        case 27:
            pixmap.load(":/dancer/img/dancer/dancer_1n12.png");
            ui->Dancer1->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_2n12.png");
            ui->Dancer2->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_3n12.png");
            ui->Dancer3->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_4n12.png");
            ui->Dancer4->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_5n12.png");
            ui->Dancer5->setPixmap(pixmap);
        break;
        case 28:
            pixmap.load(":/dancer/img/dancer/dancer_1n13.png");
            ui->Dancer1->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_2n13.png");
            ui->Dancer2->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_3n13.png");
            ui->Dancer3->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_4n13.png");
            ui->Dancer4->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_5n13.png");
            ui->Dancer5->setPixmap(pixmap);
        break;
        case 29:
            pixmap.load(":/dancer/img/dancer/dancer_1n14.png");
            ui->Dancer1->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_2n14.png");
            ui->Dancer2->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_3n14.png");
            ui->Dancer3->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_4n14.png");
            ui->Dancer4->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_5n14.png");
            ui->Dancer5->setPixmap(pixmap);
        break;
        case 30:
            pixmap.load(":/dancer/img/dancer/dancer_1n15.png");
            ui->Dancer1->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_2n15.png");
            ui->Dancer2->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_3n15.png");
            ui->Dancer3->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_4n15.png");
            ui->Dancer4->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_5n15.png");
            ui->Dancer5->setPixmap(pixmap);
        break;
        case 31:
            pixmap.load(":/dancer/img/dancer/dancer_1n16.png");
            ui->Dancer1->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_2n16.png");
            ui->Dancer2->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_3n16.png");
            ui->Dancer3->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_4n16.png");
            ui->Dancer4->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_5n16.png");
            ui->Dancer5->setPixmap(pixmap);
        break;
        case 32:
            pixmap.load(":/dancer/img/dancer/dancer_1d1.png");
            ui->Dancer1->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_2d1.png");
            ui->Dancer2->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_3d1.png");
            ui->Dancer3->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_4d1.png");
            ui->Dancer4->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_5d1.png");
            ui->Dancer5->setPixmap(pixmap);
        break;
        case 33:
            pixmap.load(":/dancer/img/dancer/dancer_1d2.png");
            ui->Dancer1->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_2d2.png");
            ui->Dancer2->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_3d2.png");
            ui->Dancer3->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_4d2.png");
            ui->Dancer4->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_5d2.png");
            ui->Dancer5->setPixmap(pixmap);
        break;
        case 34:
            pixmap.load(":/dancer/img/dancer/dancer_1d3.png");
            ui->Dancer1->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_2d3.png");
            ui->Dancer2->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_3d3.png");
            ui->Dancer3->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_4d3.png");
            ui->Dancer4->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_5d3.png");
            ui->Dancer5->setPixmap(pixmap);
        break;
        case 35:
            pixmap.load(":/dancer/img/dancer/dancer_1d4.png");
            ui->Dancer1->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_2d4.png");
            ui->Dancer2->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_3d4.png");
            ui->Dancer3->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_4d4.png");
            ui->Dancer4->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_5d4.png");
            ui->Dancer5->setPixmap(pixmap);
        break;
        case 36:
            pixmap.load(":/dancer/img/dancer/dancer_1d5.png");
            ui->Dancer1->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_2d5.png");
            ui->Dancer2->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_3d5.png");
            ui->Dancer3->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_4d5.png");
            ui->Dancer4->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_5d5.png");
            ui->Dancer5->setPixmap(pixmap);
        break;
        case 37:
            pixmap.load(":/dancer/img/dancer/dancer_1d6.png");
            ui->Dancer1->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_2d6.png");
            ui->Dancer2->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_3d6.png");
            ui->Dancer3->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_4d6.png");
            ui->Dancer4->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_5d6.png");
            ui->Dancer5->setPixmap(pixmap);
        break;
        case 38:
            pixmap.load(":/dancer/img/dancer/dancer_1d7.png");
            ui->Dancer1->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_2d7.png");
            ui->Dancer2->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_3d7.png");
            ui->Dancer3->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_4d7.png");
            ui->Dancer4->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_5d7.png");
            ui->Dancer5->setPixmap(pixmap);
        break;
        case 39:
            pixmap.load(":/dancer/img/dancer/dancer_1d8.png");
            ui->Dancer1->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_2d8.png");
            ui->Dancer2->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_3d8.png");
            ui->Dancer3->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_4d8.png");
            ui->Dancer4->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_5d8.png");
            ui->Dancer5->setPixmap(pixmap);
        break;
        case 40:
            pixmap.load(":/dancer/img/dancer/dancer_1d9.png");
            ui->Dancer1->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_2d9.png");
            ui->Dancer2->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_3d9.png");
            ui->Dancer3->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_4d9.png");
            ui->Dancer4->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_5d9.png");
            ui->Dancer5->setPixmap(pixmap);
        break;
        case 41:
            pixmap.load(":/dancer/img/dancer/dancer_1d10.png");
            ui->Dancer1->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_2d10.png");
            ui->Dancer2->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_3d10.png");
            ui->Dancer3->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_4d10.png");
            ui->Dancer4->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_5d10.png");
            ui->Dancer5->setPixmap(pixmap);
        break;
        case 42:
            pixmap.load(":/dancer/img/dancer/dancer_1d11.png");
            ui->Dancer1->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_2d11.png");
            ui->Dancer2->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_3d11.png");
            ui->Dancer3->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_4d11.png");
            ui->Dancer4->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_5d11.png");
            ui->Dancer5->setPixmap(pixmap);
        break;
        case 43:
            pixmap.load(":/dancer/img/dancer/dancer_1d12.png");
            ui->Dancer1->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_2d12.png");
            ui->Dancer2->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_3d12.png");
            ui->Dancer3->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_4d12.png");
            ui->Dancer4->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_5d12.png");
            ui->Dancer5->setPixmap(pixmap);
        break;
        case 44:
            pixmap.load(":/dancer/img/dancer/dancer_1d13.png");
            ui->Dancer1->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_2d13.png");
            ui->Dancer2->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_3d13.png");
            ui->Dancer3->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_4d13.png");
            ui->Dancer4->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_5d13.png");
            ui->Dancer5->setPixmap(pixmap);
        break;
        case 45:
            pixmap.load(":/dancer/img/dancer/dancer_1d14.png");
            ui->Dancer1->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_2d14.png");
            ui->Dancer2->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_3d14.png");
            ui->Dancer3->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_4d14.png");
            ui->Dancer4->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_5d14.png");
            ui->Dancer5->setPixmap(pixmap);
        break;
        case 46:
            pixmap.load(":/dancer/img/dancer/dancer_1d15.png");
            ui->Dancer1->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_2d15.png");
            ui->Dancer2->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_3d15.png");
            ui->Dancer3->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_4d15.png");
            ui->Dancer4->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_5d15.png");
            ui->Dancer5->setPixmap(pixmap);
        break;
        case 47:
            pixmap.load(":/dancer/img/dancer/dancer_1d16.png");
            ui->Dancer1->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_2d16.png");
            ui->Dancer2->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_3d16.png");
            ui->Dancer3->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_4d16.png");
            ui->Dancer4->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_5d16.png");
            ui->Dancer5->setPixmap(pixmap);
        break;
        default: ;
    }
    if(Now_time == 1400)
    {
        ui->Play_background1->hide();
        ui->Play_background2->show();
    }
    //金探子
    if(Drum_Gold_Life > Drum_Gold_Period){
        ui->Drum_Gold->show();
        Drum_Gold_Period = rand()%2000+500;
        Drum_Gold_Life = 0;
    }
    //時間到之後
    if(Now_time>2000)
    {
        Score=Score>999?999999:Score*1000;
        timer->stop();
        IsPlaying=false;
        ui->Drum_Button1->hide();
        ui->Drum_Button2->hide();
        ui->Drum_Button3->hide();
        ui->Drum_Button4->hide();
        ui->Drum_Button5->hide();
        ui->Drum_Button6->hide();
        ui->Drum_Button7->hide();
        ui->Drum_Button8->hide();
        ui->Hit_Drum_Position->hide();
        ui->Play_background2->hide();
        ui->Combo_Image->hide();
        ui->Drum_Man1->hide();
        ui->Drum_Man2->hide();
        ui->Drum_Man3->hide();
        ui->Drum_Man4->hide();
        ui->Time_Life->hide();
        ui->Num2_0->hide();
        ui->Dancer1->hide();
        ui->Dancer2->hide();
        ui->Dancer3->hide();
        ui->Dancer4->hide();
        ui->Dancer5->hide();
        ui->Hit_Point1->hide();
        ui->Hit_Point2->hide();
        ui->Hit_Point3->hide();
        ui->Num1_0->hide();ui->Num1_00->hide();
        ui->Num1_1->hide();ui->Num1_10->hide();
        ui->Num1_2->hide();ui->Num1_20->hide();
        ui->Num1_3->hide();ui->Num1_30->hide();
        ui->Num1_4->hide();ui->Num1_40->hide();
        ui->Num1_5->hide();ui->Num1_50->hide();
        ui->Num1_6->hide();ui->Num1_60->hide();
        ui->Num1_7->hide();ui->Num1_70->hide();
        ui->Num1_8->hide();ui->Num1_80->hide();
        ui->Num1_9->hide();ui->Num1_90->hide();
        ui->Drum_Gold->hide();
        ui->Combo_Image->hide();
        ui->Exit_Button->show();
        ui->Replay_Button->show();
        ui->Dead_Background->show();
        Music->stop();
        ui->Dancer_Ugly1->hide();
        ui->Dancer_Ugly2->hide();
        movie->stop();
        movie1->stop();
        Show_Score->setText("Score:" + QString::number(Score));
        view->show();
    }
}

void MainWindow::On_OK_Button_clicked()
{
    QMessageBox::information(this,"LOL","Thanks for enter your name, but I won't record it.");
    view->close();
}

void MainWindow::On_Cancel_Button_clicked()
{
    QMessageBox::information(this,"Please","Do you really not want to enter your name?");
    view->close();
    view->show();
}

void MainWindow::on_Start_Button_clicked()
{
    srand(time(NULL));
    ui->Start_Button->hide();
    ui->Start_Menu->hide();
    ui->Exit_Button->hide();
    ui->Play_background1->show();
    ui->Drum_Button1->show();
    ui->Drum_Button2->show();
    ui->Drum_Button3->show();
    ui->Drum_Button4->show();
    ui->Drum_Button5->show();
    ui->Drum_Button6->show();
    ui->Drum_Button7->show();
    ui->Drum_Button8->show();
    ui->Hit_Drum_Position->show();
    ui->Drum_Man1->show();
    ui->Drum_Man2->show();
    ui->Time_Life->show();
    ui->Num2_0->show();
    ui->Num2_30->show();
    ui->Fix_Num1->show();
    ui->Fix_Num2->show();
    ui->Fix_Num3->show();
    ui->Num3_0->show();
    ui->Num3_00->show();
    ui->Num3_000->show();
    ui->Life_Green->show();
    ui->Life_Red->show();
    ui->Dancer1->show();
    ui->Dancer2->show();
    ui->Dancer3->show();
    ui->Dancer4->show();
    ui->Dancer5->show();
    Music->play();
    Drum_Gold_Period=rand()%2000+500;
    if(Play_Mode==1)
    {
        ui->Drum_Button1->move(QPoint(rand()%1280*862%1280,rand()%1280*432%730));
        ui->Drum_Button2->move(QPoint(rand()%1280*462%1280,rand()%1280*411%730));
        ui->Drum_Button3->move(QPoint(rand()%1280*471%1280,rand()%1280*743%730));
        ui->Drum_Button4->move(QPoint(rand()%1280*666%1280,rand()%1280*138%730));
        ui->Drum_Button5->move(QPoint(rand()%1280*213%1280,rand()%1280*178%730));
        ui->Drum_Button6->move(QPoint(rand()%1280*971%1280,rand()%1280*756%730));
        ui->Drum_Button7->move(QPoint(rand()%1280*144%1280,rand()%1280*123%730));
        ui->Drum_Button8->move(QPoint(rand()%1280*678%1280,rand()%1280*887%730));
    }
    IsPlaying=true;
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(MySlot()));
    timer->start(15);
}

void MainWindow::on_Exit_Button_clicked()
{
    close();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape)
        close();
    if(!IsPlaying) event->ignore();
    else{
        if(event->key() == Qt::Key_F || event->key() == Qt::Key_D)
    {
        srand(time(NULL));
        Jump->stop();
        Jump->play();
        IsShow_Combo=false;
        Red_Drum_Life=4;
        if(event->key() == Qt::Key_D)
        {
            ui->Hit_Drum_Red1->show();
            ui->Drum_Man1->show();
            ui->Drum_Man2->hide();
            ui->Drum_Man3->hide();
            ui->Drum_Man4->hide();
        }
        else
        {
            ui->Hit_Drum_Red2->show();
            ui->Drum_Man3->show();
            ui->Drum_Man1->hide();
            ui->Drum_Man2->hide();
            ui->Drum_Man4->hide();
        }

        int x1 = ui->Drum_Button1->x();
        int x2 = ui->Drum_Button2->x();
        int x3 = ui->Drum_Button3->x();
        int x4 = ui->Drum_Button4->x();
        int y1 = ui->Drum_Button1->y();
        int y2 = ui->Drum_Button2->y();
        int y3 = ui->Drum_Button3->y();
        int y4 = ui->Drum_Button4->y();
        if(x1>=260-Drum_Size*10 && x1<=370+Drum_Size*5)
        {
            ui->Drum_Button1->move(QPoint(rand()%1400*1975%1400+1400,y1));
            ++Combo;
            Combo_Sign_Life=20;
            if(x1>=295-Drum_Size*10 && x1<=335+Drum_Size*5)
            {
                ui->Hit_Point1->show();
                ui->Hit_Point2->hide();
                ui->Hit_Point3->hide();
                Score+=2+(Combo/10)*2;
            }
            else
            {
                ui->Hit_Point2->show();
                ui->Hit_Point1->hide();
                ui->Hit_Point3->hide();
                Score+=1+(Combo/10)*1;
            }
        }
        else if(x2>=260-Drum_Size*10 && x2<=370+Drum_Size*5)
        {
            ui->Drum_Button2->move(QPoint(rand()%1400*3482%1400+1400,y2));
            ++Combo;
            Combo_Sign_Life=20;
            if(x2>=295-Drum_Size*10 && x2<=335+Drum_Size*5)
            {
                ui->Hit_Point1->show();
                ui->Hit_Point2->hide();
                ui->Hit_Point3->hide();
                Score+=2+(Combo/10)*2;
            }
            else
            {
                ui->Hit_Point2->show();
                ui->Hit_Point1->hide();
                ui->Hit_Point3->hide();
                Score+=1+(Combo/10)*1;
            }
        }
        else if(x3>=260-Drum_Size*10 && x3<=370+Drum_Size*5)
        {
            ui->Drum_Button3->move(QPoint(rand()%1400*7642%1400+1400,y3));
            ++Combo;
            Combo_Sign_Life=20;
            if(x3>=295-Drum_Size*10 && x3<=335+Drum_Size*5)
            {
                ui->Hit_Point1->show();
                ui->Hit_Point2->hide();
                ui->Hit_Point3->hide();
                Score+=2+(Combo/10)*2;
            }
            else
            {
                ui->Hit_Point2->show();
                ui->Hit_Point1->hide();
                ui->Hit_Point3->hide();
                Score+=1+(Combo/10)*1;
            }
        }
        else if(x4>=260-Drum_Size*10 && x4<=370+Drum_Size*5)
        {
            ui->Drum_Button4->move(QPoint(rand()%1400*1825%1400+1400,y4));
            ++Combo;
            Combo_Sign_Life=20;
            if(x4>=295-Drum_Size*10 && x4<=335+Drum_Size*5)
            {
                ui->Hit_Point1->show();
                ui->Hit_Point2->hide();
                ui->Hit_Point3->hide();
                Score+=2+(Combo/10)*2;
            }
            else
            {
                ui->Hit_Point2->show();
                ui->Hit_Point1->hide();
                ui->Hit_Point3->hide();
                Score+=1+(Combo/10)*1;
            }
        }
        else
        {
            ui->Hit_Point3->show();
            ui->Hit_Point1->hide();
            ui->Hit_Point2->hide();
            Combo=0;
        }
        //分數
        {
            switch(Score%10)
            {
                case 0:
                    ui->Num3_0->show();
                    ui->Num3_1->hide();
                    ui->Num3_2->hide();
                    ui->Num3_3->hide();
                    ui->Num3_4->hide();
                    ui->Num3_5->hide();
                    ui->Num3_6->hide();
                    ui->Num3_7->hide();
                    ui->Num3_8->hide();
                    ui->Num3_9->hide();
                break;
                case 1:
                    ui->Num3_1->show();
                    ui->Num3_0->hide();
                    ui->Num3_2->hide();
                    ui->Num3_3->hide();
                    ui->Num3_4->hide();
                    ui->Num3_5->hide();
                    ui->Num3_6->hide();
                    ui->Num3_7->hide();
                    ui->Num3_8->hide();
                    ui->Num3_9->hide();
                break;
                case 2:
                    ui->Num3_2->show();
                    ui->Num3_0->hide();
                    ui->Num3_1->hide();
                    ui->Num3_3->hide();
                    ui->Num3_4->hide();
                    ui->Num3_5->hide();
                    ui->Num3_6->hide();
                    ui->Num3_7->hide();
                    ui->Num3_8->hide();
                    ui->Num3_9->hide();
                break;
                case 3:
                    ui->Num3_3->show();
                    ui->Num3_0->hide();
                    ui->Num3_1->hide();
                    ui->Num3_2->hide();
                    ui->Num3_4->hide();
                    ui->Num3_5->hide();
                    ui->Num3_6->hide();
                    ui->Num3_7->hide();
                    ui->Num3_8->hide();
                    ui->Num3_9->hide();
                break;
                case 4:
                    ui->Num3_4->show();
                    ui->Num3_0->hide();
                    ui->Num3_1->hide();
                    ui->Num3_2->hide();
                    ui->Num3_3->hide();
                    ui->Num3_5->hide();
                    ui->Num3_6->hide();
                    ui->Num3_7->hide();
                    ui->Num3_8->hide();
                    ui->Num3_9->hide();
                break;
                case 5:
                    ui->Num3_5->show();
                    ui->Num3_0->hide();
                    ui->Num3_1->hide();
                    ui->Num3_2->hide();
                    ui->Num3_3->hide();
                    ui->Num3_4->hide();
                    ui->Num3_6->hide();
                    ui->Num3_7->hide();
                    ui->Num3_8->hide();
                    ui->Num3_9->hide();
                break;
                case 6:
                    ui->Num3_6->show();
                    ui->Num3_0->hide();
                    ui->Num3_1->hide();
                    ui->Num3_2->hide();
                    ui->Num3_3->hide();
                    ui->Num3_4->hide();
                    ui->Num3_5->hide();
                    ui->Num3_7->hide();
                    ui->Num3_8->hide();
                    ui->Num3_9->hide();
                break;
                case 7:
                    ui->Num3_7->show();
                    ui->Num3_0->hide();
                    ui->Num3_1->hide();
                    ui->Num3_2->hide();
                    ui->Num3_3->hide();
                    ui->Num3_4->hide();
                    ui->Num3_5->hide();
                    ui->Num3_6->hide();
                    ui->Num3_8->hide();
                    ui->Num3_9->hide();
                break;
                case 8:
                    ui->Num3_8->show();
                    ui->Num3_0->hide();
                    ui->Num3_1->hide();
                    ui->Num3_2->hide();
                    ui->Num3_3->hide();
                    ui->Num3_4->hide();
                    ui->Num3_5->hide();
                    ui->Num3_6->hide();
                    ui->Num3_7->hide();
                    ui->Num3_9->hide();
                break;
                case 9:
                    ui->Num3_9->show();
                    ui->Num3_0->hide();
                    ui->Num3_1->hide();
                    ui->Num3_2->hide();
                    ui->Num3_3->hide();
                    ui->Num3_4->hide();
                    ui->Num3_5->hide();
                    ui->Num3_6->hide();
                    ui->Num3_7->hide();
                    ui->Num3_8->hide();
                break;
                default: ;
            }
            switch(Score/10%10)
            {
                case 0:
                    ui->Num3_00->show();
                    ui->Num3_10->hide();
                    ui->Num3_20->hide();
                    ui->Num3_30->hide();
                    ui->Num3_40->hide();
                    ui->Num3_50->hide();
                    ui->Num3_60->hide();
                    ui->Num3_70->hide();
                    ui->Num3_80->hide();
                    ui->Num3_90->hide();
                break;
                case 1:
                    ui->Num3_10->show();
                    ui->Num3_00->hide();
                    ui->Num3_20->hide();
                    ui->Num3_30->hide();
                    ui->Num3_40->hide();
                    ui->Num3_50->hide();
                    ui->Num3_60->hide();
                    ui->Num3_70->hide();
                    ui->Num3_80->hide();
                    ui->Num3_90->hide();
                break;
                case 2:
                    ui->Num3_20->show();
                    ui->Num3_00->hide();
                    ui->Num3_10->hide();
                    ui->Num3_30->hide();
                    ui->Num3_40->hide();
                    ui->Num3_50->hide();
                    ui->Num3_60->hide();
                    ui->Num3_70->hide();
                    ui->Num3_80->hide();
                    ui->Num3_90->hide();
                break;
                case 3:
                    ui->Num3_30->show();
                    ui->Num3_00->hide();
                    ui->Num3_10->hide();
                    ui->Num3_20->hide();
                    ui->Num3_40->hide();
                    ui->Num3_50->hide();
                    ui->Num3_60->hide();
                    ui->Num3_70->hide();
                    ui->Num3_80->hide();
                    ui->Num3_90->hide();
                break;
                case 4:
                    ui->Num3_40->show();
                    ui->Num3_00->hide();
                    ui->Num3_10->hide();
                    ui->Num3_20->hide();
                    ui->Num3_30->hide();
                    ui->Num3_50->hide();
                    ui->Num3_60->hide();
                    ui->Num3_70->hide();
                    ui->Num3_80->hide();
                    ui->Num3_90->hide();
                break;
                case 5:
                    ui->Num3_50->show();
                    ui->Num3_00->hide();
                    ui->Num3_10->hide();
                    ui->Num3_20->hide();
                    ui->Num3_30->hide();
                    ui->Num3_40->hide();
                    ui->Num3_60->hide();
                    ui->Num3_70->hide();
                    ui->Num3_80->hide();
                    ui->Num3_90->hide();
                break;
                case 6:
                    ui->Num3_60->show();
                    ui->Num3_00->hide();
                    ui->Num3_10->hide();
                    ui->Num3_20->hide();
                    ui->Num3_30->hide();
                    ui->Num3_40->hide();
                    ui->Num3_50->hide();
                    ui->Num3_70->hide();
                    ui->Num3_80->hide();
                    ui->Num3_90->hide();
                break;
                case 7:
                    ui->Num3_70->show();
                    ui->Num3_00->hide();
                    ui->Num3_10->hide();
                    ui->Num3_20->hide();
                    ui->Num3_30->hide();
                    ui->Num3_40->hide();
                    ui->Num3_50->hide();
                    ui->Num3_60->hide();
                    ui->Num3_80->hide();
                    ui->Num3_90->hide();
                break;
                case 8:
                    ui->Num3_80->show();
                    ui->Num3_00->hide();
                    ui->Num3_10->hide();
                    ui->Num3_20->hide();
                    ui->Num3_30->hide();
                    ui->Num3_40->hide();
                    ui->Num3_50->hide();
                    ui->Num3_60->hide();
                    ui->Num3_70->hide();
                    ui->Num3_90->hide();
                break;
                case 9:
                    ui->Num3_90->show();
                    ui->Num3_00->hide();
                    ui->Num3_10->hide();
                    ui->Num3_20->hide();
                    ui->Num3_30->hide();
                    ui->Num3_40->hide();
                    ui->Num3_50->hide();
                    ui->Num3_60->hide();
                    ui->Num3_70->hide();
                    ui->Num3_80->hide();
                break;
                default: ;
            }
            switch(Score/100)
            {
                case 0:
                    ui->Num3_000->show();
                    ui->Num3_900->hide();
                break;
                case 1:
                    ui->Num3_100->show();
                    ui->Num3_000->hide();
                break;
                case 2:
                    ui->Num3_200->show();
                    ui->Num3_100->hide();
                break;
                case 3:
                    ui->Num3_300->show();
                    ui->Num3_200->hide();
                break;
                case 4:
                    ui->Num3_400->show();
                    ui->Num3_300->hide();
                break;
                case 5:
                    ui->Num3_500->show();
                    ui->Num3_400->hide();
                break;
                case 6:
                    ui->Num3_600->show();
                    ui->Num3_500->hide();
                break;
                case 7:
                    ui->Num3_700->show();
                    ui->Num3_600->hide();
                break;
                case 8:
                    ui->Num3_800->show();
                    ui->Num3_700->hide();
                break;
                case 9:
                    ui->Num3_900->show();
                    ui->Num3_800->hide();
                break;
                default: ;
            }
        }
    }
        if(event->key() == Qt::Key_J || event->key() == Qt::Key_K)
    {
        srand(time(NULL));
        Jump->stop();
        Jump->play();
        IsShow_Combo=false;
        Blue_Drum_Life=4;
        if(event->key() == Qt::Key_J)
        {
            ui->Hit_Drum_Blue1->show();
            ui->Drum_Man4->show();
            ui->Drum_Man1->hide();
            ui->Drum_Man2->hide();
            ui->Drum_Man3->hide();
        }
        else
        {
            ui->Hit_Drum_Blue2->show();
            ui->Drum_Man2->show();
            ui->Drum_Man1->hide();
            ui->Drum_Man3->hide();
            ui->Drum_Man4->hide();
        }
        int x5 = ui->Drum_Button5->x();
        int x6 = ui->Drum_Button6->x();
        int x7 = ui->Drum_Button7->x();
        int x8 = ui->Drum_Button8->x();
        int y5 = ui->Drum_Button5->y();
        int y6 = ui->Drum_Button6->y();
        int y7 = ui->Drum_Button7->y();
        int y8 = ui->Drum_Button8->y();
        if(x5>=260-Drum_Size*10 && x5<=370+Drum_Size*5)
        {
            ui->Drum_Button5->move(QPoint(rand()%1400*8913%1400+1400,y5));
            ++Combo;
            Combo_Sign_Life=20;
            if(x5>=295-Drum_Size*10 && x5<=335+Drum_Size*5)
            {
                ui->Hit_Point1->show();
                ui->Hit_Point2->hide();
                ui->Hit_Point3->hide();
                Score+=2+(Combo/10)*2;
            }
            else
            {
                ui->Hit_Point2->show();
                ui->Hit_Point1->hide();
                ui->Hit_Point3->hide();
                Score+=1+(Combo/10)*1;
            }
        }
        else if(x6>=260-Drum_Size*10 && x6<=370+Drum_Size*5)
        {
            ui->Drum_Button6->move(QPoint(rand()%1400*5824%1400+1400,y6));
            ++Combo;
            Combo_Sign_Life=20;
            if(x6>=295-Drum_Size*10 && x6<=335+Drum_Size*5)
            {
                ui->Hit_Point1->show();
                ui->Hit_Point2->hide();
                ui->Hit_Point3->hide();
                Score+=2+(Combo/10)*2;
            }
            else
            {
                ui->Hit_Point2->show();
                ui->Hit_Point1->hide();
                ui->Hit_Point3->hide();
                Score+=1+(Combo/10)*1;
            }
        }
        else if(x7>=260-Drum_Size*10 && x7<=370+Drum_Size*5)
        {
            ui->Drum_Button7->move(QPoint(rand()%1400*7954%1400+1400,y7));
            ++Combo;
            Combo_Sign_Life=20;
            if(x7>=295-Drum_Size*10 && x7<=335+Drum_Size*5)
            {
                ui->Hit_Point1->show();
                ui->Hit_Point2->hide();
                ui->Hit_Point3->hide();
                Score+=2+(Combo/10)*2;
            }
            else
            {
                ui->Hit_Point2->show();
                ui->Hit_Point1->hide();
                ui->Hit_Point3->hide();
                Score+=1+(Combo/10)*1;
            }
        }
        else if(x8>=260-Drum_Size*10 && x8<=370+Drum_Size*5)
        {
            ui->Drum_Button8->move(QPoint(rand()%1400*8546%1400+1400,y8));
            ++Combo;
            Combo_Sign_Life=20;
            if(x8>=295-Drum_Size*10 && x8<=335+Drum_Size*5)
            {
                ui->Hit_Point1->show();
                ui->Hit_Point2->hide();
                ui->Hit_Point3->hide();
                Score+=2+(Combo/10)*2;
            }
            else
            {
                ui->Hit_Point2->show();
                ui->Hit_Point1->hide();
                ui->Hit_Point3->hide();
                Score+=1+(Combo/10)*1;
            }
        }
        else
        {
            ui->Hit_Point3->show();
            ui->Hit_Point2->hide();
            ui->Hit_Point3->hide();
            Combo=0;
        }
        //分數
        {
            switch(Score%10)
            {
                case 0:
                    ui->Num3_0->show();
                    ui->Num3_1->hide();
                    ui->Num3_2->hide();
                    ui->Num3_3->hide();
                    ui->Num3_4->hide();
                    ui->Num3_5->hide();
                    ui->Num3_6->hide();
                    ui->Num3_7->hide();
                    ui->Num3_8->hide();
                    ui->Num3_9->hide();
                break;
                case 1:
                    ui->Num3_1->show();
                    ui->Num3_0->hide();
                    ui->Num3_2->hide();
                    ui->Num3_3->hide();
                    ui->Num3_4->hide();
                    ui->Num3_5->hide();
                    ui->Num3_6->hide();
                    ui->Num3_7->hide();
                    ui->Num3_8->hide();
                    ui->Num3_9->hide();
                break;
                case 2:
                    ui->Num3_2->show();
                    ui->Num3_0->hide();
                    ui->Num3_1->hide();
                    ui->Num3_3->hide();
                    ui->Num3_4->hide();
                    ui->Num3_5->hide();
                    ui->Num3_6->hide();
                    ui->Num3_7->hide();
                    ui->Num3_8->hide();
                    ui->Num3_9->hide();
                break;
                case 3:
                    ui->Num3_3->show();
                    ui->Num3_0->hide();
                    ui->Num3_1->hide();
                    ui->Num3_2->hide();
                    ui->Num3_4->hide();
                    ui->Num3_5->hide();
                    ui->Num3_6->hide();
                    ui->Num3_7->hide();
                    ui->Num3_8->hide();
                    ui->Num3_9->hide();
                break;
                case 4:
                    ui->Num3_4->show();
                    ui->Num3_0->hide();
                    ui->Num3_1->hide();
                    ui->Num3_2->hide();
                    ui->Num3_3->hide();
                    ui->Num3_5->hide();
                    ui->Num3_6->hide();
                    ui->Num3_7->hide();
                    ui->Num3_8->hide();
                    ui->Num3_9->hide();
                break;
                case 5:
                    ui->Num3_5->show();
                    ui->Num3_0->hide();
                    ui->Num3_1->hide();
                    ui->Num3_2->hide();
                    ui->Num3_3->hide();
                    ui->Num3_4->hide();
                    ui->Num3_6->hide();
                    ui->Num3_7->hide();
                    ui->Num3_8->hide();
                    ui->Num3_9->hide();
                break;
                case 6:
                    ui->Num3_6->show();
                    ui->Num3_0->hide();
                    ui->Num3_1->hide();
                    ui->Num3_2->hide();
                    ui->Num3_3->hide();
                    ui->Num3_4->hide();
                    ui->Num3_5->hide();
                    ui->Num3_7->hide();
                    ui->Num3_8->hide();
                    ui->Num3_9->hide();
                break;
                case 7:
                    ui->Num3_7->show();
                    ui->Num3_0->hide();
                    ui->Num3_1->hide();
                    ui->Num3_2->hide();
                    ui->Num3_3->hide();
                    ui->Num3_4->hide();
                    ui->Num3_5->hide();
                    ui->Num3_6->hide();
                    ui->Num3_8->hide();
                    ui->Num3_9->hide();
                break;
                case 8:
                    ui->Num3_8->show();
                    ui->Num3_0->hide();
                    ui->Num3_1->hide();
                    ui->Num3_2->hide();
                    ui->Num3_3->hide();
                    ui->Num3_4->hide();
                    ui->Num3_5->hide();
                    ui->Num3_6->hide();
                    ui->Num3_7->hide();
                    ui->Num3_9->hide();
                break;
                case 9:
                    ui->Num3_9->show();
                    ui->Num3_0->hide();
                    ui->Num3_1->hide();
                    ui->Num3_2->hide();
                    ui->Num3_3->hide();
                    ui->Num3_4->hide();
                    ui->Num3_5->hide();
                    ui->Num3_6->hide();
                    ui->Num3_7->hide();
                    ui->Num3_8->hide();
                break;
                default: ;
            }
            switch(Score/10%10)
            {
                case 0:
                    ui->Num3_00->show();
                    ui->Num3_10->hide();
                    ui->Num3_20->hide();
                    ui->Num3_30->hide();
                    ui->Num3_40->hide();
                    ui->Num3_50->hide();
                    ui->Num3_60->hide();
                    ui->Num3_70->hide();
                    ui->Num3_80->hide();
                    ui->Num3_90->hide();
                break;
                case 1:
                    ui->Num3_10->show();
                    ui->Num3_00->hide();
                    ui->Num3_20->hide();
                    ui->Num3_30->hide();
                    ui->Num3_40->hide();
                    ui->Num3_50->hide();
                    ui->Num3_60->hide();
                    ui->Num3_70->hide();
                    ui->Num3_80->hide();
                    ui->Num3_90->hide();
                break;
                case 2:
                    ui->Num3_20->show();
                    ui->Num3_00->hide();
                    ui->Num3_10->hide();
                    ui->Num3_30->hide();
                    ui->Num3_40->hide();
                    ui->Num3_50->hide();
                    ui->Num3_60->hide();
                    ui->Num3_70->hide();
                    ui->Num3_80->hide();
                    ui->Num3_90->hide();
                break;
                case 3:
                    ui->Num3_30->show();
                    ui->Num3_00->hide();
                    ui->Num3_10->hide();
                    ui->Num3_20->hide();
                    ui->Num3_40->hide();
                    ui->Num3_50->hide();
                    ui->Num3_60->hide();
                    ui->Num3_70->hide();
                    ui->Num3_80->hide();
                    ui->Num3_90->hide();
                break;
                case 4:
                    ui->Num3_40->show();
                    ui->Num3_00->hide();
                    ui->Num3_10->hide();
                    ui->Num3_20->hide();
                    ui->Num3_30->hide();
                    ui->Num3_50->hide();
                    ui->Num3_60->hide();
                    ui->Num3_70->hide();
                    ui->Num3_80->hide();
                    ui->Num3_90->hide();
                break;
                case 5:
                    ui->Num3_50->show();
                    ui->Num3_00->hide();
                    ui->Num3_10->hide();
                    ui->Num3_20->hide();
                    ui->Num3_30->hide();
                    ui->Num3_40->hide();
                    ui->Num3_60->hide();
                    ui->Num3_70->hide();
                    ui->Num3_80->hide();
                    ui->Num3_90->hide();
                break;
                case 6:
                    ui->Num3_60->show();
                    ui->Num3_00->hide();
                    ui->Num3_10->hide();
                    ui->Num3_20->hide();
                    ui->Num3_30->hide();
                    ui->Num3_40->hide();
                    ui->Num3_50->hide();
                    ui->Num3_70->hide();
                    ui->Num3_80->hide();
                    ui->Num3_90->hide();
                break;
                case 7:
                    ui->Num3_70->show();
                    ui->Num3_00->hide();
                    ui->Num3_10->hide();
                    ui->Num3_20->hide();
                    ui->Num3_30->hide();
                    ui->Num3_40->hide();
                    ui->Num3_50->hide();
                    ui->Num3_60->hide();
                    ui->Num3_80->hide();
                    ui->Num3_90->hide();
                break;
                case 8:
                    ui->Num3_80->show();
                    ui->Num3_00->hide();
                    ui->Num3_10->hide();
                    ui->Num3_20->hide();
                    ui->Num3_30->hide();
                    ui->Num3_40->hide();
                    ui->Num3_50->hide();
                    ui->Num3_60->hide();
                    ui->Num3_70->hide();
                    ui->Num3_90->hide();
                break;
                case 9:
                    ui->Num3_90->show();
                    ui->Num3_00->hide();
                    ui->Num3_10->hide();
                    ui->Num3_20->hide();
                    ui->Num3_30->hide();
                    ui->Num3_40->hide();
                    ui->Num3_50->hide();
                    ui->Num3_60->hide();
                    ui->Num3_70->hide();
                    ui->Num3_80->hide();
                break;
                default: ;
            }
            switch(Score/100)
            {
                case 0:
                    ui->Num3_000->show();
                    ui->Num3_900->hide();
                break;
                case 1:
                    ui->Num3_100->show();
                    ui->Num3_000->hide();
                break;
                case 2:
                    ui->Num3_200->show();
                    ui->Num3_100->hide();
                break;
                case 3:
                    ui->Num3_300->show();
                    ui->Num3_200->hide();
                break;
                case 4:
                    ui->Num3_400->show();
                    ui->Num3_300->hide();
                break;
                case 5:
                    ui->Num3_500->show();
                    ui->Num3_400->hide();
                break;
                case 6:
                    ui->Num3_600->show();
                    ui->Num3_500->hide();
                break;
                case 7:
                    ui->Num3_700->show();
                    ui->Num3_600->hide();
                break;
                case 8:
                    ui->Num3_800->show();
                    ui->Num3_700->hide();
                break;
                case 9:
                    ui->Num3_900->show();
                    ui->Num3_800->hide();
                break;
                default: ;
            }
        }
    }
        if(event->key() == Qt::Key_Control)
    {
        if(IsPause)
        {
            timer->start(15);
            ui->Pause_Message->hide();
            IsPause=false;
        }
        else
        {
            timer->stop();
            ui->Pause_Message->show();
            IsPause=true;
        }
    }
        if(event->key() == Qt::Key_Minus)
    {
        if(Speed_Level<2)
        {
            event->ignore();
        }
        else
        {
            --Speed_Level;
        }
    }
        if(event->key() == Qt::Key_Plus)
    {
        if(Speed_Level > 20)
        {
            event->ignore();
        }
        else
        {
            ++Speed_Level;

        }
    }
        if(event->key() == Qt::Key_G)
        {
            if(Drum_Size<30)
            {
                ++Drum_Size;
                int x1 = ui->Drum_Button1->x();
                int y1 = ui->Drum_Button1->y();
                int x2 = ui->Drum_Button2->x();
                int y2 = ui->Drum_Button2->y();
                int x3 = ui->Drum_Button3->x();
                int y3 = ui->Drum_Button3->y();
                int x4 = ui->Drum_Button4->x();
                int y4 = ui->Drum_Button4->y();
                int x5 = ui->Drum_Button5->x();
                int y5 = ui->Drum_Button5->y();
                int x6 = ui->Drum_Button6->x();
                int y6 = ui->Drum_Button6->y();
                int x7 = ui->Drum_Button7->x();
                int y7 = ui->Drum_Button7->y();
                int x8 = ui->Drum_Button8->x();
                int y8 = ui->Drum_Button8->y();
                ui->Drum_Button1->setIconSize(QSize(120+10*Drum_Size,120+10*Drum_Size));
                ui->Drum_Button2->setIconSize(QSize(120+10*Drum_Size,120+10*Drum_Size));
                ui->Drum_Button3->setIconSize(QSize(120+10*Drum_Size,120+10*Drum_Size));
                ui->Drum_Button4->setIconSize(QSize(120+10*Drum_Size,120+10*Drum_Size));
                ui->Drum_Button5->setIconSize(QSize(120+10*Drum_Size,120+10*Drum_Size));
                ui->Drum_Button6->setIconSize(QSize(120+10*Drum_Size,120+10*Drum_Size));
                ui->Drum_Button7->setIconSize(QSize(120+10*Drum_Size,120+10*Drum_Size));
                ui->Drum_Button8->setIconSize(QSize(120+10*Drum_Size,120+10*Drum_Size));
                ui->Drum_Button1->setGeometry(QRect(x1-5,y1-5,120+10*Drum_Size,120+10*Drum_Size));
                ui->Drum_Button2->setGeometry(QRect(x2-5,y2-5,120+10*Drum_Size,120+10*Drum_Size));
                ui->Drum_Button3->setGeometry(QRect(x3-5,y3-5,120+10*Drum_Size,120+10*Drum_Size));
                ui->Drum_Button4->setGeometry(QRect(x4-5,y4-5,120+10*Drum_Size,120+10*Drum_Size));
                ui->Drum_Button5->setGeometry(QRect(x5-5,y5-5,120+10*Drum_Size,120+10*Drum_Size));
                ui->Drum_Button6->setGeometry(QRect(x6-5,y6-5,120+10*Drum_Size,120+10*Drum_Size));
                ui->Drum_Button7->setGeometry(QRect(x7-5,y7-5,120+10*Drum_Size,120+10*Drum_Size));
                ui->Drum_Button8->setGeometry(QRect(x8-5,y8-5,120+10*Drum_Size,120+10*Drum_Size));
            }
        }
        if(event->key() == Qt::Key_H)
        {
            if(Drum_Size>-30)
            {
                --Drum_Size;
                int x1 = ui->Drum_Button1->x();
                int y1 = ui->Drum_Button1->y();
                int x2 = ui->Drum_Button2->x();
                int y2 = ui->Drum_Button2->y();
                int x3 = ui->Drum_Button3->x();
                int y3 = ui->Drum_Button3->y();
                int x4 = ui->Drum_Button4->x();
                int y4 = ui->Drum_Button4->y();
                int x5 = ui->Drum_Button5->x();
                int y5 = ui->Drum_Button5->y();
                int x6 = ui->Drum_Button6->x();
                int y6 = ui->Drum_Button6->y();
                int x7 = ui->Drum_Button7->x();
                int y7 = ui->Drum_Button7->y();
                int x8 = ui->Drum_Button8->x();
                int y8 = ui->Drum_Button8->y();
                ui->Drum_Button1->setIconSize(QSize(120+10*Drum_Size,120+10*Drum_Size));
                ui->Drum_Button2->setIconSize(QSize(120+10*Drum_Size,120+10*Drum_Size));
                ui->Drum_Button3->setIconSize(QSize(120+10*Drum_Size,120+10*Drum_Size));
                ui->Drum_Button4->setIconSize(QSize(120+10*Drum_Size,120+10*Drum_Size));
                ui->Drum_Button5->setIconSize(QSize(120+10*Drum_Size,120+10*Drum_Size));
                ui->Drum_Button6->setIconSize(QSize(120+10*Drum_Size,120+10*Drum_Size));
                ui->Drum_Button7->setIconSize(QSize(120+10*Drum_Size,120+10*Drum_Size));
                ui->Drum_Button8->setIconSize(QSize(120+10*Drum_Size,120+10*Drum_Size));
                qDebug() << Drum_Size;
                ui->Drum_Button1->setGeometry(QRect(x1+5,y1+5,120+10*Drum_Size,120+10*Drum_Size));
                ui->Drum_Button2->setGeometry(QRect(x2+5,y2+5,120+10*Drum_Size,120+10*Drum_Size));
                ui->Drum_Button3->setGeometry(QRect(x3+5,y3+5,120+10*Drum_Size,120+10*Drum_Size));
                ui->Drum_Button4->setGeometry(QRect(x4+5,y4+5,120+10*Drum_Size,120+10*Drum_Size));
                ui->Drum_Button5->setGeometry(QRect(x5+5,y5+5,120+10*Drum_Size,120+10*Drum_Size));
                ui->Drum_Button6->setGeometry(QRect(x6+5,y6+5,120+10*Drum_Size,120+10*Drum_Size));
                ui->Drum_Button7->setGeometry(QRect(x7+5,y7+5,120+10*Drum_Size,120+10*Drum_Size));
                ui->Drum_Button8->setGeometry(QRect(x8+5,y8+5,120+10*Drum_Size,120+10*Drum_Size));
            }
        }
        if(event->key() == Qt::Key_Z)
        {
            switch(Play_Mode)
            {
                case 0:
                    Play_Mode=1;
                    ui->Drum_Button1->move(QPoint(rand()%1280*232%1280,rand()%1280*992%730));
                    ui->Drum_Button2->move(QPoint(rand()%1280*182%1280,rand()%1280*911%730));
                    ui->Drum_Button3->move(QPoint(rand()%1280*911%1280,rand()%1280*193%730));
                    ui->Drum_Button4->move(QPoint(rand()%1280*236%1280,rand()%1280*228%730));
                    ui->Drum_Button5->move(QPoint(rand()%1280*553%1280,rand()%1280*888%730));
                    ui->Drum_Button6->move(QPoint(rand()%1280*671%1280,rand()%1280*186%730));
                    ui->Drum_Button7->move(QPoint(rand()%1280*774%1280,rand()%1280*463%730));
                    ui->Drum_Button8->move(QPoint(rand()%1280*188%1280,rand()%1280*647%730));
                    Impact[1]=Impact[2]=Impact[3]=Impact[4]=Impact[5]=Impact[6]=Impact[7]=Impact[8]=0;
                break;
                case 1:
                    Play_Mode=0;
                    Drum_Size=0;
                    ui->Drum_Button1->setIconSize(QSize(120,120));
                    ui->Drum_Button2->setIconSize(QSize(120,120));
                    ui->Drum_Button3->setIconSize(QSize(120,120));
                    ui->Drum_Button4->setIconSize(QSize(120,120));
                    ui->Drum_Button5->setIconSize(QSize(120,120));
                    ui->Drum_Button6->setIconSize(QSize(120,120));
                    ui->Drum_Button7->setIconSize(QSize(120,120));
                    ui->Drum_Button8->setIconSize(QSize(120,120));
                    ui->Drum_Button1->setGeometry(QRect(rand()%1400*8312%1400+1400,225,120,120));
                    ui->Drum_Button2->setGeometry(QRect(rand()%1400*1852%1400+1400,225,120,120));
                    ui->Drum_Button3->setGeometry(QRect(rand()%1400*7921%1400+1400,225,120,120));
                    ui->Drum_Button4->setGeometry(QRect(rand()%1400*9842%1400+1400,225,120,120));
                    ui->Drum_Button5->setGeometry(QRect(rand()%1400*1238%1400+1400,225,120,120));
                    ui->Drum_Button6->setGeometry(QRect(rand()%1400*5474%1400+1400,225,120,120));
                    ui->Drum_Button7->setGeometry(QRect(rand()%1400*6713%1400+1400,225,120,120));
                    ui->Drum_Button8->setGeometry(QRect(rand()%1400*7621%1400+1400,225,120,120));
                break;
                default:
                    Play_Mode=1;
                    ui->Drum_Button1->move(QPoint(rand()%1280*232%1280,rand()%1280*992%730));
                    ui->Drum_Button2->move(QPoint(rand()%1280*182%1280,rand()%1280*911%730));
                    ui->Drum_Button3->move(QPoint(rand()%1280*911%1280,rand()%1280*193%730));
                    ui->Drum_Button4->move(QPoint(rand()%1280*236%1280,rand()%1280*228%730));
                    ui->Drum_Button5->move(QPoint(rand()%1280*553%1280,rand()%1280*888%730));
                    ui->Drum_Button6->move(QPoint(rand()%1280*671%1280,rand()%1280*186%730));
                    ui->Drum_Button7->move(QPoint(rand()%1280*774%1280,rand()%1280*463%730));
                    ui->Drum_Button8->move(QPoint(rand()%1280*188%1280,rand()%1280*647%730));
                Impact[1]=Impact[2]=Impact[3]=Impact[4]=Impact[5]=Impact[6]=Impact[7]=Impact[8]=0;;
            }
            ui->Drum_Button1->show();
            ui->Drum_Button2->show();
            ui->Drum_Button3->show();
            ui->Drum_Button4->show();
            ui->Drum_Button5->show();
            ui->Drum_Button6->show();
            ui->Drum_Button7->show();
            ui->Drum_Button8->show();
        }
        if(event->key() == Qt::Key_X)
        {
            ui->Drum_Gold->show();
        }
        if(event->key() == Qt::Key_C)
        {
            if(IsDancer)
            {
                ui->Dancer_Ugly1->hide();
                ui->Dancer_Ugly2->hide();
                movie->stop();
                movie1->stop();
                IsDancer=false;
            }
            else
            {
                ui->Dancer_Ugly1->show();
                ui->Dancer_Ugly2->show();
                movie->start();
                movie1->start();
                IsDancer=true;
            }
        }
        if(event->key() == Qt::Key_F1)
        {
            timer->stop();
            IsPlaying=false;
            ui->Life_Green->hide();
            ui->Life_Red->hide();
            ui->Count_Num1->hide();
            ui->Count_Num2->hide();
            ui->Count_Num3->hide();
            ui->Drum_Button1->hide();
            ui->Drum_Button2->hide();
            ui->Drum_Button3->hide();
            ui->Drum_Button4->hide();
            ui->Drum_Button5->hide();
            ui->Drum_Button6->hide();
            ui->Drum_Button7->hide();
            ui->Drum_Button8->hide();
            ui->Hit_Drum_Position->hide();
            ui->Play_background2->hide();
            ui->Combo_Image->hide();
            ui->Drum_Man1->hide();
            ui->Drum_Man2->hide();
            ui->Drum_Man3->hide();
            ui->Drum_Man4->hide();
            ui->Time_Life->hide();
            ui->Num2_0->hide();
            ui->Dancer1->hide();
            ui->Dancer2->hide();
            ui->Dancer3->hide();
            ui->Dancer4->hide();
            ui->Dancer5->hide();
            ui->Hit_Point1->hide();
            ui->Hit_Point2->hide();
            ui->Hit_Point3->hide();
            ui->Num1_0->hide();ui->Num1_00->hide();
            ui->Num1_1->hide();ui->Num1_10->hide();
            ui->Num1_2->hide();ui->Num1_20->hide();
            ui->Num1_3->hide();ui->Num1_30->hide();
            ui->Num1_4->hide();ui->Num1_40->hide();
            ui->Num1_5->hide();ui->Num1_50->hide();
            ui->Num1_6->hide();ui->Num1_60->hide();
            ui->Num1_7->hide();ui->Num1_70->hide();
            ui->Num1_8->hide();ui->Num1_80->hide();
            ui->Num1_9->hide();ui->Num1_90->hide();
            ui->Num2_0->hide();ui->Num2_00->hide();
            ui->Num2_1->hide();ui->Num2_10->hide();
            ui->Num2_2->hide();ui->Num2_20->hide();
            ui->Num2_3->hide();ui->Num2_30->hide();
            ui->Num2_4->hide();ui->Num2_40->hide();
            ui->Num2_5->hide();ui->Num2_50->hide();
            ui->Num2_6->hide();ui->Num2_60->hide();
            ui->Num2_7->hide();ui->Num2_70->hide();
            ui->Num2_8->hide();ui->Num2_80->hide();
            ui->Num2_9->hide();ui->Num2_90->hide();
            ui->Drum_Gold->hide();
            ui->Combo_Image->hide();
            ui->Exit_Button->show();
            Music->stop();
            ui->Dancer_Ugly1->hide();
            ui->Dancer_Ugly2->hide();
            movie->stop();
            movie1->stop();
            QPixmap pixmap;
            ui->Num3_0->hide();ui->Num3_00->hide();ui->Num3_000->hide();
            ui->Num3_1->hide();ui->Num3_10->hide();ui->Num3_100->hide();
            ui->Num3_2->hide();ui->Num3_20->hide();ui->Num3_200->hide();
            ui->Num3_3->hide();ui->Num3_30->hide();ui->Num3_300->hide();
            ui->Num3_4->hide();ui->Num3_40->hide();ui->Num3_400->hide();
            ui->Num3_5->hide();ui->Num3_50->hide();ui->Num3_500->hide();
            ui->Num3_6->hide();ui->Num3_60->hide();ui->Num3_600->hide();
            ui->Num3_7->hide();ui->Num3_70->hide();ui->Num3_700->hide();
            ui->Num3_8->hide();ui->Num3_80->hide();ui->Num3_800->hide();
            ui->Num3_9->hide();ui->Num3_90->hide();ui->Num3_900->hide();
            ui->Fix_Num1->hide();
            ui->Fix_Num2->hide();
            ui->Fix_Num3->hide();
            ui->Fix_Num4->hide();
            ui->Fix_Num5->hide();
            ui->Fix_Num6->hide();
            ui->Start_Menu->show();
            ui->Start_Button->show();
            ui->Life_Green->setGeometry(QRect(128,141,255,10));
            ui->Life_Red->setGeometry(QRect(128,141,70,10));
            pixmap.load(":/dancer/img/dancer/dancer_1n14.png");
            ui->Dancer1->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_2a12.png");
            ui->Dancer2->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_3n7.png");
            ui->Dancer3->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_4d2.png");
            ui->Dancer4->setPixmap(pixmap);
            pixmap.load(":/dancer/img/dancer/dancer_5a14.png");
            ui->Dancer5->setPixmap(pixmap);
            ui->Drum_Button1->setIconSize(QSize(120,120));
            ui->Drum_Button2->setIconSize(QSize(120,120));
            ui->Drum_Button3->setIconSize(QSize(120,120));
            ui->Drum_Button4->setIconSize(QSize(120,120));
            ui->Drum_Button5->setIconSize(QSize(120,120));
            ui->Drum_Button6->setIconSize(QSize(120,120));
            ui->Drum_Button7->setIconSize(QSize(120,120));
            ui->Drum_Button8->setIconSize(QSize(120,120));
            ui->Drum_Button1->setGeometry(QRect(rand()%1400*1853%1400+1400,225,120,120));
            ui->Drum_Button2->setGeometry(QRect(rand()%1400*1758%1400+1400,225,120,120));
            ui->Drum_Button3->setGeometry(QRect(rand()%1400*9175%1400+1400,225,120,120));
            ui->Drum_Button4->setGeometry(QRect(rand()%1400*1276%1400+1400,225,120,120));
            ui->Drum_Button5->setGeometry(QRect(rand()%1400*2584%1400+1400,225,120,120));
            ui->Drum_Button6->setGeometry(QRect(rand()%1400*3187%1400+1400,225,120,120));
            ui->Drum_Button7->setGeometry(QRect(rand()%1400*1682%1400+1400,225,120,120));
            ui->Drum_Button8->setGeometry(QRect(rand()%1400*9846%1400+1400,225,120,120));
            Now_time = -200;
            Score = 0;
            Combo = 0;
            Combo_Sign_Life = 0;
            Red_Drum_Life = 0;
            Blue_Drum_Life = 0;
            Speed_Level = 5;
            Drum_Size = 0;
            Play_Mode = 0;
            for(int i=0;i<10;++i)
            {
                Impact[i]=0;
                Move_Moed[i]=i%4;
            }
            IsShow_Combo = false;
            IsPlaying = false;
            IsPause = false;
            IsDancer = false;
        }
        update();
    }
}

void MainWindow::on_Replay_Button_clicked()
{
    QPixmap pixmap;
    ui->Dead_Background->hide();
    ui->Num3_0->hide();ui->Num3_00->hide();ui->Num3_000->hide();
    ui->Num3_1->hide();ui->Num3_10->hide();ui->Num3_100->hide();
    ui->Num3_2->hide();ui->Num3_20->hide();ui->Num3_200->hide();
    ui->Num3_3->hide();ui->Num3_30->hide();ui->Num3_300->hide();
    ui->Num3_4->hide();ui->Num3_40->hide();ui->Num3_400->hide();
    ui->Num3_5->hide();ui->Num3_50->hide();ui->Num3_500->hide();
    ui->Num3_6->hide();ui->Num3_60->hide();ui->Num3_600->hide();
    ui->Num3_7->hide();ui->Num3_70->hide();ui->Num3_700->hide();
    ui->Num3_8->hide();ui->Num3_80->hide();ui->Num3_800->hide();
    ui->Num3_9->hide();ui->Num3_90->hide();ui->Num3_900->hide();
    ui->Fix_Num1->hide();
    ui->Fix_Num2->hide();
    ui->Fix_Num3->hide();
    ui->Fix_Num4->hide();
    ui->Fix_Num5->hide();
    ui->Fix_Num6->hide();
    ui->Replay_Button->hide();
    ui->Start_Menu->show();
    ui->Start_Button->show();
    ui->Life_Green->setGeometry(QRect(128,141,255,10));
    ui->Life_Red->setGeometry(QRect(128,141,70,10));
    pixmap.load(":/dancer/img/dancer/dancer_1n14.png");
    ui->Dancer1->setPixmap(pixmap);
    pixmap.load(":/dancer/img/dancer/dancer_2a12.png");
    ui->Dancer2->setPixmap(pixmap);
    pixmap.load(":/dancer/img/dancer/dancer_3n7.png");
    ui->Dancer3->setPixmap(pixmap);
    pixmap.load(":/dancer/img/dancer/dancer_4d2.png");
    ui->Dancer4->setPixmap(pixmap);
    pixmap.load(":/dancer/img/dancer/dancer_5a14.png");
    ui->Dancer5->setPixmap(pixmap);
    ui->Drum_Button1->setIconSize(QSize(120,120));
    ui->Drum_Button2->setIconSize(QSize(120,120));
    ui->Drum_Button3->setIconSize(QSize(120,120));
    ui->Drum_Button4->setIconSize(QSize(120,120));
    ui->Drum_Button5->setIconSize(QSize(120,120));
    ui->Drum_Button6->setIconSize(QSize(120,120));
    ui->Drum_Button7->setIconSize(QSize(120,120));
    ui->Drum_Button8->setIconSize(QSize(120,120));
    ui->Drum_Button1->setGeometry(QRect(rand()%1400*1853%1400+1400,225,120,120));
    ui->Drum_Button2->setGeometry(QRect(rand()%1400*1758%1400+1400,225,120,120));
    ui->Drum_Button3->setGeometry(QRect(rand()%1400*9175%1400+1400,225,120,120));
    ui->Drum_Button4->setGeometry(QRect(rand()%1400*1276%1400+1400,225,120,120));
    ui->Drum_Button5->setGeometry(QRect(rand()%1400*2584%1400+1400,225,120,120));
    ui->Drum_Button6->setGeometry(QRect(rand()%1400*3187%1400+1400,225,120,120));
    ui->Drum_Button7->setGeometry(QRect(rand()%1400*1682%1400+1400,225,120,120));
    ui->Drum_Button8->setGeometry(QRect(rand()%1400*9846%1400+1400,225,120,120));
    Now_time = -200;
    Score = 0;
    Combo = 0;
    Combo_Sign_Life = 0;
    Red_Drum_Life = 0;
    Blue_Drum_Life = 0;
    Speed_Level = 5;
    Drum_Size = 0;
    Play_Mode = 0;
    for(int i=0;i<10;++i)
    {
        Impact[i]=0;
        Move_Moed[i]=i%4;
    }
    IsShow_Combo = false;
    IsPlaying = false;
    IsPause = false;
    IsDancer = false;
}

void MainWindow::on_Drum_Button1_clicked()
{
    Jump->stop();
    Jump->play();
    ui->Drum_Button1->hide();
    ui->Hit_Point1->show();
    ui->Hit_Point2->hide();
    ui->Hit_Point3->hide();
    Score+=2+(Combo/10)*2;
    ++Combo;
    Combo_Sign_Life=20;
    {
        if(Score>999)
        {
            ui->Fix_Num1->hide();
            ui->Fix_Num2->hide();
            ui->Fix_Num3->hide();
            ui->Fix_Num4->show();
            ui->Fix_Num5->show();
            ui->Fix_Num6->show();
            ui->Num3_9->show();
            ui->Num3_90->show();
            ui->Num3_900->show();
            ui->Num3_0->hide();
            ui->Num3_00->hide();
            ui->Num3_000->hide();
            ui->Num3_1->hide();
            ui->Num3_10->hide();
            ui->Num3_100->hide();
            ui->Num3_2->hide();
            ui->Num3_20->hide();
            ui->Num3_200->hide();
            ui->Num3_3->hide();
            ui->Num3_30->hide();
            ui->Num3_300->hide();
            ui->Num3_4->hide();
            ui->Num3_40->hide();
            ui->Num3_400->hide();
            ui->Num3_5->hide();
            ui->Num3_50->hide();
            ui->Num3_500->hide();
            ui->Num3_6->hide();
            ui->Num3_60->hide();
            ui->Num3_600->hide();
            ui->Num3_7->hide();
            ui->Num3_70->hide();
            ui->Num3_700->hide();
            ui->Num3_8->hide();
            ui->Num3_80->hide();
            ui->Num3_800->hide();
        }
        else{
        switch(Score%10)
        {
            case 0:
                ui->Num3_0->show();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 1:
                ui->Num3_1->show();
                ui->Num3_0->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 2:
                ui->Num3_2->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 3:
                ui->Num3_3->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 4:
                ui->Num3_4->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 5:
                ui->Num3_5->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 6:
                ui->Num3_6->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 7:
                ui->Num3_7->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 8:
                ui->Num3_8->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_9->hide();
            break;
            case 9:
                ui->Num3_9->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
            break;
            default: ;
        }
        switch(Score/10%10)
        {
            case 0:
                ui->Num3_00->show();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 1:
                ui->Num3_10->show();
                ui->Num3_00->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 2:
                ui->Num3_20->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 3:
                ui->Num3_30->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 4:
                ui->Num3_40->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 5:
                ui->Num3_50->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 6:
                ui->Num3_60->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 7:
                ui->Num3_70->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 8:
                ui->Num3_80->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_90->hide();
            break;
            case 9:
                ui->Num3_90->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
            break;
            default: ;
        }
        switch(Score/100)
        {
            case 0:
                ui->Num3_000->show();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 1:
                ui->Num3_100->show();
                ui->Num3_000->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 2:
                ui->Num3_200->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 3:
                ui->Num3_300->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 4:
                ui->Num3_400->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 5:
                ui->Num3_500->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 6:
                ui->Num3_600->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 7:
                ui->Num3_700->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 8:
                ui->Num3_800->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_900->hide();
            break;
            case 9:
                ui->Num3_900->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
            break;
            default: ;
        }
        }
    }
}

void MainWindow::on_Drum_Button2_clicked()
{
    Jump->stop();
    Jump->play();
    ui->Drum_Button2->hide();
    ui->Hit_Point1->show();
    ui->Hit_Point2->hide();
    ui->Hit_Point3->hide();
    Score+=2+(Combo/10)*2;
    ++Combo;
    Combo_Sign_Life=20;
    {
        if(Score>999)
        {
            ui->Fix_Num1->hide();
            ui->Fix_Num2->hide();
            ui->Fix_Num3->hide();
            ui->Fix_Num4->show();
            ui->Fix_Num5->show();
            ui->Fix_Num6->show();
            ui->Num3_9->show();
            ui->Num3_90->show();
            ui->Num3_900->show();
            ui->Num3_0->hide();
            ui->Num3_00->hide();
            ui->Num3_000->hide();
            ui->Num3_1->hide();
            ui->Num3_10->hide();
            ui->Num3_100->hide();
            ui->Num3_2->hide();
            ui->Num3_20->hide();
            ui->Num3_200->hide();
            ui->Num3_3->hide();
            ui->Num3_30->hide();
            ui->Num3_300->hide();
            ui->Num3_4->hide();
            ui->Num3_40->hide();
            ui->Num3_400->hide();
            ui->Num3_5->hide();
            ui->Num3_50->hide();
            ui->Num3_500->hide();
            ui->Num3_6->hide();
            ui->Num3_60->hide();
            ui->Num3_600->hide();
            ui->Num3_7->hide();
            ui->Num3_70->hide();
            ui->Num3_700->hide();
            ui->Num3_8->hide();
            ui->Num3_80->hide();
            ui->Num3_800->hide();
        }
        else{
        switch(Score%10)
        {
            case 0:
                ui->Num3_0->show();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 1:
                ui->Num3_1->show();
                ui->Num3_0->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 2:
                ui->Num3_2->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 3:
                ui->Num3_3->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 4:
                ui->Num3_4->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 5:
                ui->Num3_5->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 6:
                ui->Num3_6->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 7:
                ui->Num3_7->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 8:
                ui->Num3_8->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_9->hide();
            break;
            case 9:
                ui->Num3_9->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
            break;
            default: ;
        }
        switch(Score/10%10)
        {
            case 0:
                ui->Num3_00->show();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 1:
                ui->Num3_10->show();
                ui->Num3_00->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 2:
                ui->Num3_20->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 3:
                ui->Num3_30->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 4:
                ui->Num3_40->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 5:
                ui->Num3_50->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 6:
                ui->Num3_60->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 7:
                ui->Num3_70->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 8:
                ui->Num3_80->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_90->hide();
            break;
            case 9:
                ui->Num3_90->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
            break;
            default: ;
        }
        switch(Score/100)
        {
            case 0:
                ui->Num3_000->show();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 1:
                ui->Num3_100->show();
                ui->Num3_000->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 2:
                ui->Num3_200->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 3:
                ui->Num3_300->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 4:
                ui->Num3_400->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 5:
                ui->Num3_500->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 6:
                ui->Num3_600->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 7:
                ui->Num3_700->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 8:
                ui->Num3_800->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_900->hide();
            break;
            case 9:
                ui->Num3_900->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
            break;
            default: ;
        }
        }
    }
}

void MainWindow::on_Drum_Button3_clicked()
{
    Jump->stop();
    Jump->play();
    ui->Drum_Button3->hide();
    ui->Hit_Point1->show();
    ui->Hit_Point2->hide();
    ui->Hit_Point3->hide();
    Score+=2+(Combo/10)*2;
    ++Combo;
    Combo_Sign_Life=20;
    {
        if(Score>999)
        {
            ui->Fix_Num1->hide();
            ui->Fix_Num2->hide();
            ui->Fix_Num3->hide();
            ui->Fix_Num4->show();
            ui->Fix_Num5->show();
            ui->Fix_Num6->show();
            ui->Num3_9->show();
            ui->Num3_90->show();
            ui->Num3_900->show();
            ui->Num3_0->hide();
            ui->Num3_00->hide();
            ui->Num3_000->hide();
            ui->Num3_1->hide();
            ui->Num3_10->hide();
            ui->Num3_100->hide();
            ui->Num3_2->hide();
            ui->Num3_20->hide();
            ui->Num3_200->hide();
            ui->Num3_3->hide();
            ui->Num3_30->hide();
            ui->Num3_300->hide();
            ui->Num3_4->hide();
            ui->Num3_40->hide();
            ui->Num3_400->hide();
            ui->Num3_5->hide();
            ui->Num3_50->hide();
            ui->Num3_500->hide();
            ui->Num3_6->hide();
            ui->Num3_60->hide();
            ui->Num3_600->hide();
            ui->Num3_7->hide();
            ui->Num3_70->hide();
            ui->Num3_700->hide();
            ui->Num3_8->hide();
            ui->Num3_80->hide();
            ui->Num3_800->hide();
        }
        else{
        switch(Score%10)
        {
            case 0:
                ui->Num3_0->show();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 1:
                ui->Num3_1->show();
                ui->Num3_0->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 2:
                ui->Num3_2->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 3:
                ui->Num3_3->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 4:
                ui->Num3_4->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 5:
                ui->Num3_5->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 6:
                ui->Num3_6->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 7:
                ui->Num3_7->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 8:
                ui->Num3_8->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_9->hide();
            break;
            case 9:
                ui->Num3_9->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
            break;
            default: ;
        }
        switch(Score/10%10)
        {
            case 0:
                ui->Num3_00->show();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 1:
                ui->Num3_10->show();
                ui->Num3_00->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 2:
                ui->Num3_20->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 3:
                ui->Num3_30->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 4:
                ui->Num3_40->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 5:
                ui->Num3_50->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 6:
                ui->Num3_60->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 7:
                ui->Num3_70->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 8:
                ui->Num3_80->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_90->hide();
            break;
            case 9:
                ui->Num3_90->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
            break;
            default: ;
        }
        switch(Score/100)
        {
            case 0:
                ui->Num3_000->show();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 1:
                ui->Num3_100->show();
                ui->Num3_000->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 2:
                ui->Num3_200->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 3:
                ui->Num3_300->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 4:
                ui->Num3_400->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 5:
                ui->Num3_500->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 6:
                ui->Num3_600->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 7:
                ui->Num3_700->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 8:
                ui->Num3_800->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_900->hide();
            break;
            case 9:
                ui->Num3_900->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
            break;
            default: ;
        }
        }
    }
}

void MainWindow::on_Drum_Button4_clicked()
{
    Jump->stop();
    Jump->play();
    ui->Drum_Button4->hide();
    ui->Hit_Point1->show();
    ui->Hit_Point2->hide();
    ui->Hit_Point3->hide();
    Score+=2+(Combo/10)*2;
    ++Combo;
    Combo_Sign_Life=20;
    {
        if(Score>999)
        {
            ui->Fix_Num1->hide();
            ui->Fix_Num2->hide();
            ui->Fix_Num3->hide();
            ui->Fix_Num4->show();
            ui->Fix_Num5->show();
            ui->Fix_Num6->show();
            ui->Num3_9->show();
            ui->Num3_90->show();
            ui->Num3_900->show();
            ui->Num3_0->hide();
            ui->Num3_00->hide();
            ui->Num3_000->hide();
            ui->Num3_1->hide();
            ui->Num3_10->hide();
            ui->Num3_100->hide();
            ui->Num3_2->hide();
            ui->Num3_20->hide();
            ui->Num3_200->hide();
            ui->Num3_3->hide();
            ui->Num3_30->hide();
            ui->Num3_300->hide();
            ui->Num3_4->hide();
            ui->Num3_40->hide();
            ui->Num3_400->hide();
            ui->Num3_5->hide();
            ui->Num3_50->hide();
            ui->Num3_500->hide();
            ui->Num3_6->hide();
            ui->Num3_60->hide();
            ui->Num3_600->hide();
            ui->Num3_7->hide();
            ui->Num3_70->hide();
            ui->Num3_700->hide();
            ui->Num3_8->hide();
            ui->Num3_80->hide();
            ui->Num3_800->hide();
        }
        else{
        switch(Score%10)
        {
            case 0:
                ui->Num3_0->show();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 1:
                ui->Num3_1->show();
                ui->Num3_0->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 2:
                ui->Num3_2->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 3:
                ui->Num3_3->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 4:
                ui->Num3_4->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 5:
                ui->Num3_5->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 6:
                ui->Num3_6->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 7:
                ui->Num3_7->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 8:
                ui->Num3_8->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_9->hide();
            break;
            case 9:
                ui->Num3_9->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
            break;
            default: ;
        }
        switch(Score/10%10)
        {
            case 0:
                ui->Num3_00->show();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 1:
                ui->Num3_10->show();
                ui->Num3_00->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 2:
                ui->Num3_20->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 3:
                ui->Num3_30->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 4:
                ui->Num3_40->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 5:
                ui->Num3_50->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 6:
                ui->Num3_60->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 7:
                ui->Num3_70->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 8:
                ui->Num3_80->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_90->hide();
            break;
            case 9:
                ui->Num3_90->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
            break;
            default: ;
        }
        switch(Score/100)
        {
            case 0:
                ui->Num3_000->show();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 1:
                ui->Num3_100->show();
                ui->Num3_000->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 2:
                ui->Num3_200->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 3:
                ui->Num3_300->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 4:
                ui->Num3_400->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 5:
                ui->Num3_500->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 6:
                ui->Num3_600->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 7:
                ui->Num3_700->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 8:
                ui->Num3_800->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_900->hide();
            break;
            case 9:
                ui->Num3_900->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
            break;
            default: ;
        }
        }
    }
}

void MainWindow::on_Drum_Button5_clicked()
{
    Jump->stop();
    Jump->play();
    ui->Drum_Button5->hide();
    ui->Hit_Point1->show();
    ui->Hit_Point2->hide();
    ui->Hit_Point3->hide();
    Score+=2+(Combo/10)*2;
    ++Combo;
    Combo_Sign_Life=20;
    {
        if(Score>999)
        {
            ui->Fix_Num1->hide();
            ui->Fix_Num2->hide();
            ui->Fix_Num3->hide();
            ui->Fix_Num4->show();
            ui->Fix_Num5->show();
            ui->Fix_Num6->show();
            ui->Num3_9->show();
            ui->Num3_90->show();
            ui->Num3_900->show();
            ui->Num3_0->hide();
            ui->Num3_00->hide();
            ui->Num3_000->hide();
            ui->Num3_1->hide();
            ui->Num3_10->hide();
            ui->Num3_100->hide();
            ui->Num3_2->hide();
            ui->Num3_20->hide();
            ui->Num3_200->hide();
            ui->Num3_3->hide();
            ui->Num3_30->hide();
            ui->Num3_300->hide();
            ui->Num3_4->hide();
            ui->Num3_40->hide();
            ui->Num3_400->hide();
            ui->Num3_5->hide();
            ui->Num3_50->hide();
            ui->Num3_500->hide();
            ui->Num3_6->hide();
            ui->Num3_60->hide();
            ui->Num3_600->hide();
            ui->Num3_7->hide();
            ui->Num3_70->hide();
            ui->Num3_700->hide();
            ui->Num3_8->hide();
            ui->Num3_80->hide();
            ui->Num3_800->hide();
        }
        else{
        switch(Score%10)
        {
            case 0:
                ui->Num3_0->show();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 1:
                ui->Num3_1->show();
                ui->Num3_0->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 2:
                ui->Num3_2->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 3:
                ui->Num3_3->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 4:
                ui->Num3_4->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 5:
                ui->Num3_5->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 6:
                ui->Num3_6->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 7:
                ui->Num3_7->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 8:
                ui->Num3_8->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_9->hide();
            break;
            case 9:
                ui->Num3_9->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
            break;
            default: ;
        }
        switch(Score/10%10)
        {
            case 0:
                ui->Num3_00->show();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 1:
                ui->Num3_10->show();
                ui->Num3_00->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 2:
                ui->Num3_20->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 3:
                ui->Num3_30->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 4:
                ui->Num3_40->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 5:
                ui->Num3_50->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 6:
                ui->Num3_60->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 7:
                ui->Num3_70->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 8:
                ui->Num3_80->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_90->hide();
            break;
            case 9:
                ui->Num3_90->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
            break;
            default: ;
        }
        switch(Score/100)
        {
            case 0:
                ui->Num3_000->show();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 1:
                ui->Num3_100->show();
                ui->Num3_000->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 2:
                ui->Num3_200->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 3:
                ui->Num3_300->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 4:
                ui->Num3_400->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 5:
                ui->Num3_500->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 6:
                ui->Num3_600->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 7:
                ui->Num3_700->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 8:
                ui->Num3_800->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_900->hide();
            break;
            case 9:
                ui->Num3_900->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
            break;
            default: ;
        }
        }
    }
}

void MainWindow::on_Drum_Button6_clicked()
{
    Jump->stop();
    Jump->play();
    ui->Drum_Button6->hide();
    ui->Hit_Point1->show();
    ui->Hit_Point2->hide();
    ui->Hit_Point3->hide();
    Score+=2+(Combo/10)*2;
    ++Combo;
    Combo_Sign_Life=20;
    {
        if(Score>999)
        {
            ui->Fix_Num1->hide();
            ui->Fix_Num2->hide();
            ui->Fix_Num3->hide();
            ui->Fix_Num4->show();
            ui->Fix_Num5->show();
            ui->Fix_Num6->show();
            ui->Num3_9->show();
            ui->Num3_90->show();
            ui->Num3_900->show();
            ui->Num3_0->hide();
            ui->Num3_00->hide();
            ui->Num3_000->hide();
            ui->Num3_1->hide();
            ui->Num3_10->hide();
            ui->Num3_100->hide();
            ui->Num3_2->hide();
            ui->Num3_20->hide();
            ui->Num3_200->hide();
            ui->Num3_3->hide();
            ui->Num3_30->hide();
            ui->Num3_300->hide();
            ui->Num3_4->hide();
            ui->Num3_40->hide();
            ui->Num3_400->hide();
            ui->Num3_5->hide();
            ui->Num3_50->hide();
            ui->Num3_500->hide();
            ui->Num3_6->hide();
            ui->Num3_60->hide();
            ui->Num3_600->hide();
            ui->Num3_7->hide();
            ui->Num3_70->hide();
            ui->Num3_700->hide();
            ui->Num3_8->hide();
            ui->Num3_80->hide();
            ui->Num3_800->hide();
        }
        else{
        switch(Score%10)
        {
            case 0:
                ui->Num3_0->show();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 1:
                ui->Num3_1->show();
                ui->Num3_0->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 2:
                ui->Num3_2->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 3:
                ui->Num3_3->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 4:
                ui->Num3_4->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 5:
                ui->Num3_5->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 6:
                ui->Num3_6->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 7:
                ui->Num3_7->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 8:
                ui->Num3_8->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_9->hide();
            break;
            case 9:
                ui->Num3_9->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
            break;
            default: ;
        }
        switch(Score/10%10)
        {
            case 0:
                ui->Num3_00->show();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 1:
                ui->Num3_10->show();
                ui->Num3_00->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 2:
                ui->Num3_20->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 3:
                ui->Num3_30->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 4:
                ui->Num3_40->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 5:
                ui->Num3_50->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 6:
                ui->Num3_60->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 7:
                ui->Num3_70->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 8:
                ui->Num3_80->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_90->hide();
            break;
            case 9:
                ui->Num3_90->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
            break;
            default: ;
        }
        switch(Score/100)
        {
            case 0:
                ui->Num3_000->show();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 1:
                ui->Num3_100->show();
                ui->Num3_000->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 2:
                ui->Num3_200->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 3:
                ui->Num3_300->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 4:
                ui->Num3_400->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 5:
                ui->Num3_500->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 6:
                ui->Num3_600->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 7:
                ui->Num3_700->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 8:
                ui->Num3_800->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_900->hide();
            break;
            case 9:
                ui->Num3_900->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
            break;
            default: ;
        }
        }
    }
}

void MainWindow::on_Drum_Button7_clicked()
{
    Jump->stop();
    Jump->play();
    ui->Drum_Button7->hide();
    ui->Hit_Point1->show();
    ui->Hit_Point2->hide();
    ui->Hit_Point3->hide();
    Score+=2+(Combo/10)*2;
    ++Combo;
    Combo_Sign_Life=20;
    {
        if(Score>999)
        {
            ui->Fix_Num1->hide();
            ui->Fix_Num2->hide();
            ui->Fix_Num3->hide();
            ui->Fix_Num4->show();
            ui->Fix_Num5->show();
            ui->Fix_Num6->show();
            ui->Num3_9->show();
            ui->Num3_90->show();
            ui->Num3_900->show();
            ui->Num3_0->hide();
            ui->Num3_00->hide();
            ui->Num3_000->hide();
            ui->Num3_1->hide();
            ui->Num3_10->hide();
            ui->Num3_100->hide();
            ui->Num3_2->hide();
            ui->Num3_20->hide();
            ui->Num3_200->hide();
            ui->Num3_3->hide();
            ui->Num3_30->hide();
            ui->Num3_300->hide();
            ui->Num3_4->hide();
            ui->Num3_40->hide();
            ui->Num3_400->hide();
            ui->Num3_5->hide();
            ui->Num3_50->hide();
            ui->Num3_500->hide();
            ui->Num3_6->hide();
            ui->Num3_60->hide();
            ui->Num3_600->hide();
            ui->Num3_7->hide();
            ui->Num3_70->hide();
            ui->Num3_700->hide();
            ui->Num3_8->hide();
            ui->Num3_80->hide();
            ui->Num3_800->hide();
        }
        else{
        switch(Score%10)
        {
            case 0:
                ui->Num3_0->show();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 1:
                ui->Num3_1->show();
                ui->Num3_0->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 2:
                ui->Num3_2->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 3:
                ui->Num3_3->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 4:
                ui->Num3_4->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 5:
                ui->Num3_5->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 6:
                ui->Num3_6->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 7:
                ui->Num3_7->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 8:
                ui->Num3_8->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_9->hide();
            break;
            case 9:
                ui->Num3_9->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
            break;
            default: ;
        }
        switch(Score/10%10)
        {
            case 0:
                ui->Num3_00->show();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 1:
                ui->Num3_10->show();
                ui->Num3_00->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 2:
                ui->Num3_20->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 3:
                ui->Num3_30->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 4:
                ui->Num3_40->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 5:
                ui->Num3_50->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 6:
                ui->Num3_60->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 7:
                ui->Num3_70->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 8:
                ui->Num3_80->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_90->hide();
            break;
            case 9:
                ui->Num3_90->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
            break;
            default: ;
        }
        switch(Score/100)
        {
            case 0:
                ui->Num3_000->show();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 1:
                ui->Num3_100->show();
                ui->Num3_000->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 2:
                ui->Num3_200->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 3:
                ui->Num3_300->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 4:
                ui->Num3_400->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 5:
                ui->Num3_500->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 6:
                ui->Num3_600->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 7:
                ui->Num3_700->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 8:
                ui->Num3_800->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_900->hide();
            break;
            case 9:
                ui->Num3_900->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
            break;
            default: ;
        }
        }
    }
}

void MainWindow::on_Drum_Button8_clicked()
{
    Jump->stop();
    Jump->play();
    ui->Drum_Button8->hide();
    ui->Hit_Point1->show();
    ui->Hit_Point2->hide();
    ui->Hit_Point3->hide();
    Score+=2+(Combo/10)*2;
    ++Combo;
    Combo_Sign_Life=20;
    {
        if(Score>999)
        {
            ui->Fix_Num1->hide();
            ui->Fix_Num2->hide();
            ui->Fix_Num3->hide();
            ui->Fix_Num4->show();
            ui->Fix_Num5->show();
            ui->Fix_Num6->show();
            ui->Num3_9->show();
            ui->Num3_90->show();
            ui->Num3_900->show();
            ui->Num3_0->hide();
            ui->Num3_00->hide();
            ui->Num3_000->hide();
            ui->Num3_1->hide();
            ui->Num3_10->hide();
            ui->Num3_100->hide();
            ui->Num3_2->hide();
            ui->Num3_20->hide();
            ui->Num3_200->hide();
            ui->Num3_3->hide();
            ui->Num3_30->hide();
            ui->Num3_300->hide();
            ui->Num3_4->hide();
            ui->Num3_40->hide();
            ui->Num3_400->hide();
            ui->Num3_5->hide();
            ui->Num3_50->hide();
            ui->Num3_500->hide();
            ui->Num3_6->hide();
            ui->Num3_60->hide();
            ui->Num3_600->hide();
            ui->Num3_7->hide();
            ui->Num3_70->hide();
            ui->Num3_700->hide();
            ui->Num3_8->hide();
            ui->Num3_80->hide();
            ui->Num3_800->hide();
        }
        else{
        switch(Score%10)
        {
            case 0:
                ui->Num3_0->show();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 1:
                ui->Num3_1->show();
                ui->Num3_0->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 2:
                ui->Num3_2->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 3:
                ui->Num3_3->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 4:
                ui->Num3_4->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 5:
                ui->Num3_5->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 6:
                ui->Num3_6->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 7:
                ui->Num3_7->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 8:
                ui->Num3_8->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_9->hide();
            break;
            case 9:
                ui->Num3_9->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
            break;
            default: ;
        }
        switch(Score/10%10)
        {
            case 0:
                ui->Num3_00->show();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 1:
                ui->Num3_10->show();
                ui->Num3_00->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 2:
                ui->Num3_20->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 3:
                ui->Num3_30->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 4:
                ui->Num3_40->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 5:
                ui->Num3_50->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 6:
                ui->Num3_60->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 7:
                ui->Num3_70->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 8:
                ui->Num3_80->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_90->hide();
            break;
            case 9:
                ui->Num3_90->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
            break;
            default: ;
        }
        switch(Score/100)
        {
            case 0:
                ui->Num3_000->show();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 1:
                ui->Num3_100->show();
                ui->Num3_000->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 2:
                ui->Num3_200->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 3:
                ui->Num3_300->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 4:
                ui->Num3_400->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 5:
                ui->Num3_500->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 6:
                ui->Num3_600->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 7:
                ui->Num3_700->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 8:
                ui->Num3_800->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_900->hide();
            break;
            case 9:
                ui->Num3_900->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
            break;
            default: ;
        }
        }
    }
}

void MainWindow::on_Drum_Gold_clicked()
{
    Jump->stop();
    Jump->play();
    ui->Drum_Gold->hide();
    ui->Hit_Point1->show();
    ui->Hit_Point2->hide();
    ui->Hit_Point3->hide();
    Score+=300;
    ++Combo;
    Combo_Sign_Life=20;
    {
        if(Score>999)
        {
            ui->Fix_Num1->hide();
            ui->Fix_Num2->hide();
            ui->Fix_Num3->hide();
            ui->Fix_Num4->show();
            ui->Fix_Num5->show();
            ui->Fix_Num6->show();
            ui->Num3_9->show();
            ui->Num3_90->show();
            ui->Num3_900->show();
            ui->Num3_0->hide();
            ui->Num3_00->hide();
            ui->Num3_000->hide();
            ui->Num3_1->hide();
            ui->Num3_10->hide();
            ui->Num3_100->hide();
            ui->Num3_2->hide();
            ui->Num3_20->hide();
            ui->Num3_200->hide();
            ui->Num3_3->hide();
            ui->Num3_30->hide();
            ui->Num3_300->hide();
            ui->Num3_4->hide();
            ui->Num3_40->hide();
            ui->Num3_400->hide();
            ui->Num3_5->hide();
            ui->Num3_50->hide();
            ui->Num3_500->hide();
            ui->Num3_6->hide();
            ui->Num3_60->hide();
            ui->Num3_600->hide();
            ui->Num3_7->hide();
            ui->Num3_70->hide();
            ui->Num3_700->hide();
            ui->Num3_8->hide();
            ui->Num3_80->hide();
            ui->Num3_800->hide();
        }
        else{
        switch(Score%10)
        {
            case 0:
                ui->Num3_0->show();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 1:
                ui->Num3_1->show();
                ui->Num3_0->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 2:
                ui->Num3_2->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 3:
                ui->Num3_3->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 4:
                ui->Num3_4->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 5:
                ui->Num3_5->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 6:
                ui->Num3_6->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 7:
                ui->Num3_7->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_8->hide();
                ui->Num3_9->hide();
            break;
            case 8:
                ui->Num3_8->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_9->hide();
            break;
            case 9:
                ui->Num3_9->show();
                ui->Num3_0->hide();
                ui->Num3_1->hide();
                ui->Num3_2->hide();
                ui->Num3_3->hide();
                ui->Num3_4->hide();
                ui->Num3_5->hide();
                ui->Num3_6->hide();
                ui->Num3_7->hide();
                ui->Num3_8->hide();
            break;
            default: ;
        }
        switch(Score/10%10)
        {
            case 0:
                ui->Num3_00->show();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 1:
                ui->Num3_10->show();
                ui->Num3_00->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 2:
                ui->Num3_20->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 3:
                ui->Num3_30->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 4:
                ui->Num3_40->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 5:
                ui->Num3_50->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 6:
                ui->Num3_60->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 7:
                ui->Num3_70->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_80->hide();
                ui->Num3_90->hide();
            break;
            case 8:
                ui->Num3_80->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_90->hide();
            break;
            case 9:
                ui->Num3_90->show();
                ui->Num3_00->hide();
                ui->Num3_10->hide();
                ui->Num3_20->hide();
                ui->Num3_30->hide();
                ui->Num3_40->hide();
                ui->Num3_50->hide();
                ui->Num3_60->hide();
                ui->Num3_70->hide();
                ui->Num3_80->hide();
            break;
            default: ;
        }
        switch(Score/100)
        {
            case 0:
                ui->Num3_000->show();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 1:
                ui->Num3_100->show();
                ui->Num3_000->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 2:
                ui->Num3_200->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 3:
                ui->Num3_300->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 4:
                ui->Num3_400->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 5:
                ui->Num3_500->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 6:
                ui->Num3_600->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 7:
                ui->Num3_700->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_800->hide();
                ui->Num3_900->hide();
            break;
            case 8:
                ui->Num3_800->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_900->hide();
            break;
            case 9:
                ui->Num3_900->show();
                ui->Num3_000->hide();
                ui->Num3_100->hide();
                ui->Num3_200->hide();
                ui->Num3_300->hide();
                ui->Num3_400->hide();
                ui->Num3_500->hide();
                ui->Num3_600->hide();
                ui->Num3_700->hide();
                ui->Num3_800->hide();
            break;
            default: ;
        }
        }
    }
}
