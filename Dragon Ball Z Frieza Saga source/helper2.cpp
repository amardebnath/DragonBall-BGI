#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "graphics.h"

//loads the background
void background(int *gpoint, int *fpoint)
{
    readimagefile("bla.jpg", 0,0,1000,600);
    readimagefile("gface.gif", 70, 70, 120, 120);
    readimagefile("fface.gif", 880, 70, 930, 120);
    setfillstyle(SOLID_FILL, RED);
    bar(70, 130, 70+2.5*(*gpoint), 150);
    setfillstyle(SOLID_FILL, BLUE);
    bar(1000-70-2.5*(*fpoint), 130, 930, 150);
}

//moves the enemy and makes him punch and shoot
void move_frieza(int *r, int i, int *t, int *n, int s, int *m, int *gpoint, int *fpoint, int *fshoot_flag, int *fblast_dir, int *fblastx, int *y)
{
    char pic2[][20] = {"fr1.gif", "fr1.gif", "fr2.gif", "fr2.gif", "fr3.gif", "fr3.gif", "fl1.gif", "fl1.gif", "fl2.gif", "fl2.gif",
                       "fl3.gif", "fl3.gif", "bla.jpg",
                       "fr6.gif", "fr7.gif", "fr8.gif", "fl6.gif", "fl7.gif", "fl8.gif", "r10.gif"
                      };
    int friezax = 750, friezay = 380, gokux = 150, gokuy = 380;

    readimagefile(pic2[i%6+*t], friezax+*n, friezay, friezax+100+*n, friezay+128);
    if(rand()%70 == 0 && ((*m>=-150 && *m<=-110) || (*m>=730 && *m<=770) || (*m>=100 && *m<=600)))
    {
        background(gpoint, fpoint);
        readimagefile("fr15.gif", friezax+*n, friezay, friezax+72+*n, friezay+128);
        delay(20);
        background(gpoint, fpoint);
        readimagefile("fr14.gif", friezax+*n, friezay, friezax+72+*n, friezay+128);
        delay(20);

        if(*r == 0) *r = 1, *n = -630;
        else if(*r == 1) *r = 0, *n = 0;

        background(gpoint, fpoint);
        readimagefile("fr15.gif", friezax+*n, friezay, friezax+72+*n, friezay+128);
        delay(20);
        background(gpoint, fpoint);
        readimagefile("fr14.gif", friezax+*n, friezay, friezax+72+*n, friezay+128);
        delay(20);

    }
    if(*r == 0)
    {
        if(friezax+*n - (gokux+80+*m) <= 200)
        {
            if(*n >= -750) *n -= 4;
            *t = 6;
        }
        else
        {
            if(*n < -80) *t = 0;
            if(*n > 100) *t = 6;
            if(*t == 6)
            {
                if(*n >= -750)
                    *n -= 4;
            }
            else
            {
                if(*n <= 170)
                    *n += 4;
            }
        }
        if(*t == 6 && rand()%50==0 && *fshoot_flag == 0)
        {
            background(gpoint, fpoint);
            readimagefile("fl12.gif", friezax+*n, friezay, friezax+128+*n, friezay+128);
            delay(10);
            background(gpoint, fpoint);
            readimagefile("fl11.gif", friezax+*n, friezay, friezax+128+*n, friezay+128);
            delay(10);
            background(gpoint, fpoint);
            readimagefile("fl10.gif", friezax+*n, friezay, friezax+128+*n, friezay+128);
            delay(10);
            *fblastx = friezax+*n-25;
            *fshoot_flag = 1;
            *fblast_dir = 1;
            *y = 0;
        }
    }

    if(*r == 1)
    {
        if(gokux+*m -  (friezax+*n+128) <= 200)
        {
            if(*n <= 170) *n += 4;
            *t = 0;
        }
        else
        {
            if(*n < -700) *t = 0;
            if(*n > -520) *t = 6;
            if(*t == 6)
            {
                if(*n >= -750)
                    *n -= 4;
            }
            else
            {
                if(*n <= 170)
                    *n += 4;
            }
        }
        if(*t == 0 && rand()%25==0 && *fshoot_flag == 0)
        {
            background(gpoint, fpoint);
            readimagefile("fr12.gif", friezax+*n, friezay, friezax+128+*n, friezay+128);
            delay(10);
            background(gpoint, fpoint);
            readimagefile("fr11.gif", friezax+*n, friezay, friezax+128+*n, friezay+128);
            delay(10);
            background(gpoint, fpoint);
            readimagefile("fr10.gif", friezax+*n, friezay, friezax+128+*n, friezay+128);
            delay(10);
            *fblastx = friezax+*n+128;
            *fshoot_flag = 1;
            *fblast_dir = 0;
            *y = 0;
        }
    }

    if(*t == 6 && *r == 0 && (gokux+80+*m-20) - (friezax+*n) >= 0)
    {
        background(gpoint, fpoint);
        readimagefile("fl6.gif", friezax+*n, friezay, friezax+100+*n, friezay+128);
        readimagefile("r10.gif", gokux+*m, gokuy, gokux+80+*m, gokuy+128);
        delay(20);
        background(gpoint, fpoint);
        readimagefile("fl7.gif", friezax+*n, friezay, friezax+100+*n, friezay+128);
        readimagefile("r10.gif", gokux+*m, gokuy, gokux+80+*m, gokuy+128);
        delay(20);
        background(gpoint, fpoint);
        readimagefile("fl8.gif", friezax+*n, friezay, friezax+100+*n, friezay+128);
        readimagefile("r10.gif", gokux+*m, gokuy, gokux+80+*m, gokuy+128);
        delay(20);
        if(*m >= -150) *m -= 20;
        *gpoint = *gpoint - 2;
    }
    else if(*t == 0 && *r == 1 && (friezax+*n+128-30) - (gokux+*m) >= 0)
    {
        background(gpoint, fpoint);
        readimagefile("fr6.gif", friezax+*n, friezay, friezax+100+*n, friezay+128);
        readimagefile("l10.gif", gokux+*m, gokuy, gokux+80+*m, gokuy+128);
        delay(20);
        background(gpoint, fpoint);
        readimagefile("fr7.gif", friezax+*n, friezay, friezax+100+*n, friezay+128);
        readimagefile("l10.gif", gokux+*m, gokuy, gokux+80+*m, gokuy+128);
        delay(20);
        background(gpoint, fpoint);
        readimagefile("fr8.gif", friezax+*n, friezay, friezax+100+*n, friezay+128);
        readimagefile("l10.gif", gokux+*m, gokuy, gokux+80+*m, gokuy+128);
        delay(20);
        if(*m <= 770) *m += 20;
        *gpoint = *gpoint - 2;
    }
}

