#include "terminal.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

EN_terminalError_t getTransactionDate(ST_terminalData_t* termData) {
	int len;
	printf("Transaction date:");
	gets(termData->transactionDate);
	len = strlen(termData->transactionDate);
	if (len == 0 || len != 10) 
		return WRONG_DATE;
	if (termData->transactionDate[2] != '/' || termData->transactionDate[5] != '/')
		return WRONG_DATE;
	else return OKTERMINAL;
}

EN_terminalError_t isCardExpired(ST_cardData_t cardData, ST_terminalData_t termData) {
	int transDate_MM = atoi(&termData.transactionDate[3]); // DD/MM/YYYY
	int transDate_YY = atoi(&termData.transactionDate[6]);
	int ExpiraDate_MM = atoi(&cardData.cardExpirationDate); // MM/YY
	int ExpiraDate_YY = atoi(&cardData.cardExpirationDate[3])+2000;

	if (transDate_YY > ExpiraDate_YY)
		return EXPIRED_CARD;

	if (transDate_YY == ExpiraDate_YY)
		 if(transDate_MM > ExpiraDate_MM)
			return EXPIRED_CARD;

	return OKTERMINAL;
}

EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData) {
	printf("Transaction amount :");
	scanf_s("%f", &termData->transAmount);
	if (termData->transAmount <= 0)
		return INVALID_AMOUNT;
	else return OKTERMINAL;
}

EN_terminalError_t setMaxAmount(ST_terminalData_t* termData) {
	termData->maxTransAmount = 100000.0f;
	if (termData->maxTransAmount <= 0)
		return INVALID_MAX_AMOUNT;
	else return OKTERMINAL;
}

EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData) {
	if (termData->transAmount > termData->maxTransAmount)
		return EXCEED_MAX_AMOUNT;
	else return OKTERMINAL;
}