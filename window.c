#include<GL/glu.h>
#include<GL/glut.h>

void Draw(){
	glClear(GL_COLOR_BUFFER_BIT);


	glFlush();
}

int main(int C,char * V[]){
	glutInit(&C, V);
	glutInitWindowPosition(250,50);
	glutInitWindowSize(500, 500);
	glutInitDisplayMode(GLUT_RGB| GLUT_SINGLE);
	glutCreateWindow("Basic OpenGL Program");
	
	
	//to set the backGround colour
	glClearColor(1, 0, 0, 1);

	//to set the default drawing colour
	glColor3f(1, 0, 0);
	
	glutDisplayFunc(Draw);
	glutMainLoop();
	return 0;
}