//moves the hero
void move_goku(int s, int *m, int *gpoint, int *fpoint)
{
    char pic2[][20] = {"r1.gif", "l1.gif", "r2.gif", "l2.gif", "bla.jpg"};
    int gokux = 150, gokuy = 380;

    background(gpoint, fpoint);

    if(s==0 && *m <= 770) *m += 30;
    else if(s==1 && *m >= -150) *m -= 30;

    readimagefile(pic2[2+s], gokux+(*m), gokuy, gokux+105+(*m), gokuy+125);
    delay(10);
}

//moves hero's blast and checks if it hit enemy
void blast_move(int *gblastx, int blast_dir, int *x, int *shoot_flag, int *t, int *n, int *gpoint, int *fpoint)
{
    char pic2[][20] = {"gblast.gif"};

    int friezax = 750, friezay = 380, gokux = 150, gokuy = 380;
    if(*shoot_flag == 1)
    {
        if(blast_dir == 0)
        {
            readimagefile(pic2[0], *gblastx+*x, gokuy+30, *gblastx+25+*x, gokuy+55);
            *x += 40;
        }
        else
        {
            readimagefile(pic2[0], *gblastx+*x, gokuy+30, *gblastx+25+*x, gokuy+55);
            *x -= 40;
        }
        if(*gblastx+25+*x > 980 || *gblastx+*x < 20) *shoot_flag = 0;
    }
    if(blast_dir == 0 && *gblastx+25+*x - friezax-*n >= 0 && friezax+100+*n - *gblastx-*x >= 0)
    {
        background(gpoint, fpoint);
        if(*t == 6)
        {
            readimagefile("fl9.gif", friezax+*n+10, friezay, friezax+100+*n+10, friezay+128);
            if(*n <= 170) *n = *n + 30;
        }
        else
        {
            readimagefile("fl13.gif", friezax+*n+10, friezay, friezax+100+*n+10, friezay+128);
            if(*n <= 170) *n = *n + 30;
            *fpoint = *fpoint - 2;
        }
        *shoot_flag = 0;
        *gblastx = -1000;
        delay(50);
    }
    else if(blast_dir == 1 && friezax+100+*n - *gblastx-*x >= 0 && *gblastx+*x+25 - friezax-*n >= 0)
    {
        background(gpoint, fpoint);
        if(*t == 0)
        {
            readimagefile("fr9.gif", friezax+*n+10, friezay, friezax+100+*n+10, friezay+128);
            if(*n >= -750) *n = *n - 30;
        }
        else
        {
            readimagefile("fr13.gif", friezax+*n+10, friezay, friezax+100+*n+10, friezay+128);
            if(*n >= -750) *n = *n - 30;
            *fpoint = *fpoint - 2;
        }
        *shoot_flag = 0;
        *gblastx = -1000;
        delay(50);
    }

}

