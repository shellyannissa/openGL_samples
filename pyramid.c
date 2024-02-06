#include <GL/glut.h>

void drawSquareBase() {
	glColor3f(1, 0, 0);
    glBegin(GL_QUADS);
    glVertex3f(-1.0, 0.0, -1.0); // Bottom-left
    glVertex3f(1.0, 0.0, -1.0);  // Bottom-right
    glVertex3f(1.0, 0.0, 1.0);   // Top-right
    glVertex3f(-1.0, 0.0, 1.0);  // Top-left
    glEnd();
}

void drawTriangle(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3) {
    glBegin(GL_TRIANGLES);
    glVertex3f(x1, y1, z1);
    glVertex3f(x2, y2, z2);
    glVertex3f(x3, y3, z3);
    glEnd();
}

void drawPyramid() {

    // Draw base square
    drawSquareBase();

    // Draw three triangular sides
	glColor3f(1, 1, 0);
    drawTriangle(0.0, 2.0, 0.0, -1.0, 0.0, -1.0, 1.0, 0.0, -1.0);
	glColor3f(0, 1, 1);
    drawTriangle(0.0, 2.0, 0.0, 1.0, 0.0, -1.0, 1.0, 0.0, 1.0);
	glColor3f(1, 0, 1);
    drawTriangle(0.0, 2.0, 0.0, 1.0, 0.0, 1.0, -1.0, 0.0, 1.0);
	glColor3f(0, 0, 0);
    drawTriangle(0.0, 2.0, 0.0, -1.0, 0.0, 1.0, -1.0, 0.0, -1.0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
   // glTranslatef(0.0, 0.0, -5.0f); // Move back to see the pyramid
    drawPyramid();
    glutSwapBuffers();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glEnable(GL_DEPTH_TEST);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(500, 500);
    glutCreateWindow("3D Pyramid");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

