
void	ft_duplicat(char **str)
{
	int	i;
	int	n;
	int k;
	int lawl;
	int tani;

	n = 0;
	i = 1;
	k = 0;
	// printf("%s\n", str[0]);
	// printf("%s\n", str[1]);
	// printf("%s\n", str[2]);
	
	while (str[k])
	{
		i = 1;
		while (str[i])
		{
			lawl = ft_atoi(str[k]);
			tani = ft_atoi(str[i]);
		printf("%d****%d\n", lawl,tani);
			if(lawl == tani && i != k)
				ft_error("pppp\n");
		i++;
		}
		k++;
	}
}

int	main(int ac, char **av)
{
	// t_s			d;
	int i;
	int n;
	char **str;
	char *s;

	n = 0;
	i = 1;
	if (ac > 1)
	{
		while (av[i])
		{
			ft_check(&av[i]);
			ft_number(&av[i]);
			s = ft_strjoin(s, av[i]);
			printf("%s\n", s);
			str = ft_split(s, ' ');
			ft_duplicat(str);
			i++;
		}
	}
	else
		exit(0);
}
