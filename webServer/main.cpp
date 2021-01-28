#include <sys/epoll.h>
#include <queue>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <unistd.h>

using namespace std;

const int BUFFSIZE = 1024;
const int MAXLINK = 10;
const int DEFAULT_PORT = 8080;

char* get_file_name(char* buff){
    char* file_name = buff + 5;
    char* space = strchr(file_name, ' ');
    *space = '\0';
    return file_name;
}

void deal_get_http(int connect_fd, char* buff){
    char* file_name = get_file_name(buff);
    const char http_correct_header[] = "HTTP/1.1 200 OK\r\nContent-type: text/html\r\n\r\n";
    int res = write(connect_fd, http_correct_header, strlen(http_correct_header));
    if(res > 0){
        cout << "send success" << endl;
    }
}

bool is_get_http(char* buff){
    if(!strncmp(buff, "GET", 3)){
        return true;
    }else{
        return false;
    }
}

int main(int argc, char const *argv[]){

    int socket_fd = 0, connect_fd = 0;
    sockaddr_in servaddr;
    char buff[BUFFSIZE];

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_fd == -1){
        cout << "create socket error!" << endl;
        return -1;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("10.135.94.221");
    servaddr.sin_port = htons(DEFAULT_PORT);

    if(bind(socket_fd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1){
        cout << "bind error" << endl;
        return -1;
    }

    if(listen(socket_fd, MAXLINK) == -1){
        cout << "listen error" << endl;
    }

    connect_fd = accept(socket_fd, (struct sockaddr*)NULL, NULL);
    if(connect_fd == -1){
        cout << "accept error" << endl;
    }else{
        cout << "link success" << endl;
    }


    memset(buff, '\0', sizeof(buff));

    recv(connect_fd, buff, BUFFSIZE - 1, 0);
    send(connect_fd, buff, BUFFSIZE - 1, 0);

    cout << "receive message from client : " << buff << endl;

    if(is_get_http(buff)){
        cout << "it is get http" << endl;
        deal_get_http(connect_fd, buff);
    }

    close(connect_fd);
    close(socket_fd);

    return 0;
}