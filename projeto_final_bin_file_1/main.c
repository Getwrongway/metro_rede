/*
 * main.c
 * 
 * Copyright 2024 gwg nunomiguelornelas894@gmail.com
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>/*GetWrongWay*/
#include <time.h>
#include "rede.h"
#if defined(_WIN32)
#include <windows.h>
#define CLS "cls"//cls windows, clear linux
#elif defined(__linux__)
#include <unistd.h>
#define CLS "clear"//cls windows, clear linux
#endif



int main(void){/*GetWrongWay*/
  int menu_0 = 0, menu_1 = 0, menu_2 = 0;
  char filename[] = "rede_metro.bin";
  srand(time(0));
  int dimensition = 1;
  stations **saved_stations = NULL;
  system(CLS);
  printf("--------------Rede Metro--------------\n");
  printf("--------Loading, please wait!---------\n");
  printf("--------------------------------------\n");
  sleep(2);
  system(CLS); 
  saved_stations = load_stations_file(saved_stations, filename, &dimensition);
  while(1){
    if (menu_0 == 1){
       system(CLS);
       if(menu_1 == 1){
		 //execute function to add stations
		 if (saved_stations == NULL){/*GetWrongWay*/
		   saved_stations = add_station(dimensition);
		   menu_0 = 1;
		   menu_1 = 0;
		 }
		 else{
		   saved_stations = alter_station(saved_stations, &dimensition); 
		   menu_0 = 1;
		   menu_1 = 0;
		 }
       }
       else if (menu_1 == 2){/*GetWrongWay*/
		 //execute function to remove stations
		 char del;
		 system(CLS);
		 saved_stations = delete_station(saved_stations, &dimensition);
		 menu_0 = 1;
	     menu_1 = 0;
       }
       else if (menu_1 == 3){/*GetWrongWay*/
		 //execute function to print stations
		 char cont;
		 system(CLS);
		 print_stations(saved_stations, dimensition);
		 printf("Add new station?(y/n)\n");
		 scanf(" %c", &cont);
		 if(cont == 'y'){
		     menu_0 = 1;
		     menu_1 = 1;
		 }
		 else{
			 menu_0 = 1;
			 menu_1 = 0;
		 }
       }
       else if(menu_1 == 4){/*GetWrongWay*/
	      // save variables to file
	      system(CLS);
	      save_stations_file(saved_stations, filename, dimensition);
	      menu_0 = 1;
	      menu_1 = 0;
       }
       else if(menu_1 == 5){/*GetWrongWay*/
	      // load variables on file
	      system(CLS);
	      saved_stations = load_stations_file(saved_stations, filename, &dimensition);
	      menu_0 = 1;
	      menu_1 = 0;
       }
       else if(menu_1 == 6){/*GetWrongWay*/
	      // back to main menu
	      menu_0 = 0;
	      menu_1 = 0;
       }
       else{
		  system(CLS);
		  printf("-----------------MENU-------------------\n");
		  printf("1-Add stations\n2-Delete stations\n3-Print stations\n4-Save stations\n5-Load stations\n6-Back Main Menu\n");
		  printf("----------------------------------------\n");
		  printf("Option: ");
		  scanf("%d", &menu_1);/*GetWrongWay*/
	   }      
    }
    else if(menu_0 == 2){
       system(CLS);
       
       if(menu_2 == 1){/*GetWrongWay*/
	 //execute function to add lines
	     menu_0 = 2;
     	 menu_2 = 0;
       }
       else if (menu_2 == 2){
	 //execute function to remove lines
	     menu_0 = 2;
     	 menu_2 = 0;
       }
       else if (menu_2 == 3){/*GetWrongWay*/
         //execute function to print lines
         menu_0 = 2;
     	 menu_2 = 0;
       }
       else if (menu_2 == 4){
	 //back to main menu
     	 menu_0 = 0;
     	 menu_2 = 0;
       }
       else{
		   printf("-----------------MENU-------------------\n");
		   printf("1-Add lines\n2-Delete lines\n3-Print lines\n4-Back Main Menu\n");
		   printf("----------------------------------------\n");
		   printf("Option: ");
		   scanf("%d", &menu_2);
	   }       
    }
    else if (menu_0 == 3){/*GetWrongWay*/
       break;
    }
    else{
      system(CLS);
      printf("------------------MENU------------------\n");
      printf("1-Manage stations\n2-Manage lines\n3-Exit\n");
      printf("----------------------------------------\n");
      printf("Option: ");
      scanf("%d", &menu_0);
    }
  }/*GetWrongWay*/
  system(CLS);
  printf("----Saving stations before closing the program----\n");
  save_stations_file(saved_stations, filename, dimensition);
  printf("--------------------------------------------------\n");
  sleep(1);
  free(saved_stations);
  system(CLS);
  printf("Hope to see you soon\nBYE!\n");
  return 0;
}
