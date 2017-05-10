#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>

static int a = 0;
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };


////Model////
class Model {
	public:
	void drawModel()
	{
		glClearColor(1.0, 0.20, 0.46, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glPushMatrix();
		glTranslatef(0, -0.4, 0);
		glScalef(1, 1, 0.2);
		glutSolidCube(1);
		glPopMatrix();
	}

};


//// Camera ////
class Camera {
	
	public:
	void drawBegin()
	{
		glMatrixMode(GL_PROJECTION);
		gluPerspective(45.0, 1.0, 1.0, 10.0);
		glMatrixMode(GL_MODELVIEW);
		gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.);
	}
	void drawEnd()
	{	
		glutSwapBuffers();
	}
};


//// Light ////
class Light {
	public:
		void draw()
		{   
		    glEnable(GL_CULL_FACE);
		    glCullFace(GL_BACK);

		    glEnable(GL_DEPTH_TEST);
		    glDepthFunc(GL_LESS);

		    glEnable(GL_LIGHT0);
		    glEnable(GL_NORMALIZE);
		    glEnable(GL_COLOR_MATERIAL);
		    glEnable(GL_LIGHTING);

		    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
		    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
		    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
		    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

		    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
		    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
		    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
		    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
		
		}
	
};

void fingerColor()
{
	glColor3ub(240,230,140);
}

void fingerColor1()
{
	glColor3ub(240,230,200);
}

//// Finger ////
class Finger {
	public:
		void drawFinger()
		{
	
			glPushMatrix();
			glRotatef(a, 1, 0, 0);
			glTranslatef(0, 0.27, 0);
			glScalef(0.3, 1, 0.3);
			fingerColor();
			glutSolidCube(0.4);

			glPushMatrix();
			glTranslatef(0, 0.27, 0);
			glScalef(3.33, 1, 3.33);
			fingerColor1();
			glutSolidSphere(0.08, 10, 10);

			glPushMatrix();
			glRotatef(a, 1, 0, 0);
			glTranslatef(0, 0.27, 0);
			glScalef(0.3, 1, 0.3);
			fingerColor();
			glutSolidCube(0.4);

			glPushMatrix();
			glTranslatef(0, 0.27, 0);
			glScalef(3.33, 1, 3.33);
			fingerColor1();
			glutSolidSphere(0.08, 10, 10);

			glPushMatrix();
			glRotatef(a, 1, 0, 0);
			glTranslatef(0, 0.18, 0);
			glScalef(0.3, 0.7, 0.3);
			fingerColor();
			glutSolidCube(0.35);
							
			glPopMatrix();
			glPopMatrix();
			glPopMatrix();
			glPopMatrix();
			glPopMatrix();
		}
};

////Thumb////
class Thumb
{	
	public:
		void drawThumb()
		{
		
			glPushMatrix();
			glRotatef(a, 1, 0, 0);
			glTranslatef(0, 0.27, 0);
			glScalef(0.3, 1, 0.3);
			fingerColor();
			glutSolidCube(0.4);

			glPushMatrix();
			glTranslatef(0, 0.27, 0);
			glScalef(3.33, 1, 3.33);
			fingerColor1();
			glutSolidSphere(0.08, 10, 10);

			glPushMatrix();
			glRotatef(a, 1, 0, 0);
			glTranslatef(0, 0.27, 0);
			glScalef(0.3, 1, 0.3);
			fingerColor();
			glutSolidCube(0.4);
			
			glPopMatrix();
			glPopMatrix();
			glPopMatrix();

	
		}
};


//// Hand ////
class Hand {
	private:
		Model Palm;
		Finger Digit[4];
		Thumb thumb;
		Camera camera;
	public:

		void drawHand()
		{
			Palm.drawModel();
			glPushMatrix();
			glTranslatef(0.35, 0, 0);
			Digit[0].drawFinger();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(0.1, 0, 0);
			Digit[1].drawFinger();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(-0.15, 0, 0);
			Digit[2].drawFinger();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(-0.4, 0, 0);
			Digit[3].drawFinger();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(0.4, 0, 0);
			glRotatef(-90, 0, 0, 1);
			thumb.drawThumb();
			glPopMatrix();

			camera.drawEnd();
		}
	
};

void keyboard(unsigned char key, int x, int y){
	switch(key){
		case 'f':
			if(a < 90){
				a = a + 7.5;
				glutPostRedisplay();
			}
			break;
		case 'g':
			if(a > 0)
				a = a - 7.5;
			glutPostRedisplay();
			break;
		case 27:
			exit(0);
			break;
		default:
			break;
	}
}

void display(void){
	
	Hand hand;
	hand.drawHand();
	
}

void init()
{
	Light light;
	Camera camera;
	light.draw();
	camera.drawBegin();

	glTranslatef(0.0, 0.0, -1.0);
	glRotatef(25, 0, 1, 0);
}

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(750, 750);
	glutInitWindowPosition(250, 50);
	glutCreateWindow("Zavrsni projekat");
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	init();
	glutMainLoop();
	
	return 0;
}
