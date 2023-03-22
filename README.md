<h1 align="center"> Libft [EXTRA] [42 School] </h1>

<p align="center">
This is not the project that was submitted, which instead you can find [here]()
</p>
<hr>
<h3>How to use</h3>

<p>In your file.c include the header</p>
<code>#include "libft.h"</code>
<br><br>
<p>In your makefile add these lines</p>

<pre><code>
INCLUDES	=	-I includes -I $(LIBFT_DIR)/includes/

LIBFT		=	$(LIBFT_DIR)libft.a
LIBFT_DIR	=	libft/
LIB_FLAGS	=	-L $(LIBFT_DIR) -lft

$(LIBFT):
			make -C $(LIBFT_DIR)
</code></pre>

<p>and edit existing lines to get a result like this</p>

<pre><code>
$(NAME):	$(OBJS) $(LIBFT)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB_FLAGS)

clean:
			make clean -C $(LIBFT_DIR)
			$(RM) $(OBJS)
			$(RM) -r $(DIR_OBJS)

fclean:		clean
			make fclean -C $(LIBFT_DIR)
			$(RM) $(NAME)
</code></pre>