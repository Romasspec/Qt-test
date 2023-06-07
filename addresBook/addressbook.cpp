#include <QtWidgets>
#include "addressbook.h"

AddressBook::AddressBook(QWidget *parent)
    : QWidget(parent)
{
    QLabel  *nameLable = new QLabel ("Name");
    nameLine = new QLineEdit;
    nameLine -> setReadOnly(true);

    QLabel *addresLable = new QLabel ("Addres:");
    addresText = new QTextEdit;
    addresText -> setReadOnly(true);

    addButton = new QPushButton ("&Add");
    addButton -> show();
    submitButton = new QPushButton ("&Submit");
    submitButton -> hide();
    cancelButton = new QPushButton ("&Cancel");
    cancelButton -> hide();

    connect (addButton, SIGNAL(clicked(bool)), this, SIGNAL(addContact()));
    connect (submitButton, SIGNAL(clicked(bool)), this, SLOT(submitContact()));
    connect (cancelButton, SIGNAL(clicked(bool)), this, SLOT(cancel()));

    QVBoxLayout *buttonLayout1 = new QVBoxLayout;
    buttonLayout1 -> addWidget(addButton);
    buttonLayout1 -> addWidget(submitButton);
    buttonLayout1 -> addWidget(cancelButton);
    buttonLayout1 -> addStretch();

    QGridLayout *mainGridLay = new QGridLayout;
    mainGridLay -> addWidget(nameLable,0,0);
    mainGridLay -> addWidget(nameLine,0,1);
    mainGridLay -> addWidget(addresLable,1,0,Qt::AlignTop);
    mainGridLay -> addWidget(addresText,1,1);
    mainGridLay -> addLayout(buttonLayout1,1,2);
    setLayout(mainGridLay);
}

AddressBook::~AddressBook()
{

}

void AddressBook::addContact()
{
    oldName = nameLine -> text();
    oldAddress =    addresText -> toPlainText();

    nameLine -> clear();
    addresText -> clear();

    nameLine -> setReadOnly(false);
    nameLine -> setFocus(Qt::OtherFocusReason);

    addresText -> setReadOnly(false);

    addButton -> setEnabled(false);
    submitButton -> show();
    cancelButton -> show();
}
