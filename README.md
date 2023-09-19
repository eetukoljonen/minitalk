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
1. Start the server <br>
   ./server <br>
  = server outputs the "pid" <br>
2. Start the client <br>
   ./client "pid" "message" <br>
  = server outputs the message. <br>
example.

<img width="598" alt="Screen Shot 2023-09-19 at 1 15 45 PM" src="https://github.com/eetukoljonen/minitalk/assets/120648288/cfcfdd7f-4bc6-440e-8743-b7569bc81900">
