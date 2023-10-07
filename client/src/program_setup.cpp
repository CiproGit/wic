#include "program_setup.h"
#include "common.h"
#include <QCoreApplication>
#include <QSettings>

Program_setup::Program_setup() {
	this->working_dir = QCoreApplication::applicationDirPath(); // Get the directory that contains the application executable

	// Read port and timeout from settings file
	QSettings settings(this->working_dir + FILE_PATH + CONFIG_FILE, QSettings::IniFormat);
	this->port = static_cast<unsigned short>(settings.value("CLIENT/PORT", DEFAULT_PORT).toUInt());
	this->timeout = static_cast<unsigned short>(settings.value("CLIENT/TIMEOUT", DEFAULT_TIMEOUT).toUInt());
}

Program_setup::~Program_setup() {}

QString Program_setup::get_working_dir() const {
	return this->working_dir;
}

unsigned short Program_setup::get_port() const {
	return this->port;
}

unsigned short Program_setup::get_timeout() const {
	return this->timeout;
}
