#ifndef __FUNC_FILE_H__
#define __FUNC_FILE_H__

int merge_file(char *f1_name, char *f2_name, char *f_out_name);
int split_file(FILE *fp, char *radice, int dim);
int concat_file(char *radice, int n_split);

#endif
