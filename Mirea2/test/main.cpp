#include <QtCore>
#include <QDebug>
#include "C:\Users\lmistie\Desktop\Mirea\SmtpClient-for-Qt-2.0/src/SmtpMime"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MimeMessage message;


    //EmailAddress sender("romaniy11052001@gmail.com", "Roman Gorbunov");
    //EmailAddress sender("romaniy11052001@yandex.ru", "Roman Gorbunov");
    EmailAddress sender("romaniy11052001@mail.ru", "Roman Gorbunov");
    message.setSender(sender);

    //EmailAddress to("romaniy11052001@mail.ru", "Roman Gorbunov");
    EmailAddress to("romaniy11052001@yandex.ru", "Roman Gorbunov");
    //EmailAddress to("romaniy11052001@gmail.com", "Roman Gorbunov");
    message.addRecipient(to);

    message.setSubject("Попытка отправить нормальное сообщение через QT 2");

    MimeText text;

    text.setText("Привет!!!\nВот новое сообщение.\n");

    message.addPart(&text);

    SmtpClient smtp("smtp.yandex.com", 465, SmtpClient::SslConnection); // yandex
    //SmtpClient smtp("smtp.mail.ru", 465, SmtpClient::SslConnection); // mail
    //SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection); // gmail

    smtp.connectToHost();
    if (!smtp.waitForReadyConnected()) {
        qDebug() << "\nНе удача, подключиться по SMTP БЛЯТТТЬЬЬЬ!!!!!\n";
        return -1;
    }

    smtp.login("romaniy11052001@yandex.ru", "R@mashka11052001"); // Yandex без шифрования TSL не работает
    //smtp.login("romaniy11052001@gmail.com", "romashka11052001"); // gmail без шифрования TSL не работает
    //smtp.login("romaniy11052001@mail.ru", "sb7GLm2tS5hEm4dXDjsn"); // Рабочая версия для mail
    if (!smtp.waitForAuthenticated()) {
        qDebug() << "\nERROR ERROR ERROR\nFailed to login!!!!!\n"; // ЭТО мои логин и пароль от google
        return -2;
    }

    smtp.sendMail(message);
    if (!smtp.waitForMailSent()) {
        qDebug() << "Failed to send mail!";
        return -3;
    }

    smtp.quit();

}
