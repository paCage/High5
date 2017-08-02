/*
 * read_h5attr.c
 * tests_file: read_h5attr_tests.c
 *
 * Retrieving one attribute from a group
 *
 * @param: fid: File identifier
 * @param: group_name:
 * @param: attr_name:
 * @param: dtype_id: Data type identifier from HDF5 lib
 * @param: dest: Pointer to the memory space to be filled
 *
 * @return: Standard EXIT_SUCCESS or EXIT_FAILURE
 */


#include <stdlib.h>
#include "./read_h5attr.h"


#ifndef PRINT
#define PRINT printf
#endif


int read_h5attr(hid_t fid, char *group_name, char *attr_name,
                hid_t dtype_id, void *dest)
{
  hid_t aid;
  hid_t gid = H5Gopen(fid, group_name, H5P_DEFAULT);

  int status = EXIT_SUCCESS;

  if(gid < 0)
    {
      H5Gclose(gid);
      PRINT("[Warning] Unable to open attribute %s\n", attr_name);
      status = EXIT_FAILURE;
    }

  aid = H5Aopen_name(gid, attr_name);

  if(aid < 0)
    {
      H5Gclose(gid);
      PRINT("[Warning] Unable to open attribute %s\n", attr_name);
      status = EXIT_FAILURE;
    }

  /* Handle string loading*/
  if(dtype_id == H5T_C_S1)
    {
      dtype_id = H5Tcopy(H5T_C_S1);
      H5Tset_size (dtype_id, H5T_VARIABLE);
    }

  if(H5Aread(aid, dtype_id, dest) < 0)
    {
      H5Aclose(aid);
      H5Gclose(gid);
      PRINT("[Warning] Unable to read attribute %s\n", attr_name);
      status = EXIT_FAILURE;
    }

  H5Aclose(aid);
  H5Gclose(gid);

  return status;
}