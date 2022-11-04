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
#include "MyHashCompare.h"

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

	connect(MyHashCompare::lMD5Thread, &MyHashCalcThread::resultReady, ui->leftMD5Edit, &QLineEdit::setText);
	connect(MyHashCompare::rMD5Thread, &MyHashCalcThread::resultReady, ui->rightMD5Edit, &QLineEdit::setText);
	connect(MyHashCompare::lSHA1Thread, &MyHashCalcThread::resultReady, ui->leftSHA1Edit, &QLineEdit::setText);
	connect(MyHashCompare::rSHA1Thread, &MyHashCalcThread::resultReady, ui->rightSHA1Edit, &QLineEdit::setText);
	connect(MyHashCompare::lSHA256Thread, &MyHashCalcThread::resultReady, ui->leftSHA256Edit, &QLineEdit::setText);
	connect(MyHashCompare::rSHA256Thread, &MyHashCalcThread::resultReady, ui->rightSHA256Edit, &QLineEdit::setText);
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

	if (ui->MD5Check->isChecked())
	{
		MyHashCompare::lMD5Thread->setFileName(m_leftFile.fileName());
		MyHashCompare::rMD5Thread->setFileName(m_rightFile.fileName());
		MyHashCompare::lMD5Thread->start();
		MyHashCompare::rMD5Thread->start();
	}

	if (ui->SHA1Check->isChecked())
	{
		MyHashCompare::lSHA1Thread->setFileName(m_leftFile.fileName());
		MyHashCompare::rSHA1Thread->setFileName(m_rightFile.fileName());
		MyHashCompare::lSHA1Thread->start();
		MyHashCompare::rSHA1Thread->start();
	}

	if (ui->SHA256Check->isChecked())
	{
		MyHashCompare::lSHA256Thread->setFileName(m_leftFile.fileName());
		MyHashCompare::rSHA256Thread->setFileName(m_rightFile.fileName());
		MyHashCompare::lSHA256Thread->start();
		MyHashCompare::rSHA256Thread->start();
	}
}

