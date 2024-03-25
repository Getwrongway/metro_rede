/*
 * rede.h
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

#ifndef REDE_H
#define REDE_H
/*GetWrongWay*/
typedef struct{
  char station_name[100];
  char id[5];
}stations;

/*GetWrongWay*/
//prototipos 
stations *create_station(void);
stations **add_station(int dim);
stations **alter_station(stations **array, int *dim);
stations **delete_station(stations **station, int *dim);
void print_stations(stations **station, int dim);
void save_stations_file(stations **station, char filename[], int dim);
stations **load_stations_file(stations **input, char filename[], int *dim);

/*GetWrongWay*/

#endif
