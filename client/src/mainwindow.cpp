#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QIcon>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
	ui->setupUi(this);
	this->setWindowIcon(QIcon(ICON_FILE));

	connect(ui->about_action, SIGNAL(triggered()), this, SLOT(show_about()));
}

MainWindow::~MainWindow() {
	delete ui;
}

void MainWindow::set_progressbar(int max) const {
	ui->progressBar->setRange(0, max);
}

void MainWindow::update_progressbar(int progress) const {
	ui->progressBar->setValue(progress + 1);
}

void MainWindow::print_settings(QString string) const{
	ui->settings_textedit->appendPlainText(string);
}

void MainWindow::print_console(QString string) const {
	ui->console_textbrowser->append(string);
}

void MainWindow::show_about() {
	this->about.show();
}
