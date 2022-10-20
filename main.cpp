
#include "media_button.h"



int main(int argc,char** argv)
{
  QApplication a(argc, argv);
  ImageButton button(nullptr);
  button.setFixedSize(200, 200);
  button.move(1000, 400);
  button.show();
  return a.exec();
}
#include <main.moc>