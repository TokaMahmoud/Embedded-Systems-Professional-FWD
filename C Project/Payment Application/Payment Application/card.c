#include "card.h"
#include <stdio.h>
#include <string.h>

EN_cardError_t getCardHolderName(ST_cardData_t* cardData) {
	printf("Cardholder's name: ");
	gets(cardData->cardHolderName);
	int len = strlen(cardData->cardHolderName);
	if (len == 0 || len < 20 || len > 24)
		return WRONG_NAME;
	else return OKCARD;
}

EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData) {
	printf("Card expiry date :");
	gets(cardData->cardExpirationDate);
	int len = strlen(cardData->cardExpirationDate);
	if (len == 0 || len != 5)
		return WRONG_EXP_DATE;
	else if(cardData->cardExpirationDate[2] != '/')
		return WRONG_EXP_DATE;
	else return OKCARD;
}

EN_cardError_t getCardPAN(ST_cardData_t* cardData) {
	printf("Card's Primary Account Number :");
	gets(cardData->primaryAccountNumber);
	int len = strlen(cardData->primaryAccountNumber);
	if (len == 0 || len < 16 || len > 19)
		return WRONG_PAN;
	else return OKCARD;
}