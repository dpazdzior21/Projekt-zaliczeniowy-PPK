/** @file */
#ifndef STRUCTS_H
#define STRUCTS_H
#include <vector>
#include <string>
#include <climits>
struct City;

/** Struktura reprezentuj�ca jednokierunkowe po��czenie pomi�dzy dwoma miastami. */
struct Road
{
    City* from; ///< miasto pocz�tkowe
    City* to; ///< miasto ko�cowe
    int length; ///< d�ugo�� drogi
};

/** Struktura reprezentuj�ca miasto. */
struct City
{
    std::string name; ///< nazwa miasta
    std::vector<Road*> roads; ///< drogi wychodz�ce z miasta
    Road* previous = nullptr; ///< poprzednie miasto (u�ywane podczas wyszukiwania trasy)
    int total_length = INT_MAX; ///< odleg�o�� od miasta pocz�tkowego (u�ywane podczas wyszukiwania trasy)
};

/** Struktura reprezentuj�ca tras� do wyznaczenia. */
struct Path
{
    City* from; ///< pocz�tek wyszukiwanej trasy
    City* to; ///< koniec wyszukiwanej trasy
    std::vector<Road*>* roads; ///< kolejne drogi od miasta pocz�tkowego, prowadz�ce do miasta ko�cowego
};

#endif