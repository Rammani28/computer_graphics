#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<stdlib.h>
#include<math.h>
double distance(double x1, double y1, double x2, double y2){
	float temp;
	temp = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
       //	printf("distance btn (%lf, %lf) & (%lf, %lf) is %lf\n",x1, y1, x2, y2, temp);
	return temp;

}

struct ball{
	int x, y, r,xdirn, ydirn;
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

	int gd=DETECT, gm, fx, fy, f2, maxx=getmaxx(), maxy=getmaxy();
	double dis;
	struct ball c1, c2;
      //	clrscr();
	initgraph(&gd, &gm, "c:\\turboc3\\bgi");
	maxx=getmaxx()-39;
	maxy=400;
       //	printf("maxx=%d, maxy=%d", maxx, maxy);

	c1.x=100;
	c1.y=100;
	c1.r=30;
	c1.xdirn=1;
	c1.ydirn=1;

	maxx=getmaxx()-2*c1.r;
	maxy=getmaxy()-2*c2.r-150;

	c2.x=580;
	c2.y=100;
	c2.r=30;
	c2.xdirn=-1;
	c2.ydirn=1;
	do{
	       //	line(0,maxy-2,maxx,maxy-2);
		drawBall(c1.x, c1.y,c1.r);
		drawBall(c2.x, c2.y, c2.r);
		delay(50);
		clrscr();
		fx=(rand()%3)*6;
		fy=(rand()%3)*5;
		dis = distance(c1.x, c1.y, c2.x, c2.y);
		if(dis<(c1.r+c2.r)){c1.xdirn=-1; c2.xdirn=1;}
		if(c1.x>maxx||c1.x<40){c1.xdirn*=-1;}
		if(c2.x>maxx||c2.x<40){c2.xdirn*=-1;}
		if(c1.y>maxy||c1.y<40){c1.ydirn*=-1;}
		if(c2.y>maxy||c2.y<40){c2.ydirn*=-1;}

		c1.x+=fx*c1.xdirn;
		c1.y+=fy*c1.ydirn;
		c2.x+=fx*c2.xdirn;
		c2.y+=fy*c2.ydirn;

	}while(!kbhit());

	getch();
	closegraph();
}
