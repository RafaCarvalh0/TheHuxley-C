#include <stdio.h>
struct no_stack
{
	struct no_stack *proximo;
	struct no_list *inicio_stack;
};
struct stack
{
	struct no_stack *topo_da_stack;
};
struct stack *gerar_stack()
{
	struct stack *stack;
	stack = (struct stack *)malloc(sizeof(struct stack));
	stack->topo_da_stack = NULL;
	return stack;
}
struct no_list
{
	int x;
	struct no_list *proximo;
};
struct list
{
	struct no_list *inicio_stack;
};
struct no_list *gerar_list()
{
	struct no_list *list;
	list = (struct no_list *)malloc(sizeof(struct no_list *));
	return list;
}
struct list *aux_list(struct no_list *list)
{
	struct list *aux;
	aux = (struct list *)malloc(sizeof(struct list *));
	aux->inicio_stack = list;
	return aux;
}
float comando_push(struct stack *stack_atual, struct list *aux)
{
	struct no_stack *prox_no_stack;
	prox_no_stack = (struct no_stack *)malloc(sizeof(struct no_stack *));
	if (prox_no_stack == NULL)
	{
		return 0;
	}
	else
	{
		prox_no_stack->proximo = stack_atual->topo_da_stack;
		stack_atual->topo_da_stack = prox_no_stack;
		prox_no_stack->inicio_stack = aux->inicio_stack;
		return 1;
	}
}
void comando_pop(struct stack *stack_atual)
{
	struct no_list *list;
	struct no_stack *i;
	if (stack_atual->topo_da_stack != NULL)
	{
		printf("\n");
		i = stack_atual->topo_da_stack;
		stack_atual->topo_da_stack = i->proximo;
		list = i->inicio_stack;
		while (list != NULL)
		{
			printf("%d", list->x);
			if (list->proximo != NULL)
			{
				printf(" ");
			}
			list = list->proximo;
		}
		free(i->inicio_stack);
		free(i);
	}
	else
	{
		printf("\nEMPTY STACK");
	}
}
void num(struct list *aux, int verificar, int x)
{
	struct no_list *prox_no_list;
	struct no_list *ultimo;
	ultimo = aux->inicio_stack;
	prox_no_list = (struct no_list *)malloc(sizeof(struct no_list));
	if (verificar == 0)
	{
		ultimo->x = x;
		ultimo->proximo = NULL;
	}
	else
	{
		while (ultimo->proximo != NULL)
		{
			ultimo = ultimo->proximo;
		}
		prox_no_list->x = x;
		prox_no_list->proximo = NULL;
		ultimo->proximo = prox_no_list;
	}
}
int main()
{
	int x;
	char numeros_em_char[999], input[999];
	char character;
	struct no_list *list = gerar_list();
	struct list *aux = aux_list(list);
	struct stack *stack_atual = gerar_stack();
	while (scanf("%s", input) != EOF)
	{
		if (strcmp(input, "PUSH") == 0)
		{
			list = gerar_list();
			aux = aux_list(list);
			int condicao = 1, condicao2 = 0;
			while (condicao)
			{
				scanf("%c", &character);
				if (character == '\n' && condicao2 == 1)
				{
					condicao = 0;
				}
				else
				{
					scanf("%s", numeros_em_char);
					x = atoi(numeros_em_char);
					num(aux, condicao2, x);
				}
				condicao2 = 1;
			}
			comando_push(stack_atual, aux);
		}
		else
		{
			comando_pop(stack_atual);
		}
	}
	return 0;
}