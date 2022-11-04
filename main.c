#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
#endif

// including headers for GNL and ftprintf from my libft
char *get_next_line(int fd);
int ft_printf(char *placeholders, ...);
int	ft_isalnum(int c);
int	ft_atoi(const char *str);
int	ft_strncmp(const char *s1, const char *s2, size_t n);

int main(int argc, char **argv)
{
  if (argc > 1)
  {
    int fd;
    char *result = malloc(100);

    if (argc > 2 && argc < 5)
    {
      fd = open(argv[3], O_RDONLY);
      if (ft_strncmp(argv[1], "-l", argc) == 0)
      {
          result = get_next_line(fd);
          for (int i = 0; i < ft_atoi(argv[2]) && result != NULL; i++)
        {
          ft_printf("%s", result);
          result = get_next_line(fd);
        }
      }
      else
      {
        ft_printf("Invalid arguments\n");
      }
      free(result);
    }
    else
    {
      fd = open(argv[1], O_RDONLY);
      result = get_next_line(fd);
      for (;result != NULL;)
    {
      ft_printf("%s", result);
      result = get_next_line(fd);
    }
    free(result);
    }
    close(fd);
  }
  return (0);
}
