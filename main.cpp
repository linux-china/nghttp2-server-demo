#include <iostream>
#include <map>
#include <nghttp2/asio_http2_server.h>

using namespace nghttp2::asio_http2;
using namespace nghttp2::asio_http2::server;
using namespace std;

int main(int argc, char *argv[]) {
    boost::system::error_code ec;
    http2 server;

    server.handle("/", [](const request &req, const response &res) {
        header_map h = {};
        h.insert(std::pair<string, header_value>("Content-Type", header_value{"text/plain"}));
        res.write_head(200, h);
        res.end("hello, world!!!\n");
    });

    if (server.listen_and_serve(ec, "localhost", "3000")) {
        cerr << "Error to start http server: " << ec.message() << endl;
    }
}
