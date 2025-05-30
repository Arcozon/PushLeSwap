NAME = push_swap
BONUS_NAME = checker

S_SRC_FORCE =  brutforce.c  init_force.c
D_SRC_FORCE =  force/
SRC_FORCE =  $(addprefix $(D_SRC_FORCE), $(S_SRC_FORCE))

S_SRC_ADALGO =  adalgo.c  ada_utils.c  cost.c  exec_best.c  find_sub_list.c
D_SRC_ADALGO =  adalgo/
SRC_ADALGO =  $(addprefix $(D_SRC_ADALGO), $(S_SRC_ADALGO))

S_SRC_ORDER =  exec_r.c  exec_rr.c  exec_s_p.c  print_exec_order.c
D_SRC_ORDER =  orders/
SRC_ORDER =  $(addprefix $(D_SRC_ORDER), $(S_SRC_ORDER))

S_SRC_INIT =  fix_them.c  init.c  is_valid.c
D_SRC_INIT =  init/
SRC_INIT =  $(addprefix $(D_SRC_INIT), $(S_SRC_INIT))

S_SRC_UTILS =  utils.c  list_utils.c
D_SRC_UTILS =  utils/
SRC_UTILS =  $(addprefix $(D_SRC_UTILS), $(S_SRC_UTILS))

SRC =  $(SRC_UTILS)  $(SRC_INIT) $(SRC_ORDER)  $(SRC_FORCE)  $(SRC_ADALGO)   main.c
D_SRC =  src/

S_SRC_BONUS =  b_exec_r.c  b_exec_rr.c  b_exec_s_p.c  b_get_next_order.c  b_init.c  b_is_valid.c  b_list_utils.c  bonus.c  b_utils.c  b_fix_them.c
D_SRC_BONUS =  bonus/
SRC_BONUS =  $(addprefix $(D_SRC_BONUS), $(S_SRC_BONUS))

D_INC = inc/ 

D_BUILD = .build/
OBJ =  $(addprefix $(D_BUILD), $(SRC:.c=.o))
B_OBJ = $(addprefix $(D_BUILD), $(SRC_BONUS:.c=.o))


CC =  cc
FLAGS = -Wall -Wextra -Werror -MMD -g

RM =  rm -rf

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o$@ $^

bonus:	$(BONUS_NAME)

$(BONUS_NAME):	$(B_OBJ)
	$(CC) -o $@ $^

$(D_BUILD)%.o:	$(D_SRC)%.c
	@mkdir -p $(@D)
	$(CC) $(FLAGS) -I$(D_INC) -c $< -o $@ 

clean:
	$(RM) $(D_BUILD)

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean
	make all

DEPS =  $(addprefix $(D_BUILD), $(SRC:.c=.d))
DEPS +=  $(addprefix $(D_BUILD), $(SRC_BONUS:.c=.d))
-include $(DEPS)

.PHONY: re fclean clean all $(CC) $(FLAGS) $(RM)

