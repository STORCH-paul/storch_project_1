#include <iostream>
#include <thread>
#include <future>
#include <bitset>
#include <boost/dynamic_bitset/dynamic_bitset.hpp>

#include "asio_include_dir/asio.hpp"
#include "cli11_include_dir/CLI11.hpp"

using namespace std;
using namespace asio::ip;

string check_callable(const string& message){
    string checklist{" !\"#$%&\'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~"};
    size_t check{message.find_first_not_of(checklist)};
    if(check == string::npos){
        return "";
    }
    else{
        return string(message) + " contains not ASCII character";
    }  
}

vector<bitset<7>> convertAsciiToBinary(string asciis){
    vector<bitset<7>> asciivector{};
    for(char ascii: asciis){
        asciivector.push_back(ascii);
    }
    return asciivector;
}


int main(int argc, char *argv[]) {
    CLI::App app("Server for ASCII-Code transfer");
    string ipaddress{"localhost"};
    string port{"8888"};
    string ascii{};
    app.add_option("ASCII", ascii, "Message in ASCII character")->required()->check(check_callable);
    app.add_option("-i,--ipv4address", ipaddress, "IP-Adress to connect!");
    app.add_option("-p,--port", port, "Port to connect!");
    CLI11_PARSE(app, argc, argv);

    vector<bitset<7>> asciibits{convertAsciiToBinary(ascii)};

    tcp::iostream strm{ipaddress, port};
    strm.expires_after(10s);
    if (strm){
        strm << ascii << endl;
        /*
        string data;
        getline(strm, data);
        if (strm){
            cout << data << endl;
        } else {
            cout << strm.error().message() << endl;
        } */
        strm.close();
    }


    return 0;
}
