#include<GL/glu.h>
#include<GL/glut.h>

GLfloat T = 0;

void Spin(){
	T = T + 0.05;
	if(T ==360){
		T = 0;
	}
	glutPostRedisplay();
}
void CustomInit()
{
	glEnable(GL_DEPTH_TEST);
	//to set the backGround colour
	glClearColor(0, 0, 0, 1);
	//to set the default drawing colour
	glColor3f(0, 1, 0);
}

void Face(
		GLfloat A[],
		GLfloat B[],
		GLfloat C[],
		GLfloat D[]
	 )
{
	glBegin(GL_POLYGON);
		glVertex3f(A[0], A[1], A[2]);
		glVertex3f(B[0], B[1], B[2]);
		glVertex3f(C[0], C[1], C[2]);
		glVertex3f(D[0], D[1], D[2]);
		//glVertex3f(0.4, 0.6, 0);
		//glVertex3f(0.4, 0.8, 0);
	glEnd();
}

void Cube(
		GLfloat V0[],
		GLfloat V1[],
		GLfloat V2[],
		GLfloat V3[],
		GLfloat V4[],
		GLfloat V5[],
		GLfloat V6[],
		GLfloat V7[]
	 )
{
	//front
	glColor3f(0, 1, 0);
	Face(V0, V1, V2, V3);

	//back
	glColor3f(1, 0, 0);
	Face(V4, V5, V6, V7);

	//left
	glColor3f(0, 0, 1);
	Face(V0, V3, V7, V4);

	//right
	glColor3f(1, 0, 1);
	Face(V1, V2, V6, V5);

	//top
	glColor3f(0.5, 0.5, 0);
	Face(V0, V1, V5, V4);

	//bottom
	glColor3f(1, 1, 0);
	Face(V3, V2, V6, V7);	
}
		
void Draw(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	GLfloat V[8][3] = {
		{ -0.5,  0.5,  0.5},
		{  0.5,  0.5,  0.5},
		{  0.5, -0.5,  0.5},
		{ -0.5, -0.5,  0.5},
		{ -0.5,  0.5, -0.5},
		{  0.5,  0.5, -0.5},
		{  0.5, -0.5, -0.5},
		{ -0.5, -0.5, -0.5}
	};

	glLoadIdentity();
	glRotatef(T , 1, 1, 0);

	Cube(V[0], V[1], V[2], V[3], V[4], V[5], V[6], V[7]);

	glutSwapBuffers();
}

int main(int C,char * V[]){
	glutInit(&C, V);
	glutInitWindowPosition(250,50);
	glutInitWindowSize(500, 500);
	glutInitDisplayMode(GLUT_RGB| GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("Spinning Cube");
	
	
	CustomInit();
	
	glutDisplayFunc(Draw);
	glutIdleFunc(Spin);
	glutMainLoop();
	return 0;
}

