/***********************************************************************
* FILENAME :       main.c             
*
* DESCRIPTION :
*       A simple 537 version of the Linux ps command
*
*
*
* AUTHOR :    Jiwon Song  HyukJoon Yang   
*
*
*
**/

#include "psfind.h"

/*
 * Function: main
 * --------------------
 * This is the main function that receives user inputs and processes outputs
 *
 *  argc: number of arguments passed to the program
 *  argv: a pointer array that points to each argument passed to the program
 *  
 *
 *  returns: 0
 */

int main(int argc, char *argv[])
{
    
  /*
  parsing part
  */
  flags * flag = parseArgument(argc, argv);
  printf("pidflag: %d, stateflag: %d, stimeflag: %d, vmemflag: %d, utimeflag: %d, cmdflag: %d\n", flag->pidflag, flag->stateflag, flag->stimeflag,flag->vmemflag, flag->utimeflag, flag->cmdflag);
    
  /*
  reading part
  */
  
  if (flag->pidflag)
  {
      readPidandPrint(flag, flag->pid);
  }
  else {
      scanDirectory(flag);
      
  }
    
  free(flag);
  return 0;
}
