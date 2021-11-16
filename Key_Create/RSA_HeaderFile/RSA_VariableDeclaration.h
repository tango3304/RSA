#ifndef PublicKey_IncludeGuard
#define PublicKey_IncludeGuard

//Variable Declaration
//=======================
//RSAKey_Create.c
//=======================
/*Multiple_START_Control_Handle*/
HANDLE hMSP;

/*PublicKey1_Value Create*/
unsigned int PublicKeyValue1_Create = 0;
int PublicKeyValue1_Create_Flag1 = 0;
int PrimeNumber, PrimeNumber_TOTAL;

/*PublicKey2_Value Create*/
unsigned int PublicKeyValue2_Create = 0;
int PublicKeyValue2_Create_Flag = 0;

/*PublicKey1 Create & PublicKeyPublicKey1_sub Create*/
unsigned int PublicKey1, PublicKey1_sub;

/*PublicKey2 Create*/
unsigned int PublicKey2, PublicKey2_TOTAL = 0;
int PublicKey2_Flag = 0;

/*PrivateKey Create*/
unsigned int PrivateKey, PrivateKey_Sub, PrivateKey_TOTAL = 0;

/*File Output*/
FILE *PublicKey1_File;
FILE *PublicKey2_File;
FILE *PrivateKey_File;
char PublicKey1_PATH[]= "RSA_TestFile/PublicKey1.txt";
char PublicKey2_PATH[]= "RSA_TestFile/PublicKey2.txt";
char PrivateKey_PATH[]= "RSA_TestFile/PrivateKey.txt";

#endif // PublicKey_IncludeGuard
