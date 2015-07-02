#include <gl/glut.h>
#include <stdio.h>
float X[100],Y[100];
int i = 0;
int j = 0;
int C = 0;
float Width,Height;
float R=1,G=1,B=1;
void GetDimention(int width, int height){
	Width = (float) width;
	Height = (float) height;
	
}
void Exit(unsigned char key, int x, int y){
	switch (key) {
		case 114:
			R=1;
			G=B=0;
			glutPostRedisplay();
			break;
		case 103:
			G=1;
			R=B=0;
			glutPostRedisplay();
			break;
		case 8:
			R=B=G=1;
			glutPostRedisplay();
			break;
		case 98:
			B=1;
			G=R=0;
			glutPostRedisplay();
			break;
		case 27:
			exit(0);
			break;
		case 110:
			C=1;
			glutPostRedisplay();
			C=0;
			i=j=0;
			break;
	}
}
void DrawLine(int button, int state, int x, int y){
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		X[i++] = (float) x/Width;
		Y[j++] = (float) y/Height;
		glutPostRedisplay();		
	}
	
}
void DrawLoop(){
	int k,l;
	k=l=0;
	int c =0;
	while(k < i){
		glVertex3f(X[k++],Y[l++],0.0);
		c++;
		if(c%2 == 0){
			glVertex3f(X[k-1],Y[l-1],0.0);
			c=1;
		}
	}
}
void Draw() {
	glClear(GL_COLOR_BUFFER_BIT);
	
	if(C==0){
		glLineWidth(10);
		glBegin(GL_LINES);
		glColor3f(R, G, B);	
		DrawLoop();
		glEnd();
	}
	glFlush();
	glutSwapBuffers();
}


void Initialize() {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0,1,1,0,-1,1);
}


int main(int iArgc, char** cppArgv) {
	glutInit(&iArgc, cppArgv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(1366, 768);
    glutCreateWindow("Continuous Lines"); 
    glutFullScreen();
	Initialize();
	glutDisplayFunc(Draw);
	glutKeyboardFunc(Exit);
	glutMouseFunc(DrawLine);
	glutReshapeFunc(GetDimention);
	glutMainLoop();
	return 0;
}