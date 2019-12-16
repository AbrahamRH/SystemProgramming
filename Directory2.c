/* Copyright (C)
 * 2019 - AbrahamRH
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 */

/**
 * @file Directory2.c
 * @brief Programa para la impletemtacion del comando 'ls' recursivo ( tipo find )
 * @author AbrahamRH
 * @version 1.0
 * @date 2019-12-15
 */

#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

/* -------------------------------*/
/**
 * @brief Función para imprimir recursivamente el contenido de un directorio
 *
 * @param pathname Nombre del directorio a listar
 */
/* -------------------------------*/
void listdir( const char* pathname )
{
	DIR *dp;
	struct dirent *dirp;
	char PATH[259] = {0};

	if( (dp = opendir(pathname)) == NULL ){
		return;
	}

	while( (dirp = readdir(dp)) != NULL ){
		if( dirp->d_type == DT_DIR ){
			/*Si los nombres del directorio son '.' o '..' los saltara para no recorrer loops infinitos*/
			if( (strcmp(dirp->d_name,".") == 0) || (strcmp(dirp->d_name,"..") == 0) )
				continue;
			/*Imprimimos el nombre del directorio que estamos recorriendo*/
			printf("%s\n", dirp->d_name);
			snprintf(PATH, sizeof(PATH)-1, "%s/%s", pathname, dirp->d_name);
			listdir(PATH);
		}else{
			printf("\t%s\n",dirp->d_name);
		}
	}
	closedir(dp);
}

int main(int argc ,char** argv)
{

	if( argc != 2 ){
		printf("Introduzca el nombre del directorio\n");
		exit(1);
	}

	listdir(argv[1]);
	exit(0);

}
