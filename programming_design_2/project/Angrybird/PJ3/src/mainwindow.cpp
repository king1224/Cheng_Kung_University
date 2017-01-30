#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Enable the event Filter
    qApp->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEvent(QShowEvent *)
{
    // Setting the QGraphicsScene
    scene = new QGraphicsScene(0,0,width(),ui->graphicsView->height());
    ui->graphicsView->setScene(scene);
    // Create world
    world = new b2World(b2Vec2(0.0f, -9.8f));
    // Setting Size
    GameItem::setGlobalSize(QSizeF(32,18),size());
    // Create ground (You can edit here)
    QGraphicsPixmapItem *item = new QGraphicsPixmapItem(QPixmap(":/Background/sky.png").scaled(width(),height()));
    //    item->setPos(105,360);
    scene->addItem(item);
    Fake = new Wall_Fake(4,1.5,0.0005,100,QPixmap(":/Background/ground.png").scaled(width()/50.0,height()),world,scene);
    new Wall_Fake(1,1.5,0.0005,100,QPixmap(":/Background/ground.png").scaled(width()/50.0,height()),world,scene);
    itemList.push_back(new Land(16,1.5,32,3,QPixmap(":/Background/ground.png").scaled(width(),height()/6.0),world,scene));
    sling = new Sling(3,4,1,3.5,QPixmap(":/Background/sling1.png").scaled(width()/24.0,height()/5.8),world,scene);

    Music->setVolume(70);

    wall[0]=new Wall_Iron(24,8,width()/48.0,height()/27.0,&timer,QPixmap(":/Background/Wall_Iron.png").scaled(width()/48.0,height()/2.7),world,scene);
    wall[1]=new Wall_Iron(23.2,8,width()/48.0,height()/27.0,&timer,QPixmap(":/Background/Wall_Iron.png").scaled(width()/48.0,height()/2.7),world,scene);
    wall[2]=new Wall_Iron(22.4,8,width()/48.0,height()/27.0,&timer,QPixmap(":/Background/Wall_Iron.png").scaled(width()/48.0,height()/2.7),world,scene);
    wall[3]=new Wall_Glass(29,8,width()/48.0,height()/27.0,&timer,QPixmap(":/Background/Wall_Glass.png").scaled(width()/48.0,height()/2.7),world,scene);
    wall[4]=new Wall_Glass(17.4,8,width()/48.0,height()/27.0,&timer,QPixmap(":/Background/Wall_Glass.png").scaled(width()/48.0,height()/2.7),world,scene);
    wall[5]=new Wall_Wood(26.35,15,width()/48.0,height()/27.0,&timer,QPixmap(":/Background/Wall_Wood.png").scaled(width()/48.0,height()/2.7),world,scene);
    wall[6]=new Wall_Wood(21.35,15,width()/48.0,height()/27.0,&timer,QPixmap(":/Background/Wall_Wood.png").scaled(width()/48.0,height()/2.7),world,scene);
    wall[7]=new Wall_Wood(23.75,20,width()/48.0,height()/27.0,&timer,QPixmap(":/Background/Wall_Wood.png").scaled(width()/48.0,height()/2.7),world,scene);
    wall[8]=new Wall_Wood(19.9,13,width()/48.0,height()/27.0,&timer,QPixmap(":/Background/Wall_Wood.png").scaled(width()/48.0,height()/2.7),world,scene);
    wall[9]=new Wall_Wood(26.5,13,width()/48.0,height()/27.0,&timer,QPixmap(":/Background/Wall_Wood.png").scaled(width()/48.0,height()/2.7),world,scene);
    wall[7]->Set_Transform(1.57);
    wall[8]->Set_Transform(1.57);
    wall[9]->Set_Transform(1.57);
    wall[10]=new Wall_Iron(15,15,width()/48.0,height()/27.0,&timer,QPixmap(":/Background/Wall_Iron.png").scaled(width()/48.0,height()/2.7),world,scene);
    wall[11]=new Wall_Iron(11,15,width()/48.0,height()/27.0,&timer,QPixmap(":/Background/Wall_Iron.png").scaled(width()/48.0,height()/2.7),world,scene);
    wall[12]=new Wall_Iron(11,8,width()/48.0,height()/27.0,&timer,QPixmap(":/Background/Wall_Iron.png").scaled(width()/48.0,height()/2.7),world,scene);
    wall[13]=new Wall_Iron(16,8,width()/48.0,height()/27.0,&timer,QPixmap(":/Background/Wall_Iron.png").scaled(width()/48.0,height()/2.7),world,scene);
    wall[14]=new Wall_Iron(13.3,13,width()/48.0,height()/27.0,&timer,QPixmap(":/Background/Wall_Iron.png").scaled(width()/48.0,height()/2.7),world,scene);
    wall[10]->Set_Transform(0.45);
    wall[11]->Set_Transform(-0.45);
    wall[14]->Set_Transform(1.57);

    pig[0] = new Pig(26.4,6,0.27,&timer,QPixmap(":/Bird/Pig1.png").scaled(scene->height()/9.0,scene->height()/9.0),world,scene);
    pig[1] = new Pig(19.6,6,0.27,&timer,QPixmap(":/Bird/Pig1.png").scaled(scene->height()/9.0,scene->height()/9.0),world,scene);
    pig[2] = new Pig(13.5,6,0.27,&timer,QPixmap(":/Bird/Pig1.png").scaled(scene->height()/9.0,scene->height()/9.0),world,scene);
    pig[3] = new Pig(23.5,14,0.27,&timer,QPixmap(":/Bird/Pig3.png").scaled(scene->height()/9.0,scene->height()/9.0),world,scene);
    pig[4] = new Pig(13.3,13,0.27,&timer,QPixmap(":/Bird/Pig3.png").scaled(scene->height()/9.0,scene->height()/9.0),world,scene);


    Exit_Button->setGeometry(QRect(500,10,105,45));
    Exit_Button->setText("Exit");
    Exit_Button->setFont(QFont("Monotype Corsiva", 16, QFont::Bold));
    Exit_Button->setStyleSheet("border-top: 0px transparent;border-bottom: 0px transparent; border- right: 0px transparent;border-left: 0px transparent;");
    Replay_Button->setGeometry(QRect(350,10,105,45));
    Replay_Button->setText("Replay");
    Replay_Button->setFont(QFont("Monotype Corsiva", 16, QFont::Bold));
    Replay_Button->setStyleSheet("border-top: 0px transparent;border-bottom: 0px transparent; border- right: 0px transparent;border-left: 0px transparent;");
    Pause_Button->setGeometry(QRect(650,10,105,45));
    Pause_Button->setText("Description");
    Pause_Button->setFont(QFont("Monotype Corsiva", 16, QFont::Bold));
    Pause_Button->setStyleSheet("border-top: 0px transparent;border-bottom: 0px transparent; border- right: 0px transparent;border-left: 0px transparent;");
    scene->addWidget(Exit_Button);
    scene->addWidget(Replay_Button);
    scene->addWidget(Pause_Button);
    connect(Exit_Button, SIGNAL(clicked()), this, SLOT(Exit()));
    connect(Replay_Button, SIGNAL(clicked()), this, SLOT(Replay()));
    connect(Pause_Button, SIGNAL(clicked()), this, SLOT(Description()));
    QIcon icon[3];
    icon[0].addPixmap(QPixmap(":/Bird/Pig1.png"),QIcon::Normal,QIcon::Off);
    Exit_Button->setIcon(icon[0]);
    icon[1].addPixmap(QPixmap(":/Bird/Bird_Red.png"),QIcon::Normal,QIcon::Off);
    Replay_Button->setIcon(icon[1]);
    icon[2].addPixmap(QPixmap(":/Bird/Bird_White2.png"),QIcon::Normal,QIcon::Off);
    Pause_Button->setIcon(icon[2]);
    Replay_Button->setIconSize(QSize(40,40));
    Exit_Button->setIconSize(QSize(40,40));
    Pause_Button->setIconSize(QSize(40,40));

    Description_Message->setText("Pause Message\n\nZ : Add a bird.\n\nX : Raining.");
    Description_Message->setFont(QFont("Monotype Corsiva", 32, QFont::Bold));
    Description_Message->setGeometry(QRect(0,0,500,400));
    scene3->addWidget(Description_Message);
    view3->setScene(scene3);

    Show_Score= new QLabel(this);
    Show_Score->setFont(QFont("Monotype Corsiva", 36, QFont::Bold));
    Show_Score->setGeometry(10,0,300,60);
    Show_Score->show();

    Bomb_Cloud= new QLabel(this);

    // Create bird (You can edit here)
    srand(time(NULL));
    for(int i=0;i<5;++i){
        Bird_Bullet[i]=bird_generator(&timer,world,scene,(i*3+5.0),Birds_Color[i]);
        itemList.push_back(Bird_Bullet[i]);
    }
    Bird_Bullet[0]->Init_Position();

    // Timer
    connect(&timer,SIGNAL(timeout()),this,SLOT(tick()));
    connect(this,SIGNAL(quitGame()),this,SLOT(QUITSLOT()));
    timer.start(100/6);

    Is_Press=false;
    Is_Flying=false;
    Is_Skill=false;
    Is_Show=false;
    Can_Play=true;
    Bird_Control=0;
    Skill_Time=0;
    Score=0;
    Bomb_Life=-1;
    Raining_Time=-1;
    More_Bird=0;
    for(int i=0;i<5;++i){
        Is_Hit_Pig[i]=true;
        Is_Dead_Pig[i]=false;
        Is_Delete_Pig[i]=false;
        Dead_Pig_Count[i]=-99999;
        Is_Delete_Bird[i]=false;
    }
    for(int i=0;i<15;++i){
        Is_Hit_Wall[i]=true;
        Is_Dead_Wall[i]=false;
        Is_Delete_Wall[i]=false;
        Dead_Wall_Count[i]=-99999;
    }



    item2->setPixmap(QPixmap(":/Background/sky.png"));
    scene2->addItem(item2);
    OK_Button->setGeometry(QRect(250,160,70,30));
    OK_Button->setText("OK");
    Cancel_Button->setGeometry(QRect(350,160,70,30));
    Cancel_Button->setText("Cancel");
    Cancel_Button->setFont(QFont("Monotype Corsiva", 16, QFont::Bold));
    Cancel_Button->setStyleSheet("border-top: 0px transparent;border-bottom: 0px transparent; border- right: 0px transparent;border-left: 0px transparent;");
    OK_Button->setFont(QFont("Monotype Corsiva", 16, QFont::Bold));
    OK_Button->setStyleSheet("border-top: 0px transparent;border-bottom: 0px transparent; border- right: 0px transparent;border-left: 0px transparent;");
    scene2->addWidget(OK_Button);
    scene2->addWidget(Cancel_Button);
    Show_Name->setText("Please Enter Your Name.");
    Show_Name->setFont(QFont("Monotype Corsiva", 16, QFont::Bold));
    Show_Name->setGeometry(QRect(130,50,250,30));
    Show_Score2->setGeometry(QRect(80,160,120,30));
    Show_Score2->setFont(QFont("Monotype Corsiva", 16, QFont::Bold));
    Catch_Name->setGeometry(QRect(130,100,250,30));
    scene2->addWidget(Show_Score2);
    scene2->addWidget(Show_Name);
    scene2->addWidget(Catch_Name);
    view->setScene(scene2);
    connect(OK_Button, SIGNAL (clicked()),this, SLOT (On_OK_Button_clicked()));
    connect(Cancel_Button, SIGNAL (clicked()),this, SLOT (On_Cancel_Button_clicked()));
}

