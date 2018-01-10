#include "data_reader.h"
#include "http_request.h"
#include "http_response.h"
#include "http_transport.h"
#include "status.h"

using googleapis_client::DataReader;
using googleapis_client::DataWriter;
using googleapis_client::HttpHeaderMap;
using googleapis_client::HttpRequest;
using googleapis_client::HttpRequestState;
using googleapis_client::HttpResponse;
using googleapis_client::HttpTransport;
using googleapis_client::HttpTransportFactory;
using googleapis_client::HttpTransportLayerConfig;
using googleapis_client::HttpTransportOptions;

class MyCustomRequest:public HttpRequest{
	public:
		MyCustomRequest(const HttpRequest::HttpMethod& method, HttpTransport* transport)
			:HttpRequest(method, transport)
		{}

		virtual ~MyCustomRequest() {}
		virtual void DoExecute(HttpResponse* response);

	private:
		DISALLOW_COPY_AND_ASSIGN(MyCustomRequest);
};


void DoExecute(HttpResponse* response) {
	mutable_state()->set_transport_status(
			googleapis_client::StatusUnimplemented("Not yet implemented"));
}
