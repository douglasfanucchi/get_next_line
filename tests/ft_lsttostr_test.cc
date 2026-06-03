#include <gtest/gtest.h>

extern "C" {
	#include <get_next_line.h>
}

TEST(FTlsttostr, itShouldReturnNULLOnEmptyList) {
	t_list	*node = NULL;

	char *result = ft_lsttostr(node);

	ASSERT_EQ(NULL, result);

	free(result);
}

TEST(FTlsttostr, itShouldConvertANonEmptyListToItsStringRepresentation) {
	t_list	*head = NULL;
	ft_lstadd_back(&head, 'h');
	t_list	*tail = head;
	ft_lstadd_back(&tail, 'e');
	ft_lstadd_back(&tail, 'l');
	ft_lstadd_back(&tail, 'l');
	ft_lstadd_back(&tail, 'o');

	char *result = ft_lsttostr(head);

	ASSERT_STREQ("hello", result);

	free(result);
	while (head)
	{
		t_list *tmp = head;
		head = head->next;
		free(tmp);
	}
}
