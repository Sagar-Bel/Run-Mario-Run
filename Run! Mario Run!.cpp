#include <conio.h>
#include <iostream>
#include <graphics.h>
#include <mmsystem.h>
#include <windows.h>
#include <fstream>
#include <string.h>
namespace Quiz{ 
          #include "Quiz\Quiz.cpp"
          }
using namespace std;
class data
{
      char na[11];
      int score,life;
      public:
             char* naret()
             {return na;}
             int scoreret()
             {return score;}
             void naacc(char a[11])
             {strcpy(na,a);life=2;}
             void scoreacc(int a)
             {score=a;}
             int life_red()
             {
                  if(life>0)
                  life--;
                  else
                  return 0;
                  return 1;
             }
             data()
             {score=0;life=2;}
}player;
int p[4];
void mm();
void nasc();
int game();
int up(int ,int ,int );
int pipe(int ,int ,int );
int pipe(int ,int );
int piped(int ,int ,int &);
void die(int ,int ,int ,int );
void scorepump();
void lose();
void win();
void info();
void hsc();
void pass();
int main()
{
    //pass();
    cout<<"x="<<getmaxwidth()<<"y="<<getmaxheight();
    initwindow(1018,730,"Run! Mario Run!");
    for(int i=0;i<1000;i+=5)
    {
            readimagefile("Cover.GIF",0,0,1018,730);
            readimagefile("Fireball2.GIF",0+i,560,35+i,635);
            readimagefile("Mario.GIF",180+i,570,215+i,635);
            delay(10);
    }
    mm();
    getch();
}
void mm()
{
     readimagefile("Mainmenu.GIF",0,0,1018,730);
     int xc=-1,yc=-1;
     b:for(;xc==-1&&yc==-1;)
     {
                            getmouseclick(WM_LBUTTONUP,xc,yc);
                            if(GetAsyncKeyState(VK_CONTROL)&&GetAsyncKeyState(VK_MENU)&&GetAsyncKeyState(72))
                            {ofstream hsc("Highscore.dat",ios::out|ios::binary|ios::trunc);hsc.close();}
     }
     if(xc>325&&xc<680&&yc>135&&yc<200)
     nasc();
     else if(xc>325&&xc<500&&yc>210&&yc<265)
     info();
     else if(xc>325&&xc<680&&yc>275&&yc<340)
     hsc();
     else if(xc>325&&xc<500&&yc>345&&yc<400)
     exit();
     else 
     {
          xc=-1;yc=-1;
          goto b;
     }
}
void nasc()
{
     int l;
     char na[10];
     readimagefile("Namescreen.GIF",0,0,1018,730);
     setcolor(WHITE);
     setbkcolor(COLOR(93,148,251));
     settextstyle(0,0,72);
     a:streamsize size=cin.rdbuf()->in_avail();
     for(int i=0;i<size;i++)
     getch();
     readimagefile("Namescreen.GIF",0,0,1018,730);
     for(int i=0;i<11;i++)
     {
             l=getch();
             if(l==0)
             {getch();goto a;}
             if(l==13)
             {na[i]='\0';break;}
             if(l==8)
             if(i>0)
             {
                     readimagefile("Blue.GIF",156+((i-1)*72),225,190+((i-1)*72),277);
                     i-=2;
                     continue;
             }
             else
             {
                 i--;
                 continue;
             }
             if(i==10)
             if(l==13)
             {na[i]='\0';break;}
             else
             {i--;continue;}
             na[i]=(char)l;
             bgiout<<(char)l;
             outstreamxy(158+(i*72),225);
     }
     player.naacc(na);
     game();
}
int game( )
{
    int s,d,pb,pf,pt,pp,pd,b,score;
    beg:PlaySound(TEXT("Theme.WAV"),NULL,SND_ASYNC);
    int x=0,y=-220,xm=480,ym=550,l=0;
    readimagefile("Level_1-1.GIF",x,y,x+14336,y+960);
    readimagefile("Fireball.GIF",0,0,35,585+(65/2));
    readimagefile("Mario.GIF",xm,ym,xm+35,ym+65);
    for(int i=0;i<4;i++)p[i]=1;
    for(;;)
    {
           pt=pipe(x,xm+35);
           pf=pipe(x,xm+35,ym);
           pb=pipe(x,xm,ym);
           pd=piped(x,xm,pp);
           if(ym==550||(ym==420&&pt))
           s=0;
           if(ym>550)
           ym=550;
           d=up(x,xm,ym);
           if(d)
           break;
           if (GetAsyncKeyState(VK_UP)&&!s)
           {
                                               s=1;
                                               readimagefile("Level_1-1.GIF",x,y,x+14336,y+960);
                                               readimagefile("Fireball.GIF",0,0,35,585+(65/2));
                                               ym-=200;
                                               readimagefile("MarioU.GIF",xm,ym,xm+35,ym+65);
           }
           else if(s)
           {
                readimagefile("Level_1-1.GIF",x,y,x+14336,y+960);
                readimagefile("Fireball.GIF",0,0,35,585+(65/2));
                if(pt&&pf&&pb)
                {
                     if(ym<420)
                     ym+=10;
                }
                else if(ym<550)
                ym+=10;
                if(b==0)
                readimagefile("MarioU.GIF",xm,ym,xm+35,ym+65);
           }
           b=0;
           if (GetAsyncKeyState(VK_LEFT)&&xm>0&&!pb)
           {
                                               readimagefile("Level_1-1.GIF",x,y,x+14336,y+960);
                                               readimagefile("Fireball.GIF",0,0,35,585+(65/2));
                                               xm-=10;
                                               if(s==1)
                                               readimagefile("MarioUB.GIF",xm,ym,xm+35,ym+65);
                                               else
                                               readimagefile("MarioB.GIF",xm,ym,xm+35,ym+65);
                                               b=1;
           }
           if (GetAsyncKeyState(VK_RIGHT)&&!pf)
           {
                                          readimagefile("Level_1-1.GIF",x-=10,y,x+14336,y+960);
                                          readimagefile("Fireball.GIF",0,0,35,585+(65/2));
                                          if(s==1)
                                          readimagefile("MarioU.GIF",xm,ym,xm+35,ym+65);
                                          else
                                          readimagefile("Mario.GIF",xm,ym,xm+35,ym+65);
           }
           if (GetAsyncKeyState(VK_DOWN)&&pd)
           {
                                                      delay(200);
                                                      for(;ym<=480;ym+=10)
                                                      {
                                                             readimagefile("Level_1-1.GIF",x,y,x+14336,y+960);
                                                             readimagefile("Fireball.GIF",0,0,35,585+(65/2));
                                                             readimagefile("Mario.GIF",xm,ym,xm+35,ym+65);
                                                             readimagefile("Pipe.GIF",pp+x,480,pp+130+x,610);
                                                             delay(50);
                                                      }
                                                      if(pd==1)
                                                      p[0]=0;
                                                      else if(pd==2)
                                                      p[1]=0;
                                                      else if(pd==3)
                                                      p[2]=0;
                                                      else if(pd==4)
                                                      p[3]=0;
                                                      score+=Quiz::main(l);
                                                      if(l==1)
                                                      goto end;
                                                      delay(500);
                                                      for(;ym>=420;ym-=10)
                                                      {
                                                             readimagefile("Level_1-1.GIF",x,y,x+14336,y+960);
                                                             readimagefile("Fireball.GIF",0,0,35,585+(65/2));
                                                             readimagefile("Mario.GIF",xm,ym,xm+35,ym+65);
                                                             readimagefile("Pipe.GIF",pp+x,480,pp+130+x,610);
                                                             delay(50);
                                                      }                                                                                    
           }
           s=1;
           if(xm<=35)
           break;
           if((xm+35)+(-x)>=13080)
           {
                                  score+=(-x)/125;
                                  player.scoreacc(score);
                                  win();
           }
    }
    die(x,y,xm,ym);
    end:score+=(-x)/125;
    if(player.life_red())
    goto beg;
    player.scoreacc(score);
    lose();
    return  0;
}
int up(int x,int xm,int ym)
{
    if(ym>=550)
    {
               if((xm+(-x)>510&&(-x)+(xm+35)<635))
               return 1;
               if((xm+(-x)>1280&&(-x)+(xm+35)<1405))
               return 1;
               if((xm+(-x)>1660&&(-x)+(xm+35)<1785))
               return 1;
               if((xm+(-x)>1855&&(-x)+(xm+35)<1916))
               return 1;
               if((xm+(-x)>1983&&(-x)+(xm+35)<2045))
               return 1;
               if((xm+(-x)>2112&&(-x)+(xm+35)<2173))
               return 1;
               if((xm+(-x)>2240&&(-x)+(xm+35)<2300))
               return 1;
               if((xm+(-x)>2367&&(-x)+(xm+35)<2492))
               return 1;
               if((xm+(-x)>2880&&(-x)+(xm+35)<3005))
               return 1;
               if((xm+(-x)>3455&&(-x)+(xm+35)<3517))
               return 1;
               if((xm+(-x)>3583&&(-x)+(xm+35)<3645))
               return 1;
               if((xm+(-x)>3711&&(-x)+(xm+35)<3773))
               return 1;
               if((xm+(-x)>4350&&(-x)+(xm+35)<4541))
               return 1;
               if((xm+(-x)>4735&&(-x)+(xm+35)<4797))
               return 1;
               if((xm+(-x)>4863&&(-x)+(xm+35)<4925))
               return 1;
               if((xm+(-x)>4990&&(-x)+(xm+35)<5052))
               return 1;
               if((xm+(-x)>5120&&(-x)+(xm+35)<5245))
               return 1;
               if((xm+(-x)>5311&&(-x)+(xm+35)<5436))
               return 1;
               if((xm+(-x)>5503&&(-x)+(xm+35)<5630))
               return 1;
               if((xm+(-x)>5951&&(-x)+(xm+35)<6076))
               return 1;
               if((xm+(-x)>6528&&(-x)+(xm+35)<6653))
               return 1;
               if((xm+(-x)>6720&&(-x)+(xm+35)<6845))
               return 1;
               if((xm+(-x)>7422&&(-x)+(xm+35)<7549))
               return 1;
               if((xm+(-x)>7808&&(-x)+(xm+35)<7870))
               return 1;
               if((xm+(-x)>7935&&(-x)+(xm+35)<8060))
               return 1;
               if((xm+(-x)>8127&&(-x)+(xm+35)<8189))
               return 1;
               if((xm+(-x)>8255&&(-x)+(xm+35)<8380))
               return 1;
               if((xm+(-x)>8447&&(-x)+(xm+35)<8509))
               return 1;
               if((xm+(-x)>8575&&(-x)+(xm+35)<8700))
               return 1;
               if((xm+(-x)>9024&&(-x)+(xm+35)<9149))
               return 1;
               if((xm+(-x)>9599&&(-x)+(xm+35)<9785))
               return 1;
               if((xm+(-x)>9855&&(-x)+(xm+35)<9917))
               return 1;
               if((xm+(-x)>9983&&(-x)+(xm+35)<10108))
               return 1;
               if((xm+(-x)>10879&&(-x)+(xm+35)<11069))
               return 1;
               if((xm+(-x)>11135&&(-x)+(xm+35)<11325))
               return 1;
               if((xm+(-x)>11391&&(-x)+(xm+35)<11516))
               return 1;
               if((xm+(-x)>11583&&(-x)+(xm+35)<11708))
               return 1;
               if((xm+(-x)>11775&&(-x)+(xm+35)<11837))
               return 1;
               if((xm+(-x)>11903&&(-x)+(xm+35)<11965))
               return 1;
               if((xm+(-x)>12031&&(-x)+(xm+35)<12156))
               return 1;
               if((xm+(-x)>12671&&(-x)+(xm+35)<12861))
               return 1;
    }
    return 0;
}

