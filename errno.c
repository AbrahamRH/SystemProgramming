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
 * @file Prueba_errno.c
 * @brief Programa de prueba para errores con la biblioteca errno.h
 * @author AbrahamRH
 * @version 1.0
 * @date 2019-12-03
 */

#include <stdio.h>
#include <fcntl.h>
//The <fcntl.h> header shall define the following requests and arguments for use by the functions fcntl() and open().
//Para el uso de O_RDONLY
#include <errno.h>
//Cabecera para el uso de perror para imprimir en pantalla el error del sistema

int main(){
	int fd;
	//Errno: number of last error
	while(((fd = open("my.file", O_RDONLY)) == -1) && (errno == EAGAIN));
		if( fd == -1 ){
			//printf("%d",errno);
			perror("Unsuccesful open of my.file");
			//Imprime la descripción del error
		}
}

