#include<graphics.h>
#include<conio.h>
#include<windows.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
char word[5][2]={"","","",""};
int n=1;
int wordx[5];
int wordy[5]={500,500,500,500};
char getword;
char score[5]="0000";
int number=0;
char input;
char lifeline[5]="****";
int life=0;
int speed;
void Score()
{
	if(score[2]=='9')
	{
		if(score[1]=='9')
		{
			score[0]++;
			score[1]='0';
			score[2]='0';
			
		}
		else
		{
			score[1]++;
			score[2]='0';
		}
	}
	else
	{
		score[2]++;
	}
	return;
}
void setup()
{
	cleardevice();
	setcolor(BLUE);
	line(0,480,410,480);
	setcolor(RED);
	line(0,300,410,300);
	setcolor(WHITE);
	outtextxy(100,200,"Lifelines.");
	outtextxy(100,220,"score : ");
	outtextxy(150,220,score);
	outtextxy(200,200,lifeline);
	for(int a=0;a<=number;a++)
	{
		up:
		if(!((int(word[a][0]<120))&&(int(word[a][0]>98))))
		{
			word[a][0]=rand();
			wordx[a]=rand();
			wordx[a]%=400;
		}
		else
		{
			setcolor(GREEN);
			outtextxy(wordx[a],wordy[a],word[a]);
			goto down;
		}
	goto up;
	down:
		cout<<"";
		
	}
}
void up()
{
	for(int a=0;a<=number;a++)
	{
		wordy[a]-=5;
	}
	return;
	
}
void keyboard()
{
	if(kbhit())
	{
		
		getword=getch();
		for(int a=0;a<=number;a++)
		{
			
		if(getword==word[a][0])
		{
			Beep(1000,100);
			word[a][0]=rand();
			wordy[a]=500;
			wordx[a]=rand();
			wordx[a]=wordx[a]%400;
			Score();
			return;
		}
		}
		Beep(2000,50);
}
	else
	{
		return;
	}
}

void start_page()
{
	string name[7];
	name[0]="*******  *******  *       *  *******      ";
	name[1]="*        *     *  * *   * *  *     ";
	name[2]="*        *     *  *  * *  *  *";
	name[3]="*   ***  *******  *   *   *  *******  ";
	name[4]="*     *  *     *  *       *  * ";
	name[5]="*     *  *     *  *       *  *";
	name[6]="*******  *     *  *       *  *******  ";
	cout<<"\n\n\n\n\n\n";
	for(int a=0;a<=6;a++)
	{
		cout<<"                      ";
		cout<<name[a]<<endl;
	}
	name[0]="*******   ***   *         *  *******";
	name[1]="   *       *    * *     * *  *";
	name[2]="   *       *    *  *   *  *  *";
	name[3]="   *       *    *   * *   *  *******  ";
	name[4]="   *       *    *    *    *  *";
	name[5]="   *       *    *         *  *";
	name[6]="   *      ***   *         *  *******  ";
	cout<<"\n\n";
	for(int a=0;a<=6;a++)
	{   cout<<"                      ";             
		cout<<name[a]<<endl;
	}
	Sleep(2000);
	system("cls");
	initwindow(420,600);
	return;
}
void loading()
{
	outtextxy(100,180,"Loading...");
	line(100,200,300,200);
	line(100,230,300,230);
	line(100,200,100,230);
	line(300,200,300,230);
	
	for(int a=0;a<200;a++)
	{
		line(100+a,200,100+a,230);
		Sleep(20);
	}
	Sleep(1000);
	cleardevice();
	
}
void check()
{
	for(int a=0;a<number;a++)
	{
		if(wordy[a]<300)
		{
			lifeline[life]=' ';
			life++;
			wordy[a]=500;
			word[a][0]='a';
			Beep(10000,50);
		}
	}
}
void Speed()
{
	back_to_up:
	outtextxy(30,200,"Select Level.");
	outtextxy(150,210,"1-->  Easy.");
	outtextxy(150,220,"2-->  Medium.");
	outtextxy(150,230,"3-->  Hard.");

	input=getch();
	if(input=='1')
	{
		speed=650;
	}
	else if(input=='2')
	{
		speed=500;
	}
	else if(input=='3')
	{
		speed=350;
	}
	else
	{
		goto back_to_up;
	}
}
void end()
{
	setcolor(YELLOW);
	cleardevice();
	outtextxy(100,130,"Your Final Score is : ");
	outtextxy(270,130,score);
	outtextxy(100,100,"GAME OVER.....!\n");
	system("pause");
}

int main()
{
	start_page();
	loading();
	Speed();
	for(;;)
	{
		setup();
		up();
		keyboard();
		up();
		Sleep(speed);
		check();
		n++;
		if(n%5==0)
		{
			number++;
			if(number==5)
			{
				number=4;
			}
			
		}
		if(life==4)
		{
			goto out;
		}	
	}
	out:
		end();
}
