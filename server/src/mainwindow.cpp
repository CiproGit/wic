#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QIcon>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
	ui->setupUi(this);
	this->setWindowIcon(QIcon(ICON_FILE));
	this->tray_icon.setIcon(QIcon(ICON_FILE));

	// Tray icon menu
	QMenu *menu = new QMenu(this);
	QAction *view_window = new QAction("Show", this);
	QAction *quit_action = new QAction("Quit", this);

	connect(view_window, SIGNAL(triggered()), this, SLOT(show()));
	connect(quit_action, SIGNAL(triggered()), this, SLOT(quit()));

	menu->addAction(view_window);
	menu->addAction(quit_action);

	this->tray_icon.setContextMenu(menu);
	this->tray_icon.show();

	connect(&this->tray_icon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));
	connect(ui->about_action, SIGNAL(triggered()), this, SLOT(show_about()));
	connect(ui->hide_action, SIGNAL(triggered()), this, SLOT(close()));
}

MainWindow::~MainWindow() {
	delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event) {
	if (this->isVisible()) {
		event->ignore(); // Do not terminate the program
		this->hide();

		this->tray_icon.showMessage("WIC Server", "Hidden");
	}
}

void MainWindow::iconActivated(QSystemTrayIcon::ActivationReason reason) {
	switch(reason) {
		case QSystemTrayIcon::Trigger:
			if (!this->isVisible()) this->show();
			else this->hide();
			break;
		default:
			break;
	}
}

void MainWindow::print_ip_addresses(QString string) const {
	ui->ip_textedit->appendPlainText(string);
}

void MainWindow::print_username(QString string) const {
	ui->username_lineedit->setText(string);
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

void MainWindow::quit() {
	QCoreApplication::exit();
}
