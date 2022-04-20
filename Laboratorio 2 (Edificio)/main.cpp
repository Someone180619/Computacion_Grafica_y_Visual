#include <windows.h>
#include <GL/glut.h>

void proyeccion(){
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-16,16,-9,9);
}

void cielo(){
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.8, 1.0);
    glVertex2i(-16, 10); glVertex2i(-16, -10);
    glVertex2i(16, -10); glVertex2i(16, 10);
    glEnd();
    glFlush();
}

void calle(){
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2i(-16, -9); glVertex2i(-16, -8);
    glVertex2i(16, -8); glVertex2i(16, -9);
    glEnd();
    glFlush();
}

void edificio1(){
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.3, 0.0);
    glVertex2i(-14, -8); glVertex2i(-14, 8);
    glVertex2i(-3, 8); glVertex2i(-3, -8);
    glEnd();
    glFlush();
}

void edificio2(){
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.7, 0.0);
    glVertex2i(3,-8); glVertex2i(3,8);
    glVertex2i(15,8); glVertex2i(15,-8);
    glEnd();
    glFlush();
}

void edificio3(){
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.0, 0.8);
    glVertex2i(-3,-1); glVertex2i(-3,6);
    glVertex2i(3,6); glVertex2i(3,-1);
    glEnd();
    glFlush();
}

void calle2(){
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex2i(-16,-8); glVertex2i(-16,-1);
    glVertex2i(16,-1); glVertex2i(16,-8);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-16,-4.6); glVertex2f(-16,-3.8);
    glVertex2f(16,-3.8); glVertex2f(16,-4.6);
    glEnd();
    glFlush();
}

void arbolito(){
    //Que pasa tronco
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.5, 0.0);
    glVertex2f(-0.8,-8); glVertex2f(-0.8,-4.6);
    glVertex2f(0.8,-4.6); glVertex2f(0.8,-8);
    glEnd();
    glFlush();
    //Triangulo inferior
    glBegin(GL_TRIANGLES);
    glColor3f(0.0,0.4,0.0);
    glVertex2f(-2.5,-4.6);
    glColor3f(0.0,0.4,0.0);
    glVertex2f(2.5,-4.6);
    glVertex2f(0,-1);
    glEnd();
    glFlush();
    //Trianculo superior
    glBegin(GL_TRIANGLES);
    glColor3f(0.0,0.7,0.0);
    glVertex2f(-2.5,-2);
    glColor3f(0.0,0.7,0.0);
    glVertex2f(2.5,-2);
    glVertex2f(0,8);
    glEnd();
    glFlush();
}

void ventanas1(){ //ventanas del edificio de la izquierda
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.7, 0.0);

    glVertex2f(-13, -4.6); glVertex2f(-13, -2.5);
    glVertex2f(-10.5, -2.5); glVertex2f(-10.5,-4.6); //ventana inferior izquierda

    glVertex2f(-13, -1); glVertex2f(-13, 1);
    glVertex2f(-10.5, 1); glVertex2f(-10.5,-1); //ventana central izquierda

    glVertex2f(-13, 3); glVertex2f(-13, 5);
    glVertex2f(-10.5, 5); glVertex2f(-10.5,3); //ventana superior izquierda

    glVertex2f(-10, -4.6); glVertex2f(-10, -2.5);
    glVertex2f(-7.5, -2.5); glVertex2f(-7.5,-4.6); //ventana inferior central

    glVertex2f(-10, -1); glVertex2f(-10, 1);
    glVertex2f(-7.5, 1); glVertex2f(-7.5,-1); //ventana central

    glVertex2f(-10, 3); glVertex2f(-10, 5);
    glVertex2f(-7.5, 5); glVertex2f(-7.5,3); //ventana superior central

    glVertex2f(-6.5, -4.6); glVertex2f(-6.5, -2.5);
    glVertex2f(-4, -2.5); glVertex2f(-4,-4.6); //ventana inferior derecha

    glVertex2f(-6.5, -1); glVertex2f(-6.5, 1);
    glVertex2f(-4, 1); glVertex2f(-4,-1); //ventana central derecha

    glVertex2f(-6.5, 3); glVertex2f(-6.5, 5);
    glVertex2f(-4, 5); glVertex2f(-4,3); //ventana superior derecha
    glEnd();
    glFlush();
}

void ventanas2(){
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.4, 0.0);

    glVertex2f(5.5, -4.6); glVertex2f(5.5, -2.5);
    glVertex2f(8.5, -2.5); glVertex2f(8.5,-4.6); //ventana inferior izquierda

    glVertex2f(5.5, -1); glVertex2f(5.5, 1);
    glVertex2f(8.5, 1); glVertex2f(8.5,-1); //ventana central izquierda

    glVertex2f(5.5, 3); glVertex2f(5.5, 5);
    glVertex2f(8.5, 5); glVertex2f(8.5,3); //ventana superior izquierda

    glVertex2f(9.5, -4.6); glVertex2f(9.5, -2.5);
    glVertex2f(12.5, -2.5); glVertex2f(12.5,-4.6); //ventana inferior derecha

    glVertex2f(9.5, -1); glVertex2f(9.5, 1);
    glVertex2f(12.5, 1); glVertex2f(12.5,-1); //ventana central derecha

    glVertex2f(9.5, 3); glVertex2f(9.5, 5);
    glVertex2f(12.5, 5); glVertex2f(12.5,3); //ventana superior derecha


    glEnd();
    glFlush();
}

void flag(){
    //Palito
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(5,-9); glVertex2f(5,-4.6);
    glVertex2f(5.1,-4.6); glVertex2f(5.1,-9);
    glEnd();
    glFlush();
    //Sostenedor
    glBegin(GL_TRIANGLES);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(4.5,-9);
    glVertex2f(5.6,-9);
    glColor3f(1.0,1.0,1.0);
    glVertex2f(5.05,-8.3);
    glEnd();
    glFlush();
    //Banderita
    glBegin(GL_TRIANGLES);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(5.1,-6.6);
    glVertex2f(6,-6.1);
    glVertex2f(5.1,-5.4);
    glEnd();
    glFlush();
}

void cuadroRojo(){
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-16,-9); glVertex2f(-16,-4.6);
    glVertex2f(-14,-4.6); glVertex2f(-14,-9);
    glEnd();
    glFlush();
}

void dibujar(void){
    glClear(GL_COLOR_BUFFER_BIT);
    cielo();
    calle();
    calle2();
    edificio1();
    edificio2();
    edificio3();
    flag();
    arbolito();
    ventanas1();
    ventanas2();
    glFlush();
}

int main(int argc, char* argv [])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1400, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Taller 2 | Edificio");
    proyeccion();
    glutDisplayFunc(dibujar);
    glutMainLoop();
}
