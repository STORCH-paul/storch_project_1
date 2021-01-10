#include "CLI11.hpp"


using namespace std;

int main(int argc, char *argv[]) {
    CLI::App app("Client for ASCII-Code transfer");
    string ipadress{"localhost"};
    string port{"8888"};
    app.add_option("-i,--ipaddress", ipadress, "IP-Adress for hosting!");
    app.add_option("-p,--port", port, "Port for hosting!");
    CLI11_PARSE(app, argc, argv);
    return 0;
}
