/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:56:53 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/03/31 14:40:53 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include	<stdlib.h>
# include	<stdio.h>
# include	<unistd.h>
# include	"./../arevik/include/readline/history.h"
# include	"./../arevik/include/readline/readline.h"
# include	<fcntl.h>
# include	<errno.h>
# include	<limits.h>
# include	<sys/ioctl.h>
# include	<termios.h>
# include	<signal.h>
# include	<sys/wait.h>
# include <dirent.h>

# define ENV 0
# define EXPORT 1
# define IS_DIR ": is a directory ❌\n"
# define NO_DIR ": No such file or directory ❌\n"
# define NO_PERM ": Permission denied ❌\n"
# define NOT_FOUND ": command not found ❌\n"
# define FAR ": filename argument required ❌\n"
# define USAGE ": usage: . filename [arguments]\n"
# define FREE_ON 7
# define SPACES " \n\t\v\f\r"
# define L_MIN "9223372036854775808"
# define L_MAX "9223372036854775807"

# define FORME 4
# define FREE_OFF 8
# define EXIT_ARG "Minishell$ : exit: too many arguments ❌\n"

extern int	g_status;

typedef struct s_stack
{
	char			c;
	struct s_stack	*next;
}	t_stack;

typedef struct s_ij
{
	int	i;
	int	j;
}	t_ij;

typedef struct s_redir
{
	int	len;
	int	hasinred;
	int	hasoutred;
	int	i;
}	t_redir;

typedef struct s_expand
{
	int			i;
	int			main_len;
	int			old_len;
	int			new_len;
	char		*result_str;
	char		*temp_str;
}	t_expand;

