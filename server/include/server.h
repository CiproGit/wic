#ifndef SERVER_H
#define SERVER_H

#include "mainwindow.h"
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Server : public QObject {
	Q_OBJECT

private:
	MainWindow *window; // Server GUI

	QString ip_address;
	unsigned short port;
	QTcpServer server;
	QTcpSocket *socket;

	QString username;

public:
	Server(MainWindow *window, QString ip_address, unsigned short port);
	virtual ~Server();
	void start_listening();

public slots:
	void on_newConnection();
	void on_new_message();
};

#endif // SERVER_H
