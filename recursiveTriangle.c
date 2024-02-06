#include<GL/glut.h>
#include<math.h>


void CustomInit()
{
	glClearColor(0, 0, 0, 1);
}


void Triangle( GLfloat A[], GLfloat B[], GLfloat C[])
{
	glBegin(GL_LINE_LOOP);
	glVertex2f(A[0], A[1]);
	glVertex2f(B[0], B[1]);
	glVertex2f(C[0], C[1]);
	glEnd();
}

void midPoint( GLfloat mid[], GLfloat A[], GLfloat B[])
{
	mid[0] = ( A[0] + B[0] ) / 2;
	mid[1] = ( A[1] + B[1] ) / 2;
}


void Div(GLfloat A[], GLfloat B[], GLfloat C[],  int n)
{
	GLfloat M1[2], M2[2], M3[2];
	if( n > 0)
	{
		midPoint(M1, A, B);
		midPoint(M2, B, C);
		midPoint(M3, C, A);
        	// Draw the three new triangles formed by subdividing the current triangle
        	Triangle(A, M1, M3);
        	Triangle(M1, B, M2);
        	Triangle(M3, M2, C);

        	// Recursively subdivide the three new triangles
        	Div(A, M1, M3, n - 1);
       		Div(M1, B, M2, n - 1);
        	Div(M3, M2, C, n - 1);
	}
	else{
		Triangle(A, B, C);
	}
}
			

		

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	GLfloat root3 = sqrt(3);
	GLfloat V[3][2] = {
		{ 0, 1 / root3 }, 
		{ -0.5, -1 / ( 2 * root3) },
		{ 0.5, -1 / ( 2 * root3) }
	};

	Div(V[0], V[1], V[2], 3);

	glFlush();
}


int main(int argc, char * argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Recursive Triangle");
	CustomInit();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
