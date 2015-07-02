#include <GL/glut.h>

void object(float i){
	
	for (int j = 0; j <= i; j++)
	{
		float l = j/i;
		if(j%2==0)
			glColor3f(1, 1, 1);
		else
			glColor3f(1, 0,0);
		glBegin(GL_QUADS);
			glVertex3f(l, 0, 0.0);
			glVertex3f(l+0.25, 0, 0.0);
			glVertex3f(l+0.25, 0.25, 0.0);
			glVertex3f(l, 0.25, 0.0);
		glEnd();
	}
	for (int j = 0; j <= i; j++)
	{
		float l = j/i;
		if(j%2==1)
			glColor3f(1, 1, 1);
		else
			glColor3f(1, 0,0);
		glBegin(GL_QUADS);
			glVertex3f(l, .25, 0.0);
			glVertex3f(l+0.25, .25, 0.0);
			glVertex3f(l+0.25, 0.5, 0.0);
			glVertex3f(l, 0.5, 0.0);
		glEnd();
	}
	for (int j = 0; j <= i; j++)
	{
		float l = j/i;
		if(j%2==0)
			glColor3f(1, 1, 1);
		else
			glColor3f(1, 0,0);
		glBegin(GL_QUADS);
			glVertex3f(l, .5, 0.0);
			glVertex3f(l+0.25, .5, 0.0);
			glVertex3f(l+0.25, 0.75, 0.0);
			glVertex3f(l, 0.75, 0.0);
		glEnd();
	}
	for (int j = 0; j <= i; j++)
	{
		float l = j/i;
		if(j%2==1)
			glColor3f(1, 1, 1);
		else
			glColor3f(1, 0,0);
		glBegin(GL_QUADS);
			glVertex3f(l, .75, 0.0);
			glVertex3f(l+0.25, .75, 0.0);
			glVertex3f(l+0.25, 1, 0.0);
			glVertex3f(l, 1, 0.0);
		glEnd();
	}

}
void Draw() {
	glClear(GL_COLOR_BUFFER_BIT);
	
	object(4);
	glFlush();
}

void Initialize() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

int main(int iArgc, char** cppArgv) {
	glutInit(&iArgc, cppArgv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(250, 250);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("AIUB lab");
	Initialize();
	glutDisplayFunc(Draw);
	glutMainLoop();
	return 0;
}