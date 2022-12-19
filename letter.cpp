#include "letter.h"
#include "ui_mainwindow.h"
#include <QDebug>

const GLfloat letter::colorArray[vertices][3] = {
    {0.0, 0.0, 0.0},
    {0.6, 0.98, 0.6},
    {1.0, 0.84,0.8},
    {0.8, 0.36, 0.36},

    {1.0, 0.27, 0.0},
    {0.0, 0.0, 1.0},
    {0.6, 0.98, 0.6},
    {0.54, 0.17, 0.89},

    {0.0, 0.0, 0.0},
    {0.82, 0.13, 0.56},
    {1.0, 0.84,0.8},
    {0.8, 0.36, 0.36},

    {1.0, 0.27, 0.0},
    {0.82, 0.13, 0.56},
    {0.54, 0.17, 0.89},
    {0.0, 1.0, 1.0},

    {0.5, 0.2, 0.3},
    {0.6, 0.72, 0.31},
    {1.0, 0.4,0.85},

    {0.0, 0.0, 0.0},
    {0.6, 0.98, 0.6},
    {1.0, 0.84,0.8},
    {0.8, 0.36, 0.15},

    {1.0, 0.27, 0.5},
    {0.82, 0.13, 0.56},
    {0.54, 0.17, 0.89},
    {0.0, 1.0, 1.0},

    {0.0, 0.0, 0.0},
    {0.6, 0.98, 0.6},
    {1.0, 0.84,0.8},
    {0.8, 0.36, 0.36},

    {1.0, 0.27, 0.0},
    {0.82, 0.13, 0.56},
    {0.54, 0.17, 0.89},
    {0.0, 1.0, 1.0},

    {0.5, 0.2, 0.3},
    {0.6, 0.72, 0.31},
    {1.0, 0.4,0.85},
    {1.0, 0.4,0.15},

};

const GLfloat letter::vertexData[vertices][3] = {
    {0.0, 0.125f,    0.0},
    {0.125f, 0.0,    0.0},
    {0.125f, 0.125f, 0.0},
    {0.25f, 0.0,     0.0},

    {0.25f, 0.125f,  0.0},
    {0.375f, 0.125f, 0.0},
    {0.25f, 0.25f,   0.0},
    {0.375f, 0.25f,  0.0},

    {0.125f, 0.375f, 0.0},
    {0.25f, 0.375f,  0.0},
    {0.25f, 0.5f,    0.0},
    {0.375f, 0.5f,   0.0},

    {0.25f, 0.625f,  0.0},
    {0.375f, 0.625f, 0.0},
    {0.25f, 0.75f,   0.0},
    {0.125f, 0.625f, 0.0},

    {0.125f, 0.75f,  0.0},
    {0.0, 0.625f,    0.0},


    {0.0, 0.125f,    0.125f},
    {0.125f, 0.0,    0.125f},
    {0.125f, 0.125f, 0.125f},
    {0.25f, 0.0,     0.125f},
    {0.25f, 0.125f,  0.125f},
    {0.375f, 0.125f, 0.125f},
    {0.25f, 0.25f,   0.125f},
    {0.375f, 0.25f,  0.125f},
    {0.125f, 0.375f, 0.125f},
    {0.25f, 0.375f,  0.125f},
    {0.25f, 0.5f,    0.125f},
    {0.375f, 0.5f,   0.125f},
    {0.25f, 0.625f,  0.125f},
    {0.375f, 0.625f, 0.125f},
    {0.25f, 0.75f,   0.125f},
    {0.125f, 0.625f, 0.125f},
    {0.125f, 0.75f,  0.125f},
    {0.0, 0.625f,    0.125f}
};


