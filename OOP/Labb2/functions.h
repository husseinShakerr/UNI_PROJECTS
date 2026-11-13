/**
 * Namn: Hussein Alshaikhshaker
 * Datum: 02 Maj 2024
 * Kurs: DT019G/DT026G
 * Laboration: Doubly linked list(Labb2)
 * Fil: functions header fil
*/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "linked_list.h"
void pushBackValues(linked_list&);
void pushFrontValues(linked_list&);
void print_list(linked_list);
linked_list merge(linked_list&, linked_list&);
bool is_sorted(linked_list&);
linked_list& smaller_list(linked_list&, linked_list&);
#endif