typedef struct s_token
{
	char			*value;
	int				type;
	struct s_token	*head;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

typedef struct s_env
{
	char			*key;
	char			*value;
	int				flag;
	struct s_env	*next;
	int				i;
	char			**tmp;
	int				pop;
	char			*tmp0;
	char			*tmp1;
	int				exflag;
	char			*tmp2;
}	t_env;

typedef struct s_groups
{
	char			**args;
	int				fd_in;
	int				fd_out;
	long long		exit_status;
	struct s_groups	*next;
	pid_t			pid;
	int				fds;
	int				invalid_flag;
}	t_groups;

typedef struct s_ft_add_f_first_prop
{
	int		len;
	int		begin;
	char	c;
	int		flag;
	int		i;
	int		j;
}			t_ft_add_f_first;

typedef struct s_hdoc
{
	char		*line;
	char		*file_path;
	char		*file_gen;
	size_t		len;
	size_t		read_;
	int			file_descriptor;
}	t_hdoc;

typedef struct s_data
{
	t_token		*token_list;
	t_groups	*groups;
	t_expand	*expand;
	char		*command;
	char		**envp;
	int			error_status;
	t_env		*env_list;
	int			exit;
	int			flag_faf;
	int			begin_faf;
	int			begin_in;
	int			begin_out;
	int			esrl_len;
	int			in;
	int			out;
	int			dup0;
	int			dup1;
	int			arg_len;
	int			invalid_flag;
	char		*res;
	int			result;
	int			fork_res;
	int			i;
	int			f;
	char		*path;
	char		**cmd_paths;
}	t_data;

typedef enum s_defines
{
	WORD,
	FIELD,
	EXP_FIELD,
	RD_OUT,
	RD_IN,
	RD_APPEND,
	RD_INSOURCE,
	PIPE,
}	t_defines;

// -------------------LEXER-----------------------------
int				ft_is_space(char c);
int				ft_is_redirection_in(char c);
int				ft_is_redirection_out(char c);
int				ft_is_word(char c);
int				ft_add_field(t_data *data, int i);
t_token			*ft_add_new_token(char *str, int type);
t_token			*ft_add_token_back(t_token *token, char *str, int type);
int				ft_add_word(t_data *data, int i);
int				ft_add_redirection_in(t_data *data, int i);
int				ft_add_redirection_out(t_data *data, int i);
int				ft_add_pipe(t_data *data, int i);
void			ft_lexer(t_data *data);
void			free_data(t_data *data);
// --------------------ENV------------------------------------
t_env			*ft_add_new_env(char *key, char *value, int flag);
t_env			*ft_add_env_back(t_env *env_list, char *key, \
				char *value, int flag);
void			ft_create_env_list(t_env **env_list, char **envp);
void			ft_delete_env_node(t_env *env_list, char *key);
void			ft_set_env_node(t_env *env_list, char *key, \
				char *new_value, int flag);
char			*ft_gval(t_env *env_list, char *key);
// ------------------EXPAND---------------------------------
void			ft_expanding(t_data *data);
// ------------------PARSING ------------------------------
int				args_len(t_token *token_list);
char			*fix_command(char *command);
int				grouping(t_data *data);
void			free_group(t_data *data);
//--------------------BUILTINS-----------------------------
int				echo(char **command);
int				pwd(void);
int				env(t_env *env);
int				cd(char **command, t_env *env);
int				export(char **command, t_env *env, t_data *data);
int				unset(char **command, t_env *env);
int				run_builtins(t_data *data, t_groups *group);
// ----------------UTILS--------------------------------
int				ft_strlen(char *str);
size_t			ft_strlcpy(char *dest, char *src, size_t size);
char			*ft_strtrim(char *str);
char			*ft_substr(char *str, int start, size_t len);
char			*ft_strdup(char *s1);
int				ft_word_len(char *word, int i);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
char			*ft_strjoin(char *s1, char *s2);
void			*ft_memmove(void *dest, const void *src, size_t len);
size_t			ft_strlcat(char *dest, const char *src, size_t len);
char			*ft_itoa(int n);
long long		ft_atoi(char *nptr);
int				ft_is_digit(int arg);
int				ft_lstsize_env(t_env *lst);
int				ft_lstsize(t_groups *lst);
char			**ft_split(char *s, char c);
int				ft_isalnum(int argument);
// -----------------ERROR-------------------------------
int				ft_print_error(t_data *data, char *error_str);
int				check_errors(t_data *data, t_token *token_list);
// ---------------EXECUTION--------------------------
char			*get_path(char **paths, t_data *data, t_groups *group);
void			env_list_to_array(t_data *data);
int				execute(t_groups *group, t_data *data);
char			*expanding_str(t_data *data, char *expand_str);
void			ft_putendl_fd(char *s, int fd);
void			*ft_memdel(void *ptr);
void			*ft_memset(void *b, int c, size_t len);
void			execute_builtin(t_groups *group, t_data *data);
int				ft_strcmp(char *s1, char *s2);
int				ft_lstsize(t_groups *lst);
int				is_builtin(char *arg);
//______________SIGNALS_____________________________

void			handler(int signal);
void			ft_ctrl_slash(int i);
void			signal_call(int i);
int				ft_is_digit_str(char *arg);
void			Remove_AllOccurrence(char *str, char ch);
int				var_len(char *s, int i, int quote);
int				expanded_len(char *cmd, int i, int quote, t_data *data);
//char	*expanded_env(char *cmd, int i, int quote);
void			strjoin_var(char *s1, char *s2);
// int	expanded_len(char *cmd, int i, int quote);
void			*ft_calloc(size_t count, size_t size);
char			*expanded_env(char *cmd, int i, int quote, t_data *data);
int				is_a_valid_name(char c, int cond);
int				ft_isspace(char c);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				var_len(char *s, int i, int quote);
void			execute_with_heredoc(char **args);
void			heredoc(char *key, int i);
void			heredoc_gen(t_groups *groups);
void			heredoc_sig(int sig);
void			handle_heredoc(char *delimiter);

int				pipe_redirections(t_groups *tmp);

t_stack			*ft_stack_push(t_stack *stack, char c);
t_stack			*ft_stack_pop(t_stack *stack);
char			ft_stack_peek(t_stack *stack);
int				ft_stack_is_empty(t_stack *stack);
void			ft_stack_clear(t_stack *stack);
void			increment_shell_level(t_env *env);
int				last_char(char *str, char c);
void			inthandle(int sig);
void			ft_signal(int handle);
void			handleterm(int sig);
char			**env_from_list(t_env *envp);

int				check_flag(t_data *data, int begin, int end);
int				get_begin_index(t_data *data, int i);
int				get_end_index(t_data *data, int i);
int				get_end_index(t_data *data, int i);
void			xecute_pipeline(t_groups *groups, t_data *data);

void			free_token_list(t_token *token_list);
void			free_tenv(t_env *env);
void			free_char_array(char ***arr);
void			free_groups(t_groups *group);
void			free_strings(char **tab);
void			free_ptr_arr(char **arr);
void			cd_helper(t_env *env, int cd_ret);
int				go_to_path(int option, t_env *env);
void			print_error(char **args);
int				update_oldpwd(t_env *env);
int				is_builtin(char *arg);
void			ft_builtin(t_groups *group, t_data *data);
int				is_valid_args(char *args, t_data *data);
void			print_sorted_env(t_env *env);
void			ft_exec(t_groups *group, t_data *data);
int				export_value(char **command, t_env *env, t_data *data);
void			num_req(char *cmd, t_groups *group, t_data *data);
int				isvalidnumber(char *str);
int				check(char *arg);
long long		ft_atoi2(char *str);
long long int	ft_abs(long double n);
void			c(t_data *data, char **command, t_groups *group);
void			h1(t_data *data, t_groups *group);
int				close_fds(int (*fds)[2], int psize);
void			forking(t_groups *groups, int num_cmds, \
				int (*fd_pipe)[2], t_data *data);
void			do_cmd(t_groups *groups, t_data *data);
int				hook_signals(void);
void			main4(t_data *data);
void			main3(t_data *data);
int				g_status_ma(t_data *data);
void			check_er_h(t_data *data);
int				fl_1(char *s, t_data *data, int *i, int *len);
void			esl(char *token_value, int i, int len, char c);
char			*rep_s(char *main_str, char *old_str, char *new_str);
int				final_len(char *s, t_data *data);
void			dosomethinggreat(char *expand_str, t_ij *iter, \
				char *res, t_data *data);
void			dosomething(char *expand_str, t_ij *iter, \
				char *res, t_data *data);
char			*ft_strncpy(char *dest, char *src, int n);
char			*ft_strcpy(char *s1, char *s2);
void			execute_pipeline(t_groups *groups, t_data *data);
int				grouping_4(t_data *data);
int				ft_h_init(t_data *data, t_hdoc *hdoc);
int				grouping_1(t_data *data);
int				grouping_2(t_data *data);
int				grouping_3(t_data *data);
int				ft_herdoc(t_data *data, char *delimiter);
int				ft_handle_quotes(t_data *data, int i);
int				ft_handle_word(t_data *data, int i);
int				ft_handle_redirection_in(t_data *data, int i);
int				ft_handle_redirection_out(t_data *data, int i);
int				ft_handle_pipe(t_data *data, int i);
void			ft_add_f_first_if(t_data *data, t_ft_add_f_first *first);
void			free_ex(t_expand	*ex);
int				ft_strncmp(char *s1, char *s2, unsigned int n);
int				r_str_init(t_expand	*ex, char *main_str, \
				char *old_str, char *new_str);
void			frre_r(t_expand	*ex);
void			r_str(t_expand	*ex, const char *new_str);
int				ft_is_dollar(char c);
int				ft_expand_string_len(char *token_value, int i);
int				get_expand_string_len(char *str, int i);
char			*expand_string_with_variable(t_data *data, char *variable_name);
char			*ft_strstr(char *str, char *to_find);
char			*ft_strchr(const char *s, int c);
char			*ft_strjoin_2(char *s1, char *s2);
int				ft_putstr_fd_1(char *s, int fd, int flag);

//______________ERRORS_____________________________
int				free_arr(char **arr);
int				cmd_errors(t_data *data, t_groups *tmp);
void			not_found(t_groups *tmp, t_data *data);
void			is_dir(t_groups *tmp, t_data *data);
void			no_dir(t_groups *tmp, t_data *data);
void			no_perm(t_groups *tmp, t_data *data);
int				cmd_errors(t_data *data, t_groups *tmp);
void			no_access(char *cmd, t_data *data);
void			cmd_errors_1(t_data *data, t_groups *tmp);
int				cmd_errors_2(t_data *data, t_groups *tmp);
char			*get_cmd(char **paths, char *cmd);
void			check_path(t_data *data, t_groups *tmp, \
				char *path, char **cmd_paths);
void			ft_exit(t_data *data, char **args, t_groups *cur);
char			*numstr(char *str);
int				ft_free(char **str);
int				find_first(char const *s1, char const *set);
size_t			ft_strlen_1(const char *str);
int				find_last(char const *s1, char const *set);
char			*ft_strdup_1(const char *src);
char			*ft_substr_1(char const *src, unsigned int start, size_t len);
char			*ft_strtrim_1(char const *s1, char const *set);
int				ft_isdigit_1(int arg);
void			h_h(t_data *data, char	*read_, char *delim);

#endif