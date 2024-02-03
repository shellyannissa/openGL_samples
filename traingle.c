#include<GL/glut.h>
#include<GL/glu.h>
#include<stdio.h>

GLfloat px, py, r;

void Draw(){
	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3f(0, 0, 1);
	glBegin(GL_LINE_LOOP);
		glVertex2f(0.6, 0.4);
		glVertex2f(0.8, 0.6);
		glVertex2f(0.9, 0.2);

	glEnd();
		
	//replaces curr matrix with identity matrix, so as to isolate from previous transformations
	glLoadIdentity();

	glTranslatef(px, py, 0);
	glRotatef(r, 0, 0, 1);// by default rotation happens wrt to origin
	glTranslatef(-px, -py, 0);

	glColor3f(0, 1, 0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(0.6, 0.4);
		glVertex2f(0.8, 0.6);
		glVertex2f(0.9, 0.2);

	glEnd();
	glFlush();
}


int main(int argc, char * argv[]){

	printf("Enter Rotation Reference (Pivot Point)::");
	scanf("%f %f", &px, &py);

	printf("Enter defree to be rotated::");
	scanf("%f", &r);


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(150, 50);
	glutCreateWindow("Traingle Rotation");

	glutDisplayFunc(Draw);
	glutMainLoop();

	return 0;

}
