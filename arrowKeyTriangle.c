#include<GL/glut.h>
#include<stdio.h>


GLfloat angle = 0.0f;


void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(0,0.4, 0);
	glRotatef(angle, 0, 0, 1);
	glTranslatef(0, -0.4, 0);
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.4, 0.0f);
	glVertex3f(1.0f, 1.0f, 0.0f);

	glEnd();

	glutSwapBuffers();
}

void handleKeyPress(int key, int x, int y)
{
	switch(key){
		case GLUT_KEY_LEFT:
			angle -= 5.0f;
			break;
		case GLUT_KEY_RIGHT:
			angle += 5.0f;
			break;
		}
	glutPostRedisplay();
}


void CustomInit()
{
	glClearColor(0, 0, 0, 1);
}

int main(int argc, char * argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB| GLUT_DOUBLE);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Rotating Triangle with arrow keys");
	CustomInit();
	glutDisplayFunc(display);
	glutSpecialFunc(handleKeyPress);
	glutMainLoop();
	return 0;
}
