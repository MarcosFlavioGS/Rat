#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000 
#endif

// including headers for GNL and ftprintf from my libft
char *get_next_line(int fd);
int ft_printf(char *placeholders, ...);
int	ft_atoi(const char *str);
int	ft_strncmp(const char *s1, const char *s2, size_t n);

void reader(int fd, char *str)
{
  if (fd == -1)
  {
    ft_printf("Error: file not found");
    exit (1);
  }
  char *result;
  int  lines = ft_atoi(str);

  if (lines < 0)
  {
    ft_printf("Error: invalid number of lines");
    exit (1);
  }
  result = get_next_line(fd);
  for (int i = 0; i < lines && result; i++)
  {
    ft_printf("%s",result);
    free (result);
    result = get_next_line(fd);
  }
  free(result);
}

int main(int argc, char **argv)
{
  if (argc > 1)
  {
    int fd;
    char *result;

    if (argc > 2)
    {
      if (ft_strncmp(argv[1], "-l", 2) == 0)
      {
        fd = open(argv[3], O_RDONLY);
        reader(fd, argv[2]);
      }
      else if (ft_strncmp(argv[1], "-h", 2) == 0)
      {
        fd = open(argv[2], O_RDONLY);
        reader(fd, "15");
      }
      else
      {
        ft_printf("Invalid arguments\n");
      }
    }
    else
    {
      fd = open(argv[1], O_RDONLY);
      if (fd == -1)
      {
        ft_printf("Error: file %s not found", argv[1]);
        return (1);
      }
      result = get_next_line(fd);
      for (;result != NULL;)
      {
        ft_printf("%s", result);
        free (result);
        result = get_next_line(fd);
      }
      free(result);
    }
    close(fd);
  }
  return (0);
}
