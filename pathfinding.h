/** @file */
#ifndef PATHFINDING_H
#define PATHFINDING_H
#include "structs.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>

/** Struktura zawiera funkcj� operator() wykorzystywan� do sortowania miast wed�ug ich odleg�o�ci od miasta startowego.*/
struct customComparator
{
    /**
    @param a pierwsze miasto
    @param b drugie miasto
    @return true, je�eli pierwsze miasto jest bli�ej miasta startowego.
    */
    bool operator() (const City* a, const City* b) const
    {
        return a->total_length < b->total_length;
    }
};

/** Funkcja zwraca miasto o podanej nazwie. Jezeli nie ma go w vectorze wej�ciowym, tworzy je.
@param cities vector z wszystkimi miastami
@param name nazwa miasta wyszukiwanego
@return wska�nik na wyszukiwane miasto
*/
City* get_or_add(std::vector<City*>* cities, std::string name);

/** Funkcja dodaje kolejne drogi mi�dzy miastami od miasta pocz�tkowego do miasta ko�cowego.
@param cities vector z wszystkimi miastami
@param path trasa dla kt�rej budowana jest �cie�ka
*/
void build_path(std::vector<City*>* cities, Path* path);

/** Funkcja zwraca drog� z path w formie tekstu.
@param path trasa z drog�
@return tekst zawieraj�cy plan trasy
*/
std::string get_path(Path* path);

/** Funkcja ustawia parametr total_length dla kazdego miasta w vectorze na INT_MAX. Jest to wymagane za ka�dym razem, gdy wyszukiwana jest nowa �cie�ka.
@param cities vector z wszystkimi miastami
*/
void reset_total_lengths(std::vector<City*>* cities);

/** Funkcja wyszukuje drog� algorytmem Dijkstry.
@param path trasa kt�ra ma by� wyznaczona
@return true, je�eli uda�o si� znale�� po��czenie, false je�eli nie
*/
bool dijkstra(Path* path);

/** Funkcja wyszukuje wszystkie wymagane po��czenia pomi�dzy miastami.
@param cities vector z wszystkimi miastami
@param paths vector z trasami do wyznaczenia
@return tekst zawieraj�cy rezultat wyszukiwania wszystkich tras
*/
std::string find_paths(std::vector<City*>* cities, std::vector<Path*>* paths);

#endif