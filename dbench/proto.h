#ifndef _PROTO_H_
#define _PROTO_H_

/* This file is automatically generated with "make proto". DO NOT EDIT */


/* The following definitions come from child.c  */

void child_run(struct child_struct *child0, const char *loadfile);

/* The following definitions come from dbench.c  */


/* The following definitions come from fileio.c  */

void nb_setup(struct child_struct *child);
void nb_unlink(struct child_struct *child, const char *fname, int attr, const char *status);
void nb_mkdir(struct child_struct *child, const char *dname, const char *status);
void nb_rmdir(struct child_struct *child, const char *fname, const char *status);
void nb_createx(struct child_struct *child, const char *fname, 
		uint32_t create_options, uint32_t create_disposition, int fnum,
		const char *status);
void nb_writex(struct child_struct *child, int handle, int offset, 
	       int size, int ret_size, const char *status);
void nb_readx(struct child_struct *child, int handle, int offset, 
	      int size, int ret_size, const char *status);
void nb_close(struct child_struct *child, int handle, const char *status);
void nb_rename(struct child_struct *child, const char *old, const char *new, const char *status);
void nb_flush(struct child_struct *child, int handle, const char *status);
void nb_qpathinfo(struct child_struct *child, const char *fname, int level, 
		  const char *status);
void nb_qfileinfo(struct child_struct *child, int handle, int level, const char *status);
void nb_qfsinfo(struct child_struct *child, int level, const char *status);
void nb_findfirst(struct child_struct *child, const char *fname, int level, int maxcnt, 
		  int count, const char *status);
void nb_cleanup(struct child_struct *child);
void nb_deltree(struct child_struct *child, const char *dname);
void nb_sfileinfo(struct child_struct *child, int handle, int level, const char *status);
void nb_lockx(struct child_struct *child, int handle, uint32_t offset, int size, 
	      const char *status);
void nb_unlockx(struct child_struct *child,
		int handle, uint32_t offset, int size, const char *status);
void nb_sleep(struct child_struct *child, int usec, const char *status);

/* The following definitions come from io.c  */

void do_unlink(char *fname);
void expand_file(int fd, int size);
void do_open(char *fname, int handle, int size);
void do_write(int handle, int size, int offset);
void do_read(int handle, int size, int offset);
void do_close(int handle);
void do_mkdir(char *fname);
void do_rmdir(char *fname);
void do_rename(char *old, char *new);
void do_stat(char *fname, int size);
void do_create(char *fname, int size);

/* The following definitions come from snprintf.c  */


/* The following definitions come from sockio.c  */

void nb_setup(struct child_struct *child);
void nb_unlink(struct child_struct *child, const char *fname, int attr, const char *status);
void nb_mkdir(struct child_struct *child, const char *dname, const char *status);
void nb_rmdir(struct child_struct *child, const char *fname, const char *status);
void nb_createx(struct child_struct *child, const char *fname, 
		uint32_t create_options, uint32_t create_disposition, int fnum,
		const char *status);
void nb_writex(struct child_struct *child, int handle, int offset, 
	       int size, int ret_size, const char *status);
void nb_readx(struct child_struct *child, int handle, int offset, 
	      int size, int ret_size, const char *status);
void nb_close(struct child_struct *child, int handle, const char *status);
void nb_rename(struct child_struct *child, const char *old, const char *new, const char *status);
void nb_flush(struct child_struct *child, int handle, const char *status);
void nb_qpathinfo(struct child_struct *child, const char *fname, int level, 
		  const char *status);
void nb_qfileinfo(struct child_struct *child, int handle, int level, const char *status);
void nb_qfsinfo(struct child_struct *child, int level, const char *status);
void nb_findfirst(struct child_struct *child, const char *fname, int level, int maxcnt, 
		  int count, const char *status);
void nb_cleanup(struct child_struct *child);
void nb_deltree(struct child_struct *child, const char *dname);
void nb_sfileinfo(struct child_struct *child, int handle, int level, const char *status);
void nb_lockx(struct child_struct *child, int handle, uint32_t offset, int size, 
	      const char *status);
void nb_unlockx(struct child_struct *child,
		int handle, uint32_t offset, int size, const char *status);
void nb_sleep(struct child_struct *child, int usec, const char *status);

/* The following definitions come from socklib.c  */

int open_socket_in(int type, int port);
int open_socket_out(const char *host, int port);
void set_socket_options(int fd, char *options);
int read_sock(int s, char *buf, int size);
int write_sock(int s, char *buf, int size);

/* The following definitions come from system.c  */

ssize_t sys_getxattr (const char *path, const char *name, void *value, size_t size);
ssize_t sys_fgetxattr (int filedes, const char *name, void *value, size_t size);
int sys_fsetxattr (int filedes, const char *name, const void *value, size_t size, int flags);

/* The following definitions come from tbench_srv.c  */


/* The following definitions come from util.c  */

void *shm_setup(int size);
void all_string_sub(char *s,const char *pattern,const char *insert);
BOOL next_token(char **ptr,char *buff,char *sep);
struct timeval timeval_current(void);
double timeval_elapsed(struct timeval *tv);
double timeval_elapsed2(struct timeval *tv1, struct timeval *tv2);
void msleep(unsigned int t);

#endif /*  _PROTO_H_  */
