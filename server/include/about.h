#ifndef ABOUT_H
#define ABOUT_H

#include <QDialog>
#include <QCloseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class About; }
QT_END_NAMESPACE

class About : public QDialog {
	Q_OBJECT

private:
	Ui::About *ui;

protected:
	void closeEvent(QCloseEvent *event);

public:
	About(QWidget *parent = nullptr);
	~About();
};
#endif // ABOUT_H
