
#ifndef MAIL_H_
#define MAIL_H_

#define MSG_FILE "mail.txt"
#define COMMAND "cat mail.txt | sendmail -t"
#define T_HIGH "For høj temperatur!"
#define T_LOW "For lav temperatur!"

void sendMail();

#endif
