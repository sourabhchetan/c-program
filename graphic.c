#include <stdio.h>
#include <graphics.h>
#include <math.h>

// Function to draw a square
void drawSquare(int x, int y, int side) {
    rectangle(x, y, x + side, y + side);
}

// Function to draw a rectangle
void drawRectangle(int x, int y, int width, int height) {
    rectangle(x, y, x + width, y + height);
}

// Function to draw a triangle
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

// Function to draw a circle
void drawCircle(int x, int y, int radius) {
    circle(x, y, radius);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Draw a square
    drawSquare(100, 100, 50);

    // Draw a rectangle
    drawRectangle(200, 100, 100, 50);

    // Draw a triangle
    drawTriangle(350, 150, 400, 100, 450, 150);

    // Draw a circle
    drawCircle(550, 125, 50);

    getch();
    closegraph();

    return 0;
}
