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
