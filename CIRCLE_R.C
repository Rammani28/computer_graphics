
#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void main(){

	int x, y, r, p,xc, yc, i=0;
	int gd=DETECT, gm;
	initgraph(&gd, &gm, "c:\\turboc3\\bgi");

	printf("Enter radius of the circle: ");
	scanf("%d",&r);
	printf("enter xc, yc: ");
	scanf("%d%d",&xc,&yc);

	x=0;
	y=r;
	p=1-r;
	while(x<=y){
		if (p<0){
			p=p+2*x+1;
			x=x+1;
			y=y;
		}else{
			p=p+2*x+1-2*y;
			x=x+1;
			y=y-1;
		}
		i=0;
		putpixel(xc+x,yc-y,++i);
		putpixel(xc+y, yc-x, ++i);
		putpixel(xc+y, yc+x, ++i);
		putpixel(xc+x, yc+y, ++i);
		putpixel(xc-x, yc+y, ++i);
		putpixel(xc-y, yc+x, ++i);
		putpixel(xc-y, yc-x, ++i);
		putpixel(xc-x, yc-y, ++i);
	}




	getch();
	closegraph();
}