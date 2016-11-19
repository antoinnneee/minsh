
#ifndef MINISHELL_H
# define MINISHELL_H
# define READ 2
# define WRITE 3
# define HEXA 1U << 2
# define OCT 1U << 1
# define STOP 1U << 0

typedef	struct	s_minish{
	char		**env;
	char		**path;
}				t_msh;

typedef struct	s_command{
	char		*prog;
	char		**param;
	char		**option;
	int		nbparam;
}			t_cmd;

typedef unsigned long long u64;

# define ft_strlensquare FSS

void	core_setenv(t_cmd **cmd, t_msh ***pmsh, int i);
void	env_param(t_cmd **cmd, t_msh ***msh, t_msh **tmp, int *opt);
void	env_unset(t_cmd **cmd, t_msh **tmp, int *opt, t_msh **msh);
int		issymb(const char c);
t_msh	*new_msh(void);
int		f(char **line, int i);
int		fb(char ***line, int i);
int		ft_issymb(const char c);
t_cmd		*split_cmd(char *str);
void		p_exit(const char *str, int value);
int		ft_itoa_base(char *str, int base);
int		ft_strlensquare(char **env, int *init);
t_cmd		*mod_cmd(t_cmd	**cmd, int i);
int		isbegin(const char *str, char *big);
int		beginby(const char *str, char *env);
char		**get_env(char *name, t_msh *env);
void		set_env(char *name, char *value, t_msh **env);
void		unset_env(char *name, t_msh **msh);
void		add_env(char *name, char *value, t_msh **env);
void		clear_term(void);
t_cmd		*parse_command(char *commande);
t_msh		*copy_env(void);
char		**copy_path(char **env);
char		*f_getenv(const char *str, char **env);
void		exec_cmd(t_cmd **cmd, t_msh **msh, t_msh **nmsh);
void		execute(char *name, t_cmd *cmd, t_msh **msh, t_msh **nmsh);
void		run_exit(t_cmd *cmd, t_msh *msh);
void		run_env(t_cmd **cmd, t_msh **msh);
void		run_unset(t_cmd *cmd, t_msh **msh);
void		run_setenv(t_cmd *cmd, t_msh **msh);
void		run_cd(t_cmd *cmd, t_msh *msh);
void		run_echo(t_cmd *cmd, t_msh *msh);
void		run_pwd(void);
void		free_cmd(t_cmd *cmd);
void		free_msh(t_msh **tmp);
void		free_split(char ***split);
void		free_tab(char **tab);
char		*get_option(char *commande, int *i);
void		print_detail_cmd(t_cmd *cmd);
char		*secure_cat(char *dest, char *str, int stqte);
void		print_msh(t_msh *env, unsigned int opt);
void		print_echo_v(void);
void		print_echo_h(void);
void		print_env_v(void);
void		print_env_help(void);
void		echoprintchar(const char *str);
void		echoprint(const char *str, unsigned int opt);
unsigned int	echoption(char **option);
int			echoflag(unsigned int state, int val);
int			ft_atoi_base(char *str, int i);
char		*g_p(char *str, int *j);
char		*g_p_n(char *str, int *j);
char		*get_param(char *commande, int *i);
void		setup_catch(void);
u64		set_add_msh(u64 ptr, int state);
t_cmd		**set_add_cmd(t_cmd **ptr, int state);
int			get_len(const char *str, int base, int max);

#endif
