#include "my_paint.h"
#include <QtOpenGL>
#include <GL/gl.h>
My_Paint::My_Paint()
{

}
//void My_Paint::initializeGL(){}
//void My_Paint::paintGL(){}
//void My_Paint::resizeGL(int w, int h){ }

void My_Paint::initializeGL()
{
//Обрати фоновий (очищуючий) колір
glClearColor(1.0,0.84,0.0,1.0);

//glClearColor(r,g,b,t); Де, r-червоний колір, g-зелений, b- голубий, t-прозрачність.

//Задаємо режим обробки полігонів - передню та задню частини,
//полігони повністю зафарбовані
//(можна просто відображувати обрамлення)
glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
}
void My_Paint::resizeGL(int nWidth, int nHeight)
{
//Встановлюємо точку огляду. Останні два параметра однакові -
// щоб не порушувати пропорції у широких экранів
glViewport(0, 0, nWidth, nHeight);
//Встановлюємо режим матриці
glMatrixMode(GL_PROJECTION);
//Завантажуємо матрицю
glLoadIdentity();
}
void My_Paint::paintGL()
{
struct MyThread : public QThread {using QThread::msleep;};
//Очищуємо екран
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//Встановити проекцію:
//Задаємо режим матриці
glMatrixMode(GL_PROJECTION);
//Завантажуємо матрицю
glLoadIdentity();
glOrtho(0.0,600.0,0.0,400.0,-1.0,1.0);
//Тут малюємо - для зручності в окремій функції
scene();
//выводимо на екран
//swapBuffers();
update();
MyThread::msleep(10);
}


void My_Paint::scene()
{
    // Установлюємо зелений фон (замість чищення кольором glClearColor)
        glClearColor(0.0, 0.5, 0.0, 1.0); // Темно-зелений фон
        glClear(GL_COLOR_BUFFER_BIT);

        // Малюємо жовтий трикутник
        glColor3f(1.0, 1.0, 0.0); // Жовтий колір
        glBegin(GL_TRIANGLES);
        glVertex3f(300.0, 300.0, 0.0); // Верхівка трикутника
        glVertex3f(200.0, 150.0, 0.0); // Лівий кут
        glVertex3f(400.0, 150.0, 0.0); // Правий кут
        glEnd();

        // Малюємо сині лінії (очі)
        glColor3f(0.0, 0.0, 1.0); // Синій колір
        glBegin(GL_LINES);
        glVertex3f(170.0, 300.0, 0.0); // Ліва лінія (початок)
        glVertex3f(230.0, 300.0, 0.0); // Ліва лінія (кінець)
        glVertex3f(400.0, 300.0, 0.0); // Права лінія (початок)
        glVertex3f(460.0, 300.0, 0.0); // Права лінія (кінець)
        glEnd();

        // Малюємо червону рамку (рот)
        glColor3f(1.0, 0.0, 0.0); // Червоний колір
        glLineWidth(5.0);
        glBegin(GL_LINE_STRIP);
        glVertex3f(100.0, 300.0, 0.0); // Лівий нижній кут
        glVertex3f(200.0, 50.0, 0.0);  // Лівий верхній кут
        glVertex3f(400.0, 50.0, 0.0);  // Правий верхній кут
        glVertex3f(500.0, 300.0, 0.0); // Правий нижній кут
        glEnd();


}
