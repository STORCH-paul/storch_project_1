#include <iostream>
#include <thread>
#include <future>
#include <bitset>
#include <vector>
#include "spdlog_include_dir/spdlog/spdlog.h"
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

string convertBlocksToAscii(vector<shared_future<bitset<80>>> message){
    string ascii{};
    for(auto blocks : message){
        int counter{0};
        string temp{"0"};
        for(auto bit : blocks.get().to_string()){            
            counter++;
            if(counter % 8 == 0 && counter <= 72 && counter > 0){
                ascii += char(bitset<8>(temp).to_ulong());
                temp = "0";
            }else{
                temp += bit;
            }
        }
    }
    return ascii;
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
    if(strm){
        spdlog::log(spdlog::level::level_enum::info, "Connection established!");
        while(true){ 
            message.push_back(async(launch::async, getStream, ref(strm)));
            status = message.at(counter).wait_for(std::chrono::seconds(2));
            if(status == std::future_status::ready){
                spdlog::log(spdlog::level::level_enum::info, "Receiving ASCII-Block: " + to_string(counter));
                //cout << message.at(counter).get().to_string() << endl;
                counter++;
            } else {
                break;
            }
        }
    }else{
        spdlog::log(spdlog::level::level_enum::err, strm.error().message());
        spdlog::log(spdlog::level::level_enum::err, "Error establishing connection with client!");
        return 1;
    }
    strm.close();
    if(checkStream(message)){
        spdlog::log(spdlog::level::level_enum::info, "ASCII-Blocks transfer successful!");
    } else{
        spdlog::log(spdlog::level::level_enum::err, "ASCII-Blocks corrupted while transferring please try again!");
    }
    spdlog::log(spdlog::level::level_enum::info, "ASCII-Message: " + convertBlocksToAscii(message));

    return 0;
}
