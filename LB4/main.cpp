#include <windows.h>
#include <GL/glut.h>
#include <math.h>

using namespace std;

float a, b;

void iniciarProyeccion (void)
{
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_MODELVIEW | GL_PROJECTION);
    glLoadIdentity();
}

void propellers(void){ //Hélices del avión tanto derecha, como izquierda.
    float calx, caly, r = 0.07, px_hp = -0.318, py_hp = 0.25, px_lp = 0.128, py_lp = -0.139;
    glColor3f(0.0, 0.0, 0.0);
    //High Propeller
    glPushMatrix();
    glTranslatef(-0.318, 0.25, 0.0);
    glRotatef(a,0,0,1);
    glTranslatef(0.318, -0.25, 0.0);
    glBegin(GL_LINES);
    for(float i = 0.0; i<25; i+= 1)
    {
        calx = r*cos(i)+ px_hp;
        caly = r*sin(i)+py_hp;
        glVertex2f(-0.318, 0.25); glVertex2f(calx, caly);
    }
    glEnd();
    glPopMatrix();
    glColor3f(0.0, 0.2, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.333, 0.25);
    glVertex2f(-0.318, 0.265);
    glVertex2f(-0.303, 0.25);
    glVertex2f(-0.318, 0.235);
    glEnd();

    //Lower Propeller
    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(0.128, -0.139, 0.0);
    glRotatef(b,0,0,1);
    glTranslatef(-0.128, 0.138, 0.0);
    glBegin(GL_LINES);
    for(float i = 0.0; i<25; i+= 1)
    {
        calx = r*cos(i)+ px_lp;
        caly = r*sin(i)+py_lp;
        glVertex2f(0.128, -0.139); glVertex2f(calx, caly);
    }
    glEnd();
    glPopMatrix();
    glColor3f(0.0, 0.2, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.113, -0.139);
    glVertex2f(0.128, -0.154);
    glVertex2f(0.143, -0.139);
    glVertex2f(0.128, -0.124);
    glEnd();
}

void internalChambers(void) //Capa interna de las turbinas.
{
    float x, y, r = 0.07, i = 0.0f;
    //High Chamber
    glColor3f(0.3, 0.3, 0.3);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x = -0.318, y = 0.25); // Center
    for(i = 0.0f; i <= 360; i++)
        glVertex2f(r*cos(3.1416 * i / 180.0) + x, r*sin(3.1416 * i / 180.0) + y);
    glEnd();
    //Lower Chamber
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x = 0.128, y = -0.139); // Center
    for(i = 0.0f; i <= 360; i++)
        glVertex2f(r*cos(3.1416 * i / 180.0) + x, r*sin(3.1416 * i / 180.0) + y);
    glEnd();
    propellers();
}

void externalChambers(void) //Capa externa de las turbinas.
{
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDisable(GL_LIGHTING);
    GLfloat luz_ambiente_ch[]={0.1,0.1,0.1,1.0};
    GLfloat luz_difusa_ch[]={0.8,0.8,0.8,1.0};
    GLfloat luz_especular_ch[]={0.4,0.4,0.4,1.0};
    GLfloat luz_alta[]={0.0,0.2,-0.8,1.0};
    glBegin(GL_QUADS);
    //celeste
    glColor3f(0.650, 0.878, 0.890);
    glVertex2f(-1.0, 1.0);
    glVertex2f(-1.0,-1.0);
    //amarillo
    glColor3f(0.815, 0.745, 0.525);
    glVertex2f(1.0,-1.0);
    glVertex2f(1.0, 1.0);
    glEnd();

    glColor3f(0.4, 0.4, 0.4);
    //High chamber
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glPushMatrix();
    glLightfv(GL_LIGHT0, GL_AMBIENT, luz_ambiente_ch);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, luz_difusa_ch);
    glLightfv(GL_LIGHT0, GL_SPECULAR, luz_especular_ch);
    glLightfv(GL_LIGHT0, GL_POSITION, luz_alta);
    glTranslatef(-0.29, 0.26, 0.0);
    glutSolidSphere(0.1, 25, 20);
    glPopMatrix();
    //LowChamber
    glPushMatrix();
    glTranslatef(0.15, -0.12, 0.0);
    glutSolidSphere(0.1, 25, 20);
    glPopMatrix();
    glDisable(GL_LIGHTING);
    internalChambers();


}

