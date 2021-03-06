#ifndef __LOKI_LOKINET_API_CLIENT_HPP__
#define __LOKI_LOKINET_API_CLIENT_HPP__

#include <QObject>
#include <QJSValue>

#include "HttpClient.hpp"
 
/**
 * A client that implements convenience wrappers around making specific
 * JSON-RPC requests to a lokinet daemon. 
 *
 * These are meant to be invoked from QML; as such, they each take a `QJSValue`
 * object which should be a Javascript callback function. This function should
 * take two parameters: the message payload and an error, e.g.:
 *
 * ```javascript
 * apiClient.llarpAdminStart(function(response, err) {
 *     if (err) {
 *         console.log("Received error when trying to start lokinet daemon: ", err);
 *     }
 * });
 * ```
 *
 * TODO: abstract this and just take a string as the endpoint. let QML/Javascript
 *       do the JSON-y things.
 */
class LokinetApiClient : public QObject
{
    Q_OBJECT

public:

    /**
     * Invoke the `llarp.admin.wakeup` endpoint.
     *
     * @param callback is an optional JS function to invoke on success
     * @return true if the asynchronous request could be made, false otherwise
     */
    Q_INVOKABLE bool llarpAdminWakeup(QJSValue callback);

    /**
     * Invoke the `llarp.version` endpoint.
     *
     * @param callback is an optional JS function to invoke on success
     * @return true if the asynchronous request could be made, false otherwise
     */
    Q_INVOKABLE bool llarpVersion(QJSValue callback);

    /**
     * Invoke the `llarp.admin.status` endpoint.
     *
     * @param callback is an optional JS function to invoke on success
     * @return true if the asynchronous request could be made, false otherwise
     */
    Q_INVOKABLE bool llarpAdminStatus(QJSValue callback);
 
private:

    HttpClient m_httpClient;

};
 
#endif // __LOKI_LOKINET_API_CLIENT_HPP__
