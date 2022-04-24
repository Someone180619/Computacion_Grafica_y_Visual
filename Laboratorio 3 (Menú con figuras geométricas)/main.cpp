#include <windows.h>
#include <GL/glut.h>

static int window;
static int save;
static int submenu_shapes;
static int submenu_colors;
static int valueShapes = 0; 
static int valueColors = 0;
static float n1 = 1.0, n2 = 1.0, n3 = 1.0;

void geometricMenu(int num){
    valueShapes = num;
    glutPostRedisplay();
} 

void geometricColors(int num){
    valueColors = num;  
    glutPostRedisplay();
}

void exit(){
    glutDestroyWindow(window);
    exit(0);
}

void createMenu(void){     
    submenu_shapes = glutCreateMenu(geometricMenu);
    glutAddMenuEntry("Square", 1);
    glutAddMenuEntry("Rectangle", 2);
    glutAddMenuEntry("Triangle", 3);
    glutAddMenuEntry("Circle", 4); 
    glutAddMenuEntry("Hexagon", 5); 
    glutAddMenuEntry("Ring", 6); 
    glutAddMenuEntry("Arrow", 7); 
    glutAddMenuEntry("Cross", 8);

    submenu_colors = glutCreateMenu(geometricColors);
    glutAddMenuEntry("Yellow", 1);
    glutAddMenuEntry("Red", 2);
    glutAddMenuEntry("Green", 3);
    glutAddMenuEntry("Blue", 4); 
    glutAddMenuEntry("Purple", 5);
    glutAddMenuEntry("Brown", 6);
    glutAddMenuEntry("White", 7);
    glutAddMenuEntry("Violet", 8);

    glutCreateMenu(geometricMenu);
    glutCreateMenu(geometricColors);
    int e = glutCreateMenu(exit);
    glutAddSubMenu("Geometric Shapes", submenu_shapes);
    glutAddSubMenu("Color Selection", submenu_colors);
    glutAddMenuEntry("Exit", e);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
} 


void display(void){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION | GL_MODELVIEW);
    if(valueColors != 0){//Color Selection
        switch (valueColors)
        {
            case 1:
            n1=1.0;n2=0.84;n3=0.0;
            break;

            case 2:
            n1=1.0;n2=0.0;n3=0.0;
            break;

            case 3:
            n1=0.0;n2=1.0;n3=0.0;
            break;

            case 4:
            n1=0.0;n2=0.0;n3=7.0;
            break;

            case 5:
            n1=0.20;n2=0.0;n3=0.40;
            break;

            case 6:
            n1=0.20;n2=0.10;n3=0.0;
            break;

            case 7:
            n1=1.0;n2=1.0;n3=1.0;
            break;

            default:
            n1=0.67;n2=0.0;n3=1.00;
            break;
        } 
    }
    switch (valueShapes)
    {
        case 1:
            glBegin(GL_QUADS);
            glVertex2f(-0.6, 0.6); glVertex2f(-0.6, -0.6);
            glVertex2f(0.6, -0.6); glVertex2f(0.6, 0.6);
            glEnd();
        break;

        case 2:
            glBegin(GL_QUADS);
            glVertex2f(-0.8, 0.4); glVertex2f(-0.8, -0.4);
            glVertex2f(0.8, -0.4); glVertex2f(0.8, 0.4);
            glEnd();
        break;

        case 3:
            glBegin(GL_TRIANGLES);
            glVertex2f(-0.6,-0.6);
            glVertex2f(0.6,-0.6);
            glVertex2f(0.0,0.6);
            glEnd();
        break;

        case 4:
            glPushMatrix();
            glutSolidSphere(0.6, 100, 100);
            glPopMatrix();
        break;

        case 5:
            glBegin(GL_POLYGON);
            glVertex2f(-0.7,0.0); glVertex2f(-0.3,0.6);
            glVertex2f(-0.3,0.6);glVertex2f(0.3,0.6);
            glVertex2f(0.3,0.6);glVertex2f(0.7,0.0);
            glVertex2f(0.7,0.0);glVertex2f(0.3,-0.6);
            glVertex2f(0.3,-0.6);glVertex2f(-0.3,-0.6);
            glEnd();
        break;

        case 6:
            glPushMatrix();
            glutSolidTorus(0.2, 0.5, 10, 50);
            glPopMatrix();
        break;

        case 7:
            glBegin(GL_TRIANGLES);
            glVertex2f(0.0,-0.4);
            glVertex2f(0.7,0.0);
            glVertex2f(0.0,0.4);
            glEnd();
            glBegin(GL_QUADS);
            glVertex2f(-0.6, 0.2); glVertex2f(-0.6, -0.2);
            glVertex2f(0.0, -0.2); glVertex2f(0.0, 0.2);
            glEnd();
        break;

        case 8:
            glBegin(GL_QUADS);
            glVertex2f(-0.6, 0.2); glVertex2f(-0.6, -0.2);
            glVertex2f(0.6, -0.2); glVertex2f(0.6, 0.2);
            glEnd();
            glBegin(GL_QUADS);
            glVertex2f(-0.2, 0.6); glVertex2f(-0.2, -0.6);
            glVertex2f(0.2, -0.6); glVertex2f(0.2, 0.6);
            glEnd();
        break;
    }
    glColor3f(n1,n2,n3);
    glFlush();
} 

int main(int argc, char **argv){     
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    window = glutCreateWindow("Geometric Shapes & Colors");
    glEnable(GL_DEPTH_TEST);
    createMenu();  
    glClearColor(0.0,0.0,0.0,0.0);
    glutDisplayFunc(display);     
    glutMainLoop();
    return EXIT_SUCCESS;
}