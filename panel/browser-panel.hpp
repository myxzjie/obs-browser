#pragma once

#include <QWidget>
#include <string>

class QCefWidget : public QWidget {
	Q_OBJECT

protected:
	inline QCefWidget(QWidget *parent) : QWidget(parent)
	{
	}

public:
	virtual void setURL(const std::string &url)=0;
};
