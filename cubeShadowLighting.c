#include<GL/glut.h>


GLfloat T = 0;

void Spin()
{
	T = T + 0.1;
	if(T > 360)
		T = 0;

	//to redraw the window to keep the animation going
	glutPostRedisplay();
}


void CustomInit()
{

	glEnable(GL_DEPTH_TEST);
	//sets the matrix stack to that corresponding to projection mode
	glMatrixMode(GL_PROJECTION);

	//identity matrix is loaded onto the matrix stack
	glLoadIdentity();

	//six parameters specifying the clipping planes:- left, right, top, bottom , near, far
	glFrustum(-1, 1, -1, 1, 2, 10);

	//mode responsible for transforming 3D scenes in respect to viewer's perspective
	glMatrixMode(GL_MODELVIEW);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}

void Draw()
{

	GLfloat Pos[] = {0, 1, 0, 1};
	GLfloat Col[] = {1, 1, 1, 0};

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	//glLightfv(GL_LIGHT0, GL_POSITION,Pos);
	//glLightfv(GL_LIGHT0, GL_DIFFUSE, Col);

	gluLookAt(0, 1, 3, 0, 0, 0, 0, 1, 0);
	
	glRotatef(T, 1, 1, 0);
	glutSolidCube(1);

	glutSwapBuffers();
}

int main(int argc, char * argv[])
{
	glutInit(&argc ,argv);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(600, 600);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("Table");

	CustomInit();
	glutDisplayFunc(Draw);
	//to register an callback function that will be called when there are no events to process
	glutIdleFunc(Spin);


	glutMainLoop();
	return 0;

}
