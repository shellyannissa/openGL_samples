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
	GLfloat Col[] = {1, 0, 0, 1};
	GLfloat M[] = {0, 0, 1, 1};

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glLightfv(GL_LIGHT0, GL_POSITION,Pos);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, Col);

	// eyeX, eyeY, eyeZ(location of camera), centerX, centerY, centerZ(point where cam is looking at), upX, upY, upZ(specifies up direction for Camera)
	gluLookAt(0, 1, 3, 0, 0, 0, 0, 1, 1);
	
	glRotatef(T, 0, 1, 0);

	glPushMatrix();
	//rescaling the cube to resenmble a table top
		glScalef(1, 0.05, 1);
		glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
		//translate should come before scaling 
		glTranslatef(-0.48, -0.5, -0.48);
		glScalef(0.05, 1, 0.05);
		glutSolidCube(1);
	glPopMatrix();


	glPushMatrix();
		//translate should come before scaling 
		glTranslatef( 0.48, -0.5, 0.48);
		glScalef(0.05, 1, 0.05);
		glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
		//translate should come before scaling 
		glTranslatef( 0.48, -0.5, -0.48);
		glScalef(0.05, 1, 0.05);
		glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
		//translate should come before scaling 
		glTranslatef(-0.48, -0.5, 0.48);
		glScalef(0.05, 1, 0.05);
		glutSolidCube(1);
	glPopMatrix();

	//enclosing in PushAttribBits so that the materialfv is applied only for the teapot
	glPushAttrib(GL_ALL_ATTRIB_BITS);	
	//for the teapot over the table
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, M);	
		glPushMatrix();
			//translate should come before scaling 
			glTranslatef(0, 0.25, 0);
			glutSolidTeapot(0.25);
		glPopMatrix();
	glPopAttrib();

	glutSwapBuffers();
}

int main(int argc, char * argv[])
{
	glutInit(&argc ,argv);
	glutInitWindowPosition(20, 100);
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
