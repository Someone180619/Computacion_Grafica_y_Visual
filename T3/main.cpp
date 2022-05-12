#include <windows.h>
#include <stdio.h>
#include<string.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>
#define PI=3.14159265358979323846;



/* Variables de uso general */
static int window;
float xx =0.0;
float yy=0.0;
void KoopaTropa();
static int valueShapes = 0;
static int submenu_menu;
using namespace std;

void geometricMenu(int num){
    valueShapes = num;
    glutPostRedisplay();
    }

void exit(){
    glutDestroyWindow(window); // Cierra la ventana.
    exit(0);
}

void createMenu(void){
    int e;
    submenu_menu = glutCreateMenu(geometricMenu); //Opciones para el submenú "Figuras".
    glutAddMenuEntry("Identificación del grupo", 1);
    glutAddMenuEntry("Paisaje", 2);
    glutAddMenuEntry("Mario Bro", 3);

    glutCreateMenu(geometricMenu); // Se Crea el menú de opciones.
    e = glutCreateMenu(exit); // Cierre de ventana.

    // Opciones principales
    glutAddSubMenu("Menu en OpenGlut", submenu_menu);
    glutAddMenuEntry("Salida", e);
    glutAttachMenu(GLUT_RIGHT_BUTTON); //Click derecho de despliegue
}


//Taller 3""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
void KoopaTropa(){
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
///lineas horizontales
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
    glVertex2i(325,425);glVertex2i(350,425);
    glVertex2i(350,275);glVertex2i(325,275);
    //espacio
    glVertex2i(325,225);glVertex2i(350,225);
    glVertex2i(350,175);glVertex2i(325,175);
    //espacio
    glVertex2i(325,150);glVertex2i(350,150);
    glVertex2i(350,125);glVertex2i(325,125);

///linea 2
    glVertex2i(350,475);glVertex2i(375,475);
    glVertex2i(375,425);glVertex2i(350,425);
    //espacio
    glVertex2i(350,375);glVertex2i(375,375);
    glVertex2i(375,350);glVertex2i(350,350);
    //espacio
    glVertex2i(350,275);glVertex2i(375,275);
    glVertex2i(375,250);glVertex2i(350,250);


///linea 3
    glVertex2i(375,500);glVertex2i(400,500);
    glVertex2i(400,475);glVertex2i(375,475);
    //espacio
    glVertex2i(375,400);glVertex2i(400,400);
    glVertex2i(400,375);glVertex2i(375,375);
    //espacio
    glVertex2i(375,350);glVertex2i(400,350);
    glVertex2i(400,325);glVertex2i(375,325);

///linea 4
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
    glVertex2i(450,450);glVertex2i(425,450);
    glVertex2i(425,425);glVertex2i(450,425);
    //espacio
    glVertex2i(450,300);glVertex2i(425,300);
    glVertex2i(425,275);glVertex2i(450,275);

///linea 6
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
    glVertex2i(475,500);glVertex2i(500,500);
    glVertex2i(500,475);glVertex2i(475,475);
    //espacio
    glVertex2i(475,400);glVertex2i(500,400);
    glVertex2i(500,375);glVertex2i(475,375);
    //espacio
    glVertex2i(475,350);glVertex2i(500,350);
    glVertex2i(500,325);glVertex2i(475,325);


///linea 9
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
    glVertex2i(550,675);glVertex2i(575,675);
    glVertex2i(575,650);glVertex2i(550,650);
    //espacio
    glVertex2i(550,475);glVertex2i(575,475);
    glVertex2i(575,400);glVertex2i(550,400);
    //espacio
    glVertex2i(550,225);glVertex2i(575,225);
    glVertex2i(575,175);glVertex2i(550,175);

///linea 12
    glVertex2i(575,725);glVertex2i(600,725);
    glVertex2i(600,600);glVertex2i(575,600);
    //espacio
    glVertex2i(575,400);glVertex2i(600,400);
    glVertex2i(600,200);glVertex2i(575,200);

///linea 13
    glVertex2i(600,475);glVertex2i(625,475);
    glVertex2i(625,425);glVertex2i(600,425);
    //espacio
    glVertex2i(600,300);glVertex2i(625,300);
    glVertex2i(625,275);glVertex2i(600,275);
    //espacio
    glVertex2i(600,200);glVertex2i(625,200);
    glVertex2i(625,175);glVertex2i(600,175);

///linea 14
    glVertex2i(625,425);glVertex2i(650,425);
    glVertex2i(650,400);glVertex2i(625,400);
    //espacio
    glVertex2i(625,350);glVertex2i(650,350);
    glVertex2i(650,300);glVertex2i(625,300);
    //espacio
    glVertex2i(625,175);glVertex2i(650,175);
    glVertex2i(650,150);glVertex2i(625,150);

///linea 15
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
    glVertex2i(675,675);glVertex2i(700,675);
    glVertex2i(700,550);glVertex2i(675,550);
    //espacio
    glVertex2i(675,450);glVertex2i(700,450);
    glVertex2i(700,425);glVertex2i(675,425);
    //espacio
    glVertex2i(675,400);glVertex2i(700,400);
    glVertex2i(700,350);glVertex2i(675,350);

///linea 17
    glVertex2i(700,550);glVertex2i(725,550);
    glVertex2i(725,425);glVertex2i(700,425);

    glEnd();
    glFlush();
}

