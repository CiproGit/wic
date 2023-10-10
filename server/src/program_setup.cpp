#include "program_setup.h"
#include "common.h"
#include <QCoreApplication>
#include <QSettings>

Program_setup::Program_setup() {
	QString working_dir = QCoreApplication::applicationDirPath(); // Get the directory that contains the application executable

	// Read IP address and port from settings file
	QSettings settings(working_dir + FILE_PATH + CONFIG_FILE, QSettings::IniFormat);
	this->ip_address = settings.value("SERVER/IP_ADDRESS", DEFAULT_IP_ADDRESS).toString();
	this->port = static_cast<unsigned short>(settings.value("SERVER/PORT", DEFAULT_PORT).toUInt());
}

Program_setup::~Program_setup() = default;

QString Program_setup::get_ip_address() const {
	return this->ip_address;
}

unsigned short Program_setup::get_port() const {
	return this->port;
}
