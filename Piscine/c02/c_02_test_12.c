#include "ex12/ft_print_memory.c"

int main() {
	// Exercise 12
	char arr[] = "Bonjour les aminches\t\n\tc\a est fou\ttout\tce qu on peut faire avec\t\n\tprint_memory\n\n\n\tlol.lol\n ";
	if (ft_print_memory(arr, 92) != arr)
		return -1;
	char brr[] = "Chuncheon is better than Seoul!\200:)\377;)";
	ft_print_memory(brr, 38);
	ft_print_memory(brr, 10);
	ft_print_memory(brr, 0);
	for (int i = 13; i < 24; ++i)
		brr[i] = '\0';
	ft_print_memory(brr, 37);
	ft_print_memory(brr, 37);
	return 0;
}
