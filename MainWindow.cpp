/**********************************************************************
**
** MainWindow.cpp
** Copyright (C) 2022-2022 Hatsushigure
**
** The source file of MainWindow
**
**********************************************************************/

#include "MainWindow.h"
#include "./ui_MainWindow.h"
#include <QFileDialog>
#include <QCryptographicHash>
#include "MyHashCalcThread.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	m_lastVisitedDir = QDir::homePath();

	initConnections();
}

MainWindow::~MainWindow()
{
	delete ui;
}

//Connect all signal and slots
void MainWindow::initConnections()
{
	connect(ui->actionOpenLeft, &QAction::triggered, this, &MainWindow::onOpenLeftFile);
	connect(ui->actionOpenRight, &QAction::triggered, this, &MainWindow::onOpenRightFile);
	connect(ui->actionCalc, &QAction::triggered, this, &MainWindow::onCalcHash);
}

void MainWindow::onOpenLeftFile()
{
	QString fileName = QFileDialog::getOpenFileName(this, "打开左侧文件", m_lastVisitedDir, "所有文件(*);;aaa(*.aaa)");
	if (!QFile::exists(fileName))
		return;
	m_leftFile.setFileName(fileName);
	qDebug() << m_leftFile.fileName();
	QFileInfo info(m_leftFile);
	m_lastVisitedDir = info.dir().path();
}

void MainWindow::onOpenRightFile()
{
	QString fileName = QFileDialog::getOpenFileName(this, "打开右侧文件", m_lastVisitedDir, "所有文件(*)");
	if (!QFile::exists(fileName))
		return;
	m_rightFile.setFileName(fileName);
	qDebug() << m_rightFile.fileName();
	QFileInfo info(m_rightFile);
	m_lastVisitedDir = info.dir().path();
}

void MainWindow::onCalcHash()
{
	if(!m_leftFile.exists() || !m_rightFile.exists())
	{
		qDebug() << "At least a file does not exist";
		return;
	}

	MyHashCalcThread* calcThread;
	calcThread = new MyHashCalcThread(QCryptographicHash::Sha256, m_leftFile.fileName(), this);

	ui->SHA256Status->setText("<span style=\"color:green;font-size:14pt;\">√</span>");
	ui->SHA256Status->setText("<span style=\"color:red;font-size:14pt;\">×</span>");
}

