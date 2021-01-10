#include <iostream>
#include <thread>
#include <future>
#include <string>
#include <vector>
#include <bitset>
#include "spdlog_include_dir/spdlog/spdlog.h"
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

vector<bitset<8>> onedParitaet(vector<bitset<7>> asciibits){
    vector<bitset<8>> onedParitaet{};
    for(auto bits: asciibits){
        //cout << bits.to_string() << endl;
        int countOnes{0};
        for(auto bit: bits.to_string()){
            if(bit == '1'){
                countOnes++;
            }
        }
        if(countOnes % 2 == 1){
            bitset<8> temp(bits.to_string() + bitset<1>(0x1).to_string());
            onedParitaet.push_back(temp);
        }else {
            bitset<8> temp(bits.to_string() + bitset<1>(0x0).to_string());
            onedParitaet.push_back(temp);
        }
    }
    return onedParitaet;
}

vector<bitset<80>> twodParitaet(vector<bitset<8>> onedParitaet){
    vector<bitset<80>> block{};
    vector<int> countOnes{0,0,0,0,0,0,0,0};
    string blockstring{};
    int counter{0};
    for(auto bits: onedParitaet){
        counter++;
        for(int i = 0; i < 8; i++){
            if(bits.to_string().at(i) == '1'){
                countOnes.at(i)++;
            }
        }
        blockstring += bits.to_string();
        if(counter % 9 == 0){
            for(int i = 0; i < 8; i++){
                if(countOnes.at(i) % 2 == 1){
                    blockstring += bitset<1>(0x1).to_string();
                } else{
                    blockstring += bitset<1>(0x0).to_string();
                }
            countOnes.at(i) = 0;
            }
            block.push_back(bitset<80>(blockstring));
            blockstring = "";
        }
    }
    if(blockstring.size() != 0){
        while(blockstring.size() != 72){
            blockstring += bitset<1>(0x0).to_string();
        }
        for(auto ones : countOnes){
            if(ones % 2 == 1){
                blockstring += bitset<1>(0x1).to_string();
            } else{
                blockstring += bitset<1>(0x0).to_string();
            }
        }
        block.push_back(bitset<80>(blockstring));
    }
    return block;
}

vector<bitset<80>> addParitaetToBits(vector<bitset<7>> asciibits){
    vector<bitset<80>> blocks{twodParitaet(onedParitaet(asciibits))};
    return blocks;
}

bool checkBlocks(vector<bitset<80>> blocks){
    for(auto block : blocks){
        vector<int> countOnes{0,0,0,0,0,0,0,0};
        int counter{0};
        int onedcounter{0};
        for(auto bit : block.to_string()){
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
    CLI::App app("Client for ASCII-Code transfer");
    u_short port{8888};
    string ascii{};
    app.add_option("ASCII", ascii, "Message in ASCII character")->required()->check(check_callable);
    app.add_option("-p,--port", port, "Port for hosting!");
    CLI11_PARSE(app, argc, argv);

    vector<bitset<7>> asciibits{convertAsciiToBinary(ascii)};
    vector<bitset<80>> blocks{addParitaetToBits(asciibits)};
    if(!checkBlocks(blocks)){
        cerr << "ASCII-Block ERROR-Detection Failed!!" << endl;
        spdlog::log(spdlog::level::level_enum::err, "ASCII-Block ERROR-Detection Failed!!");
    }

    asio::io_context ctx;
    tcp::endpoint ep{tcp::v4(), 8888};
    tcp::acceptor acceptor{ctx, ep};
    acceptor.listen();

    tcp::socket sock{ctx};
    acceptor.accept(sock);
    tcp::iostream strm{std::move(sock)};

    if (strm){
        spdlog::log(spdlog::level::level_enum::info, "Sending ASCII-Block to client!");
        for(auto block : blocks){
            strm << block;
            this_thread::sleep_for(1s);
        }
        this_thread::sleep_for(4s);
        strm.close();
    } else {
        spdlog::log(spdlog::level::level_enum::err, strm.error().message());
        spdlog::log(spdlog::level::level_enum::err, "Error while establishing connection with client!");
    }

    return 0;
}
