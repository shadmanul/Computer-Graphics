#include <gl/glut.h>
void Draw() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.4, 0.0);
	glPushMatrix();
	glColor3f(0.55, 0.0, 0.0);
	glutSolidTorus(0.4, 0.0, 15, 35);
	glPopMatrix();
	glFlush();
}
//void Draw() {
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(0.0, 0.4, 0.0);
//	glPushMatrix();
//		glBegin(GL_QUADS);
//			glVertex3f(-1.0, -1.0, 0);
//			glVertex3f(1.0, -1.0, 0);
//			glVertex3f(1.0, 1.0, 0);
//			glVertex3f(-1.0, 1.0, 0);
//		glEnd();
//		glPushMatrix();
//			glColor3f(0.55, 0.0, 0.0);
//			
//			glBegin(GL_POLYGON);
//				glVertex3f(-0.3, -0.1, 0);		//1
//				glVertex3f(-0.22, -0.245, 0);	//2
//				glVertex3f(-0.1, -0.33, 0);		//3
//				glVertex3f(0.1, -0.33, 0);		//4
//				glVertex3f(0.22, -0.245, 0);	//5
//				glVertex3f(0.3, -0.1, 0);		//6
//				glVertex3f(0.3, 0.1, 0);		//7
//				glVertex3f(0.22, 0.245, 0);		//8
//				glVertex3f(0.1, 0.33, 0);		//9
//				glVertex3f(-0.1, 0.33, 0);		//10
//				glVertex3f(-0.22, 0.245, 0);	//11
//				glVertex3f(-0.3, 0.1, 0);		//12	
//			glEnd();
//		glPopMatrix();
//	glPopMatrix();
//	glFlush();
//}

void Initialize() {
	glClearColor(0.0, 0.4, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(1.0, 1.0, 1.0, 1.0, -1.0, 1.0);
}

int main(int iArgc, char** cppArgv) {
	glutInit(&iArgc, cppArgv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 350);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("AIUB");
	Initialize();
	glutDisplayFunc(Draw);
	glutMainLoop();

	return 0;
}