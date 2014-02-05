#pragma once

#include <QWidget>
#include <QString>
#include <QTreeWidget>

namespace Ui {
	class RobotsTab;
}

class RobotsTab : public QWidget
{
	Q_OBJECT;

	public:
		RobotsTab(QWidget *parent = 0);
	protected:
		Ui_RobotsTab *ui;

		void addTreeRoot(QString name, QString description);

};






