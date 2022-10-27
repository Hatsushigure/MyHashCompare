/**********************************************************************
**
** MainWindow.h
** Copyright (C) 2022-2022 Hatsushigure
**
** Defines the main window of the app.
** Create the slots manually, rather than use "go to slots" in
** designer.
**
**********************************************************************/

#pragma once
#include <QMainWindow>
#include <QFile>

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow
{
	Q_OBJECT
private:
	Ui::MainWindow *ui;
	QFile m_leftFile;
	QFile m_rightFile;
	QString m_lastVisitedDir;
public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();
	//Connect all signal and slots
	void initConnections();
private slots:
	void onOpenLeftFile();
	void onOpenRightFile();
	void onCalcHash();
};
