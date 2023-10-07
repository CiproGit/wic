#include "about.h"
#include "./ui_about.h"

#include "config.h"

About::About(QWidget *parent) : QDialog(parent), ui(new Ui::About) {
	ui->setupUi(this);

	QString version_string = QString::number(VERSION_MAJOR) + "." + QString::number(VERSION_MINOR) + "." + QString::number(VERSION_PATCH);
	ui->version_textbrowser->append(version_string);
}

About::~About() {
	delete ui;
}
