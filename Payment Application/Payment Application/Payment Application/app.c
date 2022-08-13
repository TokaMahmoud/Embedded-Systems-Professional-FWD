#include "card.h"
#include "terminal.h"
#include "server.h"
#include "app.h"
#include <stdio.h>

void main() {
	while (1)
		appStart();
}

void appStart(void) {
	ST_cardData_t c;
	ST_terminalData_t t;
	ST_transaction_t tr;

	//<<<<<<<<<<<<<<<<<<<<<<<<<Card module>>>>>>>>>>>>>>>>>>>>>>>>>>>
	while (getCardHolderName(&c) == WRONG_NAME)
		printf("Wrong name\n");

	while (getCardExpiryDate(&c) == WRONG_EXP_DATE)
		printf("Wrong date\n");

	while (getCardPAN(&c) == WRONG_PAN)
		printf("Wrong PAN\n");

	//<<<<<<<<<<<<<<<<<<<<<<<<<Terminal module>>>>>>>>>>>>>>>>>>>>>>>>>
	while (getTransactionDate(&t) == WRONG_DATE)
		printf("WRONG DATE\n");

	if (isCardExpired(c, t) == EXPIRED_CARD)
		printf("EXPIRED CARD\n\n");

	else {
		while (getTransactionAmount(&t) == INVALID_AMOUNT)
			printf("INVALID AMOUNT\n");

		setMaxAmount(&t);

		if (isBelowMaxAmount(&t) == EXCEED_MAX_AMOUNT)
			printf("EXCEED MAX AMOUNT\n\n");

		else {
			//<<<<<<<<<<<<<<<<<Server module>>>>>>>>>>>>>>>>>>>>>>>>>>>>
			tr.cardHolderData = c;
			tr.terminalData = t;
			tr.transState = recieveTransactionData(&tr);

		}
	}
}