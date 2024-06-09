# Nom du programme
NAME = push_swap

# Dossier de sortie pour les fichiers objets
OBJ_DIR = obj/
SRCS_DIR = srcs/

# Dossiers des dépendances
PRINTF_DIR = ft_printf
LIBFT_DIR = libft

# Les différentes bibliothèques
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/ft_printf.a

# Headers et includes
HEADER = -I./includes \
	-I./libft \
	-I./printf/includes \

# Options de compilation
CFLAGS = -Wall -Wextra -Werror

# Commandes
CC = cc
RM = rm -rf

# Rechercher tous les fichiers .c dans le répertoire courant
SRCS = calculate.c \
	execute.c \
	free_utils.c \
	move_2.c \
	move_3.c \
	move.c \
	parse_utils.c \
	push_swap.c \
	small_algo.c \
	stack_3_utils.c \
	stack_2_utils.c \
	stack_utils.c \
	a_to_b.c \
	b_to_a.c

MAKEFLAGS += --no-print-directory
TOTAL_FILES := $(words $(SRCS))
CURRENT_INDEX := 0

# Conversion des fichiers source en fichiers objets
OBJS = $(addprefix ${OBJ_DIR}, $(SRCS:.c=.o))


# Cibles
all: $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) > /dev/null 2>&1
	@echo "\n"

$(PRINTF):
	@$(MAKE) -C $(PRINTF_DIR) > /dev/null 2>&1
	@echo "\n"

# Compilation de la bibliothèque

$(NAME): $(LIBFT) $(PRINTF) $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(HEADER) $(LIBFT) $(PRINTF)
	@echo "\n┗▷${BOLD}$(GREEN)『./$(NAME) Successfully created [✅]$(RESET)"

${OBJ_DIR}%.o: ${SRCS_DIR}%.c
	@mkdir -p $(dir $@)
	@$(eval CURRENT_INDEX=$(shell echo $$(($(CURRENT_INDEX)+1))))
	@$(eval PERCENT=$(shell echo $$(($(CURRENT_INDEX) * 100 / $(TOTAL_FILES)))))
	@printf "\r$(YELLOW)🔧 $(GREEN)%3d%% $(YELLOW)$(BOLD)Compiling:$(RED)$(BOLD) ${NAME}${RESET} $(RESET)$(BLUE)$(ITALIC)%-50s $(MAGENTA)[%3d/%3d]$(RESET)" $(PERCENT) "$<" $(CURRENT_INDEX) $(TOTAL_FILES)
	@${CC} ${CFLAGS} ${HEADER} -c $< -o $@

# Nettoyage des fichiers objets
clean:
	@echo "$(BOLD) [ 🗑️ ] $(YELLOW)$(REVERSED)Cleaning up$(RESET)"
	@$(MAKE) clean -C $(PRINTF_DIR) > /dev/null 2>&1
	@$(MAKE) clean -C $(LIBFT_DIR) > /dev/null 2>&1
	@$(RM) -r $(OBJ_DIR) > /dev/null 2>&1
	@echo "┗▷$(YELLOW)『$(ITALIC)./$(SRCS_DIR)'s$(RESET)$(YELLOW) object files cleaned』$(RESET)"

# Nettoyage complet
fclean: clean
	@$(MAKE) fclean -C $(PRINTF_DIR) > /dev/null 2>&1
	@$(MAKE) fclean -C $(LIBFT_DIR) > /dev/null 2>&1
	@$(RM) $(NAME) $(BONUS_NAME) > /dev/null 2>&1
	@echo "┗▷$(YELLOW)『$(ITALIC)./$(NAME)'s$(RESET)$(YELLOW) and ./$(BONUS_NAME)'s executables cleaned』$(RESET)"

# Recompiler entièrement
re: fclean
	$(MAKE) all

