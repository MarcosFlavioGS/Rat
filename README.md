# Rat
Making my own "cat" command.

Rat is a CLI command to read files, same as Cat, but it's my version of it. It is also coded using my own static lib *libft* functions, like *ft_printf* and *get_next_line*.

## How to use

It can be simply called like:
```shell
rat <yourfile>
```
Or you can specify how many lines you want it to read:
```shell
rat -l 2 <yourfile>
```
You can also use the *head* option. It will read the first 15 lines of a file:
```shell
rat -h <yourfile>
```
