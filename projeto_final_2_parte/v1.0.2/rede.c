/*
 * rede.c Version: 1.0.2
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
#include <ctype.h>
#include "rede.h"
#if defined(_WIN32)
#include <windows.h>
#define CLS "cls"//cls windows, clear linux
#elif defined(__linux__)
#include <unistd.h>
#define CLS "clear"//cls windows, clear linux
#endif

#define VERSION_SOFT 3
/*GetWrongWay*/

stations *create_station(void){ 
   stations *array = (stations*)malloc(sizeof(stations));
   printf("--------------Add Station to the server----------------\n");
   printf("Insert the station name: ");
   scanf(" %[^\n]s", array->station_name); /*GetWrongWay*/
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
	   printf("Are you sure do want to delete a station? [y/n]: ");
	   scanf(" %c", &out);
	   out = (char)toupper(out);
	   if (out == 'Y'){
		   printf("ID to delete: ");
		   scanf("%s", id);
		   for (int i = 0; i < 5; i++){
		        id[i] = (char)toupper(id[i]);
		   }
		   printf/*GetWrongWay*/("Are you sure do you want to delete id: %s? [y/n]: ", id);
		   scanf(" %c", &conf);
		   conf = (char)toupper(conf);
		   if (conf == 'Y'){
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
   fp = fopen(filename, "wb");
   /*GetWrongWay*/
   
   if(fp == NULL){
	   printf("Error, can't open the file");
   }
   else{
	   if (station != NULL){/*GetWrongWay*/
		   int version = VERSION_SOFT;
		   if (fwrite(&version, sizeof(int), 1, fp) != 1){
		   }
		   if (fwrite(&dim, sizeof(int), 1, fp) != 1){
		   }
		   
		   for (int i = 0; i < dim; i++){
			   printf("Saving station %d named %s, please wait!!\n", i+1, station[i]->station_name);
			   fwrite(station[i]->station_name, sizeof(char), 100, fp);
			   fwrite(station[i]->id, sizeof(char), 5, fp);
			   //sleep(1);
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
   fp = fopen(filename, "rb");
/*GetWrongWay*/
   if(fp == NULL){
	   printf("Error, can't open the file because file doesn't exist\n");
	   sleep(3);
   }
   else{	      /*GetWrongWay*/
	   if(input == NULL){
		   long int count = 0;
		   int version = 0;
		   if (fread(&version, sizeof(int),1, fp) != 1){
		      return NULL;
		   }
		   if (version != VERSION_SOFT){
			   printf("File not supported on this version\n");
			   sleep(2);
			   return NULL;
		   }
		   
	       if (fread(&count, sizeof(int),1, fp) != 1){
		      return NULL;
		   }
	       stations **load = (stations **)/*GetWrongWay*/malloc(sizeof(stations*) * count);
	       for(int i = 0; i < count; i++){   
			   stations *loady = (stations *)malloc(sizeof(stations));
			   load[i] = loady;
		   }
		   printf("---------------------Add Station to the server---------------------\n");
	 	   for(int i = 0; i < count;i++){
			   fread(load[i]->station_name, sizeof(char), 100, fp);
			   fread(load[i]->id, sizeof(char), 5, fp);/*GetWrongWay*/
			   printf("Adding station %d named %s to the server, please wait!!!\n", i+1, load[i]->station_name);
			   //sleep(1);
		   }
           printf("-------------------------------------------------------------------\n");
           sleep(2);
		   *dim = count;
		   fclose(fp);/*GetWrongWay*/
		   return load;
	   }
	   else{
		   char confirmation;
		   printf("Are you sure that you want to reload information from the disk? [Y/N]: ");
		   scanf(" %c", &confirmation);
		   confirmation = toupper(confirmation);
		   if (confirmation == 'Y'){
			   long int/*GetWrongWay*/ count = 0;
			   int version = 0;
			   if (fread(&version, sizeof(int),1, fp) != 1){
				  return NULL;
			   }
			   if (version != VERSION_SOFT){
				   printf("File not supported on this version\n");
				   sleep(2);
				   return input;
			   }
				if (fread(&count, sizeof(int),1, fp) != 1){
				  return NULL;
			   }/*GetWrongWay*/
				
			   stations **load = (stations **)realloc(input, sizeof(stations*) * count);
			   printf("-------------------Replace Station to the server-------------------\n");
			   for(int i = 0; i < count;i++){
				   fread(load[i]->station_name, sizeof(char), 100, fp);
				   fread(load[i]->id, sizeof(char), 5, fp);/*GetWrongWay*/
				   printf("Replacing station %d named %s, please wait!!!\n", i+1, load[i]->station_name);
				   sleep(1); 
			   } 
			   printf("-------------------------------------------------------------------\n");
			   sleep(2);/*GetWrongWay*/
			   *dim = count;
			   fclose(fp);
			   return load;
		   }
		   else{
			   printf("Operation cancelled!!\n");
			   sleep(2);
			   return input;
		   }   
       }
   }
}
/*GetWrongWay*/


//-----------------------------------------------------------------------Linhas----------------------------------------------------------------------


lines *create_line(){/*GetWrongWay*/
	lines *line = (lines*)malloc(sizeof(lines));
	
	line->head = NULL;
	line->tail = NULL;
	line->size = 0;
	
	return line;
}

lines **crt_line(lines **line, char *name_line, int *dimensition){
	int dim = *dimensition;
	if(line == NULL){
		lines **lin = (lines**)malloc(sizeof(lines*) * dim);
		lin[0] = create_line();
		strcpy(lin[0]->line, name_line);
		*dimensition = dim;
		return lin;
	}
	else{
		dim++;
		lines **lin = (lines**)realloc(line, sizeof(lines*) * dim);
		lin[dim-1] = create_line();
		strcpy(lin[dim-1]->line, name_line);
	    *dimensition = dim;
	    return lin;
	}
}

lines **delete_lines(lines **line, int num_line, int *dimensition){
	int count = *dimensition;
	char filename[100];
	sprintf(filename, "%s.txt", line[num_line]->line);
	remove(filename);
	destroy_line(line[num_line]);
	line[num_line] = NULL;
	for(int i = 0; i < count; i++){
		if(line[i] == NULL){
			for(int j = i; j < count; j++){
				line[j] = line[j+1];
			}
		}
	}
	count--;
	lines **del = (lines**)realloc(line, sizeof(lines*) * count);
	*dimensition = count;
	return del;
}

void add_line(lines *line, char *n_station, char *id_station, int reverse){/*GetWrongWay*/
  if(reverse){
		Node *newNode = (Node*)malloc(sizeof(Node));
		if (newNode == NULL)
			return;
		strcpy(newNode->linha.station_line.station_name, n_station);
	    strcpy(newNode->linha.station_line.id, id_station);
		newNode->next = NULL;
		// lista vazia
		if (line->head == NULL)
		{
			line->head = newNode;
			line->tail = newNode;
		}
		else
		{
			newNode->next = line->head;
			line->head = newNode;
		}
		line->size++;
  }
  else{
	  Node *newNode = malloc(sizeof(Node));
	  
	  if (newNode == NULL)
			return;
	  
	  strcpy(newNode->linha.station_line.station_name, n_station);
	  strcpy(newNode->linha.station_line.id, id_station);
	  newNode->next = NULL;
	  
	  if (is_empty(line))
	  {
		line->head = newNode;
		line->tail = newNode;
	  }
	  else
	  {
		line->tail->next = newNode;
		line->tail = newNode;
	  }
	  line->size++; 
  }
}

void rm_line(lines *line, int *status, char *id_station){/*GetWrongWay*/
	Node *aux, *aux1;
	if (line->head == NULL){
		*status = 0;
        return;
	}
	else
    {
        aux = line->head;
        if (strcmp(aux->linha.station_line.id, id_station) == 0)//verifica se id que esta na primeira posiçao corresponde ao id introduzido pelo utilizador.
        {
            if (line->head == line->tail)//verifica se o valor que esta na head e igual ao valor da tail. Se a tail for igual a head entao os valores sao colocados NULL e liberta a posicao de memoria auxiliar 
            {
                line->head = NULL;
                line->tail = NULL;
                free(aux);
            }
            else//O valor da head passa a ser o valor da head seguinte
            {
                line->head = line->head->next;
                free(aux);
            }
            line->size--;
            *status = 1;
            return;
        }/*GetWrongWay*/
        while (aux->next != NULL && strcmp(aux->next->linha.station_line.id, id_station) != 0){/*GetWrongWay*///Se o id nao estiver na head, entao passara por todos os nodes da lista a verificar se existe algum id igual ao que o utilizador inseriu.
            aux = aux->next;
		}
		if (aux->next != NULL){
			if (aux->next == line->tail){//Caso o proximo elemento seja a ultima posicao da lista, o elemento em questao passara a ser o ultimo elemento da lista
				line->tail = aux;
				free(aux->next);
				line->tail->next = NULL;
			}
			else{//Caso contrario, o elemento passara a ser o valor do proximo
				aux1 = aux->next;
				aux->next = aux->next->next;
				free(aux1);
			}
			*status = 1;
			line->size--;
			return;
		}
		else{
			*status = 0;
			return;
		}/*GetWrongWay*/
	}
}

int check_stations_line(lines *line, stations *station, int count){/*GetWrongWay*/
   Node *aux = line->head;
   while (aux != NULL){
	  for(int i = 0; i < count; i++){
        if(strcmp(aux->linha.station_line.id, station->id) == 0){
          return 1;
	    }
      }
      aux = aux->next;
   }
   return 0;
}

void destroy_line(lines *line){/*GetWrongWay*/
	Node *aux;
    aux = line->head;
    while(aux != NULL)
    {
        line->head = line->head->next;
        free(aux);
        aux = line->head;
    }
    free(line);
}/*GetWrongWay*/

int size(lines *line){/*GetWrongWay*/
   return line->size;
}

int is_empty(lines *line){
	return (line->size == 0);
}
/*GetWrongWay*/
/*lines_info peek(lines *line, int *status){
  if (is_empty(line))
  {
    *status = 0;
    return;
  }
  *status = 1;
  return line->head->linha;
}*/

void seek(lines *line){/*GetWrongWay*/
    Node *aux = line->head;
    int count = 0;
    printf("Estacoes disponiveis na: %s\n", line->line);
	while (aux != NULL){
		printf("Estacao %d: %s %s\n", ++count, aux->linha.station_line.station_name, aux->linha.station_line.id);
		aux = aux->next;
	}
}

int save_lines_file(lines **line, char *filename, int dimensition){/*GetWrongWay*/
	FILE *fp;
	fp = fopen(filename,"w");
	
	if (fp == NULL){
		return 0;
	}
	else{
		if (!fprintf(fp, "%d\n", dimensition))
			return 0;
		fclose(fp);

		if(line == NULL){
			return 0;
		}
		else{
			for(int i = 0; i < dimensition; i++){
				char file_line[100];
				sprintf(file_line, "%s.txt", line[i]->line);
				printf("Saving line to file: %s\n", file_line);
				fp = fopen(file_line, "w");
				if(fp == NULL){
					return 0;
				}/*GetWrongWay*/
				else{
					if (!fprintf(fp, "%s\n", line[i]->line))
						return 0;
					Node *aux = line[i]->head;
					while(aux != NULL){
						if (!fprintf(fp, "%s#%s\n", aux->linha.station_line.station_name, aux->linha.station_line.id))
							return 0;
						aux = aux->next;
					}
					printf("Line %s saved successfully\n", line[i]->line);
					fclose(fp);
					
					fp = fopen(filename, "a");
					
					fprintf(fp, "%s\n", file_line);
					
					fclose(fp);
				}/*GetWrongWay*/
			}
			return 1;	
		}
	}
}

lines **load_lines_file(lines **line, char *filename, int *dimensition){/*GetWrongWay*/
	FILE *fp;
	fp = fopen(filename, "r");
	
	if (fp == NULL){
		return NULL;
	}/*GetWrongWay*/
	else{
		int size = 0, count = 0;
		fscanf(fp, "%d", &size);
		char temp[size][100];
		
		while(fscanf(fp, "%s", temp[count])!=EOF)
			count++;
			
		fclose(fp);
		if (line == NULL){
			lines **out = (lines**)malloc(sizeof(lines*) * size);
			for(int i = 0; i < size; i++){
				fp = fopen(temp[i], "r");
				if (fp == NULL){
					return NULL;
				}/*GetWrongWay*/
				else{
					int inc = 0;
					count = 0;
					char ch;
					while(1){
						if (feof(fp)){
							break;
						}
						ch = fgetc(fp);
						if(ch == '\n'){
							count++;
						}
					}
					rewind(fp);
					
					char line_name[100];
					char temp_t[count][100];
					char stat[count][100];
					char statid[count][10];
					
					while (fgets(temp_t[inc], 100, fp) != NULL){/*GetWrongWay*/
						if (inc == 0){
							sep_string(temp_t[inc], stat[inc], line_name);
							printf("%s\n", line_name);
							out[i] = create_line();
							strcpy(out[i]->line, line_name);
						}
						else{
							sep_string(temp_t[inc], stat[inc], statid[inc]);
							printf("%s %s\n", stat[inc], statid[inc]);
							add_line(out[i], stat[inc], statid[inc], 0);/*GetWrongWay*/
						}
						inc++;
					}
				}
				printf("\n");
				fclose(fp);
			}
			*dimensition = size;
			return out;
		}/*GetWrongWay*/
		else{
			lines **out = (lines**)realloc(line, sizeof(lines*) * size);
			for(int i = 0; i < size; i++){
				fp = fopen(temp[i], "r");
				if (fp == NULL){
					return NULL;
				}
				else{
					int inc = 0;
					count = 0;
					char ch;
					while(1){
						if (feof(fp)){
							break;
						}
						ch = fgetc(fp);
						if(ch == '\n'){
							count++;
						}
					}
					rewind(fp);
					
					char line_name[100];
					char temp_t[count][100];
					char stat[count][100];
					char statid[count][10];
					
					while (fgets(temp_t[inc], 100, fp) != NULL){/*GetWrongWay*/
						if (inc == 0){
							sep_string(temp_t[inc], stat[inc], line_name);
							printf("%s\n", line_name);
							out[i] = create_line();
							strcpy(out[i]->line, line_name);
						}
						else{
							sep_string(temp_t[inc], stat[inc], statid[inc]);
							printf("%s %s\n", stat[inc], statid[inc]);
							add_line(out[i], stat[inc], statid[inc], 0);
						}
						inc++;
					}
				}
				printf("\n");
				fclose(fp);
			}
			*dimensition = size;
			return out;
		}
	}	
}/*GetWrongWay*/

void sep_string(char *input, char *output, char *output1){/*GetWrongWay*/
	int size = strlen(input), temp = 0;
	for (int i = 0; i < size; i++){
		if (input[i] == '#'){
			temp = i+1;
			for(int j = 0; j <= i; j++){
				if (j == i){
					output[j] = '\0';
				}
				else{
					output[j] = input[j];
				}
			}
		}
		else if(input[i] == '\n'){
			if(temp > 0){
				for(int j = temp; j <= i; j++){
					if(j == i){
						output1[j-temp] = '\0';
					}
					else{
						output1[j-temp] = input[j];
					}
				}
			}/*GetWrongWay*/
			else{
				for(int j = 0; j <= i; j++){
					if(j == i){
						output1[j] = '\0';
					}
					else{
						output1[j] = input[j];
					}
				}
			}
		}
	}
}

void route_calculation(lines **line, int dim, char *station_in, char *station_out){/*GetWrongWay*/
	Node *aux, *aux1;
	int n_linha_in = -1, n_linha_out = -1, block = 0, in = 0, out = 0, rin = 0, rout = 0, temp = 0;

	for(int i = 0; i < dim; i++){
		if (block)
			break;
		aux = line[i]->head;
		in = 0;
		while(aux != NULL){
			if (strcmp(aux->linha.station_line.station_name, station_in) == 0){
				n_linha_in = i;
				block = 1;
				break;
			}
			in++;
			aux = aux->next;
		}
	}
	if (!block){
		printf("Station name badly written!!!\n");
		return;
	}
	block = 0;
	for(int i = 0; i < dim; i++){
		if (block)
			break;
		aux1 = line[i]->head;
		out = 0;
		while(aux1 != NULL){
			if (strcmp(aux1->linha.station_line.station_name, station_out) == 0){
				n_linha_out = i;
				block = 1;
				break;
			}
			out++;
			aux1 = aux1->next;
		}/*GetWrongWay*/
	}
	if (!block){
		printf("Station name badly written!!!\n");
		return;
	}
	
	printf("You are at %s in the %s and you want to go to %s in the %s\n", station_in, line[n_linha_in]->line, station_out, line[n_linha_out]->line);
	
	lines *reverse_1 = reverse(line[n_linha_in]);
	lines *reverse_2 = reverse(line[n_linha_out]);
	
	Node *aux2_r = reverse_1->head;
	Node *aux3_r = reverse_2->head;
	
	while(aux2_r != NULL){
		//printf("%s\n", aux2_r->linha.station_line.station_name);
		if (strcmp(aux2_r->linha.station_line.station_name, station_in) == 0){
			break;
		}
		rin++;
		aux2_r = aux2_r->next;
	}
	
	while(aux3_r != NULL){
		//printf("%s\n", aux3_r->linha.station_line.station_name);
		if (strcmp(aux3_r->linha.station_line.station_name, station_out) == 0){
			break;
		}
		rout++;
		aux3_r = aux3_r->next;
	}
	
	printf("IN: %d,OUT: %d,RIN %d,ROUT %d, Size1: %d, Size2: %d\n\n", in, out, rin, rout, line[n_linha_in]->size, line[n_linha_out]->size);
	block = 0;
	//sleep(1);
	if (strcmp(line[n_linha_in]->line, line[n_linha_out]->line) == 0){
		if(rout > rin){
			aux2_r = reverse_1->head;
			while (aux2_r != NULL){	
				if (block){
					break;
				}		
				if (strcmp(aux2_r->linha.station_line.station_name,station_out) == 0){
					printf("%s\n", aux2_r->linha.station_line.station_name);
					block = 1;
					break;
				}
				if (!block){
					if(temp >= rin)
						printf("%s->", aux2_r->linha.station_line.station_name);
				}
				temp++;
				aux2_r = aux2_r->next;
			}
		}
		else{
			aux = line[n_linha_in]->head;
			while (aux != NULL){
				if (block){
					break;
				}			
				if (strcmp(aux->linha.station_line.station_name,station_out) == 0){
					printf("%s\n", aux->linha.station_line.station_name);
					block = 1;
					break;
				}
				if (!block){
					if(temp >= in)
						printf("%s->", aux->linha.station_line.station_name);
				}
				temp++;
				aux = aux->next;
			}
		}
	}
	else{
		if(in > rin){
			//Reverse path
			block = 0;
			aux2_r = reverse_1->head;
			while (aux2_r != NULL){
				if (block){
					break;
				}
				if (rout == 0){
					aux1 = line[n_linha_out]->head;
					while (aux1 != NULL){
						if (strcmp(aux2_r->linha.station_line.station_name,aux1->linha.station_line.station_name) == 0){
							while (aux1 != NULL){
								if (strcmp(aux1->linha.station_line.station_name, station_out) == 0){
										printf("%s\n", aux1->linha.station_line.station_name);
										block = 1;
										break;
									}
								printf("%s->", aux1->linha.station_line.station_name);
								aux1 = aux1->next;
							}
							block = 1;
							break;
						}
						aux1 = aux1->next;
					}
				}
				else if (out == 0){
					aux3_r = reverse_2->head;
					while (aux3_r != NULL){
						if (strcmp(aux2_r->linha.station_line.station_name,aux3_r->linha.station_line.station_name) == 0){
							while (aux3_r != NULL){
								if (strcmp(aux3_r->linha.station_line.station_name, station_out) == 0){
										printf("%s\n", aux3_r->linha.station_line.station_name);
										block = 1;
										break;
									}
								printf("%s->", aux3_r->linha.station_line.station_name);
								aux3_r = aux3_r->next;
							}
							block = 1;
							break;
						}
						aux3_r = aux3_r->next;
					}
				}
				else if (rout < (reverse_2->size/3) && out >= (line[n_linha_out]->size/2)){
					aux1 = line[n_linha_out]->head;
					while (aux1 != NULL){
						if (strcmp(aux2_r->linha.station_line.station_name,aux1->linha.station_line.station_name) == 0){
							while (aux1 != NULL){
								if (strcmp(aux1->linha.station_line.station_name, station_out) == 0){
										printf("%s\n", aux1->linha.station_line.station_name);
										block = 1;
										break;
									}
								printf("%s->", aux1->linha.station_line.station_name);
								aux1 = aux1->next;
							}
							block = 1;
							break;
						}
						aux1 = aux1->next;
					}
				}
				else if (rout >= (reverse_2->size/3) && out >= (line[n_linha_out]->size/2)){
					aux3_r = reverse_2->head;
					while (aux3_r != NULL){
						if (strcmp(aux2_r->linha.station_line.station_name,aux3_r->linha.station_line.station_name) == 0){
							while (aux3_r != NULL){
								if (strcmp(aux3_r->linha.station_line.station_name, station_out) == 0){
										printf("%s\n", aux3_r->linha.station_line.station_name);
										block = 1;
										break;
									}
								printf("%s->", aux3_r->linha.station_line.station_name);
								aux3_r = aux3_r->next;
							}
							block = 1;
							break;
						}
						aux3_r = aux3_r->next;
					}
				}
				else if (rout >= (reverse_2->size/3) && out <= (line[n_linha_out]->size/2)){
					aux3_r = reverse_2->head;
					while (aux3_r != NULL){
						if (strcmp(aux2_r->linha.station_line.station_name,aux3_r->linha.station_line.station_name) == 0){
							while (aux3_r != NULL){
								if (strcmp(aux3_r->linha.station_line.station_name, station_out) == 0){
										printf("%s\n", aux3_r->linha.station_line.station_name);
										block = 1;
										break;
									}
								printf("%s->", aux3_r->linha.station_line.station_name);
								aux3_r = aux3_r->next;
							}
							block = 1;
							break;
						}
						aux3_r = aux3_r->next;
					}
				}
				else if (rout >= (reverse_2->size/3)){
					aux3_r = reverse_2->head;
					while (aux3_r != NULL){
						if (strcmp(aux2_r->linha.station_line.station_name,aux3_r->linha.station_line.station_name) == 0){
							while (aux3_r != NULL){
								if (strcmp(aux3_r->linha.station_line.station_name, station_out) == 0){
										printf("%s\n", aux3_r->linha.station_line.station_name);
										block = 1;
										break;
									}
								printf("%s->", aux3_r->linha.station_line.station_name);
								aux3_r = aux3_r->next;
							}
							block = 1;
							break;
						}
						aux3_r = aux3_r->next;
					}
				}
				else if (rout <= (reverse_2->size/3)){
					aux1 = line[n_linha_out]->head;
					while (aux1 != NULL){
						if (strcmp(aux2_r->linha.station_line.station_name,aux1->linha.station_line.station_name) == 0){
							while (aux1 != NULL){
								if (strcmp(aux1->linha.station_line.station_name, station_out) == 0){
										printf("%s\n", aux1->linha.station_line.station_name);
										block = 1;
										break;
									}
								printf("%s->", aux1->linha.station_line.station_name);
								aux1 = aux1->next;
							}
							block = 1;
							break;
						}
						aux1 = aux1->next;
					}
				}
				
				if (!block){
					if (temp >= rin)
						printf("%s->", aux2_r->linha.station_line.station_name);
				}
				temp++;
				aux2_r = aux2_r->next;
			}
		}
		else{
		//None Reverse path
			block = 0;
			aux = line[n_linha_in]->head;
			while (aux != NULL){
				if (rout == 0){
					aux1 = line[n_linha_out]->head;
					while (aux1 != NULL){
						if (strcmp(aux->linha.station_line.station_name,aux1->linha.station_line.station_name) == 0){
							while (aux1 != NULL){
								if (strcmp(aux1->linha.station_line.station_name, station_out) == 0){
									printf("%s\n", aux1->linha.station_line.station_name);
									block = 1;
									break;
								}
								printf("%s->", aux1->linha.station_line.station_name);
								aux1 = aux1->next;
							}
							block = 1;
							break;
						}
						aux1 = aux1->next;
					}
				}
				else if (out == 0){
					aux3_r = reverse_2->head;
					while (aux3_r != NULL){
						if (strcmp(aux->linha.station_line.station_name,aux3_r->linha.station_line.station_name) == 0){
							while (aux3_r != NULL){
								if (strcmp(aux3_r->linha.station_line.station_name, station_out) == 0){
									printf("%s\n", aux3_r->linha.station_line.station_name);
									block = 1;
									break;
								}
								printf("%s->", aux3_r->linha.station_line.station_name);
								aux3_r = aux3_r->next;
							}
							block = 1;
							break;
						}
						aux3_r = aux3_r->next;
					}
				}
				else if (rout < (reverse_2->size/3) && out >= (line[n_linha_out]->size/2)){
					aux1 = line[n_linha_out]->head;
					while (aux1 != NULL){
						if (strcmp(aux->linha.station_line.station_name,aux1->linha.station_line.station_name) == 0){
							while (aux1 != NULL){
								if (strcmp(aux1->linha.station_line.station_name, station_out) == 0){
									printf("%s\n", aux1->linha.station_line.station_name);
									block = 1;
									break;
								}
								printf("%s->", aux1->linha.station_line.station_name);
								aux1 = aux1->next;
							}
							block = 1;
							break;
						}
						aux1 = aux1->next;
					}
				}
				
				else if (rout >= (reverse_2->size/3) && out >= (line[n_linha_out]->size/2)){
					aux3_r = reverse_2->head;
					while (aux3_r != NULL){
						if (strcmp(aux->linha.station_line.station_name,aux3_r->linha.station_line.station_name) == 0){
							while (aux3_r != NULL){
								if (strcmp(aux3_r->linha.station_line.station_name, station_out) == 0){
									printf("%s\n", aux3_r->linha.station_line.station_name);
									block = 1;
									break;
								}
								printf("%s->", aux3_r->linha.station_line.station_name);
								aux3_r = aux3_r->next;
							}
							block = 1;
							break;
						}
						aux3_r = aux3_r->next;
					}
				}
				
				else if (rout >= (reverse_2->size/3) && out <= (line[n_linha_out]->size/2)){
					aux3_r = reverse_2->head;
					while (aux3_r != NULL){
						if (strcmp(aux->linha.station_line.station_name,aux3_r->linha.station_line.station_name) == 0){
							while (aux3_r != NULL){
								if (strcmp(aux3_r->linha.station_line.station_name, station_out) == 0){
									printf("%s\n", aux3_r->linha.station_line.station_name);
									block = 1;
									break;
								}
								printf("%s->", aux3_r->linha.station_line.station_name);
								aux3_r = aux3_r->next;
							}
							block = 1;
							break;
						}
						aux3_r = aux3_r->next;
					}
				}
				else if (rout >= (reverse_2->size/3)){
					aux3_r = reverse_2->head;
					while (aux3_r != NULL){
						if (strcmp(aux->linha.station_line.station_name,aux3_r->linha.station_line.station_name) == 0){
							while (aux3_r != NULL){
								if (strcmp(aux3_r->linha.station_line.station_name, station_out) == 0){
									printf("%s\n", aux3_r->linha.station_line.station_name);
									block = 1;
									break;
								}
								printf("%s->", aux3_r->linha.station_line.station_name);
								aux3_r = aux3_r->next;
							}
							block = 1;
							break;
						}
						aux3_r = aux3_r->next;
					}
				}
				else if (rout <= (reverse_2->size/3)){
					aux1 = line[n_linha_out]->head;
					while (aux1 != NULL){
						if (strcmp(aux->linha.station_line.station_name,aux1->linha.station_line.station_name) == 0){
							while (aux1 != NULL){
								if (strcmp(aux1->linha.station_line.station_name, station_out) == 0){
									printf("%s\n", aux1->linha.station_line.station_name);
									block = 1;
									break;
								}
								printf("%s->", aux1->linha.station_line.station_name);
								aux1 = aux1->next;
							}
							block = 1;
							break;
						}
						aux1 = aux1->next;
					}
				}
				
				if (!block){
					if (temp >= in)
						printf("%s->", aux->linha.station_line.station_name);
				}
				temp++;
				aux = aux->next;
			}
		}
	}
	destroy_line(reverse_1);
	destroy_line(reverse_2);
	return;
}

lines *reverse(lines *line){
	Node *aux = line->head;
	lines *lin = (lines*)malloc(sizeof(lines));	
	while (aux != NULL){
		add_line(lin, aux->linha.station_line.station_name, aux->linha.station_line.id, 1);
		aux = aux->next;
	}
	return lin;
}

/*
 * 
 * aux3_r = reverse_2->head;
					while(aux3_r != NULL){
						if (strcmp(aux2_r->linha.station_line.station_name,aux3_r->linha.station_line.station_name) == 0){
							while(aux3_r != NULL){
								if (strcmp(aux3_r->linha.station_line.station_name, station_out) == 0){
									printf("%s\n", aux3_r->linha.station_line.station_name);
									block = 1;
									break;
								}
								printf("%s->", aux3_r->linha.station_line.station_name);
								aux3_r = aux3_r->next;
							}
							block = 1;
							break;
						}
						aux3_r = aux3_r->next;
					}
	aux1 = line[n_linha_out]->head;
					while(aux1 != NULL){
						if (strcmp(aux->linha.station_line.station_name,aux1->linha.station_line.station_name) == 0){
							while(aux1 != NULL){
								if (strcmp(aux1->linha.station_line.station_name, station_out) == 0){
									printf("%s\n", aux1->linha.station_line.station_name);
									block = 1;
									break;
								}
								printf("%s->", aux1->linha.station_line.station_name);
								aux1 = aux1->next;
							}
							block = 1;
							break;
						}
						aux1 = aux1->next;
					}				
					
					
					
					
					
					
					*/
