

#pragma once

#include <iostream>
#include <QApplication>
#include <QPixmap>
#include <QPushButton>
#include <QPainter>
#include <QPaintEvent>
#include <QTimer>
#include <QSound>

class ImageButton : public QPushButton {
  Q_OBJECT
public:
  ImageButton() = default;
  ImageButton(QWidget* parent);
  void paintEvent(QPaintEvent* e) override;
  QSize sizeHint() const override;
  QSize minimumSizeHint() const override;
  void keyPressEvent(QKeyEvent* e) override;
public slots:
  void setUp();
  void setDown();
private:
  QPixmap currButtonPixmap;
  QPixmap downButtonPixmap;
  QPixmap upButtonPixmap;
  bool isDown = false;
};

