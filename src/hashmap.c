//! \file hashmap.c

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "hashmap.h"
#include "list.h"
#include "map.h"

static int hashmap_rehash(HashMap_t *map);

int hashmap_init(HashMap_t *map, size_t key_size, size_t val_size, float load_factor, int (*cmp)(void *, void *))
{
  // TODO: Initialize HashMap
  return 0;
}

int hashmap_deinit(HashMap_t *map)
{
  // TODO: Deinitialize HashMap
  return 0;
}

int hashmap_add(HashMap_t *map, void *key, void *val)
{
  // TODO: Add pair to HashMap
  return 0;
}

int hashmap_get(HashMap_t *map, void *key, void *val)
{
  // TODO: Get value corresponding to key from HashMap
  return 0;
}

int hashmap_rem(HashMap_t *map, void *key, void *val)
{
  // TODO: Remove value corresponding to key from HashMap
  return 0;
}

static int hashmap_rehash(HashMap_t *map)
{
  // TODO: Rehash HashMap
  return 0;
}

#ifdef __cplusplus
}
#endif
