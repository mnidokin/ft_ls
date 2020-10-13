/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:49:02 by mnidokin          #+#    #+#             */
/*   Updated: 2020/02/14 12:49:04 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"

# include <dirent.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <time.h>
# include <sys/types.h>
# include <sys/acl.h>
# include <sys/xattr.h>
# include <sys/time.h>
# include <stdlib.h>
# include <errno.h>
# include <unistd.h>

typedef enum			e_stat
{
	IS_NONEXIST = 1,
	IS_NOTDIR = 2,
	IS_DIR = 4,
	IS_LINK = 8,
	IS_UNREAD = 16,
}						t_stat;

typedef enum			e_flags
{
	LONG_LISTING_FLAG = 1,
	RECURSIVE_FLAG = 2,
	ALL_FLAG = 4,
	REVERSE_FLAG = 8,
	MODIFICATION_DATE_SORT = 16,
}						t_flags;

typedef struct			s_date
{
	char				*month;
	char				*day;
	char				*hour;
	char				*minute;
	char				*year;
	unsigned long long	sec;
	unsigned long long	nsec;
}						t_date;

typedef struct			s_file
{
	char				*name;
	long				link;
	char				*modes;
	char				*owner;
	char				*group;
	t_date				date;
	char				*dname;
	int					is_dir_info;
	int					device_file_flag;
	int					link_file_flag;
	int					nonprint_flag;
	int					size;
	unsigned int		user_id;
	unsigned int		group_id;
	int					status;
	struct s_file		*next;
	struct stat			file_info;
	long				major;
	long				minor;
	char				*link_name;
}						t_file;

typedef struct			s_dir
{
	char				*name;
	int					status;
	t_file				*files;
	t_file				*self;
	int					is_default;
	int					is_unread;
	int					valid_files;
	int					total_blocks;
	struct s_dir		*sub_dirs;
	struct s_dir		*next;
	t_date				date;
	char				*dname;
	int					device_file_flag_in;
}						t_dir;

char					*ft_pathjoin(char *p1, char *p2);
int						ft_strendswith(char *s1, char *s2);
char					*ft_path_to_obj_name(char *str);
int						ft_flag(char **av, t_flags *flag);
void					ft_flag_check(char *str, t_flags *flag);
void					ft_flag_set(char c, t_flags *flag);
t_dir					*ft_dir(char **av, t_flags flag);
t_dir					*ft_dir_new(char *path, char *sub_name,
						t_flags flag, int *stat_def);
t_dir					*ft_dir_subdir(t_dir *dir, t_dir **sub,
						t_flags flag);
void					ft_dir_init(t_dir *dir, int stat,
						char *path, char *sub_name);
void					ft_dir_av(char *str, t_dir **dir, char
						*sub_name, t_flags flag);
void					ft_dir_add(t_dir **dir, t_dir *new);
int						ft_dir_islast(t_dir *dir);
t_dir					*ft_dir_revers(t_dir *dir);
void					ft_dir_free(t_dir **dir);
t_dir					*ft_dir_mall(char *path);
void					ft_dir_mergesort(t_dir **dir, t_flags flag);
void					ft_dir_listsplit(t_dir *source, t_dir
						**front, t_dir **back);
t_dir					*ft_dir_sortedmerge(t_dir *a, t_dir *b, t_flags flag);
int						ft_dir_sort_alpha(t_dir *a, t_dir *b, t_flags flag);
t_file					*ft_file(t_dir *dir, t_flags flag);
void					ft_file_add(t_file **cur, t_dir **dir, t_flags flag);
void					ft_file_stat(t_file **cur, t_dir *dir, char *file);
void					ft_file_perm(t_file **cur, struct stat file_info);
void					ft_file_perm_extra(t_file **cur, struct stat file_info);
char					ft_file_objtype(int st_mode);
t_file					*ft_file_revers(t_file *file);
void					ft_file_nondir(t_dir	**dir, t_flags flag);
int						ft_file_islast(t_dir *file);
void					ft_file_free(t_file **file);
void					ft_file_chr_blk(t_file **cur,
						struct stat file_info, t_dir *dir);
void					ft_file_lnk(t_file **cur, char *file, char *buf);
char					*ft_file_filename(t_file **cur, char *name_dir);
void					ft_file_dname(struct dirent *dr, t_file **file);
int						ft_file_nonprint(char *str, int str_len);
char					*ft_displname(char *file_name, int len);
void					ft_file_date(t_date *file_date, struct stat file);
void					ft_file_mergesort(t_file **file_list, t_flags flag);
void					ft_file_split(t_file *src,
						t_file **front, t_file **back);
t_file					*ft_file_merge(t_file *a, t_file *b, t_flags flag);
int						ft_file_sort(t_file *a, t_file *b, t_flags flag);
void					ft_not_printf(t_flags flag, t_dir *dir);
void					ft_not_printf_dir(t_flags flag, t_dir *dir,
						t_dir **tmp);
void					ft_not_printf_ll(t_file *file);
void					ft_not_printf_date(t_date date);
void					ft_not_prints_nonexist(t_dir *dir);
void					ft_not_printf_nodir(t_dir *dir, t_flags flag);
void					ft_pr_minor_major(t_file *file);
void					ft_pr_size(t_file *file);
void					ft_pr_dt(t_file *file);
void					ft_pr_owner_group(t_file *file);
void					ft_pr_notdir(t_dir *tmp);
void					ft_pr_total(t_flags flag, t_file *tmp_file, t_dir *tmp);
int						ft_pr_unr_nonex(t_file *tmp_file);
void					ft_pr_nonll(t_file *tmp_file);
void					ft_pr_nondir(t_flags flag, t_file *tmp_file);
void					ft_error_nonexist(char *name);
void					ft_error_unread(char *name);
int						ft_error_lstat(char *file, t_file **cur);
void					ft_file_unreadname(t_dir **dir);
void					ft_matrix_free(char ***mat);
void					ft_file_date_parse(t_date *file_date, time_t timer);

#endif
