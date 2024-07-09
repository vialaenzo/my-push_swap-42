# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eviala <eviala@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/05 11:41:47 by eviala            #+#    #+#              #
#    Updated: 2024/07/07 09:59:09 by eviala           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom du programme
NAME = push_swap
BONUS_NAME = checker

# Dossier de sortie pour les fichiers objets
OBJ_DIR = obj/
SRCS_DIR = srcs/
SRCS_COMMON_DIR = srcs_common/
BONUS_DIR = srcs_bonus/

# Dossiers des dépendances
FT_PRINTF_DIR = ft_printf
LIBFT_DIR = libft

# Les différentes bibliothèques
LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = $(FT_PRINTF_DIR)/ft_printf.a

# Headers et includes
HEADER = -I./includes \
	-I./libft/includes \
	-I./ft_printf/includes \
	-I./src_bonus/includes

# Options de compilation
CFLAGS = -Wall -Wextra -Werror

# Commandes
CC = cc
RM = rm -rf

# Rechercher tous les fichiers .c dans le répertoire courant
SRCS = push_swap.c \
	ft_sorts.c \
	ft_sort_utils.c \
	ft_sort.c \
	index.c

SRCS_COMMON = ft_swap.c \
	ft_stack_utils.c \
	ft_stack_utils_2.c \
	ft_stdisplay.c \
	ft_rotate.c \
	ft_reverse_rotate.c \
	ft_push.c \
	checks.c \
	ft_utils.c \

SRCS_BONUS = checker_bonus.c \
	ft_push_bonus.c \
	ft_reverse_rotate_bonus.c \
	ft_rotate_bonus.c \
	ft_swap_bonus.c \


MAKEFLAGS += --no-print-directory
TOTAL_FILES := $(words $(SRCS) $(SRCS_COMMON))
TOTAL_FILES_BONUS := $(words $(SRCS_BONUS))
CURRENT_INDEX := 0
CURRENT_INDEX_BONUS := 0

# Conversion des fichiers source en fichiers objets
OBJS = $(addprefix ${OBJ_DIR}, $(SRCS:.c=.o))
OBJS_COMMON = $(addprefix ${OBJ_DIR}, $(SRCS_COMMON:.c=.o))
OBJS_BONUS = $(addprefix ${OBJ_DIR}, $(SRCS_BONUS:.c=.o))

# Cibles
all: $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "\n"

$(FT_PRINTF):
	@$(MAKE) -C $(FT_PRINTF_DIR)
	@echo "\n"

# Compilation de la bibliothèque

$(NAME): $(LIBFT) $(FT_PRINTF) $(OBJS) $(OBJS_COMMON)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(OBJS_COMMON) $(HEADER) $(LIBFT) $(FT_PRINTF)
	@echo "\n┗▷${BOLD}$(GREEN)『./$(NAME) Successfully created [✅]$(RESET)"

${OBJ_DIR}%.o: ${SRCS_DIR}%.c
	@mkdir -p $(dir $@)
	@$(eval CURRENT_INDEX=$(shell echo $$(($(CURRENT_INDEX)+1))))
	@$(eval PERCENT=$(shell echo $$(($(CURRENT_INDEX) * 100 / $(TOTAL_FILES)))))
	@printf "\r$(YELLOW)🔧 $(GREEN)%3d%% $(YELLOW)$(BOLD)Compiling:$(RED)$(BOLD) ${NAME}${RESET} $(RESET)$(BLUE)$(ITALIC)%-50s $(MAGENTA)[%3d/%3d]$(RESET)" $(PERCENT) "$<" $(CURRENT_INDEX) $(TOTAL_FILES)
	@${CC} ${CFLAGS} ${HEADER} -c $< -o $@

