#pragma once

#include <QTimer>
#include "browser-panel.hpp"
#include "cef-headers.hpp"

class QCefWidgetInteral : public QCefWidget {
	Q_OBJECT

public:
	QCefWidgetInteral(QWidget *parent, const std::string &url);
	~QCefWidgetInteral();

	CefRefPtr<CefBrowser> cefBrowser;
	std::string url;
	QTimer timer;

	virtual void resizeEvent(QResizeEvent *event) override;
	virtual void showEvent(QShowEvent *event) override;
	virtual QPaintEngine *paintEngine() const override;

	virtual void setURL(const std::string &url) override;

public slots:
	void Init();
};
