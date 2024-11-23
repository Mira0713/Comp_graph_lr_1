#ifndef MY_PAINT_H
#define MY_PAINT_H

#include <QOpenGLWidget>

class My_Paint : public QOpenGLWidget
{
public:
    My_Paint();
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void scene();
};

#endif // MY_PAINT_H
