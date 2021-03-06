GREEN='\033[0;32m'
NC='\033[0m'

printf "${GREEN}"
make -C ..
gcc -g ../ft_printf.o -w main.c -o main -L../libft -lft
printf "${NC}"
