#include <iostream>
#include <fstream>
#include <sys/socket.h>
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include <thread>

#define PORT	 8008 
#define MAXLINE  1024 


namespace UdpLog
{
	



static void doUdpLogging()
{
    std::cout << "starting udp server...\n";

    std::ofstream runLogFile;
    runLogFile.open("upd_server_log.txt", std::ios_base::app);
    runLogFile << "\n\nstarting udp server...\n";

    std::ofstream udpLogFile;
    udpLogFile.open("udp_log_8008.txt", std::ios_base::app);

    int serverSockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (serverSockfd == 0) {
        runLogFile << "socket failed\n";
    }

    struct sockaddr_in address, cliaddr;
    int opt = 1;
    memset(&address, 0, sizeof(address)); 
	memset(&cliaddr, 0, sizeof(cliaddr)); 

    // Forcefully attaching socket to the port 8080 
    // if (setsockopt(serverSockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, 
    //                                               &opt, sizeof(opt))) 
    // { 
    //     runLogFile << "setsockopt failed\n";
    // } 
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons( PORT ); 

    // Forcefully attaching socket to the port 8008 
    if (bind(serverSockfd, (struct sockaddr *)&address, sizeof(address))<0) { 
        runLogFile << "bind failed" << "\n";
    } 
    runLogFile.flush();
    unsigned int len, n; 
    char buffer[MAXLINE]; 

    // ==== loop here !!!
    while(1) {
        n = recvfrom(serverSockfd, (char *)buffer, MAXLINE, 
                    MSG_WAITALL, ( struct sockaddr *) &cliaddr, 
                    &len);
        if (n > 0) {
            udpLogFile.write(buffer, n);
            udpLogFile.flush();
        }
    }


    //udpLogFile << "my text here!" << std::endl;
    udpLogFile.close();
    runLogFile.close();
}


class UdpLogger
{
	public:
		void DoLogging()
		{
			std::thread t1 (doUdpLogging);
            t1.detach();
		}
};


} // UdpLog