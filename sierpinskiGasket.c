#include<GL/glut.h>

void Triangle(
		GLfloat A[],
		GLfloat B[],
		GLfloat C[]
	     )
{
	glBegin(GL_TRIANGLES);
		glVertex3fv(A);
		glVertex3fv(B);
		glVertex3fv(C);
	glEnd();
}


void middlePoint(GLfloat result[], GLfloat A[], GLfloat B[])
{
    for (int i = 0; i < 3; ++i) {
        result[i] = (A[i] + B[i]) / 2.0;
    }
}


void Tetra(
    GLfloat V1[],
    GLfloat V2[],
    GLfloat V3[],
    GLfloat V4[]
)
{
    glColor3f(1, 1, 1);
    Triangle(V1, V2, V3);

    glColor3f(0, 0, 1);
    Triangle(V2, V4, V3);

    glColor3f(1, 0, 0);
    Triangle(V3, V4, V1);

    glColor3f(0, 1, 0);
    Triangle(V4, V2, V1);
}


void Div(GLfloat A[], GLfloat B[], GLfloat C[], GLfloat D[], int n)
{
    GLfloat M1[3], M2[3], M3[3], M4[3], M5[3], M6[3];

    if (n > 0) 
    {
        middlePoint(M1, A, B);
        middlePoint(M2, B, C);
        middlePoint(M3, C, A);
        middlePoint(M4, A, D);
        middlePoint(M5, B, D);
        middlePoint(M6, C, D);

        Div(A, M1, M3, M4, n - 1);
        Div(M1, B, M2, M5, n - 1);
        Div(M2, C, M3, M6, n - 1);
        Div(M4, M5, M6, D, n - 1);
    }
    else
    {
        Tetra(A, B, C, D);
    }
}

void Draw()
{
	GLfloat P[4][3] = {
		{-0.5, -0.5, 0.5},
		{ 0.5, -0.5, 0.5},
		{ 0, 0.5, 0.5},
		{ 0, -0.1, -0.5}
	};
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	Div(P[0], P[1], P[2], P[3], 2);
	glutSwapBuffers();
}

int main(int argc, char * argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("3D Sierprinski Gasket");
	glutDisplayFunc(Draw);
	glutMainLoop();
	return 0;
}
