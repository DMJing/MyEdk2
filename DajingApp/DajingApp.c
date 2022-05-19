/** @file
  This is a test application that demonstrates how to use the C-style entry point
  for a shell application.

  Copyright (c) 2009 - 2015, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include <string.h>
#include <unistd.h>
#include <Uefi.h>
#include <Library/UefiLib.h>
#include <Library/DebugLib.h>
#include <Library/ShellCEntryLib.h>
#include <Library/SortLib.h>
#include <stdio.h>
#include <../Library/TimerLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/IoLib.h> 
/**
  Test comparator.

  @param[in] b1   The first INTN
  @param[in] b2   The other INTN

  @retval 0       They are the same.
  @retval -1      b1 is less than b2
  @retval 1       b1 is greater then b2
**/
INTN
EFIAPI
Test (
  CONST VOID  *b1,
  CONST VOID  *b2
  )
{
  if (*(INTN *)b1 == *(INTN *)b2) {
    return (0);
  }

  if (*(INTN *)b1 < *(INTN *)b2) {
    return (-1); 
  }


  return (1);
}

BOOLEAN Test1()
{
  Print(L"hello Test1\r\n");
  return TRUE;
}
BOOLEAN Test2()
{
  Print(L"hello Test2\r\n");
  return TRUE;
}
typedef struct{
	char	 cmd_name[128];//name of your test command	
  BOOLEAN (*test_func)();
	char     help[200];
}CMD_INFO;

CMD_INFO MT86FuncList[]={
  {"addrtest", Test1, "help addrtest"},
  {"addrtest2", Test2, "help addrtest2"}

};




// ****************************** 配置 ***************************
// 最后100%时的输出形式  
const char LastStr[] = "[--------------------] 100% "; 

// 进度条标志，可以改用"*"或其它符号
const char ProgressIcon = '-'; 

// 进度每加5，进度条就会加一格，注意Step值要和LastStr中的"-"数量相匹配，两者相乘等于100
const int Step = 5; 

// 总共需要多少进度标志，即LastStr中"-"的数量
const int IconMaxNum = 20; 

// 每隔100ms打印一次，这里同时每隔100ms会让进度加1
const int PrintInterval = 100000; 
// ****************************************************************


// main函数
int main123(void)
{
    Print(L"\r\n Output recorded data: ");
    
    for (int i = 0; i <= 100; ++i)
    {
        // -------------- 打印进度条 --------------
        Print(L"[");
        int currentIndex = i / Step;
        for (int j = 0; j < IconMaxNum; ++j)
        {
            if (j < currentIndex)
            {
                Print(L"%c", ProgressIcon); // 打印进度条标志
            }
            else
            {
                Print(L" "); // 未达进度则打印空格
            }
        }
        
        Print(L"] ");
        // ----------------------------------------

        // -------- 打印数字进度 ----------
        Print(L"%3d%%", i);
        //delay
        MicroSecondDelay(1000000);
        //gST->ConOut->ClearScreen(gST->ConOut); 
        
        for (int j = 0; j < sizeof(LastStr)-2; ++j)
        {
            Print(L"\b"); // 回删字符，让数字和进度条原地变化
        }
        
        //gST->ConOut->ClearScreen(gST->ConOut); 
    }
    
    Print(L"\n\n");
    
    return 0;
}

/**
  UEFI application entry point which has an interface similar to a
  standard C main function.

  The ShellCEntryLib library instance wrappers the actual UEFI application
  entry point and calls this ShellAppMain function.

  @param[in] Argc     The number of items in Argv.
  @param[in] Argv     Array of pointers to strings.

  @retval  0               The application exited normally.
  @retval  Other           An error occurred.

**/
INTN
EFIAPI
ShellAppMain (
  IN UINTN   Argc,
  IN CHAR16  **Argv
  )
{

  Print(L"123\r\n");
  main123();
  return 0;
}