static void display(void) //Función encargada de la construcción en general de la estructura del avión.
{
    GLfloat luz_ambiente[]={0.30, 0.30, 0.35, 1.0};
    GLfloat luz_difusa[]={0.30, 0.30, 0.50, 1.0};
    GLfloat luz_especular[]={0.70, 0.70, 0.80, 1.0};
    GLfloat luz_baja[]={0.0,0.2,-0.8,1.0};
    float wx = -0.25, wy = -0.1, cx = 0.0, cy = 0.0;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //Chambers
    externalChambers();
    //Wing
    glBegin(GL_POLYGON);
    //high
    glColor3f(0.0, 0.8, 0.4);
    glVertex2f(-0.2, 0.1);
    glVertex2f(-0.36, 0.75);
    glColor3f(0.0, 0.4, 0.1);
    glVertex2f(-0.34, 0.8);
    glVertex2f(0.15, 0.3);
    glEnd();
    glBegin(GL_POLYGON);
    //low
    glColor3f(0.0, 0.8, 0.4);
    glVertex2f(-0.3, 0.1);
    glVertex2f(0.7, -0.3);
    glColor3f(0.0, 0.4, 0.1);
    glVertex2f(0.76, -0.28);
    glVertex2f(0.2, 0.2);
    glEnd();
    glBegin(GL_POLYGON);

    //Aircraft Body
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.2, 0.4);
    glVertex2f(-0.5, -0.43);
    glVertex2f(-0.6, -0.1);
    glColor3f(0.1, 0.4, 0.4);
    glVertex2f(0.3, 0.6);
    glVertex2f(0.5, 0.4);
    glEnd();

    //Aircraft rudder
    glBegin(GL_POLYGON);
    glVertex2f(0.3, 0.6);
    glVertex2f(0.25, 0.75);
    glVertex2f(0.3, 0.8);
    glVertex2f(0.4, 0.68);
    glVertex2f(0.6, 0.9);
    glVertex2f(0.56, 0.54);
    glVertex2f(0.56, 0.54);
    glVertex2f(0.7, 0.4);
    glVertex2f(0.65, 0.35);
    glVertex2f(0.5, 0.4);
    glEnd();


    //Main Cabin
    glDisable(GL_LIGHTING);
    glPushMatrix();
    glColor3f(0.0, 0.2, 0.4);
    glTranslatef(-0.53, -0.205, 0.0);
    glutSolidSphere(0.125, 25, 20);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.56, -0.318, 0.0);
    glutSolidSphere(0.125, 25, 20);
    glPopMatrix();

    //Windows
    glColor3f(1.0, 0.0, 0.0);
    glColor3f(0.4, 0.2, 0.4);
    glPushMatrix();
    glTranslatef(-0.6, -0.2, 0.0);
    glutSolidSphere(0.025, 25, 20);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.45, -0.15, 0.0);
    glutSolidSphere(0.025, 25, 20);
    glPopMatrix();
    glDisable(GL_LIGHTING);
    glBegin(GL_POLYGON);
    glVertex2f(-0.6, -0.175);
    glVertex2f(-0.45, -0.125);
    glVertex2f(-0.45, -0.175);
    glVertex2f(-0.6, -0.225);
    glEnd();
    glPushMatrix();
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glLightfv(GL_LIGHT0, GL_AMBIENT, luz_ambiente);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, luz_difusa);
    glLightfv(GL_LIGHT0, GL_SPECULAR, luz_especular);
    glLightfv(GL_LIGHT0, GL_POSITION, luz_baja);
    glTranslatef(-0.35, -0.2, 0.0);
    glutSolidSphere(0.035, 25, 20);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.2, -0.08, 0.0);
    glutSolidSphere(0.035, 25, 20);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.05, 0.04, 0.0);
    glutSolidSphere(0.035, 25, 20);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.1, 0.16, 0.0);
    glutSolidSphere(0.035, 25, 20);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.25, 0.28, 0.0);
    glutSolidSphere(0.035, 25, 20);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.4, 0.4, 0.0);
    glutSolidSphere(0.035, 25, 20);
    glPopMatrix();
    glFlush();
}

void specialkey(int key, int x, int y)
{
    if(key==GLUT_KEY_UP|GLUT_KEY_DOWN|GLUT_KEY_RIGHT|GLUT_KEY_LEFT)
        a-=10; //Hélices altas
        b+=10; //Hélices bajas
        glutPostRedisplay();
}

int main (int argc, char* argv []) //Función principal.
{

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(800,700);
    glutInitWindowPosition(300,100);

    glutCreateWindow ("Aircraft");

    iniciarProyeccion();
    glutDisplayFunc(display);
    glutSpecialFunc(specialkey);

    glutMainLoop();
    return EXIT_SUCCESS;
}