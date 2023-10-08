# wic

## Description
**Who Is Connected (WIC)** allows you to request from a predetermined set of servers which users are logged in and on which machines, getting the (server IP address, username) pairs.

This suite is made up of two applications: **WIC Server** and **WIC Client**,
which act as server and client respectively.<br>
WIC Server must always be running on every server machine; WIC Client should only be run when necessary on the client machine.

The message that the client sends to the server to request the logged in user is called *WIC Request* (or *WIC Query*).
Each server will respond with a *WIC Response* containing the message formatted as follows:<br>
`server IP address ---> logged in username`

## WIC Server
WIC Server contains:
* the executable WIC Server
* the configuration file server_config.ini.

The server starts in tray icon. It prints all its IP addresses (excluding loopback and IPv6) and the name of the logged in user. It listens on the IP and port of the configuration file. As soon as it receives a WIC Request from a client, it responds to the request with its IP address and the currently logged in user.

### Requirements
* Windows 10 or later
* Mac OS 11 (Big Sur) or later.

### Installation
Just put WIC Server where you want.<br>
server_config.ini must be present and configured in the same location as WIC Server.<br>
server_config.ini must be configured with IP address and listening port of the server.<br>
In the absence of the file, WIC Server uses the IP address 127.0.0.1 and the port 50000 by default.

### Usage
1. Double-click on WIC Server
2. It starts in tray icon, ready to listen to requests from clients.

## WIC Client
WIC Client contains:
* the executable WIC Client
* the configuration file client_config.ini
* server_list.txt.

The client reads the server list. It opens a socket for each server. As soon as it connects to the server, it sends the WIC Request. It prints server responses.

### Requirements
* Windows 10 or later
* Mac OS 11 (Big Sur) or later.

### Installation
Just put WIC Client where you want.<br>
client_config.ini and server_list.txt files must be present and configured in the same location as WIC Client.<br>
client_config.ini must be configured with client port and timeout.<br>
In the absence of the file, WIC Client defaults to port 50000 and a timeout of 30000 ms.<br>
server_list.txt must contain the list of IP addresses of the servers to contact; the syntax is as follows:<br>
`one IP address for each line`<br>
In the absence of the file, WIC Client will not be able to send WIC Requests.

### Usage
1. Double-click on WIC Client
2. The client starts sending automatically the requests to the servers in the list and prints the responses in the console.
