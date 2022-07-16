// metadata-extractor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>

extern "C" void decrypt_global_metadata(uint8_t * data, size_t size);
extern "C" void encrypt_global_metadata(uint8_t * data, size_t size);

struct PARAMETERS {
    char * inputFile = nullptr;
    char * outputFile = nullptr;
    bool function = false;
};

void processParameters(int argc, char** argv, PARAMETERS* param)
{
    for (uint32_t i = 1; i < argc; i++)
    {
        if ((std::string)argv[i] == "-o")
        {
            if (i + 1 <= argc)
            {
                param->outputFile = argv[i + 1];
            }
        }
        if ((std::string)argv[i] == "-i")
        {
            if (i + 1 <= argc)
            {
                param->inputFile = argv[i + 1];
            }
        }
        if ((std::string)argv[i] == "--encrypt")
        {
            param->function = true;
        }
        if ((std::string)argv[i] == "--decrypt")
        {
            param->function = false;
        }
    }
}


int main(int argc, char ** argv)
{
    PARAMETERS * params = new PARAMETERS;
    processParameters(argc, argv, params);
    if (params->inputFile != nullptr && params->outputFile != nullptr) {
        //open file
        std::ifstream infile(params->inputFile, std::ios::binary);

        //get length of file
        infile.seekg(0, std::ios::end);
        size_t length = infile.tellg();
        infile.seekg(0, std::ios::beg);

        std::vector<uint8_t> buffer(length, 0);

        //read file
        infile.read(reinterpret_cast<char*>(&buffer[0]), length);
        infile.close();
        if (params->function == true) {
            encrypt_global_metadata(buffer.data(), length);
        } else {
            decrypt_global_metadata(buffer.data(), length);
        }
        std::ofstream outFile(params->outputFile, std::ios::binary);
        outFile.write((char*)buffer.data(), length);
        outFile.flush();
        outFile.close();
    }
}
