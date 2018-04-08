char	*ft_gets(void)
{
	register char	buff[4];
	int		rd;

	while ((rd = read(0, buff, 3)))
	{
		buff[rd] = 0;
	}
}
