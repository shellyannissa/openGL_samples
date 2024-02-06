#include <GL/glut.h>
#include<math.h>

float ballRadius = 0.1; // Radius of the bouncing ball
float ballX = 0.5;     // Initial x-coordinate of the ball
float ballY = 0.5;     // Initial y-coordinate of the ball
float ballSpeedX = 0.02; // Initial speed of the ball in the x-direction
float ballSpeedY = 0.03; // Initial speed of the ball in the y-direction

void drawBall() {
    glColor3f(1.0, 0.0, 0.0); // Red color
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float angle = i * 3.14159 / 180.0;
        float x = ballX + ballRadius * cos(angle);
        float y = ballY + ballRadius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawBall();

    glutSwapBuffers();
}

void update(int value) {
    // Update ball position
    ballX += ballSpeedX;
    ballY += ballSpeedY;

    // Bounce off the walls
    if (ballX > 1.0 - ballRadius || ballX < -1.0 + ballRadius) {
        ballSpeedX = -ballSpeedX;
    }

    if (ballY > 1.0 - ballRadius || ballY < -1.0 + ballRadius) {
        ballSpeedY = -ballSpeedY;
    }

    glutPostRedisplay();
    glutTimerFunc(16, update, 0); // 60 frames per second
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // White background
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Bouncing Ball Animation");

    glutDisplayFunc(display);
    glutTimerFunc(25, update, 0); // Initial call to update after 25 milliseconds

    init();

    glutMainLoop();
    return 0;
}

