/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgreiner <rgreiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:41:58 by rgreiner          #+#    #+#             */
/*   Updated: 2024/05/29 11:42:09 by rgreiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include "iostream"
#include "poll.h"
#include "string"
#include "sstream"
#include "cstdlib"
#include "fstream"
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include<cstring>
#include<vector>


class Client
{
protected:

public:
    Client(/* args */);
    ~Client();
    int clientSocket;
    int isConnected;
    int passwordVerif;
    std::string nickname;
    std::string username;
    std::string hostname;
    std::string servername;
    std::string realname;
    int hasNickname;
    int hasUsername;
    sockaddr_in clientAddr;
    socklen_t addr_len;
    std::vector<char> buf;
	std::vector<char> finalbuf;
    void    connectClient(std::string buf, std::string password);
    void	verifPassword(std::vector<std::string> str, std::string password);
    void	newnickname(std::vector<std::string> str);
    void	newusername(std::vector<std::string> str);
    void	exec(std::vector<std::string> str);

};

std::vector<std::string> split (const std::string &s, char delim);
std::string trim(const std::string& str);
