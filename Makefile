SHELL = /bin/sh
NAME = libft.a
# Libc functions
SRCS = \
	srcs/ft_isalpha.c \
	srcs/ft_isdigit.c \
	srcs/ft_isalnum.c \
	srcs/ft_isascii.c \
	srcs/ft_isprint.c \
	srcs/ft_strlen.c \
	srcs/ft_memset.c \
	srcs/ft_bzero.c \
	srcs/ft_memcpy.c \
	srcs/ft_memmove.c \
	srcs/ft_strlcpy.c \
	srcs/ft_strlcat.c \
	srcs/ft_toupper.c \
	srcs/ft_tolower.c \
	srcs/ft_strchr.c \
	srcs/ft_strrchr.c \
	srcs/ft_strncmp.c \
	srcs/ft_memchr.c \
	srcs/ft_memcmp.c \
	srcs/ft_strnstr.c \
	srcs/ft_atoi.c \
	srcs/ft_calloc.c \
	srcs/ft_strdup.c 

# Additional functions
SRCS += \
	srcs/ft_substr.c \
	srcs/ft_strjoin.c \
	srcs/ft_strtrim.c \
	srcs/ft_split.c \
	srcs/ft_itoa.c \
	srcs/ft_strmapi.c \
	srcs/ft_striteri.c \
	srcs/ft_putchar_fd.c \
	srcs/ft_putstr_fd.c \
	srcs/ft_putendl_fd.c \
	srcs/ft_putnbr_fd.c 

# Bonus Functions
BONUS = \
	srcs/ft_lstnew.c \
	srcs/ft_lstadd_front.c \
	srcs/ft_lstsize.c \
	srcs/ft_lstlast.c \
	srcs/ft_lstadd_back.c \
	srcs/ft_lstdelone.c \
	srcs/ft_lstclear.c \
	srcs/ft_lstiter.c \
	srcs/ft_lstmap.c

# Personal Functions
SRCS += \
	srcs/ft_putnbr_base.c \
	srcs/ft_listnewfd.c \
	srcs/ft_strndup.c

INC = includes/

# **************************************************************************** #

OBJDIR	= objs/
OBJS = $(patsubst srcs/%.c, $(OBJDIR)%.o, $(SRCS))
DEPS	= $(OBJS:.o=.d)

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
CFLAGS	+= -MMD -MP
CFLAGS	+= $(addprefix -I,$(INC))
ARC		= ar rc
RAN		= ranlib
RM		= rm -f

ifdef WITH_BONUS
SRCS += $(BONUS)
endif

GR	= \033[32;1m
RE	= \033[31;1m
YE	= \033[33;1m
CY	= \033[36;1m
RC	= \033[0m

# **************************************************************************** #

all: $(NAME)

$(NAME) : $(OBJDIR) $(OBJS)
	@printf "\n$(GR)=== Compiled ==="
	@printf "\n--- $(notdir $(SRCS))$(RC)\n"
	$(ARC) $(NAME) $(OBJS)
	$(RAN) $(NAME)
	@printf "$(YE)=== Linked [$(CC)] ===\n--- $(NAME)$(RC)\n"

$(OBJDIR):
	@mkdir -p $(OBJDIR)
	@printf "$(GR)=== Compiling ... [$(CC) $(CFLAGS)] ===$(RC)\n"

$(OBJDIR)%.o: srcs/%.c
	@$(CC) $(CFLAGS) -c -o $@ $<
	@printf "$(GR)+$(RC)"

bonus:
	@make --no-print-directory WITH_BONUS=1

clean:
	$(RM) -r $(OBJDIR)

fclean: clean
	@printf "$(RE)=== Removing $(NAME) ===$(RC)\n"
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

-include $(DEPS)