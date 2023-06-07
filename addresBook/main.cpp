#include "addressbook.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AddressBook *w = new AddressBook;
    w->show();
   void addContact();

    return a.exec();
}
