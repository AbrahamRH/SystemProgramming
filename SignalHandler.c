/**
 * @file SignalHandler.c
 * @brief Programa para observar el funcionamiento de las señales
 * @author AbrahamRH
 * @version 1.0
 * @date 2019-12-14
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void sig_handler( int signum )
{
	/*Mensaje del handler*/
	printf("Alarm delivered signum is %d\n", signum);
	/* Ejecuta el comando de terminal 'ls' */
	system("/bin/ls");
	/*Función para terminar el programa*/
	exit(0);
}

int main()
{
	/*Despues de 5 segundos se activara una señal de alarma*/
	alarm(5);

	/*Para buscar otras señales usar comando:  kill -l */

	/**
	 * Handler para recibir la señal de alarma y mandar un mensaje en la pantalla
	 * Nota: No necesariamente debe ir en esta parte del código, puede ir al inicio
	 *		 pero a un lado de la funcion de alarma.
	 *
	 *		 Si se termina la señal de alarma y no hay un handler, el sistema matara el proceso
	 *		 Todas las señales tienen que ser atrapadas con excepcion de la señal: -9.
	 *
	 *		 Igualemete necesita ser atrapada por SIGALRM  y no otra señal ya que en la linea 18
	 *		 se esta mando una señal de alarma.
	 **/
	signal(SIGALRM, sig_handler);

	/*Creamos un loop infinito para mantenernos en el programa y observar la señal*/
	//Se empieza a ejecutar en esta linea solo si no sale de la función signal handler
#if 1
	for(;;)
		sleep(1);
#endif

	return 0;
}


/*Comando de terminal strace ./%.out para poder ver como se ejecuta el programa con los procesos*/

