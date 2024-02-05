#include <GL/glut.h>
#include <math.h>

// Function to draw a circle
void drawCircle(GLfloat radius, GLfloat centerX, GLfloat centerY) {
	glColor3f(1.0, 0.0, 0.0);  // Set color to white
    glBegin(GL_POLYGON);
    GLfloat twoPi = 2.0f * 3.14;

    for (int i = 0; i <= 100; i++) {
        GLfloat angle = i * twoPi / 100;
        float x = centerX + radius * cos(angle);
        float y = centerY + radius * sin(angle);
        glVertex2f(x, y);
    }

    glEnd();
}

// Function to handle all drawings
void display() {
    glClear(GL_COLOR_BUFFER_BIT);  // Clear the color buffer (set background)

    // Draw a white circle with radius 100 at the center of the window
    drawCircle(0.5, 0, 0);

    glFlush();  // Force execution of OpenGL commands
}

// Function to set up the OpenGL environment
void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);  // Set background color to black
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("White Circle on Black Background");

    init();  // Initialize OpenGL settings
    glutDisplayFunc(display);  // Set the display callback function

    glutMainLoop();  // Enter the event processing loop

    return 0;
}

