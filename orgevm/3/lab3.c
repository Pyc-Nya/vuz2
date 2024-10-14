#include <GRAPHICS.H>
#include <MATH.H>
#include <CONIO.H>
#include <STDIO.H>

#define PI M_PI

float f(float x){
    // (sin(x))**2 - (cos(x))**2 = -cos(2x)
    return -1 * cos(2*x);
}

void drawAxesLabels(float x_left_border, float x_right_border, float y_bottom_border, float y_top_border, float x_step, float y_step) {
    char label[50];
    float x, y;
    float screen_x, screen_y;
    float count = 2;
    float offsetX, scaleX;
    float offsetY, scaleY;

    setcolor(WHITE);

    for (x = x_left_border; x <= x_right_border; x += x_step) { // draw labels on X-axis
        count += 1;
        offsetX = x - x_left_border;
        scaleX = 550 / (x_right_border - x_left_border);
        screen_x = 50 + offsetX * scaleX;
        line(screen_x, 335, screen_x, 325); // draw a small line
        sprintf(label, "%.1fpi", count / 2);
        outtextxy(screen_x - 10, 340, label); // draw value of line
    }

    for (y = y_bottom_border + y_step; y < y_top_border; y += y_step) { // draw labels on Y-axis
        offsetY = y - y_bottom_border;
        scaleY = 350 / (y_top_border - y_bottom_border);
        screen_y = 400 - offsetY * scaleY;
        line(42, screen_y, 57, screen_y); // draw a small line
        sprintf(label, "%.1f", y);
        outtextxy(20, screen_y - 10, label); // draw value of line
    }
}

int main(void) {
   int gdriver = DETECT, gmode, errorcode; // request auto detection
   float x_left_border = 3*PI/2, x_right_border = 8*PI; // vertical interval (task)
   float y_bottom_border = -2, y_top_border = 8; // horizontal interval
   float step = 0.01; // step
   float x, y; // variables in loop
   float screen_x, screen_y; // x, y coordinates in loop 
   float y_max_value = -32000; // max function value
   int x_max_coordinate, y_max_coordinate; // x, y coordinates of max function value
   char max_value[50];
   float scaleX, scaleY, offsetX, offsetY;

   initgraph(&gdriver, &gmode, "//tc//bgi"); // initialize graphics and local variables

   setlinestyle(0, 1, 2); // solid line, useless, thick width
   setcolor(WHITE);
   line (50, 330, 600, 330); // X line x1, y1, x2, y2
   line(595, 325, 600, 330);
   line(595, 335, 600, 330);
   outtextxy(590, 340, "X");
   line(50, 400, 50, 50); // Y line
   line(45, 55, 50, 50);
   line(55, 55, 50, 50);
   outtextxy(30, 50, "Y");

   drawAxesLabels(x_left_border, x_right_border, y_bottom_border, y_top_border, PI / 2, 1);

   for(x = x_left_border; x < x_right_border - PI; x += step) { // x from 3pi/2 to 17pi
      y = f(x);
      scaleX = 550 / (x_right_border - x_left_border);
      scaleY = 350 / (y_top_border - y_bottom_border);
      offsetX = x - x_left_border;
      offsetY = y - y_bottom_border;
      screen_x = 50 + offsetX * scaleX; // '50' is offset to 'oy' // 'x-x_left_border' is change '[xleft, xright]' to '[0, xright-xleft] // 550 / (x_r_border - x_l_border) is scale (size) = single step in the interval Δ𝑥 will be converted to a proportional number of pixels on the screen
      screen_y = 400 - offsetY * scaleY; // '400' is offset to 'ox' // 'y-y_bottom_border' is change '[ybottom, ytop]' to '[0, ytop-ybottom] // 350 / (y_t_border - y_b_border) is scale (size) = single step in the interval Δ𝑥 will be converted to a proportional number of pixels on the screen
      putpixel(screen_x, screen_y, WHITE); // put pixel on screen_x, screen_y coordinates

      if(y > y_max_value){
         x_max_coordinate = screen_x;
         y_max_coordinate = screen_y;
         y_max_value = y;
      }
   }

   settextstyle(0, 0, 2);
   sprintf(max_value, "Max Value: %.2f", y_max_value);
   setcolor(RED);
   circle(x_max_coordinate, y_max_coordinate, 10); // draw a circle in coordinates with max function value
   outtextxy(x_max_coordinate + 10, y_max_coordinate-20, "max value");
   setcolor(WHITE);
   settextstyle(0, 0, 1);
   outtextxy(50, 420, "f(x) = (sin(x))**2 - (cos(x))**2");
   outtextxy(50, 450, max_value);
   getch(); // wait user action
   closegraph(); // clear and close
   return 0;
}
