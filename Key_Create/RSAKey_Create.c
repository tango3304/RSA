#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include <limits.h>
#include "RSA_HeaderFile/RSA_VariableDeclaration.h"// Variable Declaration
#define RandomNumber (rand() % 100000)

//########################
//Main_Process START
//########################
int main(){
    // FreeConsole(); //Console_Hide
    srand((unsigned)time(NULL));// Change Random Number Value

    // Multiple_START_Control
    hMSP = CreateMutex(NULL, TRUE, "DoubleStartPrevention");
    if(GetLastError() == ERROR_ALREADY_EXISTS){
        ReleaseMutex(hMSP);
        CloseHandle(hMSP);
        return FALSE;
    }

//########################
//RSA_KEY_CREATE START
//########################
    //=============================
    //PublicKey1_Value Create
    //=============================
    while(PublicKeyValue1_Create_Flag1 == 0){
        PublicKeyValue1_Create = RandomNumber;
        for(PrimeNumber = 2; PrimeNumber <= sqrt(PublicKeyValue1_Create); PrimeNumber++){
            PrimeNumber_TOTAL = PublicKeyValue1_Create % PrimeNumber;// 
            if(PrimeNumber_TOTAL == 0){
                PublicKeyValue1_Create_Flag1 = 0;
                break;
            }
            PublicKeyValue1_Create_Flag1 = 1;
        }
    }

    //=============================
    //PublicKey2_Value Create
    //=============================
    while(PublicKeyValue2_Create_Flag == 0){
        PublicKeyValue2_Create = RandomNumber;
        for(PrimeNumber = 2; PrimeNumber <= sqrt(PublicKeyValue2_Create); PrimeNumber++){
            PrimeNumber_TOTAL = PublicKeyValue2_Create % PrimeNumber;
            if(PrimeNumber_TOTAL == 0){
                PublicKeyValue2_Create_Flag = 0;
                break;
            }
            PublicKeyValue2_Create_Flag = 1;
        }
    }

    //=============================
    //PublicKey1 Create
    //=============================
    PublicKey1 = PublicKeyValue1_Create * PublicKeyValue2_Create;
    
    //====================================
    //PublicKeyPublicKey1_sub Create
    //====================================
    PublicKey1_sub = (PublicKeyValue1_Create - 1) * (PublicKeyValue2_Create- 1);

    //=============================
    //PublicKey2 Create
    //=============================
    while(PublicKey2_Flag == 0){
        PublicKey2 = RandomNumber;
        for(PrimeNumber = 2; PrimeNumber <= sqrt(PublicKey2); PrimeNumber++){
            PublicKey2_TOTAL = PublicKey2 % PrimeNumber;
            if(PublicKey2_TOTAL == 0){
                break;
            }
            PublicKey2_Flag = 1;
        }
    }

    //=============================
    //PrivateKey Create
    //=============================
    while(PrivateKey_Sub != 1){
        PrivateKey++;
        PrivateKey_TOTAL = PublicKey2 * PrivateKey;
        PrivateKey_Sub = PrivateKey_TOTAL % PublicKey1_sub;
    }

    //=============================
    //File Output
    //=============================
    PublicKey1_File = fopen(PublicKey1_PATH, "w");
    PublicKey2_File = fopen(PublicKey2_PATH, "w");
    PrivateKey_File = fopen(PrivateKey_PATH, "w");

    fprintf(PublicKey1_File, "%u", PublicKey1);
    fprintf(PublicKey2_File, "%u", PublicKey2);
    fprintf(PrivateKey_File, "%u", PrivateKey);

    fclose(PublicKey1_File);
    fclose(PublicKey2_File);
    fclose(PrivateKey_File);

printf("公開鍵１：%u\n", PublicKey1);
printf("公開鍵２：%u\n", PublicKey2);    
printf("秘密鍵　：%u\n", PrivateKey);
 
    //Multiple_START_Control（Release）
    ReleaseMutex(hMSP);
    CloseHandle(hMSP);
}
