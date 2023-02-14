#include <stdlib.h>
#include <graphics.h>
#include <conio.h>
#include <time.h>

#define NUM_BALLS 6
int i, j;
struct Ball {
  int x, y;
  int xdir, ydir;
  int color;
};

void initBalls(struct Ball balls[]) {
  for ( i = 0; i < NUM_BALLS; i++) {
    balls[i].x = rand() % 100;
    balls[i].y = rand() % 100;
    balls[i].xdir = (rand() % 3) + 1;
    balls[i].ydir = (rand() % 3) + 1;
    balls[i].color = (rand() % 15) + 1;
  }
}

void moveBalls(struct Ball balls[]) {
  for ( i = 0; i < NUM_BALLS; i++) {
    balls[i].x += balls[i].xdir;
    balls[i].y += balls[i].ydir;

    if (balls[i].x > getmaxx() || balls[i].x < 0) {
      balls[i].xdir = -balls[i].xdir;
    }
    if (balls[i].y > getmaxy() || balls[i].y < 0) {
      balls[i].ydir = -balls[i].ydir;
    }
  }
}

void bounceBalls(struct Ball balls[]) {
  for ( i = 0; i < NUM_BALLS; i++) {
    for ( j = i + 1; j < NUM_BALLS; j++) {
      int xdiff = balls[i].x - balls[j].x;
      int ydiff = balls[i].y - balls[j].y;
      int distance = xdiff * xdiff + ydiff * ydiff;

      if (distance <= 25) {
        int temp = balls[i].xdir;
        balls[i].xdir = balls[j].xdir;
        balls[j].xdir = temp;

        temp = balls[i].ydir;
        balls[i].ydir = balls[j].ydir;
        balls[j].ydir = temp;
      }
    }
  }
}

void drawBalls(struct Ball balls[]) {
  for (i = 0; i < NUM_BALLS; i++) {
    setcolor(balls[i].color);
    circle(balls[i].x, balls[i].y, 5);
    floodfill(balls[i].x, balls[i].y, balls[i].color);
  }
}

int main() {
  int gd = DETECT, gm;
  struct Ball balls[NUM_BALLS];
  
  srand(time(NULL));
  initgraph(&gd, &gm, "C:\\turboc3\\BGI");

  initBalls(balls);

  while (!kbhit()) {
    cleardevice();
    moveBalls(balls);
    bounceBalls(balls);
    drawBalls(balls);
    delay(30);
  }

  getch();
  closegraph();
  return 0;
}
