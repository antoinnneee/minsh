#include "../includes/minishell.h"
#include "../libft/includes/libft.h"

static unsigned int	echoption(char	**option)
{
	int	i;
	int	opt;

	i = 0;
	opt = 0;
	if (option)
		while (option[i])
		{
			if (isbegin("-n", option[i]))
				opt = opt | (1U << 0);
			else if (isbegin("-e", option[i]))
				opt = opt | (1U << 1);
			else if (isbegin("-E", option[i]))
				opt = opt | (1U << 2);
			else if (isbegin("--help", option[i]))
			{
				print_echo_h();
				opt = opt | (1U << 3);
				return (opt);
			}
			else if (isbegin("--version", option[i]))
			{
				print_echo_v();
				opt = opt | (1U << 3);
				return (opt);
			}
			i++;
		}
	return (opt);
}

# define READ 2
# define WRITE 3
# define HEXA 1U << 2
# define OCT 1U << 1
# define STOP 1U << 0

static int	echoflag(unsigned int state, int val)
{
	static int st_val = 0;

	if (state == WRITE)
	{
		if (val == 0)
			st_val = 0;
		else
			st_val = st_val | val;
		return (0);
	}
	else if (state == READ)
	{
		if (st_val & val)
			return (1);
		else
			return (0);
	}
	else
		return(0);
}

void	echoprintchar(const char *c)
{
	if (*c == '\\')
		ft_putchar('\\');
	else if (*c == 'a')
		ft_putchar(7);
	else if (*c == 'b')
		ft_putchar(8);
	else if (*c == 'c')
		echoflag(WRITE, STOP);
	else if (*c == 'e')
		ft_putchar(27);
	else if (*c == 'f')
		ft_putchar(12);
	else if (*c == 'n')
		ft_putchar('\n');
	else if (*c == 'r')
		ft_putchar(13);
	else if (*c == 't')
		ft_putchar(9);
	else if (*c == 'v')
		ft_putchar(11);
	else if (*c == '0')
		echoflag(WRITE, OCT);
	else if (*c == 'x')
		echoflag(WRITE, HEXA);
	else
	{
		ft_putchar('\\');
		ft_putchar(*c);
	}
}

int	get_len(const char *str, int base, int max)
{
	int	i;

	i = 0;
	while (ft_isalnum(str[i]) && i < max)
	{
		if (base > 10)
		{
			if (!((str[i] >= 'a' && str[i] < 'a' + base - 10)
		|| (str[i] >= 'A' && str[i] < 'A' + base - 10) || ft_isdigit(str[i])))
				return (i);
		}
		else
		{
			if (!(ft_isdigit(str[i]) && str[i] < '0' + base))
				return (i);
		}
		i++;
	}
	return (i);
}

static void	printhexa(const char *str, int *i)
{
	int	len;
	char	*sub;

	if ((len = get_len(str, 16, 2)))
	{
		sub = ft_strsub(str, 0, len + 1);
		ft_putendl(sub);
		if (sub)
		{
			ft_putchar((char)ft_atoi_base(sub, 16));
			free(sub);
		}
		*i = *i + len + 1;
	}
	echoflag(WRITE, 0);
}

static void	printoct(const char *str, int *i)
{
	int	len;
	char	*sub;

	if ((len = get_len(str, 8, 2)))
	{
		sub = ft_strsub(str, 0, len + 1);
		ft_putendl("sub :");
		ft_putendl(sub);
		ft_putendl(": sub");
		if (sub)
		{
			ft_putchar((char)ft_atoi_base(sub, 8));
			free(sub);
		}
		*i = *i + len + 1;
	}
	echoflag(WRITE, 0);
}

static void	echoprint(const char *str, unsigned int opt)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (echoflag(READ, STOP))
			return ;
		if (echoflag(READ, OCT))
		{
			printoct(&str[i], &i);
		}
		if (echoflag(READ, HEXA))
		{
			printhexa(&str[i], &i);
		}
		if ((opt & (1U << 1)))
			if (str[i] == '\\')
				echoprintchar(&str[++i]);
			else
				ft_putchar(str[i]);
		else
			ft_putchar(str[i]);
		i++;
	}
}

void	run_echo(t_cmd *cmd, t_msh *msh)
{
	int	i;
	unsigned int	opt;

	opt = echoption(cmd->option);
	i = 0;
	if (cmd->param)
	{
		while (cmd->param[i])
		{
			echoprint(cmd->param[i], opt);
			if (echoflag(READ, STOP))
			{
				echoflag(WRITE, 0);
				return ;
			}
			ft_putchar(' ');
			i++;
		}
	}
	if (!(opt & (1U << 0)))
		ft_putchar('\n');
}

