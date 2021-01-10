#include <iostream>
#include <thread>
#include <future>

#include "asio_include_dir/asio.hpp"
#include "cli11_include_dir/CLI11.hpp"


using namespace std;
using namespace asio::ip;

int main(int argc, char *argv[]) {
    CLI::App app("Client for ASCII-Code transfer");
    u_short port{8888};
    app.add_option("-p,--port", port, "Port for hosting!");
    CLI11_PARSE(app, argc, argv);

    asio::io_context ctx;
    tcp::endpoint ep{tcp::v4(), port};
    tcp::acceptor acceptor{ctx, ep};
    acceptor.listen();

    tcp::socket sock{ctx};
    acceptor.accept(sock);
    tcp::iostream strm{std::move(sock)};

    string data;
    strm >> data;
    cout << data << endl;
    strm << data;
    strm.close();

    return 0;
}
