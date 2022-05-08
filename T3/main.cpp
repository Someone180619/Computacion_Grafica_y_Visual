#include <windows.h>
#include <stdio.h>
#include<string.h>
#include <GL/glut.h>
#include <math.h>

void proyeccion(){
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-16,16,-9,9);
}

void KoopaTropa(){
    glBegin(GL_QUADS);
///lineas horizontales
	glColor3f(0.0,0.0,0.0);
    glVertex2i(600,750);glVertex2i(650,750);
    glVertex2i(650,725);glVertex2i(600,725);
    //espacio
    glVertex2i(600,500);glVertex2i(650,500);
    glVertex2i(650,475);glVertex2i(600,475);
    //espacio
    glVertex2i(350,175);glVertex2i(500,175);
    glVertex2i(500,150);glVertex2i(350,150);
    //espacio
    glVertex2i(400,525);glVertex2i(475,525);
    glVertex2i(475,500);glVertex2i(400,500);
    //espacio
    glVertex2i(325,250);glVertex2i(500,250);
    glVertex2i(500,225);glVertex2i(325,225);
    //espacio (ultima linea)
    glVertex2i(500,125);glVertex2i(650,125);
    glVertex2i(650,100);glVertex2i(500,100);
    //espacio (ultima linea)
    glVertex2i(325,125);glVertex2i(475,125);
    glVertex2i(475,100);glVertex2i(325,100);

///linea 1
    glColor3f(0.0,0.0,0.0);
    glVertex2i(325,425);glVertex2i(350,425);
    glVertex2i(350,275);glVertex2i(325,275);
    //espacio
    glVertex2i(325,225);glVertex2i(350,225);
    glVertex2i(350,175);glVertex2i(325,175);
    //espacio
    glVertex2i(325,150);glVertex2i(350,150);
    glVertex2i(350,125);glVertex2i(325,125);

///linea 2
    glColor3f(0.0,0.0,0.0);
    glVertex2i(350,475);glVertex2i(375,475);
    glVertex2i(375,425);glVertex2i(350,425);
    //espacio
    glVertex2i(350,375);glVertex2i(375,375);
    glVertex2i(375,350);glVertex2i(350,350);
    //espacio
    glVertex2i(350,275);glVertex2i(375,275);
    glVertex2i(375,250);glVertex2i(350,250);


///linea 3
    glColor3f(0.0,0.0,0.0);
    glVertex2i(375,500);glVertex2i(400,500);
    glVertex2i(400,475);glVertex2i(375,475);
    //espacio
    glVertex2i(375,400);glVertex2i(400,400);
    glVertex2i(400,375);glVertex2i(375,375);
    //espacio
    glVertex2i(375,350);glVertex2i(400,350);
    glVertex2i(400,325);glVertex2i(375,325);

///linea 4
    glColor3f(0.0,0.0,0.0);
    glVertex2i(400,475);glVertex2i(425,475);
    glVertex2i(425,450);glVertex2i(400,450);
    //espacio
    glVertex2i(400,425);glVertex2i(425,425);
    glVertex2i(425,400);glVertex2i(400,400);
    //espacio
    glVertex2i(400,325);glVertex2i(425,325);
    glVertex2i(425,300);glVertex2i(400,300);
    //espacio
    glVertex2i(400,275);glVertex2i(425,275);
    glVertex2i(425,250);glVertex2i(400,250);

///linea 5
    glColor3f(0.0,0.0,0.0);
    glVertex2i(450,450);glVertex2i(425,450);
    glVertex2i(425,425);glVertex2i(450,425);
    //espacio
    glVertex2i(450,300);glVertex2i(425,300);
    glVertex2i(425,275);glVertex2i(450,275);

///linea 6
    glColor3f(0.0,0.0,0.0);
    glVertex2i(475,475);glVertex2i(450,475);
    glVertex2i(450,450);glVertex2i(475,450);
    //espacio
    glVertex2i(475,425);glVertex2i(450,425);
    glVertex2i(450,400);glVertex2i(475,400);
    //espacio
    glVertex2i(475,325);glVertex2i(450,325);
    glVertex2i(450,300);glVertex2i(475,300);
    //espacio
    glVertex2i(475,275);glVertex2i(450,275);
    glVertex2i(450,250);glVertex2i(475,250);
    //espacio
    glVertex2i(475,150);glVertex2i(450,150);
    glVertex2i(450,125);glVertex2i(475,125);


///linea 8
    glColor3f(0.0,0.0,0.0);
    glVertex2i(475,500);glVertex2i(500,500);
    glVertex2i(500,475);glVertex2i(475,475);
    //espacio
    glVertex2i(475,400);glVertex2i(500,400);
    glVertex2i(500,375);glVertex2i(475,375);
    //espacio
    glVertex2i(475,350);glVertex2i(500,350);
    glVertex2i(500,325);glVertex2i(475,325);


///linea 9
    glColor3f(0.0,0.0,0.0);
    glVertex2i(500,625);glVertex2i(525,625);
    glVertex2i(525,525);glVertex2i(500,525);
    //espacio
    glVertex2i(500,500);glVertex2i(525,500);
    glVertex2i(525,400);glVertex2i(500,400);
    //espacio
    glVertex2i(500,375);glVertex2i(525,375);
    glVertex2i(525,350);glVertex2i(500,350);
    //espacio
    glVertex2i(500,275);glVertex2i(525,275);
    glVertex2i(525,225);glVertex2i(500,225);
    //espacio
    glVertex2i(500,200);glVertex2i(525,200);
    glVertex2i(525,125);glVertex2i(500,125);

///linea 10
    glColor3f(0.0,0.0,0.0);
    glVertex2i(525,650);glVertex2i(550,650);
    glVertex2i(550,625);glVertex2i(525,625);
    //espacio
    glVertex2i(525,525);glVertex2i(550,525);
    glVertex2i(550,475);glVertex2i(525,475);
    //espacio
    glVertex2i(525,400);glVertex2i(550,400);
    glVertex2i(550,275);glVertex2i(525,275);
    //espacio
    glVertex2i(525,200);glVertex2i(550,200);
    glVertex2i(550,175);glVertex2i(525,175);

///linea 11
    glColor3f(0.0,0.0,0.0);
    glVertex2i(550,675);glVertex2i(575,675);
    glVertex2i(575,650);glVertex2i(550,650);
    //espacio
    glVertex2i(550,475);glVertex2i(575,475);
    glVertex2i(575,400);glVertex2i(550,400);
    //espacio
    glVertex2i(550,225);glVertex2i(575,225);
    glVertex2i(575,175);glVertex2i(550,175);

///linea 12
    glColor3f(0.0,0.0,0.0);
    glVertex2i(575,725);glVertex2i(600,725);
    glVertex2i(600,600);glVertex2i(575,600);
    //espacio
    glVertex2i(575,400);glVertex2i(600,400);
    glVertex2i(600,200);glVertex2i(575,200);

///linea 13
    glColor3f(0.0,0.0,0.0);
    glVertex2i(600,475);glVertex2i(625,475);
    glVertex2i(625,425);glVertex2i(600,425);
    //espacio
    glVertex2i(600,300);glVertex2i(625,300);
    glVertex2i(625,275);glVertex2i(600,275);
    //espacio
    glVertex2i(600,200);glVertex2i(625,200);
    glVertex2i(625,175);glVertex2i(600,175);

///linea 14
    glColor3f(0.0,0.0,0.0);
    glVertex2i(625,425);glVertex2i(650,425);
    glVertex2i(650,400);glVertex2i(625,400);
    //espacio
    glVertex2i(625,350);glVertex2i(650,350);
    glVertex2i(650,300);glVertex2i(625,300);
    //espacio
    glVertex2i(625,175);glVertex2i(650,175);
    glVertex2i(650,150);glVertex2i(625,150);

///linea 15
    glColor3f(0.0,0.0,0.0);
    glVertex2i(650,725);glVertex2i(675,725);
    glVertex2i(675,675);glVertex2i(650,675);
    //espacio
    glVertex2i(650,650);glVertex2i(675,650);
    glVertex2i(675,575);glVertex2i(650,575);
    //espacio
    glVertex2i(650,550);glVertex2i(675,550);
    glVertex2i(675,525);glVertex2i(650,525);
    //espacio
    glVertex2i(650,475);glVertex2i(675,475);
    glVertex2i(675,450);glVertex2i(650,450);
    //espacio
    glVertex2i(650,400);glVertex2i(675,400);
    glVertex2i(675,375);glVertex2i(650,375);
    //espacio
    glVertex2i(650,350);glVertex2i(675,350);
    glVertex2i(675,325);glVertex2i(650,325);
    //espacio
    glVertex2i(650,150);glVertex2i(675,150);
    glVertex2i(675,100);glVertex2i(650,100);

///linea 16
    glColor3f(0.0,0.0,0.0);
    glVertex2i(675,675);glVertex2i(700,675);
    glVertex2i(700,550);glVertex2i(675,550);
    //espacio
    glVertex2i(675,450);glVertex2i(700,450);
    glVertex2i(700,425);glVertex2i(675,425);
    //espacio
    glVertex2i(675,400);glVertex2i(700,400);
    glVertex2i(700,350);glVertex2i(675,350);

///linea 17
    glColor3f(0.0,0.0,0.0);
    glVertex2i(700,550);glVertex2i(725,550);
    glVertex2i(725,425);glVertex2i(700,425);

    glEnd();
    glFlush();
}


void myDisplay(void)
{
    glClearColor(1.0,1.0,1.0,1.0);
    glClear (GL_COLOR_BUFFER_BIT);
    KoopaTropa();
    glEnd();
    glFlush ();
}

void Dibujar (void)
{
    glColor3f(0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 800.0, 0.0, 800.0);
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (800, 600);
    glutInitWindowPosition (200,50);
    glutCreateWindow ("Taller3 - Koopa Tropa" );
    glutDisplayFunc(myDisplay);
    Dibujar();
    glutMainLoop();
}

