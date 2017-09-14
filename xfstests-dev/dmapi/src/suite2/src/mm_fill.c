/*
 * Copyright (c) 2000-2001 Silicon Graphics, Inc.
 * All Rights Reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it would be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write the Free Software Foundation,
 * Inc.,  51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */
/*
 *      mmap_fill
 * 
 *      use memory mapping to fill a filesystem! :)
 */
#include <stdio.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/fcntl.h>
#include <sys/stat.h>
#include <strings.h>
#include <errno.h>


char * progname;
int	fd;      		/* file descriptor */
addr_t	ptr;			/* mapped pointers */
off_t   off;
long long  junk[512] = { -1 };
long long counter;

main(int argc, char * argv[])
{ 
  int i;
  for (i=0; i<512; i++) junk[i]=-1;
  

  if ((progname = strrchr(argv[0], '/')) == NULL)
    progname = argv[0];
  else
    progname++;
  
  if (argc < 2) {
    fprintf(stderr,"Usage: %s filename\n", progname);
    exit(1);
  }
  
  fd = open(argv[1], O_RDWR|O_CREAT, 0644);
  if (fd < 0) {
    fprintf(stderr,"%s: cannot open %s\n", progname, argv[1]);
    perror(argv[1]);
    exit(3);
  }

  ptr = mmap64(NULL, (size_t)(0x10000000), PROT_WRITE, MAP_SHARED|MAP_AUTOGROW, fd, 0);
  if (ptr == MAP_FAILED) {
    fprintf(stderr,"%s: cannot mmap64 %s\n", progname, argv[1]);
    perror(argv[1]);
    exit(3);
  }
  
  for(counter=0; ; counter++) {
    junk[0] = counter;
    bcopy(junk, ptr, sizeof(junk));
    ptr+=sizeof(junk);
  }
  printf("%s complete.\n", progname);
  return 0;
}
