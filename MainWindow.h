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
//the enum
private:
	enum {lMD5, rMD5, lSHA1, rSHA1, lSHA256, rSHA256};
private:
	Ui::MainWindow *ui;
	QFile m_leftFile;
	QFile m_rightFile;
	QString m_lastVisitedDir;
	std::array<bool, 6> m_calcState;
public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();
	//Connect all signal and slots
	void initConnections();
private slots:
	void onOpenLeftFile();
	void onOpenRightFile();
	void onCalcHash();
	void onCalcFinished();
};
