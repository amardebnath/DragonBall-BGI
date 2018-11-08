#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "graphics.h"
#include "winbgim.h"
#include "helper1.h"

//this makes opponents come high or low above the ground
int up(int a[],int b)
{
    if(a[b%10]==0) return 0;
    else return -65;
}
//this encrypts the name of the highscore file
void encrypt(char s1[], char s2[])
{
    int i, j, k;
    for(i=0, j = 0; s1[i]; i++, j++)
    {
        if(j==3) j=0;
        if(s1[i] >= 'a' && s1[i] <= 'z')
        {
            k = 'a' + ((s1[i]-'a'+s2[j]-'a') % 26);
        }
        else
        {
             k = 'A' + ((s1[i]-'A'+s2[j]-'a') % 26);
        }
        s1[i] = k;
    }
}
//this decrypts the name of the highscore file
void decrypt(char s1[], char s2[])
{
    int i, j, k;
    for(i=0, j = 0; s1[i]; i++, j++)
    {
        if(j==3) j=0;
        if(s1[i] >= 'a' && s1[i] <= 'z') k = 'a' + (s1[i]-'a'+26-s2[j]+'a') % 26;
        else k = 'A' + (s1[i]-'A'+26-s2[j]+'a') % 26;
        s1[i] = k;
    }
}

