#include "about.h"
#include "./ui_about.h"

About::About(QWidget *parent) : QDialog(parent), ui(new Ui::About) {
	ui->setupUi(this);
}

About::~About() {
	delete ui;
}

void About::closeEvent(QCloseEvent *event) {
	event->ignore(); // Do not terminate the program
	this->hide();
}
