
#ifndef MINISHELL_H
# define MINISHELL_H

typedef	struct	s_speopt{
	char	*option;
	char	*value;
}		t_spo;

typedef	struct	s_minish{
	char	**env;
	char	**path;
}		t_msh;

typedef struct	s_command{
	char	*prog;
//	t_spo	*spo;
	char	**param;
	char	**option;
	int	nbparam;
}		t_cmd;

# define ft_strlensquare FSS

int		ft_issymb(const char c);
t_cmd		*split_cmd(char *str);
void		p_exit(const char *str, int value);
int		ft_itoa_base(char *str, int base);
int		ft_strlensquare(char **env);
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
int		ft_atoi_base(char *str, int i);
char		*g_p(char *str, int *j);
char		*g_p_n(char *str, int *j);
char		*get_param(char *commande, int *i);

#endif
