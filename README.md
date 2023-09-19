# minitalk

# UNIX Signal-Based Communication Program
This repository contains a simple communication program implemented in C, consisting of a server and a client, which communicate with each other using UNIX signals (SIGUSR1 and SIGUSR2). The server is capable of handling multiple clients and quickly displaying received messages. Additionally, it supports Unicode characters.

Features
The server must be started first and will print its Process ID (PID) upon launch.
The client accepts two parameters:
The server's PID.
The string to send.
The client sends the provided string to the server.
Upon receiving a message, the server promptly displays it.
The server can handle multiple clients in a row without needing to be restarted.
Requirements
To run this program, you will need:

A Unix-based operating system (e.g., Linux or macOS).
A C compiler (e.g., GCC).
Usage
Follow these steps to use the communication program:

# Usage

```
git clone https://github.com/eetukoljonen/minitalk.git
```
Start the "server"
./server