$(OBJ_DIR)%.o: $(SRCS_COMMON_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(eval CURRENT_INDEX=$(shell echo $$(($(CURRENT_INDEX)+1))))
	@$(eval PERCENT=$(shell echo $$(($(CURRENT_INDEX) * 100 / $(TOTAL_FILES)))))
	@printf "\r$(YELLOW)🔧 $(GREEN)%3d%% $(YELLOW)$(BOLD)Compiling:$(RED)$(BOLD) ${NAME}${RESET} $(RESET)$(BLUE)$(ITALIC)%-50s $(MAGENTA)[%3d/%3d]$(RESET)" $(PERCENT) "$<" $(CURRENT_INDEX) $(TOTAL_FILES)
	@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

# Cible bonus
bonus: $(BONUS_NAME)

$(BONUS_NAME): $(LIBFT) $(FT_PRINTF) $(OBJS_BONUS) $(OBJS_COMMON)
	@$(CC) $(CFLAGS) -o $(BONUS_NAME) $(OBJS_BONUS) $(OBJS_COMMON) $(HEADER) $(LIBFT) $(FT_PRINTF)
	@echo "\n┗▷${BOLD}$(GREEN)『./$(BONUS_NAME) Successfully created [✅]$(RESET)"

${OBJ_DIR}%.o: ${BONUS_DIR}%.c
	@mkdir -p $(dir $@)
	@$(eval CURRENT_INDEX_BONUS=$(shell echo $$(($(CURRENT_INDEX_BONUS)+1))))
	@$(eval PERCENT=$(shell echo $$(($(CURRENT_INDEX_BONUS) * 100 / $(TOTAL_FILES_BONUS)))))
	@printf "\r$(YELLOW)🔧 $(GREEN)%3d%% $(YELLOW)$(BOLD)Compiling:$(RED)$(BOLD) ${BONUS_NAME}${RESET} $(RESET)$(BLUE)$(ITALIC)%-50s $(MAGENTA)[%3d/%3d]$(RESET)" $(PERCENT) "$<" $(CURRENT_INDEX_BONUS) $(TOTAL_FILES_BONUS)
	@${CC} ${CFLAGS} ${HEADER} -c $< -o $@



# Nettoyage des fichiers objets
clean:
	@echo "$(BOLD) [ 🗑️ ] $(YELLOW)$(REVERSED)Cleaning up$(RESET)"
	@$(MAKE) clean -C $(FT_PRINTF_DIR) > /dev/null 2>&1
	@$(MAKE) clean -C $(LIBFT_DIR) > /dev/null 2>&1
	@$(RM) -r $(OBJ_DIR) > /dev/null 2>&1
	@echo "┗▷$(YELLOW)『$(ITALIC)./$(SRCS_DIR)'s$(RESET)$(YELLOW) object files cleaned』$(RESET)"

# Nettoyage complet
fclean: clean
	@$(MAKE) fclean -C $(FT_PRINTF_DIR) > /dev/null 2>&1
	@$(MAKE) fclean -C $(LIBFT_DIR) > /dev/null 2>&1
	@$(RM) $(NAME) $(BONUS_NAME) > /dev/null 2>&1
	@echo "┗▷$(YELLOW)『$(ITALIC)./$(NAME)'s$(RESET)$(YELLOW) and ./$(BONUS_NAME)'s executables cleaned』$(RESET)"

# Recompiler entièrement
re: fclean
	$(MAKE) all

test:
	@echo "$(GREEN)$(BOLD)Running tests..."
	@if [ -z "$(ELT)" ]; then echo "$(RED)Error: Please provide the number of elements to sort (e.g., make test ELT=100 REP=1000)"; exit 1; fi
	@if [ -z "$(REP)" ]; then echo "$(RED)Error: Please provide the number of repetitions (e.g., make test ELT=100 REP=1000)"; exit 1; fi
	@TOTAL_MOVES=0; \
	for i in $$(seq 1 $(REP)); do \
	    NUMBERS=$$(shuf -i 1-1000 -n $(ELT) | tr '\n' ' '); \
	    ARG="$$NUMBERS"; \
	    RESULT=$$(./$(NAME) $$ARG | ./$(BONUS_NAME) $$ARG); \
	    if [ "$$RESULT" != "OK" ]; then \
	        echo "$(RED)Erreur: Le tri n'a pas réussi pour le test $$i"; \
	        continue; \
	    fi; \
	    MOVES=$$(./$(NAME) $$ARG | wc -l); \
	    TOTAL_MOVES=$$((TOTAL_MOVES + MOVES)); \
	    echo "$(GREEN)Test$(RESET) $(YELLOW)$$i:$(RESET) $(RED)$(BOLD)$$MOVES $(RESET)$(BLUE)coups$(RESET)"; \
	done; \
	AVERAGE=$$((TOTAL_MOVES / $(REP))); \
	echo "Moyenne sur $(CYAN)$(BOLD)$(REP)$(RESET) tests avec $(CYAN)$(BOLD)$(ELT)$(RESET) éléments: $(RED)$(BOLD)$$AVERAGE$(RESET) coups"


.PHONY: all clean fclean re bonus test

# ... (le reste du Makefile reste inchangé)
.SILENT:
# Colors
RED := \033[0;31m
GREEN := \033[0;32m
YELLOW := \033[0;33m
BLUE := \033[0;34m
MAGENTA := \033[0;35m
CYAN := \033[0;36m
WHITE := \033[0;37m
RESET := \033[0m
BOLD := \033[1m
UNDERLINE := \033[4m
REVERSED := \033[7m
ITALIC := \033[3m
