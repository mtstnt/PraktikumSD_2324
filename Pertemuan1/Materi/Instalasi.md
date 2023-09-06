# Instalasi Compiler C++

## Windows/Linux
Install TDM GCC (64 bit) di [https://github.com/jmeubank/tdm-gcc/releases/download/v10.3.0-tdm64-2/tdm64-gcc-10.3.0-2.exe](https://github.com/jmeubank/tdm-gcc/releases/download/v10.3.0-tdm64-2/tdm64-gcc-10.3.0-2.exe)

Untuk compile:
```bash
g++ -o <path ke output> <file cpp kalian>
```
dan hasil executablenya bisa dirun langsung:
Untuk Powershell/Terminal Linux/MacOS
```ps1
./<path ke output>
```
Untuk Windows Command Prompt:
```cmd
cd <path ke folder output> && <nama executable>
```

## MacOS
Ada bawaan compiler Clang++, untuk cek:
```bash
clang++ --version
```
kalau tidak error, berarti bisa digunakan.

Untuk compile:
```bash
clang++ -o <path ke output> <file cpp>
```
dan untuk run:
```bash
./<path ke output>
```