bool MainWindow::eventFilter(QObject *, QEvent *event)
{if(Can_Play){
    // Hint: Notice the Number of every event!
    if(event->type() == QEvent::MouseButtonPress)
    {
        /* TODO : add your code here */
        Mouse_Press_x=QCursor::pos().x();
        Mouse_Press_y=QCursor::pos().y();
        //std::cout << "Press !" << std::endl ;
        if(Mouse_Press_y>200){
            if(!Is_Press&&!Is_Flying){
                if(Bird_Control>0 && Bird_Control<6+More_Bird&&!Is_Delete_Bird[Bird_Control-1]){
                    Is_Delete_Bird[Bird_Control-1]=true;
                    Bird_Bullet[Bird_Control-1]->Delete_Bird();
                    delete Bird_Bullet[Bird_Control-1];
                }

                if(Bird_Control>=0 && Bird_Control<5+More_Bird){
                    Bird_Bullet[Bird_Control]->Kikk_Gravity();
                    Bird_Bullet[Bird_Control]->setLinearVelocity(b2Vec2(0,0));
                    Music->stop();
                }

                Is_Press=true;
                Release_Time=-10000;
                sling->Set_Transform(-20);
                Fake->Set_Transform(100);
            }
            else if(!Is_Press&&Is_Flying&&!Is_Skill){
                if(Bird_Control>0&&Bird_Control<6+More_Bird){
                    Bird_Bullet[Bird_Control-1]->Skill();
                    Bomb_Life=96;
                    Skill_Time=0;
                    Release_Time-=35;
                    Is_Skill=true;
                }
            }
        }
    }
    if(event->type() == QEvent::MouseMove)
    {
        /* TODO : add your code here */
        //std::cout << "x=" << QCursor::pos().x() << ",y=" << QCursor::pos().y() << std::endl;
        if(Mouse_Press_y>200){
            if(Is_Press){
                if(Bird_Control>=0 && Bird_Control<5+More_Bird)
                    Bird_Bullet[Bird_Control]->Set_Transform(b2Vec2((QCursor::pos().x()-Mouse_Press_x+450)/150.0,(-QCursor::pos().y()+Mouse_Press_y+1080)/150.0));
            }
        }
    }
    if(event->type() == QEvent::MouseButtonRelease)
    {
        /* TODO : add your code here */
        //std::cout << "Release !" << std::endl ;
        if(Mouse_Press_y>200){
            if(Is_Press&&!Is_Flying){
                if(Bird_Control>=5+More_Bird){
                    ++Bird_Control;
                    view->show();
                }
                if(Bird_Control>=0 && Bird_Control<5+More_Bird){
                    float x=(-QCursor::pos().x()+Mouse_Press_x)/10.0;
                    float y=(QCursor::pos().y()-Mouse_Press_y)/10.0;
                    x=x<=30?x:30;
                    x=x>=-30?x:-30;
                    y=y<=30?y:30;
                    y=y>=-30?y:-30;
                    Bird_Bullet[Bird_Control]->setLinearVelocity(b2Vec2(x,y));
                    Bird_Bullet[Bird_Control]->Add_Gravity();
                    switch(Bird_Change_Color%6){
                        case 0:
                            Music->setMedia(QUrl("qrc:/Music/Music.mp3"));
                        break;
                        case 1:
                            Music->setMedia(QUrl("qrc:/Music/Music2.mp3"));
                        break;
                        case 2:
                            Music->setMedia(QUrl("qrc:/Music/Music3.mp3"));
                        break;
                        case 3:
                            Music->setMedia(QUrl("qrc:/Music/Music4.mp3"));
                        break;
                        case 4:
                            Music->setMedia(QUrl("qrc:/Music/Music5.mp3"));
                        break;
                        case 5:
                            Music->setMedia(QUrl("qrc:/Music/Music6.mp3"));
                            Score+=20000;
                        break;
                        default:
                            Music->setMedia(QUrl("qrc:/Music/Music.mp3"));
                    }
                    Music->play();
                    ++Bird_Control;
                    Release_Time=0;
                    Is_Flying=true;
                    Is_Press=false;
                }
                for(int i=0;i<5;++i){
                    Is_Hit_Pig[i]=false;
                }
                for(int i=0;i<15;++i){
                    Is_Hit_Wall[i]=false;
                }
            }
        }
    }}
    return false;
}

