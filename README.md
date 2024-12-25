# XOR File Encryption Tool

This tool allows you to easily encrypt and decrypt files using a simple XOR-based encryption method. It works with any file type (e.g., `.txt`, `.exe`, `.jpg`, etc.), and generates an encrypted version of the file with the `.enc` extension.

## Features

- Simple XOR-based file encryption.
- Encrypts any type of file (text files, executables, images, etc.).
- The encrypted file is saved with a `.enc` extension.
- User-friendly file selection dialog.

## Requirements

- Windows operating system.
- A C++ compiler (such as MSVC, MinGW) to compile the code.

## Usage

1. Clone or download the repository.
2. Compile the project using your preferred C++ compiler.
3. Run the program.
4. A file selection dialog will appear. Choose the file you want to encrypt.
5. The file will be encrypted using a simple XOR encryption and saved with the `.enc` extension.

### Example

- Original File: `example.txt`
- Encrypted File: `example.txt.enc`

The encryption uses a fixed key (`0xAA`) which can be modified in the source code.

## Decryption

To decrypt the file, simply run the tool again with the encrypted file. Since the same XOR key is used for both encryption and decryption, it will restore the original file.

### Decryption Process

1. Run the program.
2. Select the `.enc` file.
3. The file will be decrypted back to its original form.

## Customization

- **Encryption Key**: The default encryption key is `0xAA`. You can change the key by modifying the source code in the `xorEncryptDecrypt` function.
- **File Types**: The tool can encrypt any file type. The file extension is not important, but the `.enc` extension is added to the encrypted files for clarity.

## Contributing

Feel free to fork the repository, create an issue, or submit a pull request if you'd like to contribute improvements or bug fixes!

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