int pipe(int x,int xm,int ym)
{
    if(ym>420||ym==0)
    {
              if((xm+(-x)>765&&(-x)+(xm)<895))
              return 1;
              if((xm+(-x)>4605&&(-x)+(xm)<4735))
              return 1;
              if((xm+(-x)>8765&&(-x)+(xm)<8895))
              return 1;
              if((xm+(-x)>10495&&(-x)+(xm)<10625))
              return 1;
    }
    return 0;
}

int pipe(int x,int xm)
{
              if((xm+(-x)>765&&(-x)+(xm-35)<895))
              return 1;
              if((xm+(-x)>4605&&(-x)+(xm-35)<4735))
              return 1;
              if((xm+(-x)>8765&&(-x)+(xm-35)<8895))
              return 1;
              if((xm+(-x)>10495&&(-x)+(xm-35)<10625))
              return 1;
              return 0;
}

int piped(int x,int xm,int &pp)
{
              if((xm+(-x)>765&&(-x)+(xm+35)<895)&&p[0])
              {pp=765;return 1;}
              if((xm+(-x)>4605&&(-x)+(xm+35)<4735)&&p[1])
              {pp=4605;return 2;}
              if((xm+(-x)>8765&&(-x)+(xm+35)<8895)&&p[2])
              {pp=8765;return 3;}
              if((xm+(-x)>10495&&(-x)+(xm+35)<10625)&&p[3])
              {pp=10495;return 4;}
              return 0;
}
    