void MainWindow::closeEvent(QCloseEvent *)
{
    // Close event
    emit quitGame();
}

void MainWindow::tick()
{if(Can_Play){
    Show_Score->setText("Score :  " + QString::number(Score));
    Show_Score2->setText("Score :  " + QString::number(Score));
    world->Step(1.0/60.0,6,2);
    scene->update();
    ++Release_Time;
    ++Skill_Time;
    --Bomb_Life;
    --Raining_Time;
    Bird_Change_Color=Bird_Change_Color+1<0xffffff?Bird_Change_Color+1:0;
    if(Release_Time==16){
        sling->Set_Transform(4);
        Fake->Set_Transform(4);
    }
    if(( Release_Time>=200) && Is_Flying){
        if(Bird_Control>=0 && Bird_Control<5+More_Bird)
            Bird_Bullet[Bird_Control]->Init_Position();
        Is_Flying=false;
        Is_Skill=false;
    }
    if(Is_Skill&&Skill_Time==32){
        if(Bird_Control>0 && Bird_Control<6+More_Bird){
            Bomb_Life=96;
            Bird_Bullet[Bird_Control-1]->Skill2();
        }
    }
    if(Bird_Control<=5+More_Bird){
        for(int i=0;i<5;++i){
            --Dead_Pig_Count[i];
            if(!Is_Hit_Pig[i]&&!Is_Dead_Pig[i]){
                int tmp=pig[i]->Kill();
                if(tmp==1){
                    Is_Hit_Pig[i]=true;
                }
                else if(tmp==2){
                    Is_Dead_Pig[i]=true;
                    Dead_Pig_Count[i]=32;
                }
            }
            if(Dead_Pig_Count[i]<=0 && Dead_Pig_Count[i]>-90000 && !Is_Delete_Pig[i] && Is_Dead_Pig[i]){
                Is_Delete_Pig[i]=true;
                delete pig[i];
                Score+=3000;
            }
        }
        for(int i=0;i<15;++i){
            --Dead_Wall_Count[i];
            if(!Is_Hit_Wall[i] && !Is_Dead_Wall[i]){
                int tmp=wall[i]->Kill();
                if(tmp==1){
                    Is_Hit_Wall[i]=true;
                }
                else if(tmp==2){
                    Is_Dead_Wall[i]=true;
                    Dead_Wall_Count[i]=32;
                }
            }
            if(Dead_Wall_Count[i]<=0 && Dead_Wall_Count[i]>-90000 && !Is_Delete_Wall[i] && Is_Dead_Wall[i]){
                Is_Delete_Wall[i]=true;
                delete wall[i];
                Score+=500;
            }
        }
    }
    else{
        Can_Play=false;
    }
    for(int i=0;i<5+More_Bird;++i){
        if(Birds_Color[i]==4&&!Is_Delete_Bird[i]){
            switch((Bird_Change_Color/10)%4){
            case 0:
                Bird_Bullet[i]->Set_Pixmap(QPixmap(":/Bird/Bird_Black1.png").scaled(scene->height()/9.0,scene->height()/9.0));
            break;
            case 1:
                Bird_Bullet[i]->Set_Pixmap(QPixmap(":/Bird/Bird_Black2.png").scaled(scene->height()/9.0,scene->height()/9.0));
            break;
            case 2:
                Bird_Bullet[i]->Set_Pixmap(QPixmap(":/Bird/Bird_Black3.png").scaled(scene->height()/9.0,scene->height()/9.0));
            break;
            case 3:
                Bird_Bullet[i]->Set_Pixmap(QPixmap(":/Bird/Bird_Black4.png").scaled(scene->height()/9.0,scene->height()/9.0));
            break;
            default:
                Bird_Bullet[i]->Set_Pixmap(QPixmap(":/Bird/Bird_Black1.png").scaled(scene->height()/9.0,scene->height()/9.0));
            }
        }
        if(Birds_Color[Bird_Control-1]==4&&!Is_Delete_Bird[Bird_Control-1]&&Is_Skill&&Bomb_Life>=0){
            QPointF F = Bird_Bullet[Bird_Control-1]->Get_Position_Px();
            if(Bomb_Life>64){
                Bomb_Cloud->setPixmap(QPixmap(":/Background/Bomb1.png").scaled(scene->height()/5.0,scene->height()/5.0));
                Bomb_Cloud->setGeometry(F.x(),F.y()-110,300,300);
                Bomb_Cloud->show();
            }
            else if(Bomb_Life>32){
                Bomb_Cloud->setPixmap(QPixmap(":/Background/Bomb2.png").scaled(scene->height()/4.0,scene->height()/4.0));
            }
            else if(Bomb_Life>0){
                Bomb_Cloud->setPixmap(QPixmap(":/Background/Bomb3.png").scaled(scene->height()/3.0,scene->height()/3.0));
            }
            else{
                Bomb_Cloud->hide();
            }
        }
        if(Birds_Color[Bird_Control-1]==3&&!Is_Delete_Bird[Bird_Control-1]&&Is_Skill&&Bomb_Life>=0){
            QPointF F = Bird_Bullet[Bird_Control-1]->Get_Position_Px();
            if(Bomb_Life>64){
                Bomb_Cloud->setPixmap(QPixmap(":/Background/Bomb1.png").scaled(scene->height()/5.0,scene->height()/5.0));
                Bomb_Cloud->setGeometry(F.x(),F.y()-110,300,300);
                Bomb_Cloud->show();
            }
            else if(Bomb_Life>32){
                Bomb_Cloud->setPixmap(QPixmap(":/Background/Bomb2.png").scaled(scene->height()/4.0,scene->height()/4.0));
            }
            else if(Bomb_Life>0){
                Bomb_Cloud->setPixmap(QPixmap(":/Background/Bomb3.png").scaled(scene->height()/3.0,scene->height()/3.0));
            }
            else{
                Bomb_Cloud->hide();
            }
        }
    }
    if(Raining_Time==0){
        for(int i=0;i<20;++i)
            delete Rain[i];
    }
}}

