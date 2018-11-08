#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "graphics.h"
#include "helper1.h"
#include "helper2.h"

using namespace std;



int part2(int *score, int *retreat)
{

    long long int i = 5;
    char pic2[][20] = {"bla.jpg", "r1.gif", "l1.gif", "fr1.gif", "fr2.gif", "fr3.gif", "fl1.gif", "fl2.gif", "fl3.gif"};
    char keypress;
    int gokux = 150, gokuy = 380, s = 0, m = 0, x = 0, y = 0, shoot_flag = 0, fshoot_flag = 0, fblast_dir, blast_dir, gblastx, fblastx;
    int friezax = 750, friezay = 380, n = 0, t = 6, r = 0, fpoint = 80, gpoint = 80, h = 0;
    //For hero the m variable keeps track of the movement, s keeps track of which side he is facing, x keeps track of his blast
    //for enemy the n variable keeps track of the movement, t keep track of which side he is facing, y keeps track of his blast
    //variable r keeps track of which side the enemy is in the screen
    while(i++)
    {
        background(&gpoint, &fpoint); //loads the background in every frame
        readimagefile(pic2[1+s], gokux+m, gokuy, gokux+80+m, gokuy+128);
        move_frieza(&r, i, &t, &n, s, &m, &gpoint, &fpoint, &fshoot_flag, &fblast_dir, &fblastx, &y); //enemy moves in every frame
        blast_move(&gblastx, blast_dir, &x, &shoot_flag, &t, &n, &gpoint, &fpoint);
        fblast_move(&h, &fblastx, fblast_dir, &y, &fshoot_flag, &t, &m, &gpoint, &fpoint);
        delay(10);

        if(gpoint <= 0)
        {
            return 0;
        }
        else if(fpoint <= 0)
        {
            *score = *score + (gpoint - fpoint); //calculates the score
            return 1;
        }

        if(kbhit())
        {
            keypress = getch();
            if(keypress == KEY_RIGHT) //makes hero move
            {
                s = 0;
                move_goku(s, &m, &gpoint, &fpoint);
                move_frieza(&r, i, &t, &n, s, &m, &gpoint, &fpoint, &fshoot_flag, &fblast_dir, &fblastx, &y);
                blast_move(&gblastx, blast_dir, &x, &shoot_flag, &t, &n, &gpoint, &fpoint);
                while(kbhit()) getch();
            }

            else if(keypress == KEY_LEFT)
            {
                s = 1;
                move_goku(s, &m, &gpoint, &fpoint);
                move_frieza(&r, i, &t, &n, s, &m, &gpoint, &fpoint, &fshoot_flag, &fblast_dir, &fblastx, &y);
                blast_move(&gblastx, blast_dir, &x, &shoot_flag, &t, &n, &gpoint, &fpoint);
                while(kbhit()) getch();
            }

            else if(keypress == KEY_UP) //makes hero jump
            {
                goku_jump(&h, &r, i, s, &m, &gblastx, blast_dir, &x, &shoot_flag, &t, &n, &gpoint, &fpoint, &fshoot_flag, &fblast_dir, &fblastx, &y);
                while(kbhit()) getch();
            }

            else if(keypress == 's' && shoot_flag == 0) //makes hero shoot
            {
                goku_shoot(s, m, &blast_dir, &gblastx, &gpoint, &fpoint);
                move_frieza(&r, i, &t, &n, s, &m, &gpoint, &fpoint, &fshoot_flag, &fblast_dir, &fblastx, &y);
                shoot_flag = 1, x = 0;
                while(kbhit()) getch();
            }

            else if(keypress == 'd') //makes hero punch
            {
                goku_punch(&r, i, &t, &n, &s, &m, &gpoint, &fpoint, &fshoot_flag, &fblast_dir, &fblastx, &y);
                move_frieza(&r, i, &t, &n, s, &m, &gpoint, &fpoint, &fshoot_flag, &fblast_dir, &fblastx, &y);
                while(kbhit()) getch();
            }
            else if(keypress == 27) //this triggers the pause menu
            {
                i = pause_menu(i);
                if(i==0)
                {
                    *retreat = 1;
                    return 0;
                }
            }
        }
    }
}

