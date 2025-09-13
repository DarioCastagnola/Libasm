NAME    = main
LIBNAME = libasm.a

ASM     = nasm
ASMFLAGS = -f elf64 -DPIC
AR      = ar
ARFLAGS = rcs

# Sources
LIBSRC  = ft_write.s ft_strlen.s ft_strcpy.s ft_strdup.s ft_read.s ft_strcmp.s   # all asm files that go into the library
LIBOBJ  = $(LIBSRC:.s=.o)

MAINSRC = main.c
MAINOBJ = $(MAINSRC:.c=.o)

all: $(NAME)

# final program
$(NAME): $(MAINOBJ) $(LIBNAME)
	gcc -o $(NAME) $(MAINOBJ) -L. -lasm

# static library
$(LIBNAME): $(LIBOBJ)
	$(AR) $(ARFLAGS) $(LIBNAME) $(LIBOBJ)

# generic rule to assemble .s → .o
%.o: %.s
	$(ASM) $(ASMFLAGS) $< -o $@

clean:
	rm -f $(LIBOBJ) $(MAINOBJ)

fclean: clean
	rm -f $(NAME) $(LIBNAME)

re: fclean all

run: re
	valgrind --leak-check=full ./$(NAME)
