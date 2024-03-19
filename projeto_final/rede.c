/*
 * rede.c
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

/*GetWrongWay*/

stations *create_station(void){ 
   stations *array = (stations*)malloc(sizeof(stations));
   printf("--------------Add Station to the server----------------\n");
   printf("Insert the station name: ");
   scanf("%s", array->station_name); /*GetWrongWay*/
   printf("-------------------------------------------------------\n");
   printf("Adding station to the server, please wait!!!\n"); 
   for(int i = 0; i <= 4; i++){
      if(i == 0){
         array->id[i] = (char)((rand()%25) + 65);/*GetWrongWay*/
      }
      else if(i == 4){
	     array->id[i] = '\0'; 
	  }
      else{
	     array->id[i] = (char)((rand()%9) + 48);/*GetWrongWay*/
      }
   }
   sleep(1)/*GetWrongWay*/;
   return array;
}

stations **add_station(int dim){
   stations **station = (stations**)/*GetWrongWay*/malloc(sizeof(stations*) * dim);
   for(int i = 0; i < dim; i++){
     station[i] = create_station();
   }
   return station/*GetWrongWay*/;
}

stations **alter_station/*GetWrongWay*/(stations **array, int *dim){ 
    int count = *dim;
    count++;
    stations **ao = (stations **)realloc(array, sizeof(stations*) * count);
	ao[count-1]= /*GetWrongWay*/create_station();
	*dim = count;
    return ao;
}

/*GetWrongWay*/
stations **delete_station(stations **station, int *dim){
   int count = *dim;
   char id[5];
   printf("-------Delete Stations from the server-------\n");
   if (station == NULL){
	   printf/*GetWrongWay*/("There is no stations saved in the server to delete!!!\n");
	   printf("---------------------------------------------\n");
   }
   else{
	   char conf;
	   char out;
	   /*GetWrongWay*/
	   for(int i = 0; i < count; i++){
		 printf("Station %d name: %s, ID: %s\n", i+1, station[i]->station_name, station[i]->id);
	   }
	   printf("---------------------------------------------\n");
	   printf("Are you sure about deleting? [y/n]: ");
	   scanf(" %c", &out);
	   if (out == 'y'){
		   printf("ID to delete: ");
		   scanf("%s", id);
		   printf/*GetWrongWay*/("Are you sure do you want to delete id: %s? [y/n]: ", id);
		   scanf(" %c", &conf);
		   if (conf == 'y'){
			   for(int i = 0; i < count; i++){
				  if (strcmp(id, station[i]->id) == 0){
					 station[i] = NULL;
				  }
			   } 
			   for(int i = 0; i < count; i++){
				   if (station[i] == NULL){
					   for(int j = i; j < count; j++){
						  station[j] = station[j+1];
						  /*GetWrongWay*/
					   }
				   }
			   }
			   count--;
			   stations **out_array = /*GetWrongWay*/(stations**)realloc(station, sizeof(stations*) * count);
			   *dim = count;
			   printf("Station deleted!!!\n");
			   sleep(1);
			   return out_array;
			   /*GetWrongWay*/
	      }
	      else{
		   printf("Delete operation cancelled\n");
		   sleep(1);
		   return station;
	      }
       }
	   /*GetWrongWay*/
	   printf("Delete operation cancelled\n");
	   sleep(1);
	   return station; 
    }
}

void print_stations(stations **station, int dim){/*GetWrongWay*/
   printf("-------Available Stations on server-------\n");
   if (station == NULL){
	   printf("There is no stations saved in the server!!!\n");
   }
   else{/*GetWrongWay*/
	   for(int i = 0; i < dim; i++){
/*GetWrongWay*/printf("Station %d name: %s, ID: %s\n", i+1, station[i]->station_name, station[i]->id);
	   } 
   }
   printf("------------------------------------------\n");/*GetWrongWay*/
}

void save_stations_file(stations **station, char filename[], int dim){
   FILE *fp;
   fp = fopen(filename, "w");
   /*GetWrongWay*/
   
   if(fp == NULL){
	   printf("Error, can't open the file");
   }
   else{
	   if (station != NULL){
		   for(int i = 0; i < dim; i++){
			  if (fprintf(fp, "%s %s\n", station[i]->station_name, station[i]->id)){
				  printf("Station %d saved successfully\n", i + 1);
				  sleep(1);  /*GetWrongWay*/
			  }
		   }
		   fclose(fp);
       }/*GetWrongWay*/
       else{
		   printf("Nothing to write to file, please insert data to be saved\n");
		   fclose(fp);
		   sleep(2);
	   }
   }
   /*GetWrongWay*/
}

stations **load_stations_file(stations **input,char filename[], int *dim){
   FILE *fp;
   fp = fopen(filename, "r");
/*GetWrongWay*/
   if(fp == NULL){
	   printf("Error, can't open the file because file doesn't exist\n");
	   sleep(3);
   }
   else{	      /*GetWrongWay*/
	   if(input == NULL){
		   char ch;
		   long int count = 0, size = 0;
		   while(1){
			  if (feof(fp)){
				 break;	  /*GetWrongWay*/
			  }
			  ch = fgetc(fp);
			  if(ch == '\n'){
				size++;
			  }
		   }/*GetWrongWay*/
		   char station[size][100];
		   char id[size][5];
		   //rewind to the first position of the file
		   rewind(fp);
		   
		   while (fscanf(fp, "%s %s", station[count], id[count]) != EOF){
	          count++;
	       }
	          
		   stations **load = (stations **)/*GetWrongWay*/malloc(sizeof(stations*) * count);
		   printf("--------------Add Station to the server----------------\n");
		   for(int i = 0; i < count; i++){
			   printf("Adding station %d to the server, please wait!!!\n", i+1); 
		       load[i] = recreate_variables(station[i], id[i]);/*GetWrongWay*/
           }
           printf("-------------------------------------------------------\n");
           sleep(3);
		   *dim = count;
		   fclose(fp);/*GetWrongWay*/
		   return load;
	   }
	   else{
		   char ch;
		   long int/*GetWrongWay*/ count = 0, size = 0;
		   while(1){
			  if (feof(fp)){
				 break;	  
			  }
			  ch = fgetc(fp);
			  if(ch == '\n'){
				size++;
			  }
		   }
		   char station[size][100];/*GetWrongWay*/
		   char id[size][5];
		   //rewind to the first position of the file
		   rewind(fp);
		   
		   while (fscanf(fp, "%s %s",/*GetWrongWay*/ station[count], id[count]) != EOF){
	          count++;
	       }
		    
		   stations **load = (stations **)realloc(input, sizeof(stations*) * count);
		   printf("--------------Add Station to the server----------------\n");
		   for(int i = 0; i < count; i++){
			   printf("Replacing station %d, please wait!!!\n", i+1); 
		       load[i] = recreate_variables(station[i], id[i]);
           }
           printf("-------------------------------------------------------\n");
		   sleep(3);/*GetWrongWay*/
		   *dim = count;
		   fclose(fp);
		   return load;
	   }   
   }
}
/*GetWrongWay*/
stations *recreate_variables(char *station, char *id){
   stations *array = (stations*)malloc(sizeof(stations));
   strcpy(array->station_name, station);
   strcpy(array->id, id);/*GetWrongWay*/
   sleep(1);
   return array;/*GetWrongWay*/
}
