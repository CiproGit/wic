#ifndef PROGRAM_SETUP_H
#define PROGRAM_SETUP_H

#include <QObject>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Program_setup : public QObject {
	Q_OBJECT

private:
	const QString CONFIG_FILE = "server_config.ini";
	const QString DEFAULT_IP_ADDRESS = "127.0.0.1";
	const QString DEFAULT_PORT = "50000";

	QString ip_address;
	unsigned short port;

public:
	Program_setup();
	virtual ~Program_setup();
	QString get_ip_address() const;
	unsigned short get_port() const;
};

#endif // PROGRAM_SETUP_H
