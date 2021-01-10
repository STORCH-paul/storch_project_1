#include <iostream>
#include <thread>
#include <future>

#include "asio_include_dir/asio.hpp"
#include "cli11_include_dir/CLI11.hpp"

using namespace std;
using namespace asio::ip;

int main(int argc, char *argv[]) {
    CLI::App app("Server for ASCII-Code transfer");
    string ipaddress{"localhost"};
    string port{"8888"};
    app.add_option("-i,--ipv4address", ipaddress, "IP-Adress to connect!");
    app.add_option("-p,--port", port, "Port to connect!");
    CLI11_PARSE(app, argc, argv);

    tcp::iostream strm{ipaddress, port};
    strm.expires_after(10s);
    if (strm){
        strm << "Test Server" << endl;
        string data;
        getline(strm, data);
        if (strm){
            cout << data << endl;
        } else {
            cout << strm.error().message() << endl;
        }
        strm.close();
    }


    return 0;
}