void letter::getIndexArray()
{
    setTriangle(0, 0, 1, 2);
    setTriangle(1, 3, 5, 4);
    setTriangle(2, 13, 12, 14);
    setTriangle(3, 15, 16, 17);
    setTriangle(4, 18, 20, 19);
    setTriangle(5, 21, 22, 23);
    setTriangle(6, 30, 32, 31);
    setTriangle(7, 35, 34, 33);


    setQuad(0, 1, 2, 4, 3);
    setQuad(1, 4, 6, 7, 5);
    setQuad(2, 6, 8, 9, 7);
    setQuad(3, 8, 10, 11, 9);
    setQuad(4, 10, 12, 13, 11);
    setQuad(5, 12, 15, 16, 14);

    setQuad(6, 19, 20, 22, 21);
    setQuad(7, 22, 24, 25, 23);
    setQuad(8, 24, 26, 27, 25);
    setQuad(9, 26, 28, 29, 27);
    setQuad(10, 28, 30, 31, 29);
    setQuad(11, 30, 33, 34, 32);

    setQuad(12, 0, 1, 19, 18);
    setQuad(13, 1, 3, 21, 19);
    setQuad(14, 3, 5, 23, 21);
    setQuad(15, 5, 7, 25, 23);
    setQuad(16, 7, 9, 27, 25);
    setQuad(17, 9, 11, 29, 27);
    setQuad(18, 11, 13, 31, 29);
    setQuad(19, 13, 14, 32, 31);
    setQuad(20, 14, 16, 34, 32);
    setQuad(21, 16, 17, 35, 34);
    setQuad(22, 17, 12, 30, 35);
    setQuad(23, 12, 10, 28, 30);
    setQuad(24, 8, 10, 28, 26);
    setQuad(25, 8, 6, 24, 26);
    setQuad(26, 6, 4, 22, 24);
    setQuad(27, 4, 0, 18, 22);

}
void letter::setQuad(int idx, int x1, int x2, int x3, int x4)
{
    IndexArray[idx][0] = x1;
    IndexArray[idx][1] = x2;
    IndexArray[idx][2] = x3;
    IndexArray[idx][3] = x4;
}

void letter::setTriangle(int idx, int x1, int x2, int x3)
{
    TriangleIndexArray[idx][0] = x1;
    TriangleIndexArray[idx][1] = x2;
    TriangleIndexArray[idx][2] = x3;
}

letter::letter(QWidget *parent)
    : QGLWidget(parent)
{
    setGeometry(400,200,800,600);
    xRot=0; yRot=0; zRot=0; zTra=-1; nSca=1;
    getVertexArray();
    getIndexArray();
}

void letter::initializeGL()
{
    qglClearColor(Qt::white); // цвет для очистки буфера изображения - здесь просто фон окна
    glEnable(GL_DEPTH_TEST);  // устанавливает режим проверки глубины пикселей
    glShadeModel(GL_FLAT);    // отключает режим сглаживания цветов
    glEnableClientState(GL_VERTEX_ARRAY); // активизация массива вершин
    glEnableClientState(GL_COLOR_ARRAY);
}

void letter::resizeGL(int nWidth, int nHeight)
{
    glMatrixMode(GL_PROJECTION); // устанавливает текущей проекционную матрицу
    glLoadIdentity();            // присваивает проекционной матрице единичную матрицу

    GLfloat ratio=(GLfloat)nHeight/(GLfloat)nWidth; // отношение высоты окна виджета к его ширине

    // мировое окно
    if (nWidth>=nHeight)
       glOrtho(-1.0/ratio, 1.0/ratio, -1.0, 1.0, -5.0, 5.0); // параметры видимости ортогональной проекции
    else
       glOrtho(-1.0, 1.0, -1.0*ratio, 1.0*ratio, -5.0, 5.0); // параметры видимости ортогональной проекции
    // плоскости отсечения (левая, правая, верхняя, нижняя, передняя, задняя)

    // glFrustum(-1.0, 1.0, -1.0, 1.0, 1.0, 10.0); // параметры видимости перспективной проекции
    // плоскости отсечения (левая, правая, верхняя, нижняя, ближняя, дальняя)

    // поле просмотра
    glViewport(0, 0, (GLint)nWidth, (GLint)nHeight);
}

