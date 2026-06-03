#include <gtest/gtest.h>

extern "C" {
	#include <fcntl.h>
	#include <get_next_line.h>
}

TEST(FTlstaddback, itShouldAddANodeToTheEndOfAnEmptyList) {
	t_list	*node = NULL;

	ft_lstadd_back(&node, 'A');

	ASSERT_EQ('A', node->c);
	ASSERT_TRUE(NULL != node);

	free(node);
}

TEST(FTlstaddback, itShouldAddANodeIntoTheEndOfANonEmptyListAndUpdateItsTail)
{
	t_list *node = (t_list *)malloc(sizeof(t_list));
	node->c = 'A';
	node->next = NULL;
	t_list *tail = node;

	ft_lstadd_back(&tail, 'B');

	ASSERT_NE(node, tail);
	ASSERT_EQ(node->next, tail);
	ASSERT_EQ('B', tail->c);

	free(node);
	free(tail);
}
