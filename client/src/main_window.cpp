#include "main_window.h"
#include "ui_main_window.h"

Main_window::Main_window(QWidget *parent) : QMainWindow(parent), ui(new Ui::Main_window) {
	ui->setupUi(this);

	connect(ui->about_action, SIGNAL(triggered()), this, SLOT(show_about()));
}

Main_window::~Main_window() {
	delete ui;
}

void Main_window::set_progressbar(int max) const {
	ui->progressBar->setRange(0, max);
}

void Main_window::update_progressbar(int progress) const {
	ui->progressBar->setValue(progress + 1);
}

void Main_window::print_settings(QString string) const{
	ui->settings_textedit->appendPlainText(string);
}

void Main_window::print_console(QString string) const {
	ui->console_textbrowser->append(string);
}

void Main_window::show_about() {
	this->about.show();
}
