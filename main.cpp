#include <windows.h>
#include <GL/glut.h>

void display(void)
{

    glClear (GL_COLOR_BUFFER_BIT);


    double sqr[4][2] = { {0, 800}, {100, 800}, {100,700}, {0,700} };

    double x, y = 0;

    for(int i = 0 ; i < 8 ; i ++)
    {
        x = 0;
        for(int j = 0 ; j < 8 ; j ++)
        {
            glColor3d( (i+j)%2, (i+j)%2,(i+j)%2);

            glBegin(GL_POLYGON);
            for(int k = 0 ; k < 4 ; k ++)
            {
                glVertex2d(sqr[k][0]+x,sqr[k][1]+y);
            }
            glEnd();

            x+=100;
        }
        y-=100;
    }


    glFlush ();
}

void init (void)
{

    glClearColor (0.0, 0.0, 0.0, 0.0);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();
    gluOrtho2D(0, 800, 0, 800);
}



int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (650, 650);
    glutInitWindowPosition (350, 50);
    glutCreateWindow ("171-15-XXXX");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
