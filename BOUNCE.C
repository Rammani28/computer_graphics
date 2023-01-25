#include<graphics.h>
#include<conio.h>
#include<stdio.h>
// #include<dos.h>

void drawBall(int x,int y,int r){
	circle(x, y, r);

}


void main(){

	struct ball{
		int r=40, x=100, y=100;
	}c;

	int gd=DETECT, gm;
	struct ball c1;
	initgraph(&gd, &gm, "c:\\turboc3\\bgi");

	drawBall(c1.x, c1.y,c1.r);

	getch();
	closegraph();
}