#include<GL/glut.h>

GLfloat T;

void Spin(){
	T = T + 0.05;
	if( T > 360 ) 
		T = 0;
	glutPostRedisplay();
}

void Draw()
{
	
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	//to rotate about a point translate-> rotate -> translate back to origin 
	glTranslatef(-0.4, -0.5, 0);
	glRotatef(T, 0, 0, 1);
	glTranslatef(0.4, 0.5, 0);


	glBegin(GL_POLYGON);
	glVertex2f(0, 0.7);
	glVertex2f(-0.4, -0.5);
	glVertex2f(0.5, 0.3);
	glEnd();
	glFlush();

}

void CustomInit(){
	glColor3f(1, 0, 0);
	T = 0;
}

int main(int argc, char * argv[])
{
	glutInit(&argc, argv);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(600, 600);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Automatically Rotating Triangle");

	CustomInit();

	glutDisplayFunc(Draw);
	glutIdleFunc(Spin);
	glutMainLoop();
	return 0;
}
