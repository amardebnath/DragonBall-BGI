#include <stdio.h>
#include "graphics.h"
#include "helper1.h"
#include "helper2.h"

using namespace std;

int main()
{
    int score = 0, flag = 0, key, retreat = 0, z;
    char c;
    char story[][20] = {"start.jpg", "d1.jpg", "d2.jpg", "d3.jpg", "d4.jpg", "d5.jpg", "d6.jpg", "d7.jpg", "d8.jpg", "d9.jpg", "d10.jpg"
                        "d11.jpg", "d12.jpg", "d13.jpg", "d14.jpg", "d15.jpg", "d16.jpg", "d17.jpg", "d18.jpg", "d19.jpg", "d20.jpg"
                       };
    initwindow(1000, 600, "GAME");
    readimagefile("tbackground.jpg", 0,0, 1000, 600);
    getch();
    while(key = menu()) //The menu function returns an int that's correspondent to what user clicks in the menu
    {
        if(key == 1)
        {
            for(z = 0; z <= 4; z++) //The story dialogues
            {
                readimagefile(story[z], 0,0,1000,600);
                getch();
            }
            readimagefile("in1.jpg", 0,0,1000,600);
            getch();
            readimagefile("inins12.jpg", 0,0,1000,600);
            getch();
            readimagefile("in4.jpg", 0,0,1000,600);
            getch();
            flag = part1(&score, &retreat); //part1 of the game starts and function returns an int that determines if hero won or lost
            if(flag == 0)
            {
                readimagefile("end.jpg", 0,0,1000,600);
                getch();
            }
            if(flag)
            {
                for(z = 5; z <= 20; z++) //story dialogues
                {
                    readimagefile(story[z], 0,0,1000,600);
                    getch();
                }
                readimagefile("in2.jpg", 0,0,1000,600);
                c = getch();
                while(c != 'c')
                    c = getch();
                flag = part2(&score, &retreat); //the second part of the game starts
            }
            if(flag == 0) //game over title of either winning or losing
            {
                readimagefile("end.jpg", 0,0,1000,600);
                getch();
            }
            else
            {
                readimagefile("win.jpg", 0,0,1000,600);
                getch();
            }
            if(!retreat) //checks is user exited from pause menu
                scrcheck(score);
        }
        if(key == 2)
        {
            leaderboard(); //this function shows the scoreboard
        }
        if(key == 3) //It shows the instructions
        {
            readimagefile("inins1.jpg", 0,0,1000,600);
            getch();
            readimagefile("inins12.jpg", 0,0,1000,600);
            getch();
            readimagefile("in4.jpg", 0,0,1000,600);
            getch();
            readimagefile("inins3.jpg", 0,0,1000,600);
            getch();
        }
        if(key == 4) //It shows the credits
        {
            readimagefile("c5.jpg", 0,0,1000,600);
            getch();
        }
    }
    return 0;
}
