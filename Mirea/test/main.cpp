#include <QtCore>
#include <QDebug>
#include "../SmtpClient-for-Qt/src/SmtpMime"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // This is a first demo application of the SmtpClient for Qt project

    // Now we create a MimeMessage object. This is the email.

    MimeMessage message;

    EmailAddress sender("romaniy11052001@gmail.com", "Roman");
    message.setSender(sender);

    EmailAddress to("romaniy11052001@gmail.com", "Roman Gorbunov");
    message.addRecipient(to);

    message.setSubject("SmtpClient for Qt - Demo");

    // Now add some text to the email.
    // First we create a MimeText object.
    MimeText text;

    text.setText("Hi,\nThis is a simple email message.\n");

    message.addPart(&text);

    //SmtpClient smtp("smtp.yandex.com", 465, SmtpClient::SslConnection); // yandex
    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection); // gmail 587
    //SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection); // mail

    smtp.connectToHost();
    if (!smtp.waitForReadyConnected()) {
        qDebug() << "\nНе удача, подключиться по SMTP БЛЯТТТЬЬЬЬ!!!!!\n";
        return -1;
    }

    smtp.login("romaniy11052001@gmail.com", "romashka11052001");
    if (!smtp.waitForAuthenticated()) {
        qDebug() << "\nАВТОРИЗОВАРЬСЯ НЕ ПОЛУЧИЛОСЬ ССССУУУККААА!!!!\n"; // ЭТО мои логин и пароль от google
        return -2;
    }

    smtp.sendMail(message);
    if (!smtp.waitForMailSent()) {
        qDebug() << "Failed to send mail!";
        return -3;
    }

    smtp.quit();

}
