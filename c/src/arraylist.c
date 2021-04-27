/*! \file arraylist.c
 *  \brief ArrayList Implementation
 */

#include "arraylist.h"

#include <stdlib.h>
#include <string.h>

int arraylist_init(ArrayList_t *list, int length, size_t element_size)
{
  if (list == NULL)
    return -1;

  list->capacity = length;
  list->size = 0;
  list->elem_size = element_size;

  list->data = malloc(length * element_size);

  if (list->data == NULL)
    return -1;

  list->first = list->data;
  list->last = list->data;

  return 0;
}

int arraylist_deinit(ArrayList_t *list)
{
  if (list == NULL || list->data == NULL)
    return -1;

  free(list->data);
  list->capacity = 0;
  list->size = 0;
  list->elem_size = 0;
  list->first = NULL;
  list->last = NULL;

  return 0;
}

int arraylist_add(ArrayList_t *list, void *element)
{
  if (list == NULL || list->data == NULL)
    return -1;

  if (list->size >= list->capacity)
  {
    if (arraylist_resize(list) < 0)
      return -1;
  }

  memcpy(list->data[list->size++], element, list->elem_size);
  return 0;
}

int arraylist_insert(ArrayList_t *list, int i, void *element)
{
  if (list == NULL || list->data == NULL)
    return -1;

  if (i < 0 || i > list->size)
    return -1;

  if (list->size >= list->capacity)
  {
    if (arraylist_resize(list) < 0)
      return -1;
  }

  if (list->data[i] != NULL)
  {
    int j;
    for (j = list->size; j > i; j--)
      list->data[j] = list->data[j - 1];
  }

  memcpy(list->data[i], element, list->elem_size);
  list->size++;
  return 0;
}

int arraylist_set(ArrayList_t *list, int i, void *element, void *out)
{
  if (list == NULL || list->data == NULL || out == NULL)
    return -1;

  if (i < 0 || i > list->size)
    return -1;

  if (list->size >= list->capacity)
  {
    if (arraylist_resize(list) < 0)
      return -1;
  }

  memcpy(out, list->data[i], list->elem_size);
  memcpy(list->data[i], element, list->elem_size);
  return 0;
}

int arraylist_remove(ArrayList_t *list, int i, void *out)
{
  if (list == NULL || list->data == NULL || out == NULL)
    return -1;

  if (i < 0 || i >= list->size)
    return -1;

  memcpy(out, list->data[i], list->elem_size);

  int j;
  for (j = i; j < list->size - 1; j++)
  {
    list->data[j] = list->data[j + 1];
  }

  return 0;
}

static int arraylist_resize(ArrayList_t *list)
{
  void **tmp = realloc(list->data, 2 * list->capacity * list->elem_size);
  if (tmp == NULL)
    return -1;

  list->data = tmp;
  return 0;
}