//this loads the background
void background1(int *score, int enemy, int lives, char s1[])
{
    int a = *score;
    char e[10], l[10], s[10];
    itoa(enemy, e, 10);
    itoa(lives, l, 10);
    itoa(*score, s, 10);
    readimagefile(s1, 0,0, 1000, 600);
    outtextxy(130,90, "Enemy:  ");
    outtextxy(220,90, e);
    outtextxy(440, 90, "Score: ");
    outtextxy(540, 90, s);
    outtextxy(750,90, "Lives: ");
    outtextxy(850,90, l);
}
//detects collision of hero and enemy
bool collision(int x, int y, int u, int v, int j, int k)
{
    if(u-k-x-65 <= 0 && u-k+60-x-10 >= 0 && v-y-80+j <= 0)
    {
        outtextxy(x+45, y-j-80, " -1 ");
        delay(80);
        return true;
    }
    return false;
}
bool rcollision(int x, int y, int u, int v, int j, int k,int h)
{
    if(u-k-x-65 <= 0 && u-k+60-x-10 >= 0 && v+h-y+j >= 0)
    {
        outtextxy(x+45, y-j-80, " -1 ");
        delay(80);
        return true;
    }
    return false;
}
//detects if blast hit enemy
bool enemyhit(int x, int y, int u, int v, int j, int k, int t)
{
    if(u-k-x-170-j <= 0 && u+60-k-x-100-j >= 0)
    {
        if(t==1)
        {
            outtextxy(u-k+20,v-50," -1 ");
            delay(80);
        }
        else delay(50);
        return true;
    }
    return false;
}
//generates random 0s and 1s
int random()
{
    srand(time(NULL));
    return rand()%2;
}
//activates pause menu
int pause_menu(long long int i)
{
    int x,y;
    readimagefile("m32.jpg",0,0,1000,600);
    readimagefile("continue.gif",100,450,475,490);
    readimagefile("back.gif",100,530,700,570);
        while(!ismouseclick(WM_LBUTTONDOWN));
        getmouseclick(WM_LBUTTONDOWN, x, y);
        if(x>=100 && x<=475 && y>=450 && y<=490)
        {
            return i;
        }
        else if(x>=100 && x<=700 && y>=530 && y<=570)
        {
            return 0;
        }

}
//activates the menu screen
int menu()
{
    int x, y;
    readimagefile("b2.jpg",0,0,1000,600);
    readimagefile("m1.gif",400,125,600,150);
    readimagefile("m2.gif",375,215,625,240);
    readimagefile("m3.gif",375,305,625,330);
    readimagefile("m5.gif",400,390,590,420);
    readimagefile("m4.gif",430,485,555,510);
    while(1)
    {
        while(!ismouseclick(WM_LBUTTONDOWN));
        getmouseclick(WM_LBUTTONDOWN, x, y);
        if(x>=400 && x<=600 && y>=125 && y<=150)
        {
            readimagefile("m11.gif",400,125,600,150);
            delay(100);
            return 1;
        }
        else if(x>=375 && x<=625 && y>=215 && y<=240)
        {
            readimagefile("m22.gif",375,215,625,240);
            delay(100);
            return 2;
        }
        else if(x>=375 && x<=625 && y>=305 && y<=330)
            {
        readimagefile("m33.gif",375,305,625,330);
        delay(100);
        return 3;
        }
        else if(x>=400 && x<= 590 && y>=390 && y<=420)
        {
            readimagefile("m55.gif",400,390,590,420);
            delay(100);
            return 4;
        }
        else if(x>=430 && x<=555 && y>=485 && y<=510)
        {
            readimagefile("m44.gif",430,485,555,510);
            delay(100);
            return 0;
        }
    }
}
struct f
{
    char name[10];
    int points;
};
//compares the score with the highscore file
void scrcheck(int point)
{
    readimagefile("i1.jpg",0,0,1000,600);
    char player[10]= {'\0'};
    char points1[50], s2[] = "cat";
    int f=0,ak=0,i;
    struct f en[3];
    FILE *f1;
    f1=fopen("f1.txt","r");
    for(i=0; i<3; i++)
    {
        fscanf(f1,"%s %d",&en[i].name,&en[i].points);
        decrypt(en[i].name, s2);
    }
    fclose(f1);
    setbkcolor(BLACK);
    setcolor(WHITE);
    settextstyle(BOLD_FONT,HORIZ_DIR,1);
    outtextxy(300,200,"YOUR NAME: ");
    while(f<10)
    {
        if(kbhit)
        {
            player[f]=getch();
            if (player[f]==13)
            {
                player[f]='\0';
                break;
            }
            if(player[f]==8)
            {
                player[f]='\0';
                player[f-1]='\0';
                f=f-1;ak=1;
            }
            readimagefile("i1.jpg",0,0,1000,600);
            outtextxy(300,200,"YOUR NAME: ");
            outtextxy(460,200,player);
            if(ak==0)
            {
                f=f+1;
            }
            else
            {
                ak=0;
            }
        }

    }
    sprintf(points1,"%d",point);
    outtextxy(300,300,"YOUR SCORE: ");
    outtextxy(430,300,points1);
    getch();
    if(point>en[2].points)
    {
        if(point>en[1].points)
        {
            if(point>en[0].points)
            {
                f1=fopen("f1.txt","w");
                en[2].points=en[1].points;
                en[1].points=en[0].points;
                strcpy(en[2].name,en[1].name);
                strcpy(en[1].name,en[0].name);
                strcpy(en[0].name,player);
                en[0].points=point;
                for(i=0; i<3; i++)
                {
                    encrypt(en[i].name, s2);
                    fprintf(f1,"%s %d\n",en[i].name,en[i].points);
                }
                fclose(f1);
                return;
            }
            else
            {
                f1=fopen("f1.txt","w");
                en[2].points=en[1].points;
                strcpy(en[2].name,en[1].name);
                strcpy(en[1].name,player);
                en[1].points=point;
                for(i=0; i<3; i++)
                {
                    encrypt(en[i].name, s2);
                    fprintf(f1,"%s %d\n",en[i].name,en[i].points);
                }
                fclose(f1);
                return;
            }
        }
        else
        {
            f1=fopen("f1.txt","w");
            strcpy(en[2].name,player);
            en[2].points=point;
            for(i=0; i<3; i++)
            {
                encrypt(en[i].name, s2);
                fprintf(f1,"%s %d\n",en[i].name,en[i].points);
            }
            fclose(f1);
            return;
        }
        getch();
    }

    return;
}

//loads the scoreboard
void leaderboard()
{
    readimagefile("i3.jpg",0,0,1000,600);
    char sc1[50],sc2[50],sc3[50], s2[] = "cat";
    FILE *f1;int ed;int i,h=0;
    struct f en[3];
    setbkcolor(BLACK);
    setcolor(YELLOW);
    settextstyle(BOLD_FONT ,HORIZ_DIR,4);
    outtextxy(350,100,"HIGH SCORES");
    f1=fopen("f1.txt","r");
    for(i=0;i<3;i++)
    {
        fscanf(f1,"%s %d",&en[i].name,&en[i].points);
        decrypt(en[i].name, s2);
    }
    for(i=0;i<3;i++)
    {
        outtextxy(300,200+h,en[i].name);
        sprintf(sc1,"%d",en[i].points);
        outtextxy(500,200+h,sc1);
        h=h+100;
    }
    getch();
}

