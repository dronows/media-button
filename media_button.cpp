// media_button.cpp: определяет точку входа для приложения.
//

#include "media_button.h"

ImageButton::ImageButton(QWidget* parent) {
  setParent(parent);
  setToolTip("Stop");
  setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  downButtonPixmap.load("buttDown.png");
  upButtonPixmap.load("buttUp.png");
  currButtonPixmap = upButtonPixmap;
  setGeometry(currButtonPixmap.rect());
  connect(this, &QPushButton::clicked, this, &ImageButton::setDown);
}
//---------------------------------------------------------------------
void ImageButton::paintEvent(QPaintEvent* e) {
  QPainter p(this);
  p.drawPixmap(e->rect(), currButtonPixmap);
}
//-------------------------------------------------------
QSize ImageButton::sizeHint() const {
  return QSize(100, 100);
}
//--------------------------------------------------------------
QSize ImageButton::minimumSizeHint() const {
  return sizeHint();
}
//-----------------------------------------------------------
void ImageButton::setDown() {
  currButtonPixmap = downButtonPixmap;
  update();
  QSound::play("button-17.wav");
  QTimer::singleShot(500, this, &ImageButton::setUp);
}
//------------------------------------------------------------
void ImageButton::setUp() {
  currButtonPixmap = upButtonPixmap;
  update();
}
//---------------------------------------------------------
void ImageButton::keyPressEvent(QKeyEvent* e) {
  setDown();
}