//moves enemy's blast and checks if it hit hero
void fblast_move(int *h, int *fblastx, int fblast_dir, int *y, int *fshoot_flag, int *t, int *m, int *gpoint, int *fpoint)
{
    char pic2[][20] = {"fblast.gif"};

    int friezax = 750, friezay = 380, gokux = 150, gokuy = 380;
    if(*fshoot_flag == 1)
    {
        if(fblast_dir == 0) readimagefile(pic2[0], *fblastx+*y, gokuy+30, *fblastx+25+*y, gokuy+55), *y += 30;
        else readimagefile(pic2[0], *fblastx+*y, gokuy+30, *fblastx+25+*y, gokuy+55), *y -= 30;
        if(*fblastx+25+*y > 980 || *fblastx+*y < 20) *fshoot_flag = 0, *fblastx = 2000;
    }
    if(*fshoot_flag == 1 && fblast_dir == 1 && (gokux+*m+40) - (*fblastx+*y) >= 0 && (*fblastx+*y+25) - (gokux+*m) >= 0 && (gokuy+128-*h) - (gokuy+30) >= 0)
    {
        *gpoint -= 2;
        *fshoot_flag = 0;
        *fblastx = 2000;
        *h = 0;
        background(gpoint, fpoint);
        readimagefile("r10.gif", gokux+*m-10, gokuy, gokux+80+*m-10, gokuy+128);
        if(*m >= -150) *m = *m - 20;
        delay(50);
    }
    if(*fshoot_flag == 1 && fblast_dir == 0 && (*fblastx+*y+25) - (gokux+*m) >= 0 && (gokux+*m+80) - (*fblastx+*y) >= 0 && (gokuy+128-*h) - (gokuy+30) >= 0)
    {
        *gpoint -= 2;
        *fshoot_flag = 0;
        *fblastx = 2000;
        *h = 0;
        background(gpoint, fpoint);
        readimagefile("l10.gif", gokux+*m-10, gokuy, gokux+80+*m-10, gokuy+128);
        if(*m <= 770) *m = *m + 20;
        delay(50);
    }

}

//makes the hero jump
void goku_jump(int *h, int *r, int i, int s, int *m, int *gblastx, int blast_dir, int *x, int *shoot_flag, int *t, int *n, int *gpoint, int *fpoint, int *fshoot_flag, int *fblast_dir, int *fblastx, int *y)
{
    char pic2[][20] = {"bla.jpg", "r3.gif", "l3.gif", "r4.gif", "l4.gif", "r5.gif", "l5.gif"};
    int jump_flag = 0, gokux = 150, gokuy = 380;
    *h = 10;
    background(gpoint, fpoint);
    readimagefile(pic2[1+s], gokux+*m, gokuy, gokux+80+*m, gokuy+128);
    move_frieza(r, i, t, n, s, m, gpoint, fpoint, fshoot_flag, fblast_dir, fblastx, y);
    delay(10);
    while(*h > 0)
    {
        background(gpoint, fpoint);
        if(jump_flag == 0)
        {
            readimagefile(pic2[3+s], gokux+*m, gokuy-*h, gokux+80+*m, gokuy+128-*h);
            *h += 35;
        }
        else
        {
            readimagefile(pic2[5+s], gokux+*m, gokuy-10-*h, gokux+85+*m, gokuy+128-*h);
            *h -= 35;
        }
        move_frieza(r, i, t, n, s, m, gpoint, fpoint, fshoot_flag, fblast_dir, fblastx, y);
        if(*h > 180) jump_flag = 1;
        blast_move(gblastx, blast_dir, x, shoot_flag, t, n, gpoint, fpoint);
        fblast_move(h, fblastx, *fblast_dir, y, fshoot_flag, t, m, gpoint, fpoint);
    }
    *h == 0;
}

