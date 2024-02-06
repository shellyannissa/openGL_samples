#include<GL/glut.h>

void polygon(
		GLfloat V[][2])
{
	glBegin(GL_LINES);
	for( int i = 0; i < 5; i ++){
		for( int j = i + 1; j < 5; j++){
			glVertex2f(V[i][0], V[i][1]);
			glVertex2f(V[j][0], V[j][1]);
		}
	}
	glEnd();
}

void draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 1, 1);
	GLfloat V[5][2] = {
		{0.2, 0.2},
		{0.4, 0},
		{0.3, -0.3},
		{-0.3, -0.2},
		{-0.4, 0.4}
	};
	polygon(V);
	glFlush();
}


void customInit()
{
	glClearColor(0, 0, 0, 1);
}

int main(int argc, char * argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(600, 600);
	customInit();
	glutCreateWindow("polygon with diagonals");

	glutDisplayFunc(draw);
	glutMainLoop();
	return 0;
}
