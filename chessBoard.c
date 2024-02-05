#include<GL/glut.h>


void CustomInit()
{
	glClearColor(0, 0, 0, 1);
}


void drawSquare(GLfloat x, GLfloat y, GLfloat size, int color)
{
	glBegin(GL_QUADS);
	if(color == 0)
		glColor3f(1.0, 1.0, 1.0);
	else
		glColor3f(0, 0, 0);

	glVertex2f(x, y);
	glVertex2f(x + size, y);
	glVertex2f(x + size, y + size);
	glVertex2f(x, y + size);
	glEnd();
}

void ChessBoard()
{
	glClear(GL_COLOR_BUFFER_BIT);
	GLfloat size = 0.25;
	for(int i = -4;i < 4; i++)
	{
		for(int j = -4; j < 4 ;j++)
		{
			drawSquare(i * size, j * size, size, (i + j) %2);
		}
	}
	glFlush();
}


int main(int argc, char * argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(50, 50);
	CustomInit();
	glutCreateWindow("ChessBoard");
	glutDisplayFunc(ChessBoard);
	glutMainLoop();
	return 0;
}