//makes the hero shoot
void goku_shoot(int s, int m, int *blast_dir, int *gblastx, int *gpoint, int *fpoint)
{
    char pic2[][20] = {"bla.jpg", "r6.gif", "l6.gif", "r7.gif", "l7.gif", "gblast.gif"};
    int gokux = 150, gokuy = 380;

    background(gpoint, fpoint);
    readimagefile(pic2[1+s], gokux+m, gokuy, gokux+80+m, gokuy+128);
    delay(20);
    background(gpoint, fpoint);
    readimagefile(pic2[3+s], gokux+m, gokuy, gokux+96+m, gokuy+128);
    delay(20);
    if(s==0)
    {
        readimagefile(pic2[5], gokux+96+m, gokuy+30, gokux+96+m+25, gokuy+55);
        *blast_dir = 0;
        *gblastx = gokux+96+m;
    }
    else
    {
        readimagefile(pic2[5], gokux-25+m, gokuy+30, gokux+m, gokuy+55);
        *blast_dir = 1;
        *gblastx = gokux-25+m;
    }
}

//makes the hero punch and detects if it hit enemy
void goku_punch(int *r, int i, int *t, int *n, int *s, int *m, int *gpoint, int *fpoint, int *fshoot_flag, int *fblast_dir, int *fblastx, int *y)
{
    char pic2[][20] = {"r8.gif", "l8.gif", "r9.gif", "l9.gif", "bla.jpg"};
    int friezax = 750, friezay = 380, gokux = 150, gokuy = 380;

    background(gpoint, fpoint);
    readimagefile(pic2[0+*s], gokux+*m, gokuy, gokux+80+*m, gokuy+128);
    move_frieza(r, i, t, n, *s, m, gpoint, fpoint, fshoot_flag, fblast_dir, fblastx, y);
    delay(10);
    background(gpoint, fpoint);
    if(*s==0) readimagefile(pic2[2+*s], gokux+*m, gokuy, gokux+118+*m, gokuy+128);
    else readimagefile(pic2[2+*s], gokux-38+*m, gokuy, gokux+80+*m, gokuy+128);
    srand(time(NULL));

    if(*r == 0 && *s == 0 && gokux+80+*m+20 - friezax-*n >= 0)
    {
        if(rand()%2==0)
        {
            background(gpoint, fpoint);
            if(*n <= 170) *n = *n + 30;
            readimagefile("fl13.gif", friezax+*n, friezay, friezax+100+*n, friezay+128);
            delay(30);
            *fpoint = *fpoint - 2;
        }
        else
        {
            background(gpoint, fpoint);
            if(*n <= 170) *n = *n + 30;
            readimagefile("fl9.gif", friezax+10+*n+10, friezay, friezax+100+*n+20, friezay+128);
            delay(30);
        }
    }
    else if(*r == 1 && *s == 1 && friezax+*n+128 - gokux+38-*m-30 >= 0)
    {
        if(rand()%2==0)
        {
            background(gpoint, fpoint);
            if(*n >= -750) *n = *n - 30;
            if(*s == 1) readimagefile("fr13.gif", friezax+*n, friezay, friezax+100+*n, friezay+128);
            delay(30);
            *fpoint = *fpoint - 2;
        }
        else
        {
            background(gpoint, fpoint);
            if(*n >= -750) *n = *n - 30;
            if(*s == 1) readimagefile("fr9.gif", friezax+*n-10, friezay, friezax+100+*n-10, friezay+128);
            delay(30);
        }
    }
    else move_frieza(r, i, t, n, *s, m, gpoint, fpoint, fshoot_flag, fblast_dir, fblastx, y);
    delay(10);
}






