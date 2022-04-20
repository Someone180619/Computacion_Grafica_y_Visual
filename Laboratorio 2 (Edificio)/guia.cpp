#include <windows.h>
#include <GL/glut.h>

void proyeccion(){
    glClearColor(0.0,0.3,0.5,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-20,21,-22,20);
}

void dibujar_edificio() {

    glBegin(GL_QUADS);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.52,0.37,0.26);
    glVertex2f(14,-20);glVertex2f(14,-14);
    glVertex2f(18,-14);glVertex2f(18,-20);
    glEnd();
    glFlush();

    glBegin(GL_TRIANGLES);
    glColor3f(0.17,0.34,0.17);
    glVertex2f(12,-14);
    glColor3f(0.17,0.64,0.17);
    glVertex2f(20,-14);
    glVertex2f(16,-5);
    glEnd();
    glFlush();

    glBegin(GL_TRIANGLES);
    glColor3f(0.17,0.34,0.17);
    glVertex2f(12,-11);
    glColor3f(0.17,0.64,0.17);
    glVertex2f(20,-11);
    glVertex2f(16,-1);
    glEnd();
    glFlush();

    glBegin(GL_TRIANGLES);
    glColor3f(0.17,0.34,0.17);
    glVertex2f(12,-7);
    glColor3f(0.17,0.64,0.17);
    glVertex2f(20,-7);
    glVertex2f(16,5);
    glEnd();
    glFlush();

    glBegin(GL_QUADS);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.52,0.37,0.26);
    glVertex2f(-20,-22);glVertex2f(-20,-20);
    glColor3f(0.2,0.7,0.26);
    glVertex2f(21,-20);glVertex2f(21,-22);
    glEnd();
    glFlush();

}

void dibujar(void){
    glClear(GL_COLOR_BUFFER_BIT);
    dibujar_edificio();

    glPushMatrix();
    glTranslated(14,12,5);
    glColor3f(1.72,1.45,0.5);
    glutSolidSphere(6,40,5);
    glPopMatrix();
    glFlush();
}

int main(int argc, char* argv [])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Taller 2 | Edificio");
    proyeccion();
    glutDisplayFunc(dibujar);
    glutMainLoop();
}