void MainWindow::QUITSLOT()
{
    // For debug
    std::cout << "Quit Game Signal receive !" << std::endl ;
}

void MainWindow::Exit()
{
    close();
}

void MainWindow::Description()
{
    if(Is_Show)
        view3->close();
    else
        view3->show();
}

void MainWindow::Replay()
{
    itemList.clear();
    for(int i=0;i<5;++i){
        if(!Is_Delete_Pig[i]){
            Is_Delete_Pig[i]=true;
            delete pig[i];
        }
    }
    for(int i=0;i<5+More_Bird;++i){
        if(!Is_Delete_Bird[i]){
            Is_Delete_Bird[i]=true;
            delete Bird_Bullet[i];
        }
    }
    for(int i=0;i<15;++i){
        if(!Is_Delete_Wall[i]){
            Is_Delete_Wall[i]=true;
            delete wall[i];
        }
    }

    wall[0]=new Wall_Iron(24,8,width()/48.0,height()/27.0,&timer,QPixmap(":/Background/Wall_Iron.png").scaled(width()/48.0,height()/2.7),world,scene);
    wall[1]=new Wall_Iron(23.2,8,width()/48.0,height()/27.0,&timer,QPixmap(":/Background/Wall_Iron.png").scaled(width()/48.0,height()/2.7),world,scene);
    wall[2]=new Wall_Iron(22.4,8,width()/48.0,height()/27.0,&timer,QPixmap(":/Background/Wall_Iron.png").scaled(width()/48.0,height()/2.7),world,scene);
    wall[3]=new Wall_Glass(29,8,width()/48.0,height()/27.0,&timer,QPixmap(":/Background/Wall_Glass.png").scaled(width()/48.0,height()/2.7),world,scene);
    wall[4]=new Wall_Glass(17.4,8,width()/48.0,height()/27.0,&timer,QPixmap(":/Background/Wall_Glass.png").scaled(width()/48.0,height()/2.7),world,scene);
    wall[5]=new Wall_Wood(26.35,15,width()/48.0,height()/27.0,&timer,QPixmap(":/Background/Wall_Wood.png").scaled(width()/48.0,height()/2.7),world,scene);
    wall[6]=new Wall_Wood(21.35,15,width()/48.0,height()/27.0,&timer,QPixmap(":/Background/Wall_Wood.png").scaled(width()/48.0,height()/2.7),world,scene);
    wall[7]=new Wall_Wood(23.75,20,width()/48.0,height()/27.0,&timer,QPixmap(":/Background/Wall_Wood.png").scaled(width()/48.0,height()/2.7),world,scene);
    wall[8]=new Wall_Wood(19.9,13,width()/48.0,height()/27.0,&timer,QPixmap(":/Background/Wall_Wood.png").scaled(width()/48.0,height()/2.7),world,scene);
    wall[9]=new Wall_Wood(26.5,13,width()/48.0,height()/27.0,&timer,QPixmap(":/Background/Wall_Wood.png").scaled(width()/48.0,height()/2.7),world,scene);
    wall[7]->Set_Transform(1.57);
    wall[8]->Set_Transform(1.57);
    wall[9]->Set_Transform(1.57);
    wall[10]=new Wall_Iron(15,15,width()/48.0,height()/27.0,&timer,QPixmap(":/Background/Wall_Iron.png").scaled(width()/48.0,height()/2.7),world,scene);
    wall[11]=new Wall_Iron(11,15,width()/48.0,height()/27.0,&timer,QPixmap(":/Background/Wall_Iron.png").scaled(width()/48.0,height()/2.7),world,scene);
    wall[12]=new Wall_Iron(11,8,width()/48.0,height()/27.0,&timer,QPixmap(":/Background/Wall_Iron.png").scaled(width()/48.0,height()/2.7),world,scene);
    wall[13]=new Wall_Iron(16,8,width()/48.0,height()/27.0,&timer,QPixmap(":/Background/Wall_Iron.png").scaled(width()/48.0,height()/2.7),world,scene);
    wall[14]=new Wall_Iron(13.3,13,width()/48.0,height()/27.0,&timer,QPixmap(":/Background/Wall_Iron.png").scaled(width()/48.0,height()/2.7),world,scene);
    wall[10]->Set_Transform(0.45);
    wall[11]->Set_Transform(-0.45);
    wall[14]->Set_Transform(1.57);

    pig[0] = new Pig(26.4,6,0.27,&timer,QPixmap(":/Bird/Pig1.png").scaled(scene->height()/9.0,scene->height()/9.0),world,scene);
    pig[1] = new Pig(19.6,6,0.27,&timer,QPixmap(":/Bird/Pig1.png").scaled(scene->height()/9.0,scene->height()/9.0),world,scene);
    pig[2] = new Pig(13.5,6,0.27,&timer,QPixmap(":/Bird/Pig1.png").scaled(scene->height()/9.0,scene->height()/9.0),world,scene);
    pig[3] = new Pig(23.5,14,0.27,&timer,QPixmap(":/Bird/Pig3.png").scaled(scene->height()/9.0,scene->height()/9.0),world,scene);
    pig[4] = new Pig(13.3,13,0.27,&timer,QPixmap(":/Bird/Pig3.png").scaled(scene->height()/9.0,scene->height()/9.0),world,scene);

    for(int i=0;i<5;++i){
        Bird_Bullet[i]=bird_generator(&timer,world,scene,(i*3+5.0),Birds_Color[i]);
        itemList.push_back(Bird_Bullet[i]);
    }
    Bird_Bullet[0]->Init_Position();
    sling->Set_Transform(4);
    Fake->Set_Transform(4);

    Is_Press=false;
    Is_Flying=false;
    Is_Skill=false;
    Can_Play=true;
    Is_Show=false;
    Bird_Control=0;
    Skill_Time=0;
    Score=0;
    Bomb_Life=-1;
    Raining_Time=-1;
    More_Bird=0;
    for(int i=0;i<5;++i){
        Is_Hit_Pig[i]=true;
        Is_Dead_Pig[i]=false;
        Is_Delete_Pig[i]=false;
        Dead_Pig_Count[i]=-99999;
        Is_Delete_Bird[i]=false;
    }
    for(int i=0;i<15;++i){
        Is_Hit_Wall[i]=true;
        Is_Dead_Wall[i]=false;
        Is_Delete_Wall[i]=false;
        Dead_Wall_Count[i]=-99999;
    }
    Music->stop();
    view3->close();
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

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Z){
        if(More_Bird<90){
            Score-=5000;
            ++More_Bird;
            Is_Delete_Bird[More_Bird+4]=false;
            Bird_Bullet[More_Bird+4]=bird_generator(&timer,world,scene,(More_Bird*3+17.0),Birds_Color[More_Bird+4]);
        }
    }
    if(event->key()==Qt::Key_X && Raining_Time<0){
        Raining_Time=200;
        Score-=5000;
        for(int i=0;i<20;++i){
            Rain[i] = new Bird_Black((i+4),20,0.27,&timer,QPixmap(":/Bird/Bird_White2.png").scaled(scene->height()/45.0,scene->height()/45.0),world,scene);
            Rain[i]->setLinearVelocity(b2Vec2(3,-3));
        }
        for(int i=0;i<5;++i){
            Is_Hit_Pig[i]=false;
        }
        for(int i=0;i<15;++i){
            Is_Hit_Wall[i]=false;
        }
    }
}