# test:
# 	@echo "$(GREEN)$(BOLD)Running tests..."
# 	@if [ -z "$(ELT)" ]; then echo "$(RED)Error: Please provide the number of elements to sort (e.g., make test ELT=100 REP=1000)"; exit 1; fi
# 	@if [ -z "$(REP)" ]; then echo "$(RED)Error: Please provide the number of repetitions (e.g., make test ELT=100 REP=1000)"; exit 1; fi
# 	@TOTAL_MOVES=0; \
# 	for i in $$(seq 1 $(REP)); do \
# 	    NUMBERS=$$(shuf -i 1-1000 -n $(ELT) | tr '\n' ' '); \
# 	    ARG="$$NUMBERS"; \
# 	    RESULT=$$(./$(NAME) $$ARG | ./$(BONUS_NAME) $$ARG); \
# 	    if [ "$$RESULT" != "OK" ]; then \
# 	        echo "$(RED)Erreur: Le tri n'a pas réussi pour le test $$i"; \
# 	        continue; \
# 	    fi; \
# 	    MOVES=$$(./$(NAME) $$ARG | wc -l); \
# 	    TOTAL_MOVES=$$((TOTAL_MOVES + MOVES)); \
# 	    echo "$(GREEN)Test$(RESET) $(YELLOW)$$i:$(RESET) $(RED)$(BOLD)$$MOVES $(RESET)$(BLUE)coups$(RESET)"; \
# 	done; \
# 	AVERAGE=$$((TOTAL_MOVES / $(REP))); \
# 	echo "Moyenne sur $(CYAN)$(BOLD)$(REP)$(RESET) tests avec $(CYAN)$(BOLD)$(ELT)$(RESET) éléments: $(RED)$(BOLD)$$AVERAGE$(RESET) coups"

test:
	@echo "$(GREEN)$(BOLD)Running tests..."
	@if [ -z "$(ELT)" ]; then echo "$(RED)Error: Please provide the number of elements to sort (e.g., make test ELT=100 REP=1000)"; exit 1; fi
	@if [ -z "$(REP)" ]; then echo "$(RED)Error: Please provide the number of repetitions (e.g., make test ELT=100 REP=1000)"; exit 1; fi
	@TOTAL_MOVES=0; \
	SUCCESS_COUNT=0; \
	MIN_MOVES=999999; \
	MAX_MOVES=0; \
	for i in $$(seq 1 $(REP)); do \
	NUMBERS=$$(shuf -i 1-1000 -n $(ELT) | tr '\n' ' '); \
	ARG="$$NUMBERS"; \
	RESULT=$$(./$(NAME) $$ARG | ./checker_linux $$ARG); \
	if [ "$$RESULT" != "OK" ]; then \
		echo "$(RED)Erreur: Le tri n'a pas réussi pour le test $$i"; \
		continue; \
	fi; \
	MOVES=$$(./$(NAME) $$ARG | wc -l); \
	TOTAL_MOVES=$$((TOTAL_MOVES + MOVES)); \
	echo "$(GREEN)Test$(RESET) $(YELLOW)$$i:$(RESET) $(RED)$(BOLD)$$MOVES $(RESET)$(BLUE)coups$(RESET)"; \
	if [ $$MOVES -lt $$MIN_MOVES ]; then \
		MIN_MOVES=$$MOVES; \
	fi; \
	if [ $$MOVES -gt $$MAX_MOVES ]; then \
		MAX_MOVES=$$MOVES; \
	fi; \
	if [ $(ELT) -eq 100 ] && [ $$MOVES -lt 700 ]; then \
		SUCCESS_COUNT=$$((SUCCESS_COUNT + 1)); \
	elif [ $(ELT) -eq 500 ] && [ $$MOVES -lt 5500 ]; then \
		SUCCESS_COUNT=$$((SUCCESS_COUNT + 1)); \
	fi; \
	done; \
	AVERAGE=$$((TOTAL_MOVES / $(REP))); \
	SUCCESS_PERCENTAGE=$$((SUCCESS_COUNT * 100 / $(REP))); \
	echo "Moyenne sur $(CYAN)$(BOLD)$(REP)$(RESET) tests avec $(CYAN)$(BOLD)$(ELT)$(RESET) éléments: $(RED)$(BOLD)$$AVERAGE$(RESET) coups"; \
	echo "Nombre minimum de coups: $(GREEN)$(BOLD)$$MIN_MOVES$(RESET)"; \
	echo "Nombre maximum de coups: $(RED)$(BOLD)$$MAX_MOVES$(RESET)"; \
	if [ $(ELT) -eq 100 ]; then \
	echo "Nombre de tests avec moins de $(CYAN)$(BOLD)700$(RESET) coups: $(GREEN)$(BOLD)$$SUCCESS_COUNT$(RESET)"; \
	elif [ $(ELT) -eq 500 ]; then \
	echo "Nombre de tests avec moins de $(CYAN)$(BOLD)5500$(RESET) coups: $(GREEN)$(BOLD)$$SUCCESS_COUNT$(RESET)"; \
	fi; \
	echo "Pourcentage de réussite: $(GREEN)$(BOLD)$$SUCCESS_PERCENTAGE%$(RESET)"

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
