#ifndef ADDRESBOOK_H
#define ADDRESBOOK_H

#include <QtWidgets>

//QT_BEGIN_NAMESPACE
//class QLineEdit;
//class QTextEdit;
//QT_END_NAMESPACE

class AddressBook : public QWidget
{
    Q_OBJECT

public:
    AddressBook(QWidget *parent = 0);
    ~AddressBook();
    void addContact();
    void submitContact();
    void cancel();
private:
    QLineEdit *nameLine;
    QTextEdit *addresText;
    QPushButton *addButton;
    QPushButton *submitButton;
    QPushButton *cancelButton;

    QMap < QString, QString > contacts;
    QString oldName;
    QString oldAddress;
};

#endif // ADDRESBOOK_H
