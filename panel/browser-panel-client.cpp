#include "browser-panel-client.hpp"

#include <QUrl>
#include <QDesktopServices>

/* CefClient */
CefRefPtr<CefLoadHandler> QCefBrowserClient::GetLoadHandler()
{
	return this;
}

CefRefPtr<CefDisplayHandler> QCefBrowserClient::GetDisplayHandler()
{
	return this;
}

CefRefPtr<CefLifeSpanHandler> QCefBrowserClient::GetLifeSpanHandler()
{
	return this;
}


/* CefLifeSpanHandler */
bool QCefBrowserClient::OnBeforePopup(
		CefRefPtr<CefBrowser>,
		CefRefPtr<CefFrame>,
		const CefString &target_url,
		const CefString &,
		WindowOpenDisposition,
		bool,
		const CefPopupFeatures &,
		CefWindowInfo &,
		CefRefPtr<CefClient> &,
		CefBrowserSettings &,
		bool *)
{
	/* Open popup URLs in user's actual browser */
	std::string str_url = target_url;
	QUrl url = QUrl(str_url.c_str(), QUrl::TolerantMode);
	QDesktopServices::openUrl(url);
	return true;
}
