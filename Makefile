# Define program names
NAME_SERVER = server
NAME_CLIENT = client

# Including libft & ft_printf & ensuring #include "libft.h" works
LIBFT_DIR = libft_42
LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF_DIR = ft_printf_42
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

# Headers
INCLUDES = -I. -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR)

# Define source files
SRCS_SERVER =	server.c
SRCS_CLIENT =	client.c

# Define object files
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

# Define compiler
CC = cc

# Define flags for compilation
CFLAGS = -Wall -Werror -Wextra

all: libft ft_printf $(NAME_SERVER) $(NAME_CLIENT)

libft:
	@make -C $(LIBFT_DIR)

ft_printf:
	@make -C $(FT_PRINTF_DIR)

$(NAME_SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBFT) $(FT_PRINTF) $(INCLUDES) -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(LIBFT) $(FT_PRINTF) $(INCLUDES) -o $(NAME_CLIENT)

# Rule to compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	@rm -f $(OBJS_CLIENT) $(OBJS_SERVER)
	@make -C $(LIBFT_DIR) clean
	@make -C $(FT_PRINTF_DIR) clean

fclean: clean
	@rm -f $(NAME_CLIENT) $(NAME_SERVER)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: clean fclean all re libft ft_printf

