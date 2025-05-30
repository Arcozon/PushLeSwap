NAME = push_swap
BONUS_NAME = checker

S_SRC_FORCE =  brutforce.c  init_force.c
D_SRC_FORCE =  force/
SRC_FORCE =  $(addprefix $(D_SRC_FORCE), $(S_SRC_FORCE))

S_SRC_PAPALGO =  papalgo.c
D_SRC_PAPALGO =  papalgo/
SRC_PAPALGO =  $(addprefix $(D_SRC_PAPALGO), $(S_SRC_PAPALGO))

S_SRC_ORDER =  exec_r.c  exec_rr.c  exec_s_p.c  print_exec_order.c  is_sorted.c
D_SRC_ORDER =  orders/
SRC_ORDER =  $(addprefix $(D_SRC_ORDER), $(S_SRC_ORDER))

S_SRC_INIT =  fix_them.c  init.c  is_valid.c
D_SRC_INIT =  init/
SRC_INIT =  $(addprefix $(D_SRC_INIT), $(S_SRC_INIT))

S_SRC_UTILS =  utils.c  list_manip.c
D_SRC_UTILS =  utils/
SRC_UTILS =  $(addprefix $(D_SRC_UTILS), $(S_SRC_UTILS))

SRC =  $(SRC_UTILS)  $(SRC_INIT) $(SRC_ORDER)  $(SRC_FORCE)  $(SRC_PAPALGO)  debug.c  main.c  find_sub_list.c adalgo.c
D_SRC =  src/

S_SRC_BONUS =  bonus.c
D_SRC_BONUS =  bonus/
SRC_BONUS =  $(addprefix $(D_SRC_BONUS), $(sort $(S_SRC_BONUS)))

D_INC = inc/ 

D_BUILD = .build/
OBJ =  $(addprefix $(D_BUILD), $(SRC:.c=.o))


CC =  cc
FLAGS = -Wall -Wextra -Werror -MMD -g

RM =  rm -rf

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o$@ $^

bonus:	$(BONUS_NAME)
	cc -o $@ $^

$(OBJ): $(D_BUILD)%.o:	$(D_SRC)%.c
	@mkdir -p $(@D)
	$(CC) $(FLAGS) -I$(D_INC) -c $< -o $@ 

clean:
	$(RM) $(D_BUILD)

fclean: clean
	$(RM) $(NAME)

re: fclean
	make all

DEPS = $(addprefix $(D_BUILD), $(SRC:.c=.d))
-include $(DEPS)

.PHONY: re fclean clean all $(CC) $(FLAGS) $(RM)

