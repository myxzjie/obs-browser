#pragma once

#include "cef-headers.hpp"

class QCefBrowserClient : public CefClient,
                          public CefDisplayHandler,
                          public CefLifeSpanHandler,
                          public CefLoadHandler {

public:
	inline QCefBrowserClient() {}

	/* CefClient */
	virtual CefRefPtr<CefLoadHandler> GetLoadHandler() override;
	virtual CefRefPtr<CefDisplayHandler> GetDisplayHandler() override;
	virtual CefRefPtr<CefLifeSpanHandler> GetLifeSpanHandler() override;

	/* CefLifeSpanHandler */
	virtual bool OnBeforePopup(
			CefRefPtr<CefBrowser> browser,
			CefRefPtr<CefFrame> frame,
			const CefString &target_url,
			const CefString &target_frame_name,
			WindowOpenDisposition target_disposition,
			bool user_gesture,
			const CefPopupFeatures &popupFeatures,
			CefWindowInfo &windowInfo,
			CefRefPtr<CefClient> &client,
			CefBrowserSettings &settings,
			bool *no_javascript_access) override;

	IMPLEMENT_REFCOUNTING(QCefBrowserClient);
};
