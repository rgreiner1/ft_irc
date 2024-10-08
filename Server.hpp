/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogregoir <ogregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:16:27 by rgreiner          #+#    #+#             */
/*   Updated: 2024/08/13 17:36:15 by ogregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once
# include <sys/socket.h>
# include <netinet/in.h>
# include <iostream>
# include "poll.h"
# include "string"
# include "sstream"
# include "cstdlib"
# include "fstream"
# include <unistd.h>
# include <arpa/inet.h>
# include <fcntl.h>
# include <cstring>
# include <cctype>
# include <vector>
# include <csignal>
# include"Channel.hpp"

class Client;
class Server
{
	private:
		
		sockaddr_in             serverAddr;
		nfds_t                  nfds;
		std::vector<pollfd>     fds;
		
	public:
	
		std::vector<Client>     clients;
		std::vector<Channel>    channels;
		int                     serverSocket;
		Server();
		Server(char **argv);
		void                    topic_chan(std::vector<std::string> tmp, Client &client, int arg, std::vector<std::string> buffer);
		void                    invite_chan(Client &client, int arg, std::vector<std::string> buffer);
		void                    kick_chan(int arg, Client &client, std::vector<std::string> tmp, std::vector<std::string> buffer);
		void                    update_topic(std::vector<std::string> buffer, unsigned long i);
		void                    part_chan(Client &client, int arg, std::vector<std::string> buffer);
		void   					quit_Server(std::string clientName, int clientSocketcpy);
		std::string             pass;
		~Server();
		void routine();
};

extern Server 	server;
void    		parse_argv(Server& server, char **argv);
