#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void xorEncryptDecrypt(std::vector<char>& data, unsigned char key) {
    for (size_t i = 0; i < data.size(); i++) {
        data[i] ^= key;  // XOR encryption / decryption
    }
}

void saveEncryptedFile(const std::vector<char>& data, const std::string& fileName) {
    std::ofstream output(fileName, std::ios::binary);
    if (!output.is_open()) {
        std::cerr << "Encrypted file could not be saved!" << std::endl;
        return;
    }
    output.write(data.data(), data.size());
    std::cout << "Encrypted file saved as: " << fileName << std::endl;
}

void loadAndEncryptFile(const std::string& filePath, unsigned char key) {
    // Read the file
    std::ifstream input(filePath, std::ios::binary);
    if (!input.is_open()) {
        std::cerr << "File could not be opened: " << filePath << std::endl;
        return;
    }

    std::vector<char> fileData((std::istreambuf_iterator<char>(input)), std::istreambuf_iterator<char>());

    // Encrypt the file
    xorEncryptDecrypt(fileData, key);

    // Save the encrypted file
    std::string encryptedFilePath = filePath + ".enc";
    saveEncryptedFile(fileData, encryptedFilePath);
}

void showFileDialogAndEncrypt() {
    OPENFILENAME ofn;       // File open dialog
    char szFile[260];       // Selected file path
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = GetConsoleWindow();
    ofn.lpstrFile = szFile;
    ofn.nMaxFile = sizeof(szFile);
    ofn.lpstrFilter = "All Files\0*.*\0";
    ofn.nFilterIndex = 1;
    ofn.lpstrFile[0] = '\0';
    ofn.lpstrFileTitle = NULL;
    ofn.nMaxFileTitle = 0;
    ofn.lpstrInitialDir = NULL;
    ofn.lpstrTitle = "Select a File";
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

    if (GetOpenFileName(&ofn) == TRUE) {
        std::cout << "Selected file: " << szFile << std::endl;

        unsigned char key = 0xAA;  // Encryption key

        // Encrypt the file
        loadAndEncryptFile(szFile, key);
    }
    else {
        std::cout << "No file selected!" << std::endl;
    }
}

int main() {
    std::cout << "Welcome to the XOR encryption tool!" << std::endl;
    showFileDialogAndEncrypt();  // File selection and encryption process
    return 0;
}
