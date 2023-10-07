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
	QString working_dir;

	const QString CONFIG_FILE = "client_config.ini";
	const QString DEFAULT_PORT = "50000";
	const QString DEFAULT_TIMEOUT = "30000";

	unsigned short port;
	unsigned short timeout;

public:
	Program_setup();
	virtual ~Program_setup();
	QString get_working_dir() const;
	unsigned short get_port() const;
	unsigned short get_timeout() const;
};

#endif // PROGRAM_SETUP_H
