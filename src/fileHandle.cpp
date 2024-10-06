#include "../include/fileHandle.h"


FileHandle::FileHandle(const std::string& arg, std::ios_base::openmode mode) {
    std::filesystem::path filePath(arg);
    if (filePath.extension() != ".txt")
        throw std::invalid_argument("The file should be of TXT format.");

    file = std::fstream(filePath, mode);
    if (!file.is_open())
        throw std::invalid_argument("Issues opening the file at " + arg + ".");
}

std::fstream& FileHandle::getStream() {
    return file;
}

FileHandle::~FileHandle() {
    if (file.is_open())
        file.close();
}