void Color(){
    glBegin(GL_QUADS);
///caparazon verde
    glColor3f(0.0,0.5,0.0);
    glVertex2i(350,500);glVertex2i(525,500);
    glVertex2i(525,225);glVertex2i(350,225);
    glColor3f(1.0,1.0,1.0);
    glVertex2i(350,500);glVertex2i(375,500);
    glVertex2i(375,475);glVertex2i(350,475);
///Relleno Amarillo
    glColor3f(1.0,0.5,0.0);
    //patas
    glVertex2i(500,175);glVertex2i(625,175);
    glVertex2i(625,125);glVertex2i(500,125);
    glVertex2i(375,150);glVertex2i(475,150);
    glVertex2i(475,125);glVertex2i(375,125);
    glVertex2i(575,200);glVertex2i(600,200);
    glVertex2i(600,175);glVertex2i(575,175);
    //cara
    glVertex2i(525,650);glVertex2i(600,650);
    glVertex2i(600,475);glVertex2i(525,475);
    glVertex2i(575,550);glVertex2i(625,550);
    glVertex2i(625,300);glVertex2i(575,300);
    glVertex2i(625,525);glVertex2i(650,525);
    glVertex2i(650,500);glVertex2i(625,500);
    glVertex2i(650,550);glVertex2i(700,550);
    glVertex2i(700,450);glVertex2i(650,450);
    glVertex2i(625,400);glVertex2i(675,400);
    glVertex2i(675,350);glVertex2i(625,350);

    glEnd();
    glFlush();

}
//fin taller 3""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//Taller 2######################################################3

//fin taller 2############################################################

void Display(void){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION | GL_MODELVIEW);
    switch (valueShapes)//Proyecta identificación del grupo, taller 2 o 3 y
    {
        case 1: //identificación de grupo

        break;
        case 2: //taller 2

        break;
        case 3: //taller 3
            glColor3f(0.0f, 0.0f, 0.0f);
            glClearColor(1.0,1.0,1.0,1.0);
            glClear (GL_COLOR_BUFFER_BIT);
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            gluOrtho2D(0.0, 800.0, 0.0, 800.0);
            Color();
            KoopaTropa();
            glEnd();
        break;
    }
    glFlush ();
}


int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize (800, 600);
    glutInitWindowPosition (100,100);
    window = glutCreateWindow ("Taller3 - Koopa Tropa" );
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(Display);
    createMenu();
    glutMainLoop();
    return EXIT_SUCCESS;
}
