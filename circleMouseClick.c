#include <GL/glut.h>
#include <stdlib.h>
#include<math.h>
#include<stdio.h>

// Data structure to store circle information
struct Circle {
    GLfloat x, y;  // Center coordinates
    GLfloat radius;
    GLfloat color[3];  // RGB color values
};

// Function to draw a circle
void drawCircle(GLfloat x, GLfloat y, GLfloat radius, GLfloat color[3]) {
    const int numSegments = 100;
    glColor3fv(color);
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < numSegments; i++) {
        double theta = 2.0 * 3.1415926 * (i) / numSegments;
        double cx = x + radius * cos(theta);
        double cy = y + radius * sin(theta);
        glVertex2d(cx, cy);
    }
    glEnd();
}

// Vector to store circles
struct Circle circles[100];  // Adjust the size based on your needs
int circleCount = 0;

// Function to render the circles
void renderCircles() {
    glClear(GL_COLOR_BUFFER_BIT);

    for (int i = 0; i < circleCount; i++) {
        drawCircle(circles[i].x, circles[i].y, circles[i].radius, circles[i].color);
    }

    glutSwapBuffers();
}

// Callback function for mouse clicks
void mouseButtonCallback(int button, int state, int x, int y) {
    if (state == GLUT_DOWN) {
        // Left-click: draw a new circle
        if (button == GLUT_LEFT_BUTTON) {
            circles[circleCount].x = x;
            circles[circleCount].y = y;
            circles[circleCount].radius = 25.0;
            circles[circleCount].color[0] = 1.0;  // Red color by default
            circles[circleCount].color[1] = 0.0;
            circles[circleCount].color[2] = 0.0;
            circleCount++;
        }
        // Right-click: change the color of the last drawn circle
        else if (button == GLUT_RIGHT_BUTTON && circleCount > 0) {

		printf("right");
            struct Circle* lastCircle = &circles[circleCount - 1];
            lastCircle->color[0] = (float)rand() / RAND_MAX;
            lastCircle->color[1] = (float)rand() / RAND_MAX;
            lastCircle->color[2] = (float)rand() / RAND_MAX;
        }
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Circle Drawer");

    glOrtho(0.0, 800.0, 600.0, 0.0, -1.0, 1.0);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glutDisplayFunc(renderCircles);
    glutMouseFunc(mouseButtonCallback);

    glutMainLoop();
    return 0;
}

