#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 

/*
====================
LemonadeChange
*/
// Verifica se é possível fornecer troco a todos os clientes em uma fila.
bool LemonadeChange( const int *bills, const int billsSize ) {
	int fiveBills = 0;
	int tenBills = 0;

	for ( int i = 0; i < billsSize; i++ ) {
		int bill = bills[i];

		if ( bill == 5 ) {
			fiveBills++;
		} else if ( bill == 10 ) {
			if ( fiveBills > 0 ) {
				fiveBills--;
				tenBills++;
			} else {
				return false;
			}
		} else if ( bill == 20 ) {
			if ( tenBills > 0 && fiveBills > 0 ) {
				tenBills--;
				fiveBills--;
			} else if ( fiveBills >= 3 ) {
				fiveBills -= 3;
			} else {
				return false;
			}
		}
	}

	return true;
}

/*
==================
main
*/

int main( void ) {
	int billsSize = 0;

	printf( "Quantos clientes estao na fila? " );
	scanf( "%d", &billsSize );

	if ( billsSize <= 0 ) {
		return 0; 
	}

	// Aloca memória para o array de notas
	int *bills = (int *)malloc( billsSize * sizeof( int ) );
	if ( bills == NULL ) {
		return 1; 
	}

	//dados de entrada
	printf( "Digite o valor da nota de cada cliente (5, 10 ou 20):\n" );
	for ( int i = 0; i < billsSize; i++ ) {
		printf( "Cliente %d: ", i + 1 );
		scanf( "%d", &bills[i] );
	}

	//chama a func
	bool result = LemonadeChange( bills, billsSize );

	//output result
	if ( result ) {
		printf( "\ntrue\n" );
	} else {
		printf( "\nfalse\n" );
	}

	// Libera memoria
	free( bills );

	return 0; 
}