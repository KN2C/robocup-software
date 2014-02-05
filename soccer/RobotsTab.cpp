#include "RobotsTab.hpp"
#include "ui_RobotsTab.h"

using namespace std;

RobotsTab::RobotsTab(QWidget* parent) :
	QRobotsTab(parent),
	ui(new Ui::RobotsTab)
{
	ui.setupUi(this);

	ui->treeWidget->setColumnCount(2);

	addTreeRoot("Robot No.", "1233425345");
}

RobotsTab::~Robots()
{
	delete ui;
}

void RobotsTab::addTreeRoot(QString name, QString description)
{
	QTreeWidgetItem *treeItem = new QTreeWidgetItem(ui->treeWidget);

	treeItem->setText(0,name);
	treeItem->setText(1,description);

}