void die(int x,int y,int xm,int ym)
{
     PlaySound(TEXT("die.WAV"),NULL,SND_ASYNC);
     readimagefile("Level_1-1.GIF",x,y,x+14336,y+960);
     readimagefile("Fireball.GIF",0,0,35,585+(65/2));
     readimagefile("MarioD.GIF",xm,ym,xm+35,ym+65);
     delay(1000);
     for(;ym>400;)
     {
                  readimagefile("Level_1-1.GIF",x,y,x+14336,y+960);
                  readimagefile("Fireball.GIF",0,0,35,585+(65/2));
                  ym-=20;
                  readimagefile("MarioD.GIF",xm,ym,xm+35,ym+65);
     }
     for(;ym<700;)
     {
                  readimagefile("Level_1-1.GIF",x,y,x+14336,y+960);
                  readimagefile("Fireball.GIF",0,0,35,585+(65/2));
                  ym+=20;
                  readimagefile("MarioD.GIF",xm,ym,xm+35,ym+65);
     }
}

void scorepump()
{
     int pt=0,tsi;
     data s;
     ifstream fout("Highscore.dat",ios::in|ios::binary);
     ofstream temp("temp.dat",ios::out|ios::binary|ios::trunc);
     fout.seekg(0,ios::end);
     tsi=fout.tellg();
     fout.seekg(0,ios::beg);
     while(fout.tellg()<tsi&&fout.tellg()>=0)
     {
                            fout.read((char*)&s,sizeof(data));
                            if(player.scoreret()>s.scoreret()&&pt==0)
                            {
                                                                temp.write((char*)&player,sizeof(data));
                                                                pt=1;
                            }                             
                            temp.write((char*)&s,sizeof(data));
     }
     if(pt==0)
     temp.write((char*)&player,sizeof(data));
     fout.close();
     temp.close();
     remove("Highscore.dat");
     rename("temp.dat","Highscore.dat");
}

