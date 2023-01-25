#include<graphics.h>
#include<conio.h>
//#include<stdio.h>
#include<dos.h>
#include<stdlib.h>
struct ball{
	int x, y, r;
	};

void drawBall(int x,int y,int r){
	static int i=0;
	if(i%2==0){
	setcolor(YELLOW);
	setfillstyle(SOLID_FILL, YELLOW);
	circle(x, y, r);
	floodfill(x, y, YELLOW);
	}
	else{
		setcolor(BLUE);
		setfillstyle(SOLID_FILL, BLUE);
		circle(x,y,r);
		floodfill(x,y,BLUE);
	}
	i++;
}

void main(){

	int gd=DETECT, gm, f, f2;
	struct ball c1, c2;
	clrscr();
	printf("maxx=%d, maxy=%d", getmaxx(), getmaxy());
	initgraph(&gd, &gm, "c:\\turboc3\\bgi");
	rectangle(0,0,getmaxx(), getmaxy());
	c1.x=100;
	c1.y=100;
	c1.r=40;
	c2.x=500;
	c2.y=100;
	c2.r=40;
	do{
		drawBall(c1.x, c1.y,c1.r);
		drawBall(c2.x, c2.y, c2.r);
		delay(40);
		clrscr();
		f=rand()%10;
		c1.x+=f;
		c1.y+=f;
		c2.x-=f;
		c2.y+=f;
		if(kbhit()){break;};

	}while(c1.x<getmaxy());

	getch();
	closegraph();
}