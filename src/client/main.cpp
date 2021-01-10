#include <iostream>
#include <thread>
#include <future>
#include <bitset>
#include <vector>

#include "asio_include_dir/asio.hpp"
#include "cli11_include_dir/CLI11.hpp"

using namespace std;
using namespace asio::ip;

bitset<80> getStream(tcp::iostream& strm){
    bitset<80> data;
    strm >> data;
    //cout << data.to_string(); << endl;
    return data;
}

bool checkStream(vector<shared_future<bitset<80>>> message){
    for(auto blocks : message){
        vector<int> countOnes{0,0,0,0,0,0,0,0};
        int counter{0};
        int onedcounter{0};
        for(auto bit : blocks.get().to_string()){
            if(counter % 8 == 0 && counter <= 72){
                if(onedcounter % 2 == 1){
                    return false;
                }
                onedcounter = 0;
            }
            if(bit == '1'){
                countOnes.at(counter % 8)++;
                onedcounter++;
            }
        counter++;
        }
        for(auto ones : countOnes){
            if(ones % 2 == 1){
                return false;
            }
        }
    }
    return true;
}

int main(int argc, char *argv[]) {
    CLI::App app("Server for ASCII-Code transfer");
    string ipaddress{"localhost"};
    string port{"8888"};
    app.add_option("-i,--ipv4address", ipaddress, "IP-Adress to connect!");
    app.add_option("-p,--port", port, "Port to connect!");
    CLI11_PARSE(app, argc, argv);

    tcp::iostream strm{ipaddress, port};
    strm.expires_after(10s);
    

    vector<shared_future<bitset<80>>> message{};
    std::future_status status;
    int counter{0};
    while(true){ 
        message.push_back(async(launch::async, getStream, ref(strm)));
        status = message.at(counter).wait_for(std::chrono::seconds(2));
        if(status == std::future_status::ready){
            cout << message.at(counter).get().to_string() << endl;
            counter++;
        } else {
            break;
        }
    }
    strm.close();
    cout << checkStream(message) << endl;

    return 0;
}