void lose()
{
     scorepump();
     readimagefile("You lose.GIF",0,0,1018,730);
     setcolor(WHITE);
     bgiout<<player.naret();
     setbkcolor(COLOR(93,148,251));
     settextstyle(0,0,96);
     outstreamxy(290, 155);
     bgiout<<player.scoreret()<<"m";
     outstreamxy(310, 250);
     int xc=-1,yc=-1;
     c:for(;xc==-1&&yc==-1;)
     getmouseclick(WM_LBUTTONUP,xc,yc);
     if(xc>90&&xc<400&&yc>410&&yc<470)
     mm();
     else if(xc>635&&xc<950&&yc>410&&yc<470)
     hsc();
     else
     {
         xc=-1;
         yc=-1;
         goto c;
     }
}
void win()
{
     scorepump();
     readimagefile("You win.GIF",0,0,1018,730);
     setcolor(WHITE);
     bgiout<<player.naret();
     setbkcolor(COLOR(93,148,251));
     settextstyle(0,0,96);
     outstreamxy(290, 155);
     bgiout<<player.scoreret()<<"m";
     outstreamxy(310, 250);
     int xc=-1,yc=-1;
     c:for(;xc==-1&&yc==-1;)
     getmouseclick(WM_LBUTTONUP,xc,yc);
     if(xc>90&&xc<400&&yc>410&&yc<470)
     mm();
     else if(xc>635&&xc<950&&yc>410&&yc<470)
     hsc();
     else
     {
         xc=-1;
         yc=-1;
         goto c;
     }
}
void info()
{
     readimagefile("Info.GIF",0,0,1018,730);
     int xc=-1,yc=-1;
     d:for(;xc==-1&&yc==-1;)
     getmouseclick(WM_LBUTTONUP,xc,yc);
     if(xc>320&&xc<630&&yc>545&&yc<600)
     mm();
     else
     {
         xc=-1;
         yc=-1;
         goto d;
     }
}

void hsc()
{
     int tsi,i=0,x=200;
     ifstream fout("Highscore.dat",ios::in);
     fout.seekg(0,ios::end);
     tsi=fout.tellg();
     fout.seekg(0,ios::beg);
     readimagefile("Highscore.GIF",0,0,1018,730);
     setcolor(WHITE);
     setbkcolor(COLOR(93,148,251));
     settextstyle(0,0,72);
     while(fout.tellg()<tsi&&i<5)
     {
             fout.read((char*)&player,sizeof(data));
             bgiout<<i+1;
             outstreamxy(105, x);
             bgiout<<player.naret();
             outstreamxy(345, x);
             bgiout<<player.scoreret()<<"m";
             outstreamxy(830, x);
             i++;
             x+=60;
     }
     fout.close();
     int xc=-1,yc=-1;
     d:for(;xc==-1&&yc==-1;)
     getmouseclick(WM_LBUTTONUP,xc,yc);
     if(xc>320&&xc<630&&yc>545&&yc<600)
     mm();
     else
     {
         xc=-1;
         yc=-1;
         goto d;
     }
}
void pass()
{
     char pass[9];
     a:cout<<"ENTER PASSWORD.(HINT:PASSWORD)\n";
     cin>>pass;
     if(strcmp(pass,"PASSWORD")!=0)
     {
                                   cout<<"INCORRECT PASSWORD.\n";
                                   goto a;
     }
     system("cls");
}
