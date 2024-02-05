#include<GL/glut.h>



void Display()
{
	glBegin(GL_POLYGON);
 	glVertex2f(-0.5,-0.5);
 	glVertex2f(-0.5,0.5);
 	glVertex2f(0.5,0.5);
 	glVertex2f(0.5,-0.5);
 	glEnd();
 	glFlush();
}

int main(int argc, char** argv)
{
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA);
 glutInitWindowSize(500,500);
 glutInitWindowPosition(100,100);
 glutCreateWindow("OpenGL - First window demo");
glutDisplayFunc(Display);
  glutMainLoop();
 return 0;
}
