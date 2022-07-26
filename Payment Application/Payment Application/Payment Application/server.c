#include "server.h"
#include <stdio.h>

ST_accountsDB_t accounts_database[255] = {
	{10000.0f, "123456789123456789"},
	{100000.0f, "123456789987654321"},
	{1000000.0f, "123456789102030405"},
	{10000000.0f, "123456789908070605"},
	{100000000.0f, "123456789010203040"}
};

ST_transaction_t transactions_database[255];
int i;

EN_serverError_t isValidAccount(ST_cardData_t* cardData) { 
	for (i = 0; i < 5; i++) {
		if (atoll(cardData->primaryAccountNumber) == atoll(accounts_database[i].primaryAccountNumber))
			return OK;
	}
	return ACCOUNT_NOT_FOUND;
}

EN_serverError_t isAmountAvailable(ST_terminalData_t* termData) {
	if (termData->transAmount > accounts_database[i].balance)
		return LOW_BALANCE;
	else return OK;
}

EN_serverError_t saveTransaction(ST_transaction_t* transData) {
	static int sequence_number = 0;
	transData->transactionSequenceNumber = sequence_number;

	if (sequence_number >= 255)
		return SAVING_FAILED;
	else {
		transactions_database[sequence_number].cardHolderData = transData->cardHolderData;
		transactions_database[sequence_number].terminalData = transData->terminalData;
		transactions_database[sequence_number].transState = transData->transState;
		transactions_database[sequence_number].transactionSequenceNumber = sequence_number;

		printf("\n\n");
		printf("<<<<<<<<Card Holder Data>>>>>>>>>>\n");
		printf("Card Holder Name: %s\n", transactions_database[sequence_number].cardHolderData.cardHolderName);
		printf("Card Expiration Date: %s\n", transactions_database[sequence_number].cardHolderData.cardExpirationDate);
		printf("PAN : %s\n\n", transactions_database[sequence_number].cardHolderData.primaryAccountNumber);

		printf("<<<<<<<<<Terminal Data>>>>>>>>>>\n");
		printf("Max Transaction Amount : %f\n", transactions_database[sequence_number].terminalData.maxTransAmount);
		printf("Transaction Date : %s\n", transactions_database[sequence_number].terminalData.transactionDate);
		printf("Transaction Amount : %f\n\n", transactions_database[sequence_number].terminalData.transAmount);

		printf("<<<<<<<<<Transaction Data>>>>>>>>>\n");
		printf("Transaction Sequence Number : %d\n", transactions_database[sequence_number].transactionSequenceNumber);

		printf("Transaction State : ");
		if (transactions_database[sequence_number].transState == APPROVED)
			printf("APPROVED\n\n");
		else if (transactions_database[sequence_number].transState == DECLINED_INSUFFECIENT_FUND)
			printf("DECLINED INSUFFECIENT FUND\n\n");
		else if (transactions_database[sequence_number].transState == DECLINED_STOLEN_CARD)
			printf("DECLINED STOLEN CARD\n\n");
		else if (transactions_database[sequence_number].transState == INTERNAL_SERVER_ERROR)
			printf("INTERNAL SERVER ERROR\n\n");

		printf("Balance = %f\n\n", accounts_database[i].balance);

		sequence_number++;
		return OK;
	}
}

EN_transState_t recieveTransactionData(ST_transaction_t* transData) {
	if (isValidAccount(&transData->cardHolderData) == ACCOUNT_NOT_FOUND)
		transData->transState = DECLINED_STOLEN_CARD;

	else if (isAmountAvailable(&transData->terminalData) == LOW_BALANCE)
		transData->transState = DECLINED_INSUFFECIENT_FUND;

	else {
		accounts_database[i].balance -= transData->terminalData.transAmount;
		transData->transState = APPROVED;
	} 

	if (saveTransaction(transData) == SAVING_FAILED) {
		transData->transState = INTERNAL_SERVER_ERROR;
		printf("INTERNAL SERVER ERROR\n");
	}

	return transData->transState;
}