void letter::paintGL()
{

    glClearColor(1,1,1,0); // цвет фона
    glClear(GL_COLOR_BUFFER_BIT); // окно виджета очищается текущим цветом очистки
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // очистка буфера изображения и глубины
    glMatrixMode(GL_MODELVIEW); // устанавливает положение и ориентацию матрице моделирования
    glLoadIdentity();           // загружает единичную матрицу моделирования
    // последовательные преобразования
    glScalef(nSca, nSca, nSca);        // масштабирование
    glTranslatef(0.0f, zTra, 0.0f);  // трансляция
    glRotatef(xRot, 1.0f, 0.0f, 0.0f); // поворот вокруг оси X
    glRotatef(yRot, 0.0f, 1.0f, 0.0f); // поворот вокруг оси Y
    glRotatef(zRot, 0.0f, 0.0f, 1.0f); // поворот вокруг оси Z
    drawAxis();
    double e=1,r=0,t=0;
    colour.getRgbF(&e,&r,&t,nullptr);
    glColor4f(0, 1, t, 0.0f);
    if(check==1)
    draw_xy_projection();
    else if(check==2)
    draw_xz_projection();
    else if(check==3)
    draw_zy_projection();
    else if(check==4)
    draw_scaling();
    else if(check==5)
    draw_transfer();
    else if(check==6)
    draw_rotation_x();
    else if(check==7)
    draw_rotation_y();
    else if(check==8)
    draw_rotation_z();
    else if(check==9)
    {
        glColorPointer(3, GL_FLOAT, 0, colorArray);
        getVertexArray();
        drawFigure();
    }

    QFont tmpfont;
            tmpfont.setFamily("Arial Black");
            tmpfont.setPointSize(10);
            tmpfont.setBold(false);
            glColor3f(1,0,0);
            renderText(10,0.0,0.0,"X",tmpfont);
            glColor3f(1,0,0);
            renderText(0.0,10,0.0,"Y",tmpfont);
            glColor3f(1,0,0);
            renderText(0.0,0.0,10,"Z",tmpfont);

}

/*virtual*/void letter::mousePressEvent(QMouseEvent* pe) // нажатие клавиши мыши
{
   // при нажатии пользователем кнопки мыши переменной ptrMousePosition будет
   // присвоена координата указателя мыши
   ptrMousePosition = pe->pos();

   // ptrMousePosition = (*pe).pos(); // можно и так написать
}

/*virtual*/void letter::mouseReleaseEvent(QMouseEvent* pe) // отжатие клавиши мыши
{
   // некоторые функции, которые должны выполняться при отжатии клавиши мыши
}

/*virtual*/void letter::mouseMoveEvent(QMouseEvent* pe) // изменение положения стрелки мыши
{
   xRot += 1/M_PI*(GLfloat)(pe->y()-ptrMousePosition.y());//height(); // вычисление углов поворота
   yRot += 1/M_PI*(GLfloat)(pe->x()-ptrMousePosition.x());//width();
   ptrMousePosition = pe->pos();
   updateGL(); // обновление изображения
}

/*virtual*/void letter::wheelEvent(QWheelEvent* pe) // вращение колёсика мыши
{
   if ((pe->delta())>0) scale_plus(); else if ((pe->delta())<0) scale_minus();

   updateGL(); // обновление изображения
}

/*virtual*/void letter::keyPressEvent(QKeyEvent* pe) // нажатие определенной клавиши
{
   switch (pe->key())
   {
      case Qt::Key_Plus:
         scale_plus();     // приблизить сцену
      break;

      case Qt::Key_Equal:
         scale_plus();     // приблизить сцену
      break;

      case Qt::Key_Minus:
         scale_minus();    // удалиться от сцены
      break;

      case Qt::Key_W:
         rotate_up();      // повернуть сцену вверх
      break;

      case Qt::Key_S:
         rotate_down();    // повернуть сцену вниз
      break;

      case Qt::Key_A:
        rotate_left();     // повернуть сцену влево
      break;

      case Qt::Key_D:
         rotate_right();   // повернуть сцену вправо
      break;

      case Qt::Key_Z:
         translate_down(); // транслировать сцену вниз
      break;

      case Qt::Key_X:
         translate_up();   // транслировать сцену вверх
      break;

      case Qt::Key_Space:  // клавиша пробела
         defaultScene();   // возвращение значений по умолчанию
      break;

      case Qt::Key_Escape: // клавиша "эскейп"
         this->close();    // завершает приложение
      break;
   }

   updateGL(); // обновление изображения
}

