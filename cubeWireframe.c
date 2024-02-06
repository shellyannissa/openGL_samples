#include <GL/glut.h>

float angle = 0.0; // Initial angle of rotation

void drawCube() {
    glutWireCube(0.5); // Draw a wireframe cube with side length 0.5
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
glColor3f(1, 0, 0);
glRotatef(angle, 1, 1, 0);
    drawCube();

    glutSwapBuffers();
}

void rotateCube(int value) {
    angle += 1.0; // Increment the rotation angle
    if (angle > 360.0) {
        angle -= 360.0; // Keep the angle within the range [0, 360)
    }

    glutPostRedisplay();
    glutTimerFunc(16, rotateCube, 0); // 60 frames per second
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // White background
    glEnable(GL_DEPTH_TEST);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Rotating Cube");

    glutDisplayFunc(display);
    glutTimerFunc(25, rotateCube, 0); // Initial call to rotateCube after 25 milliseconds

    init();

    glutMainLoop();
    return 0;
}

