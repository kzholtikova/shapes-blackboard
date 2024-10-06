#pragma once
#include <fstream>
#include <filesystem>


class FileHandle {
public:
    FileHandle(const std::string& arg, std::ios_base::openmode mode);
    std::fstream& getStream();
    ~FileHandle();
private:
    std::fstream file;
};