void letter::scale_plus() // приблизить сцену
{
   nSca = nSca*1.1;
}

void letter::scale_minus() // удалиться от сцены
{
   nSca = nSca/1.1;
}

void letter::rotate_up() // повернуть сцену вверх
{
   xRot += 1.0;
}

void letter::rotate_down() // повернуть сцену вниз
{
   xRot -= 1.0;
}

void letter::rotate_left() // повернуть сцену влево
{
   zRot += 1.0;
}

void letter::rotate_right() // повернуть сцену вправо
{
   zRot -= 1.0;
}

void letter::translate_down() // транслировать сцену вниз
{
   zTra -= 0.05;
}

void letter::translate_up() // транслировать сцену вверх
{
   zTra += 0.05;
}

void letter::defaultScene() // наблюдение сцены по умолчанию
{
   xRot=-90; yRot=0; zRot=0; zTra=0; nSca=1;
}

void letter::drawAxis()
{
    glLineWidth(3.0f); // устанавливаю ширину линии приближённо в пикселях
    // до вызова команды ширина равна 1 пикселю по умолчанию

    glColor4f(1.00f, 0.00f, 0.00f, 1.0f); // устанавливается цвет последующих примитивов
    // ось x красного цвета
    glBegin(GL_LINES); // построение линии
       glVertex3f( 10.0f,  0.0f,  0.0f); // первая точка
       glVertex3f(-10.0f,  0.0f,  0.0f); // вторая точка
    glEnd();

    QColor halfGreen(0, 128, 0, 255);
    qglColor(halfGreen);
    glBegin(GL_LINES);
       // ось y зеленого цвета
       glVertex3f( 0.0f,  10.0f,  0.0f);
       glVertex3f( 0.0f, -10.0f,  0.0f);

       glColor4f(0.00f, 0.00f, 1.00f, 1.0f);
       // ось z синего цвета
       glVertex3f( 0.0f,  0.0f,  10.0f);
       glVertex3f( 0.0f,  0.0f, -10.0f);

        glColor4f(0.00f, 0.00f, 0.00f, 0.0f);
       for (float i = -10; i < 10; i+=0.25){
           float k = 20.0;
           glBegin(GL_LINES);
           glVertex3f(i, -1.0 / k, 0.0f);
           glVertex3f(i, 1.0 / k, 0.0f);
           glVertex3f(-1.0 / k, i, 0.0f);
           glVertex3f(1.0 / k, i, 0.0f);
           glVertex3f( 0.0f, 1.0 / k, i);
           glVertex3f( 0.0f, -1.0 / k, i);
       }

    glEnd();
}

void letter::getVertexArray()
{
    if(VertexArray == nullptr) {
        VertexArray = new GLfloat*[vertices];
        for(int i = 0; i < vertices; i++) {
            VertexArray[i] = new GLfloat[3];
            for(int j = 0; j < 3; j++) {
                VertexArray[i][j] = vertexData[i][j];
            }
        }
    }
    else
    {
        for(int i = 0; i < vertices; i++) {
            for(int j = 0; j < 3; j++) {
                VertexArray[i][j] = vertexData[i][j];
            }
        }
    }
}

void letter::setVertex(int idx, float k, float x, float y, float z)
{
    VertexArray[idx][0] = x * k;
    VertexArray[idx][1] = y * k;
    VertexArray[idx][2] = z * k;
}

