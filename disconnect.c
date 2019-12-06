/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disconnect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweinste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 16:33:06 by lweinste          #+#    #+#             */
/*   Updated: 2017/07/24 16:40:56 by lweinste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

	pid_t process_id = 0;
	pid_t sid = 0;

	process_id = fork();

	if (process_id < 0){
		dprintf(2, "error making new process\n");
		exit(1);
	}
	if (process_id > 0){
		printf("Hello from the parent process\n");
		printf("Goodbye from the parent process("leaving now\n");
		exit(0);
	}
	umask(0);
	sid = setsid();
	if (sid < 0)
		exit(1);
	chdir("/");
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);

	while (1){
	sleep(10);
	system("networksetup -setairportpower en0 off");
	system("networksetup -setairportpower en1 off"); //One of these two will work on each type of mac and the other will do nothing
	sleep(10);
	system("networksetup -setairportpower en0 on");
	system("networksetup -setairportpower en1 on");
	}
	return (0);
}

		
