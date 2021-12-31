/*! \file       vla.h
 *  \brief      VLA definition and manipulation functions.
 *  \author     Brian Reece
 *  \version    v0.3-alpha
 */
#ifndef VLA_H
#define VLA_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

//! \brief VLA struct definition.
typedef struct vla {
  unsigned long size;      //!< VLA size.
  unsigned long capacity;  //!< VLA capacity.
  size_t element_size;     //!< VLA element size.
  void *elements;          //!< VLA elements.
} vla_t;

/*! \brief VLA construction function.
 *  \details This function creates a VLA of a given size and element size.
 *  \param[in] vla VLA to create.
 *  \param[in] size VLA size.
 *  \param[in] element_size VLA element size.
 *  \param[in] initial_capacity VLA initial capacity.
 *  \return Zero on success, non-zero on failure.
 */
int vla_init(vla_t *vla, const size_t element_size,
             const long initial_capacity);

/*! \brief VLA destruction function.
 *  \details This function destroys a VLA.
 *  \param[in] vla VLA to destroy.
 *  \return Zero on success, non-zero on failure.
 */
int vla_deinit(vla_t *vla);

/*! \brief VLA push function.
 *  \details This function pushes an element onto the VLA.
 *           Time complexity on the order of O(n).
 *  \param[in] vla VLA to push to.
 *  \param[in] element Element to push.
 *  \return Zero on success, non-zero on failure.
 */
int vla_push(vla_t *vla, const void *element);

/*! \brief VLA pop function.
 *  \details This function pops an element from the VLA.
 *           Time complexity on the order of O(n).
 *  \param[in] vla VLA to pop from.
 *  \param[out] element Element to pop.
 *  \return Zero on success, non-zero on failure.
 */
int vla_pop(vla_t *vla, void *element);

/*! \func vla_enq
 *  \brief VLA enqueue function.
 *  \details This function enqueues an element onto the VLA.
 *           Time complexity on the order of O(1).
 *  \param[in] vla VLA to resize.
 *  \param[in] size New VLA size.
 *  \return Zero on success, non-zero on failure.
 */
int vla_enq(vla_t *vla, const void *element);

/*! \brief VLA get function.
 *  \details This function gets an element from the VLA.
 *  \param[in] vla VLA to get from.
 *  \param[in] index Index of element to get.
 *  \param[out] element Element to get.
 *  \return Zero on success, non-zero on failure.
 */
int vla_get(const vla_t *vla, const long index, void *element);

/*! \brief VLA get pointer function
 *  \details This function gets the pointer to an element in the VLA.
 *  \param[in] vla VLA to get from
 *  \param[in] index Index of element to get.
 *  \param[out] element Element to get
 *  \return Zero on success, non-zero on failure
 */
int vla_getp(const vla_t *vla, const long index, void **element);

/*! \brief VLA set function.
 *  \details This function sets an element in the VLA.
 *  \param[in] vla VLA to set in.
 *  \param[in] index Index of element to set.
 *  \param[in] element Element to set.
 *  \return Zero on success, non-zero on failure.
 */
int vla_set(vla_t *vla, const long index, const void *element);

/*! \brief VLA insert function.
 *  \details This function inserts an element into the VLA.
 *           Time complexity on the order of O(n).
 *  \param[in] vla VLA to insert into.
 *  \param[in] index Index to insert at.
 *  \param[in] element Element to insert.
 *  \return Zero on success, non-zero on failure.
 */
int vla_ins(vla_t *vla, const long index, const void *element);

/*! \brief VLA delete function.
 *  \details This function deletes an element from the VLA. Time complexity on
 * the order of O(n).
 * \param[in] vla VLA to delete from.
 * \param[in] index Index
 * of element to delete. \return Zero on success, non-zero on failure.
 */
int vla_del(vla_t *vla, const long index);

/*! \brief VLA clear function.
 *  \details This function clears the VLA.
 *  \param[in] vla VLA to clear.
 *  \return Zero on success, non-zero on failure.
 */
int vla_clear(vla_t *vla);

/*! \brief VLA extend function
 *  \details This function appends the element of VLA src to dest.
 *  \param[out] dest The destination VLA
 *  \param[in] src The source VLA
 *  \return Zero on success, non-zero on failure.
 */
int vla_ext(vla_t *dest, const vla_t *src);

/*! \brief VLA size function.
 *  \details This function returns the VLA size.
 *  \param[in] vla VLA to get size of.
 *  \return VLA size.
 */
extern long vla_size(const vla_t *vla);

/*! \brief VLA capacity function.
 *  \details This function returns the VLA capacity.
 *  \param[in] vla VLA to get capacity of.
 *  \return VLA capacity.
 */
extern long vla_capacity(const vla_t *vla);

#ifdef __cplusplus
}
#endif

#endif  // VLA_H
