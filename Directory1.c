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
 * @file Directory1.c
 * @brief Programa para la implementación del comando 'ls' en lenguaje c
 * @author AbrahamRH
 * @version 1.0
 * @date 2019-12-14
 */


#include <stdio.h>
#include <dirent.h>
//Para el uso de DIR y la estructura dirent

#include <string.h>
#include <errno.h>
#include <stdlib.h>
//Pra exit()

int main(int argc,char** argv)
{
	if( argc != 2 ){
		printf("Por favor introduzca el directorio a listar\n");
		exit(1);
	}

	/*DIR.- Tipo de tato que representa un un canal de datos de un directorio (directory stream)*/
	DIR *dp;

	/* dirent es una estructura que contiene información acerca del archivo, inodos, offset, etc
	 * Notas: Un inodo es una estructura de datos para archivos que contiene los metadatos de esos mismos
	 *		  tales como su tamaño, permisos, fechas de creación, etc.
	 *		  Offset. indica el desplazamiento desde un incio hasta alguna parte del objeto.
	 */
	struct dirent *dirp;

	/*Se envia un mensaje si no es podible abrir el directorio*/
	if( (dp = opendir(argv[1])) == NULL ){
		fprintf(stderr,"No es posible acceder al directorio, error: %s\n", strerror(errno));
		exit(1);
	}

	while( (dirp = readdir(dp)) != NULL )
		printf("   %s   ",dirp->d_name);
	printf("\n");

	closedir(dp);
	exit(0);
}



