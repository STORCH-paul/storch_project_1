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

vector<bitset<8>> onedParitaet(vector<bitset<7>> asciibits){
    vector<bitset<8>> onedParitaet{};
    for(auto bits: asciibits){
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
            for(auto ones: countOnes){
                if(ones % 2 == 1){
                    blockstring += bitset<1>(0x1).to_string();
                } else{
                    blockstring += bitset<1>(0x0).to_string();
                }
            }
            block.push_back(bitset<80>(blockstring));
            blockstring = "";
        }
    }
    if(blockstring.size() != 0){
        while(blockstring.size() != 72){
            blockstring += bitset<1>(0x0).to_string();
        }
        for(auto ones: countOnes){
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
    vector<bitset<80>> blocks{addParitaetToBits(asciibits)};

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
