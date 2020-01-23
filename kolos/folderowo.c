/*
 * .c
 * 
 * Copyright 2020 root <root@MrArlen>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int checkCreatedFolder; 
	char* folder = "FolderUtworzony";
	
	printf("Ścieżka katalogu w ktorym bedzie tworzony katalog:\n");
	system("pwd");
	printf("\nPokazanie zawartosci folderu rodzica przed utworzeniem\n");
	system("ls -la");
	checkCreatedFolder = mkdir(folder, 0777);
	if (!checkCreatedFolder){
		printf("\nPokazanie folderu po utworzeniu\n");
		system("ls -la");
		chdir(folder);
		printf("\nCzy przeszło: ścieżka\n");
		system("pwd");
		printf("\nCzy powróciło: ?\n");
		chdir("..");
		system("pwd");
	}
	else{
		printf("\nSie nie utworzyl bo jest stworzony\n");
	}
	
	
	return 0;
}