void letter::draw_rotation_z()
{

    conv[0][0]=cos(angle*(M_PI/180.0));;
    conv[0][1]=-sin(angle*(M_PI/180.0));;
    conv[0][2]=0;

    conv[1][0]=sin(angle*(M_PI/180.0));
    conv[1][1]=cos(angle*(M_PI/180.0));
    conv[1][2]=0;

    conv[2][0]=0;
    conv[2][1]=0;
    conv[2][2]=1;
    qDebug()<<"Z rotation matrix"<<endl;
    for(int i=0; i < 3; i++)
    {
    qDebug()<<conv[i][0]<<" "<<conv[i][1]<<" "<<conv[i][2]<<" ";
     qDebug()<<endl;
    }



    for(int i=0; i < vertices; i++)
    {
     for(int j=0; j < 3; j++)
     {
     VertexArray[i][j]=0;
     for(int k=0; k < 3; k++)
     {
     VertexArray[i][j]+=vertexData[i][k]*conv[k][j];
     }
     }
    }
    drawFigure();

}
void letter::draw_rotation_y()
{
    GLfloat conv[3][3] ;
    conv[0][0]=cos(angle*(M_PI/180.0));
    conv[0][1]=0;
    conv[0][2]=sin(angle*(M_PI/180.0));

    conv[1][0]=0;
    conv[1][1]=1;
    conv[1][2]=0;

    conv[2][0]=-sin(angle*(M_PI/180.0));
    conv[2][1]=0;
    conv[2][2]=cos(angle*(M_PI/180.0));

    qDebug()<<"Y rotation matrix"<<endl;
    for(int i=0; i < 3; i++)
    {
     qDebug()<<conv[i][0]<<" "<<conv[i][1]<<" "<<conv[i][2]<<" ";
     qDebug()<<endl;
    }

    for(int i=0; i < vertices; i++)
    {
     for(int j=0; j < 3; j++)
     {
     VertexArray[i][j]=0;
     for(int k=0; k < 3; k++)
     {
     VertexArray[i][j]+=vertexData[i][k]*conv[k][j];
     }
     }
    }
    drawFigure();

}
void letter::draw_rotation_x()
{
    GLfloat conv[3][3] ;
    conv[0][0]=1;
    conv[0][1]=0;
    conv[0][2]=0;

    conv[1][0]=0;
    conv[1][1]=cos(angle*(M_PI/180.0));
    conv[1][2]=-sin(angle*(M_PI/180.0));

    conv[2][0]=0;
    conv[2][1]=sin(angle*(M_PI/180.0));
    conv[2][2]=cos(angle*(M_PI/180.0));

    qDebug()<<"X rotation matrix"<<endl;
    for(int i=0; i < 3; i++)
    {
    qDebug()<<conv[i][0]<<" "<<conv[i][1]<<" "<<conv[i][2]<<" ";
     qDebug()<<endl;
    }

    for(int i=0; i < vertices; i++)
    {
     for(int j=0; j < 3; j++)
     {
     VertexArray[i][j]=0;
     for(int k=0; k < 3; k++)
     {
     VertexArray[i][j]+=vertexData[i][k]*conv[k][j];
     }
     }
    }
    drawFigure();

}
void letter::draw_transfer()
{
    GLfloat conv[4][3] ;
    conv[0][0]=1;
    conv[0][1]=0;
    conv[0][2]=0;

    conv[1][0]=0;
    conv[1][1]=1;
    conv[1][2]=0;

    conv[2][0]=0;
    conv[2][1]=0;
    conv[2][2]=1;

    conv[3][0]=x_transfer;
    conv[3][1]=y_transfer;
    conv[3][2]=z_transfer;

    qDebug()<<"transfer matrix"<<endl;
    for(int i=0; i < 4; i++)
    {
       qDebug()<<conv[i][0]<<" "<<conv[i][1]<<" "<<conv[i][2]<<" ";
       qDebug()<<endl;
    }

    for(int i=0; i < vertices; i++)
    {
        for(int j=0; j < 3; j++)
        {
            VertexArray[i][j]=0;
            for(int k=0; k < 4; k++)
            {
                if(k==3)
                   VertexArray[i][j]+=1*conv[k][j];
                else
                   VertexArray[i][j]+=vertexData[i][k]*conv[k][j];
            }
        }
    }
    drawFigure();
}
void letter::draw_scaling()
{
    GLfloat conv[3][3] ;
    conv[0][0]=x_scale;
    conv[0][1]=0;
    conv[0][2]=0;

    conv[1][0]=0;
    conv[1][1]=y_scale;
    conv[1][2]=0;

    conv[2][0]=0;
    conv[2][1]=0;
    conv[2][2]=z_scale;

    qDebug()<<"scale matrix"<<endl;
    for(int i=0; i < 3; i++)
    {
     qDebug()<<conv[i][0]<<" "<<conv[i][1]<<" "<<conv[i][2]<<" ";
     qDebug()<<endl;
    }

    for(int i=0; i < vertices; i++)
    {
     for(int j=0; j < 3; j++)
     {
     VertexArray[i][j]=0;
     for(int k=0; k < 3; k++)
     VertexArray[i][j]+=vertexData[i][k]*conv[k][j];
     }
    }
    drawFigure();
}
void letter::draw_xy_projection()
{
    GLfloat conv[3][3] ;
    conv[0][0]=1;
    conv[0][1]=0;
    conv[0][2]=0;

    conv[1][0]=0;
    conv[1][1]=1;
    conv[1][2]=0;

    conv[2][0]=0;
    conv[2][1]=0;
    conv[2][2]=0;
    for(int i=0; i < vertices; i++)
    {
     for(int j=0; j < 3; j++)
     {
     VertexArray[i][j]=0;
     for(int k=0; k < 3; k++)
     VertexArray[i][j]+=vertexData[i][k]*conv[k][j];
     }
    }
    drawFigure();
}
void letter::draw_xz_projection()
{
    GLfloat conv[3][3] ;
    conv[0][0]=1;
    conv[0][1]=0;
    conv[0][2]=0;

    conv[1][0]=0;
    conv[1][1]=0;
    conv[1][2]=0;

    conv[2][0]=0;
    conv[2][1]=0;
    conv[2][2]=1;
    for(int i=0; i < vertices; i++)
    {
     for(int j=0; j < 3; j++)
     {
     VertexArray[i][j]=0;
     for(int k=0; k < 3; k++)
     VertexArray[i][j]+=vertexData[i][k]*conv[k][j];
     }
    }
    drawFigure();
}
void letter::draw_zy_projection()
{
    GLfloat conv[3][3] ;
    conv[0][0]=0;
    conv[0][1]=0;
    conv[0][2]=0;

    conv[1][0]=0;
    conv[1][1]=1;
    conv[1][2]=0;

    conv[2][0]=0;
    conv[2][1]=0;
    conv[2][2]=1;
    for(int i=0; i < vertices; i++)
    {
     for(int j=0; j < 3; j++)
     {
     VertexArray[i][j]=0;
     for(int k=0; k < 3; k++)
     VertexArray[i][j]+=vertexData[i][k]*conv[k][j];
     }
    }
    drawFigure();
}

void letter::drawFigure(){
  GLfloat c[vertices * 3];
  for(int i = 0; i < vertices; i++) {
      for(int j = 0; j < 3; j++) {
          c[i * 3 + j] = VertexArray[i][j];
      }
  }
  GLfloat d[vertices * 3];
  for(int i = 0; i < vertices; i++) {
      for(int j = 0; j < 3; j++) {
          d[i * 3 + j] = colorArray[i][j];
      }
  }
  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3, GL_FLOAT, 0, c);
  glDrawElements(GL_QUADS, indexPoints, GL_UNSIGNED_BYTE, IndexArray);
  glDrawElements(GL_TRIANGLES, triangleIndexPoints, GL_UNSIGNED_BYTE, TriangleIndexArray);
  glColorPointer(3, GL_FLOAT, 0, colorArray);
  glDisableClientState(GL_VERTEX_ARRAY);
}
